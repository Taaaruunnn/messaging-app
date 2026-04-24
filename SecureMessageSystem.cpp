#include "SecureMessageSystem.h"
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

size_t SecureMessageSystem::hashPassword(const string& password) {
    return hash<string>{}(password);
}

bool SecureMessageSystem::registerUser(const string& username, const string& password) {
    if (users.find(username) != users.end()) {
        return false;
    }
    users[username] = hashPassword(password);
    return true;
}

bool SecureMessageSystem::login(const string& username, const string& password) {
    auto it = users.find(username);
    if (it != users.end()) {
        return it->second == hashPassword(password);
    }
    return false;
}

void SecureMessageSystem::sendMessage(const string& sender, const string& content, int priority) {
    Message msg(sender, content, priority);
    messageQueue.push(msg);
    messageHistory.push_back(msg);
    cout << "Message sent successfully!\n";
}

void SecureMessageSystem::viewQueueMessages() {
    if (messageQueue.empty()) {
        cout << "No unread messages in the queue.\n";
        return;
    }
    cout << "\n--- Consuming Unread Messages (Priority Queue) ---\n";
    while (!messageQueue.empty()) {
        Message msg = messageQueue.top();
        messageQueue.pop();
        string prioStr = (msg.priority == 1) ? "[URGENT] " : "[NORMAL] ";
        cout << prioStr << "[" << msg.sender << "]: " << msg.content << "\n";
    }
}

void SecureMessageSystem::searchMessages(const string& keyword) {
    cout << "\n--- Search Results for '" << keyword << "' ---\n";
    bool found = false;
    for (const auto& msg : messageHistory) {
        if (msg.content.find(keyword) != string::npos || msg.sender.find(keyword) != string::npos) {
            cout << "[" << msg.sender << "]: " << msg.content << "\n";
            found = true;
        }
    }
    if (!found) cout << "No matching messages found.\n";
}

void SecureMessageSystem::sortMessagesByLength() {
    if (messageHistory.empty()) {
        cout << "No messages to sort.\n";
        return;
    }
    vector<Message> sortedMsgs = messageHistory;
    sort(sortedMsgs.begin(), sortedMsgs.end(), [](const Message& a, const Message& b) {
        return a.content.length() < b.content.length();
    });
    
    cout << "\n--- Messages Sorted by Length (Shortest to Longest) ---\n";
    for (const auto& msg : sortedMsgs) {
        cout << "[" << msg.sender << "] (" << msg.content.length() << " chars): " << msg.content << "\n";
    }
}

void SecureMessageSystem::sortMessagesByTime() {
    if (messageHistory.empty()) {
        cout << "No messages to sort.\n";
        return;
    }
    vector<Message> sortedMsgs = messageHistory;
    sort(sortedMsgs.begin(), sortedMsgs.end(), [](const Message& a, const Message& b) {
        return a.timestamp < b.timestamp;
    });
    
    cout << "\n--- Messages Sorted by Time (Oldest to Newest) ---\n";
    for (const auto& msg : sortedMsgs) {
#ifdef _WIN32
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &msg.timestamp);
        string timeStr(buffer);
#else
        string timeStr(ctime(&msg.timestamp));
#endif
        timeStr.pop_back();
        cout << "[" << timeStr << "] [" << msg.sender << "]: " << msg.content << "\n";
    }
}

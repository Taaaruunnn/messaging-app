#ifndef SECURE_MESSAGE_SYSTEM_H
#define SECURE_MESSAGE_SYSTEM_H

#include "Message.h"
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>

struct CompareMessages {
    bool operator()(const Message& a, const Message& b) const {
        if (a.priority == b.priority) {
            return a.timestamp > b.timestamp;
        }
        return a.priority < b.priority;
    }
};

class SecureMessageSystem {
private:
    std::unordered_map<std::string, size_t> users;
    std::priority_queue<Message, std::vector<Message>, CompareMessages> messageQueue;
    std::vector<Message> messageHistory;

    size_t hashPassword(const std::string& password);

public:
    bool registerUser(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    void sendMessage(const std::string& sender, const std::string& content, int priority);
    void viewQueueMessages();
    void searchMessages(const std::string& keyword);
    void sortMessagesByLength();
    void sortMessagesByTime();
};

#endif

#include "SecureMessageSystem.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu(bool loggedIn) {
    cout << "\n=== Secure Message Queue System ===\n";
    if (!loggedIn) {
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "0. Exit\n";
    } else {
        cout << "3. Send Message (Priority Queue)\n";
        cout << "4. View & Read Queue (Priority Queue)\n";
        cout << "5. Search Messages & Users\n";
        cout << "6. Sort Messages by Length\n";
        cout << "7. Sort Messages by Time\n";
        cout << "8. Logout\n";
        cout << "0. Exit\n";
    }
    cout << "Select an option: ";
}

int main() {
    SecureMessageSystem system;
    bool running = true;
    string currentUser = "";

    while (running) {
        displayMenu(currentUser != "");
        int choice;
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore();

        if (currentUser == "") {
            switch (choice) {
                case 1: {
                    string user, pass;
                    cout << "Enter new username: ";
                    getline(cin, user);
                    cout << "Enter new password: ";
                    getline(cin, pass);
                    if (system.registerUser(user, pass)) {
                        cout << "Registration successful!\n";
                    } else {
                        cout << "Username already exists!\n";
                    }
                    break;
                }
                case 2: {
                    string user, pass;
                    cout << "Enter username: ";
                    getline(cin, user);
                    cout << "Enter password: ";
                    getline(cin, pass);
                    if (system.login(user, pass)) {
                        cout << "Login successful! Welcome, " << user << ".\n";
                        currentUser = user;
                    } else {
                        cout << "Invalid username or password.\n";
                    }
                    break;
                }
                case 0:
                    running = false;
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid option! Please pick 1, 2, or 0.\n";
            }
        } else {
            switch (choice) {
                case 3: {
                    string content;
                    cout << "Enter your message: ";
                    getline(cin, content);
                    string prioStr;
                    int priorityChoice = 0;
                    cout << "Choose priority (0 = Normal, 1 = Urgent): ";
                    getline(cin, prioStr);
                    if (prioStr == "1") {
                        priorityChoice = 1;
                    }
                    system.sendMessage(currentUser, content, priorityChoice);
                    break;
                }
                case 4:
                    system.viewQueueMessages();
                    break;
                case 5: {
                    string keyword;
                    cout << "Enter keyword to search for (Content or User): ";
                    getline(cin, keyword);
                    system.searchMessages(keyword);
                    break;
                }
                case 6:
                    system.sortMessagesByLength();
                    break;
                case 7:
                    system.sortMessagesByTime();
                    break;
                case 8:
                    cout << "Logged out successfully.\n";
                    currentUser = "";
                    break;
                case 0:
                    running = false;
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid option!\n";
            }
        }
    }
    return 0;
}

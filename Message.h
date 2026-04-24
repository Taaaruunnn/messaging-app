#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ctime>

struct Message {
    std::string sender;
    std::string content;
    time_t timestamp;
    int priority;

    Message(std::string s, std::string c, int p);
};

#endif

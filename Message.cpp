#include "Message.h"

Message::Message(std::string s, std::string c, int p) : sender(s), content(c), priority(p) {
    timestamp = time(0);
}

#include "ChatRoom.h"
#include "Users.h"

void ChatRoom::saveMessage(const std::string& message, Users& fromUser) {
    if (this->chatHistory == nullptr) {
        this->chatHistory = new std::string();
    }
    *this->chatHistory += message + "\n";
}
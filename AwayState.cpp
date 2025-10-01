#include "AwayState.h"
#include "Users.h"
#include "ChatRoom.h"
#include <iostream>

void AwayState::handleMessage(Users* user, const std::string& message, Users& fromUser, ChatRoom& room) {
    std::cout << user->getName() << " (AWAY) - Auto-reply: 'I'm away, will respond later'" << std::endl;
    // Could send auto-reply back to sender
}

std::string AwayState::getStatusName() {
    return "Away";
}

bool AwayState::canReceiveMessages() {
    return true;
}
/**
 * @file ActiveState.cpp
 * @brief Implements the ActiveState behaviour.
 */

#include "ActiveState.h"
#include "Users.h"
#include "ChatRoom.h"
#include <iostream>

void ActiveState::handleMessage(Users* user, const std::string& message, Users& fromUser, ChatRoom& room) {
    std::cout << user->getName() << " (ACTIVE) received: " << message << std::endl;
}

std::string ActiveState::getStatusName() {
    return "Active";
}

bool ActiveState::canReceiveMessages() {
    return true;
}
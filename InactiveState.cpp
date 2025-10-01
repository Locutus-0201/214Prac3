/**
 * @file InactiveState.cpp
 * @brief Implements the InactiveState behaviour.
 */

#include "InactiveState.h"
#include "Users.h"
#include "ChatRoom.h"
#include <iostream>

void InactiveState::handleMessage(Users* user, const std::string& message, Users& fromUser, ChatRoom& room) {
    std::cout << user->getName() << " is INACTIVE - message queued: " << message << std::endl;
}

std::string InactiveState::getStatusName() {
    return "Inactive";
}

bool InactiveState::canReceiveMessages() {
    return false;
}
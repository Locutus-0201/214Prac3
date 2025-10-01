#include "Users.h"
#include "Command.h"
#include "SendMessageCommand.h" 
#include "SaveMessageCommand.h"
#include "ChatRoom.h"
#include "ActiveState.h"
#include "InactiveState.h"
#include "AwayState.h"
#include <iostream>

// Fix: Single constructor with state initialization
Users::Users(std::string name) : name(name), currentState(new ActiveState()) {}
Users::Users(const char* name) : name(name ? name : ""), currentState(new ActiveState()) {}

// Add: Destructor implementation
Users::~Users() {
    delete currentState;
}

void Users::setState(UserState* newState) {
    delete currentState;
    currentState = newState;
}

void Users::goActive() { setState(new ActiveState()); }
void Users::goInactive() { setState(new InactiveState()); }
void Users::goAway() { setState(new AwayState()); }

void Users::send(const std::string& message, ChatRoom& room) {
    addCommand(new SendMessageCommand(&room, this, message));
    addCommand(new SaveMessageCommand(&room, this, message));
    executeAll();
}

// Fix: Use state pattern for message handling
void Users::receive(const std::string& message, Users& fromUser, ChatRoom& room) {
    currentState->handleMessage(this, message, fromUser, room);
}

void Users::addCommand(Command* command) {
    commandQueue.push_back(command);
}

void Users::executeAll() {
    for (Command* cmd : commandQueue) {
        if (cmd) {
            cmd->execute();
            delete cmd;
        }
    }
    commandQueue.clear();
}

// Add: Missing method implementations
std::string Users::getStatus() {
    return currentState->getStatusName();
}

bool Users::isActive() {
    return currentState->canReceiveMessages();
}
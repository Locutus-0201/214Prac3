/**
 * @file SendMessageCommand.cpp
 * @brief Implements the SendMessageCommand behaviour.
 */

#include "SendMessageCommand.h"
#include "ChatRoom.h"
#include "Users.h"

void SendMessageCommand::execute() {
    if (chatRoom && fromUser) {
        chatRoom->sendMessage(message, *fromUser);
    }
}
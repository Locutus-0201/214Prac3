/**
 * @file SaveMessageCommand.cpp
 * @brief Implements the SaveMessageCommand behaviour.
 */

#include "SaveMessageCommand.h"
#include "ChatRoom.h"
#include "Users.h"

void SaveMessageCommand::execute() {
    if (chatRoom && fromUser) {
        chatRoom->saveMessage(message, *fromUser);
    }
}
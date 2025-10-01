#include "SaveMessageCommand.h"
#include "ChatRoom.h"
#include "Users.h"

void SaveMessageCommand::execute() {
    if (chatRoom && fromUser) {
        chatRoom->saveMessage(message, *fromUser);
    }
}
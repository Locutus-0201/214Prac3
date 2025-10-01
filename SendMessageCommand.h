#ifndef SENDMESSAGECOMMAND_H
/**
 * @file SendMessageCommand.h
 * @brief Command to send a message to all users in a chat room.
 * @author Aaron Kim, Damian Moustakis
 * @date 2025-09-30
 */
#define SENDMESSAGECOMMAND_H

#include "Command.h"

/**
 * @class SendMessageCommand
 * @brief Command to send a message to all users in a chat room.
 *
 * Responsibilities:
 * - Deliver a message to all users in the room
 */
class SendMessageCommand : public Command {
public:
    /**
     * @brief Construct a SendMessageCommand object.
     * @param room Target chat room.
     * @param user User who sends the message.
     * @param msg Message content.
     */
    SendMessageCommand(ChatRoom* room, Users* user, const std::string& msg)
        : Command(room, user, msg) {}
    
    /**
     * @brief Execute the send message command.
     */
    void execute() override;
};

#endif
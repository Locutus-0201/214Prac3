#ifndef SAVEMESSAGECOMMAND_H
/**
 * @file SaveMessageCommand.h
 * @brief Command to save a message to chat history.
* @author Aaron Kim, Damian Moustakis
 * @date 2025-09-30
 */
#define SAVEMESSAGECOMMAND_H

#include "Command.h"

/**
 * @class SaveMessageCommand
 * @brief Command to save a message to chat history.
 *
 * Responsibilities:
 * - Save a message to the chat room's history
 */
class SaveMessageCommand : public Command {
public:
    /**
     * @brief Construct a SaveMessageCommand object.
     * @param room Target chat room.
     * @param user User who sends the message.
     * @param msg Message content.
     */
    SaveMessageCommand(ChatRoom* room, Users* user, const std::string& msg)
        : Command(room, user, msg) {}
    
    /**
     * @brief Execute the save message command.
     */
    void execute() override;
};

#endif
#ifndef COMMAND_H
/**
 * @file Command.h
 * @brief Abstract base class for command pattern in chat system.
* @author Aaron Kim, Damian Moustakis
 * @date 2025-09-30
 */
#define COMMAND_H

#include <string>

// Forward declares
class ChatRoom;
class Users;

/**
 * @class Command
 * @brief Abstract base class for command pattern in chat system.
 *
 * Attributes:
 * - chatRoom: Target chat room
 * - fromUser: User who issued the command
 * - message: Message content
 *
 * Responsibilities:
 * - Encapsulate actions as objects
 * - Provide execute() interface
 */
class Command {
protected:
    ChatRoom* chatRoom;
    Users* fromUser;
    std::string message;

public:
    /**
     * @brief Construct a Command object.
     * @param room Target chat room.
     * @param user User who issued the command.
     * @param msg Message content.
     */
    Command(ChatRoom* room, Users* user, const std::string& msg)
        : chatRoom(room), fromUser(user), message(msg) {}
    
    /**
     * @brief Virtual destructor.
     */

     
    virtual ~Command() = default;
    /**
     * @brief Execute the command.
     */
    virtual void execute() = 0;
};

#endif
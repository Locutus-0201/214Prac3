#ifndef USERSTATE_H
/**
 * @file UserState.h
 * @brief Abstract state for user status in the chat system.
* @author Aaron Kim, Damian Moustakis
 * @date 2025-09-30
 */
#define USERSTATE_H

#include <string>

class Users;
class ChatRoom;

/**
 * @class UserState
 * @brief Abstract state for user status in the chat system.
 *
 * Responsibilities:
 * - Define interface for user state behavior
 */
class UserState {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~UserState() = default;
    /**
     * @brief Handle a message for a user in a given state.
     * @param user The user receiving the message.
     * @param message The message content.
     * @param fromUser The user who sent the message.
     * @param room The chat room where the message was sent.
     */
    virtual void handleMessage(Users* user, const std::string& message, Users& fromUser, ChatRoom& room) = 0;
    /**
     * @brief Get the name of the current state.
     * @return The status name as a string.
     */
    virtual std::string getStatusName() = 0;
    /**
     * @brief Check if the user can receive messages in this state.
     * @return True if can receive, false otherwise.
     */
    virtual bool canReceiveMessages() = 0;
};

#endif


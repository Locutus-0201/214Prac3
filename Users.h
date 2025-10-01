#ifndef USERS_H
/**
 * @file Users.h
 * @brief Abstract base class for users in the chat system.
* @author Aaron Kim, Damian Moustakis
 * @date 2025-09-30
 */
#define USERS_H

#include <string>
#include <vector>

// Forward declarations only
class UserState;
class ChatRoom;
class Command;

/**
 * @class Users
 * @brief Abstract base class for users in the chat system.
 *
 * Attributes:
 * - currentState: The current state of the user (Active, Away, Inactive)
 * - chatRooms: Rooms the user is part of
 * - name: User's name
 * - commandQueue: Commands to be executed
 *
 * Responsibilities:
 * - Send and receive messages
 * - Manage state and commands
 */
class Users {
private:
    UserState* currentState;
    std::vector<std::string> queuedMessages;

protected:
    std::vector<ChatRoom*> chatRooms;
    std::string name;
    std::vector<Command*> commandQueue;

public:
    Users() = default;
    explicit Users(std::string name);
    Users(const char* name);
    ~Users();

    /**
     * @brief Send a message to a chat room.
     * @param message The message to send.
     * @param room The chat room to send the message to.
     */
    void send(const std::string& message, ChatRoom& room);
    /**
     * @brief Receive a message from another user.
     * @param message The message received.
     * @param fromUser The user who sent the message.
     * @param room The chat room where the message was sent.
     */
    void receive(const std::string& message, Users& fromUser, ChatRoom& room);
    /**
     * @brief Add a command to the user's command queue.
     * @param command Pointer to the command to add.
     */
    void addCommand(Command* command);
    /**
     * @brief Execute all commands in the user's command queue.
     */
    void executeAll();

    /**
     * @brief Get the user's name.
     * @return The user's name.
     */
    const std::string& getName() const { return name; }
    
    /**
     * @brief Set the user's state.
     * @param newState Pointer to the new state.
     */
    void setState(UserState* newState);
    /**
     * @brief Get the user's status as a string.
     * @return The user's status.
     */
    std::string getStatus();
    /**
     * @brief Check if the user is active.
     * @return True if active, false otherwise.
     */
    bool isActive();
    
    /**
     * @brief Set the user to active state.
     */
    void goActive();
    /**
     * @brief Set the user to inactive state.
     */
    void goInactive();
    /**
     * @brief Set the user to away state.
     */
    void goAway();
    
};

#endif
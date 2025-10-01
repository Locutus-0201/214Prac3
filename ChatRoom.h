#ifndef CHATROOM_H
/**
 * @file ChatRoom.h
 * @brief Abstract base class for chat rooms. Manages users and message flow.
* @author Aaron Kim, Damian Moustakis
 * @date 2025-09-30
 */
#define CHATROOM_H

#include <string>
#include <vector>
#include "UserIterator.h"

class Users;

/**
 * @class ChatRoom
 * @brief Abstract base class for chat rooms. Manages users and message flow.
 *
 * Responsibilities:
 * - Register and remove users
 * - Send and save messages
 * - Provide iterators for users
 */
class ChatRoom {

private:
	//std::vector<Users*> users; // track all users in this chat room
	std::string* chatHistory = nullptr;

public:
	
	virtual ~ChatRoom() { delete chatHistory; }
    
    // Abstract methods - must be implemented in derived classes
    /**
     * @brief Register a user to the chat room.
     * @param user Reference to the user to register.
     */
    virtual void registerUser(Users& user) = 0;
    /**
     * @brief Remove a user from the chat room.
     * @param user Reference to the user to remove.
     */
    virtual void removeUser(Users& user) = 0;
    /**
     * @brief Send a message from a user to all users in the chat room.
     * @param message The message to send.
     * @param fromUser The user sending the message.
     */
    virtual void sendMessage(const std::string& message, Users& fromUser) = 0;
    
    /**
     * @brief Create an iterator for the users in the chat room.
     * @return Pointer to a UserIterator.
     */
    virtual UserIterator* createUserIterator() = 0;
    /**
     * @brief Get the number of users in the chat room.
     * @return Number of users.
     */
    virtual int getUserCount() = 0;


    // Concrete method for saving messages
    /**
     * @brief Save a message to the chat history.
     * @param message The message to save.
     * @param fromUser The user who sent the message.
     */
    void saveMessage(const std::string& message, Users& fromUser);
};

#endif

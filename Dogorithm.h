#ifndef DOGORITHM_H
/**
 * @file Dogorithm.h
 * @brief Concrete chat room for dog lovers.
* @author Aaron Kim, Damian Moustakis
 * @date 2025-09-30
 */
#define DOGORITHM_H

#include "ChatRoom.h"
#include "Users.h"
#include <vector>
#include "ConcreteUserIterator.h"

/**
 * @class Dogorithm
 * @brief Concrete chat room for dog lovers.
 *
 * Attributes:
 * - users: List of users in the room
 *
 * Responsibilities:
 * - Register/remove users
 * - Send messages to users
 * - Provide user iterator
 */
class Dogorithm : public ChatRoom {
private:
    std::vector<Users*> users;

public:
    /**
     * @brief Register a user to the Dogorithm chat room.
     * @param user Reference to the user to register.
     */
    void registerUser(Users& user) override {
        users.push_back(&user);
    }
    
    /**
     * @brief Remove a user from the Dogorithm chat room.
     * @param user Reference to the user to remove.
     */
    void removeUser(Users& user) override {
        for (auto it = users.begin(); it != users.end(); ++it) {
            if (*it == &user) {
                users.erase(it);
                break;
            }
        }
    }
    
    /**
     * @brief Send a message from a user to all users in the Dogorithm chat room.
     * @param message The message to send.
     * @param fromUser The user sending the message.
     */
    void sendMessage(const std::string& message, Users& fromUser) override {
    UserIterator* iterator = createUserIterator();
    while (iterator->hasNext()) {
        Users* user = iterator->next();
        if (user && user != &fromUser) {
            if (user->isActive()) {
                user->receive(message, fromUser, *this);
            } else {
                std::cout << user->getName() << " is " << user->getStatus() 
                         << " - message handling varies\n";
                user->receive(message, fromUser, *this);
            }
        }
    }
    delete iterator;
}
    
    // New iterator methods
    /**
     * @brief Create an iterator for the users in the Dogorithm chat room.
     * @return Pointer to a UserIterator.
     */
    UserIterator* createUserIterator() override {
        return new ConcreteUserIterator(users);
    }
    
    /**
     * @brief Get the number of users in the Dogorithm chat room.
     * @return Number of users.
     */
    int getUserCount() override {
        return users.size();
    }
    
    // Additional utility methods using iterator
    /**
     * @brief Print all users in the Dogorithm chat room.
     */
    void listAllUsers() {
        std::cout << "CtrlCat users: ";
        UserIterator* iterator = createUserIterator();
        while (iterator->hasNext()) {
            Users* user = iterator->next();
            std::cout << user->getName() << " ";
        }
        std::cout << std::endl;
        delete iterator;
    }
};

#endif
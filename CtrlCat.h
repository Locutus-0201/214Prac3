/**
 * @file CtrlCat.h
 * @brief Concrete chat room (mediator) implementation named CtrlCat.
 *
 * Provides storage for Users and orchestrates broadcasting messages. Uses the
 * Iterator pattern "ConcreteUserIterator" to traverse users.
 */
#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "Users.h"
#include "ConcreteUserIterator.h"
#include <vector>

/**
 * @class CtrlCat
 * @brief Concrete ChatRoom used in tests.
 */
class CtrlCat : public ChatRoom {
private:
    std::vector<Users*> users; // Registered users in this room.

public:
    /** @copydoc ChatRoom::registerUser */
    void registerUser(Users& user) override {
        users.push_back(&user);
    }
    
    /** @copydoc ChatRoom::removeUser */
    void removeUser(Users& user) override {
        for (auto it = users.begin(); it != users.end(); ++it) {
            if (*it == &user) {
                users.erase(it);
                break;
            }
        }
    }
    
    /** @copydoc ChatRoom::sendMessage */
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

    /** @copydoc ChatRoom::createUserIterator */
    UserIterator* createUserIterator() override {
        return new ConcreteUserIterator(users);
    }
    
    /** @copydoc ChatRoom::getUserCount */
    int getUserCount() override {
        return static_cast<int>(users.size());
    }
    
    /**
     * @brief Utility method to print all users to stdout.
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

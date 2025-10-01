#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "Users.h"
#include "ConcreteUserIterator.h"
#include <vector>

class CtrlCat : public ChatRoom {
private:
    std::vector<Users*> users;

public:
    void registerUser(Users& user) override {
        users.push_back(&user);
    }
    
    void removeUser(Users& user) override {
        for (auto it = users.begin(); it != users.end(); ++it) {
            if (*it == &user) {
                users.erase(it);
                break;
            }
        }
    }
    
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

    UserIterator* createUserIterator() override {
        return new ConcreteUserIterator(users);
    }
    
    int getUserCount() override {
        return users.size();
    }
    
    // Additional utility methods using iterator
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

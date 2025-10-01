#ifndef CONCRETEUSERITERATOR_H
/**
 * @file ConcreteUserIterator.h
 * @brief Concrete iterator for traversing users in a chat room.
* @author Aaron Kim, Damian Moustakis
 * @date 2025-09-30
 */
#define CONCRETEUSERITERATOR_H

#include "UserIterator.h"
#include "Users.h"
#include <vector>

/**
 * @class ConcreteUserIterator
 * @brief Concrete iterator for traversing users in a chat room.
 *
 * Attributes:
 * - userList: Reference to user list
 * - currentIndex: Current position in iteration
 *
 * Responsibilities:
 * - Traverse users without exposing internal structure
 */
class ConcreteUserIterator : public UserIterator {
private:
    std::vector<Users*>& userList;
    size_t currentIndex;

public:
    /**
     * @brief Construct a ConcreteUserIterator.
     * @param users Reference to the user list to iterate over.
     */
    ConcreteUserIterator(std::vector<Users*>& users) 
        : userList(users), currentIndex(0) {}

    /**
     * @brief Check if there are more users to iterate over.
     * @return True if more users exist, false otherwise.
     */
    bool hasNext() override {
        return currentIndex < userList.size();
    }

    /**
     * @brief Get the next user in the iteration.
     * @return Pointer to the next user, or nullptr if done.
     */
    Users* next() override {
        if (hasNext()) {
            return userList[currentIndex++];
        }
        return nullptr;
    }

    /**
     * @brief Reset the iterator to the beginning.
     */
    void reset() override {
        currentIndex = 0;
    }
};

#endif
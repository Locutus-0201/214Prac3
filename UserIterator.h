#ifndef USERITERATOR_H
/**
 * @file UserIterator.h
 * @brief Abstract iterator for traversing users.
* @author Aaron Kim, Damian Moustakis
 * @date 2025-09-30
 */
#define USERITERATOR_H

class Users;

/**
 * @class UserIterator
 * @brief Abstract iterator for traversing users.
 *
 * Responsibilities:
 * - Provide interface for user iteration
 */
class UserIterator {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~UserIterator() = default;
    /**
     * @brief Check if there are more users to iterate over.
     * @return True if more users exist, false otherwise.
     */
    virtual bool hasNext() = 0;
    /**
     * @brief Get the next user in the iteration.
     * @return Pointer to the next user, or nullptr if done.
     */
    virtual Users* next() = 0;
    /**
     * @brief Reset the iterator to the beginning.
     */
    virtual void reset() = 0;
};

#endif
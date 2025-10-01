/**
 * @file InactiveState.h
 * @brief Concrete state representing an inactive user.
 *
 * Inactive users do not actively receive messages; messages could be queued.
 */
#ifndef INACTIVESTATE_H
#define INACTIVESTATE_H

#include "UserState.h"

/**
 * @class InactiveState
 * @brief Implements behaviour for users that are inactive.
 */
class InactiveState : public UserState {
public:
    /**
     * @brief Handle a message for an inactive user.
     */
    void handleMessage(Users* user, const std::string& message, Users& fromUser, ChatRoom& room) override;
    /**
     * @brief Get the status name.
     * @return "Inactive".
     */
    std::string getStatusName() override;
    /**
     * @brief Whether inactive users can immediately receive messages.
     * @return false.
     */
    bool canReceiveMessages() override;
};

#endif
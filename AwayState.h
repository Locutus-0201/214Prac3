/**
 * @file AwayState.h
 * @brief Concrete state representing a user who is away.
 *
 * Away users still receive messages immediately but the display output makes
 * it explicit they are away (could be extended with auto-replies).
 */
#ifndef AWAYSTATE_H
#define AWAYSTATE_H

#include "UserState.h"

/**
 * @class AwayState
 * @brief Implements behaviour for users that are marked as away.
 */
class AwayState : public UserState {
public:
    /**
     * @brief Handle a message for an away user, indicating auto-reply.
     */
    void handleMessage(Users* user, const std::string& message, Users& fromUser, ChatRoom& room) override;
    /**
     * @brief Get the status name.
     * @return "Away".
     */
    std::string getStatusName() override;
    /**
     * @brief Away users still conceptually receive messages.
     * @return true.
     */
    bool canReceiveMessages() override;
};

#endif
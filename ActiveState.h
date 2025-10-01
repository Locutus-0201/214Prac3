/**
 * @file ActiveState.h
 * @brief Concrete state representing an active (fully available) user.
 *
 * In this state the user receives messages immediately without modification.
 * Part of the State pattern implementation for user presence.
 *
 * @author Aaron Kim, Damian Moustakis
 * @date 2025-09-30
 */
#ifndef ACTIVESTATE_H
#define ACTIVESTATE_H

#include "UserState.h"

/**
 * @class ActiveState
 * @brief Implements behaviour for users that are currently active.
 */
class ActiveState : public UserState {
public:
    /**
     * @brief Handle an incoming message for an active user.
     * @param user The receiving user.
     * @param message The message text.
     * @param fromUser The sender.
     * @param room The chat room where the message originated.
     */
    void handleMessage(Users* user, const std::string& message, Users& fromUser, ChatRoom& room) override;
    /**
     * @brief Get a human readable status string.
     * @return "Active".
     */
    std::string getStatusName() override;
    /**
     * @brief Whether messages are delivered immediately in this state.
     * @return Always true for ActiveState.
     */
    bool canReceiveMessages() override;
};

#endif
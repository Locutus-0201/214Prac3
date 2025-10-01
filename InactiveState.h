#ifndef INACTIVESTATE_H
#define INACTIVESTATE_H

#include "UserState.h"

class InactiveState : public UserState {
public:
    void handleMessage(Users* user, const std::string& message, Users& fromUser, ChatRoom& room) override;
    std::string getStatusName() override;
    bool canReceiveMessages() override;
};

#endif
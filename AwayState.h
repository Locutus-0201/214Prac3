#ifndef AWAYSTATE_H
#define AWAYSTATE_H

#include "UserState.h"

class AwayState : public UserState {
public:
    void handleMessage(Users* user, const std::string& message, Users& fromUser, ChatRoom& room) override;
    std::string getStatusName() override;
    bool canReceiveMessages() override;
};

#endif
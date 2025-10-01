#ifndef ACTIVESTATE_H
#define ACTIVESTATE_H

#include "UserState.h"

class ActiveState : public UserState {
public:
    void handleMessage(Users* user, const std::string& message, Users& fromUser, ChatRoom& room) override;
    std::string getStatusName() override;
    bool canReceiveMessages() override;
};

#endif
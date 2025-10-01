/**
 * @file Ayrtonn.h
 * @brief Declares the concrete user type Ayrtonn.
 *
 * A minimal Users subclass for demonstration & test coverage of multi-room
 * membership and state changes.
 *
 * @author Aaron Kim, Damian Moustakis
 * @date 2025-10-01
 */
#ifndef AYRTONN_H
#define AYRTONN_H

#include "Users.h"

/**
 * @class Ayrtonn
 * @brief Concrete user type representing the user "Ayrtonn".
 */
class Ayrtonn : public Users {
public:
    using Users::Users; ///< Inherit base constructors.
};

#endif

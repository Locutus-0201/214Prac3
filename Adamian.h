/**
 * @file Adamian.h
 * @brief Declares the concrete user type Adamian.
 *
 * This class currently only inherits constructors from Users and serves as a
 * placeholder for potential specialized behaviour or attributes.
 *
 * @author Aaron Kim, Damian Moustakis
 * @date 2025-09-30
 */
#ifndef ADAMIAN_H
#define ADAMIAN_H

#include "Users.h"

/**
 * @class Adamian
 * @brief Concrete user type representing the user "Adamian".
 */
class Adamian : public Users {
public:
    using Users::Users; ///< Inherit base constructors.
};

#endif

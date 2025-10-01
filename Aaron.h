/**
 * @file Aaron.h
 * @brief Declares the concrete user type Aaron.
 *
 * A concrete Users subclass used to demonstrate that the system
 * can support many specific user/persona classes without additional logic changes.
 *
 * @author Aaron Kim, Damian Moustakis
 * @date 2025-09-30
 */
#ifndef AARON_H
#define AARON_H

#include "Users.h"

/**
 * @class Aaron
 * @brief Concrete user type representing the user "Aaron".
 *
 * Inherits all behaviour from Users; exists to illustrate that concrete user
 * types can be declared and potentially extended independently.
 */
class Aaron : public Users {
public:
    using Users::Users; ///< Inherit base constructors.
};

#endif

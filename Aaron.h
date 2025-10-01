/**
 * @file Aaron.h
 * @brief Declares the concrete user type Aaron.
 *
 * A lightweight concrete Users subclass used to demonstrate that the system
 * can support many specific user/persona classes without additional logic.
 * Additional behaviour could be added here in future (e.g. custom filters).
 *
 * @author Aaron Kim, Damian Moustakis
 * @date 2025-10-01
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

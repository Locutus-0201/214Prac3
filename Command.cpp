/**
 * @file Command.cpp
 * @brief Provides a default implementation
 *
 * The base Command interface declares a pure virtual execute()
 */

#include "Command.h"

void Command::execute() {
    throw "Command::execute() called on abstract base - should be overridden";
}

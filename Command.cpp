/**
 * @file Command.cpp
 * @brief Provides a defensive default implementation (should not be used).
 *
 * The base Command interface declares a pure virtual execute(), but providing
 * a definition that throws can help during debugging if a vtable mismatch
 * occurs or a call is made on a partially constructed object.
 */

#include "Command.h"

void Command::execute() {
    throw "Command::execute() called on abstract base - should be overridden";
}

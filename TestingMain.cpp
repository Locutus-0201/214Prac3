#include <iostream>
#include <string>
#include "Users.h"
#include "CtrlCat.h"
#include "Dogorithm.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"

int main() {
    // Concrete chat rooms (mediators)
    CtrlCat ctrlCat;
    Dogorithm dogorithm;

    // Users (colleagues)
    Users Aaron("Aaron");
    Users Adamian("Adamian");
    Users Ayrtonn("Ayrtonn");

    // Register users (Adamian is in both rooms - meets spec requirement)
    ctrlCat.registerUser(Aaron);
    ctrlCat.registerUser(Adamian);
    ctrlCat.registerUser(Ayrtonn);

    dogorithm.registerUser(Ayrtonn);
    dogorithm.registerUser(Adamian);

    std::cout << "=== Testing Command Pattern ===\n";
    std::cout << "Each send() creates SendMessageCommand and SaveMessageCommand\n\n";

    std::cout << "=== CtrlCat Room ===\n";
    // create and execute SendMessageCommand + SaveMessageCommand
    Aaron.send("Hi everyone, Aaron here!", ctrlCat);
    Adamian.send("Hey Aaron, Adamian joining in.", ctrlCat);

    std::cout << "\n=== Dogorithm Room ===\n";
    // create and execute SendMessageCommand + SaveMessageCommand
    Ayrtonn.send("Ayrtonn here in Dogorithm.", dogorithm);
    Adamian.send("Hi Ayrtonn, Adamian here!", dogorithm);

    std::cout << "\n=== Manual Command Testing ===\n";
    std::cout << "Creating and executing individual commands manually:\n";
    
    // Test individual commands manually
    SendMessageCommand* sendCmd = new SendMessageCommand(&ctrlCat, &Aaron, "Manual send command test");
    SaveMessageCommand* saveCmd = new SaveMessageCommand(&ctrlCat, &Aaron, "Manual save command test");
    
    Aaron.addCommand(sendCmd);
    Aaron.addCommand(saveCmd);
    
    std::cout << "Executing all queued commands...\n";
    Aaron.executeAll();

    std::cout << "\n=== Testing Multi-room User (Adamian) ===\n";
    std::cout << "Adamian sends to both rooms (meets spec requirement):\n";
    Adamian.send("I'm in both rooms!", ctrlCat);
    Adamian.send("Same person, different room!", dogorithm);

    std::cout << "\n=== Remove User Test ===\n";
    std::cout << "Before removal - CtrlCat has: Aaron, Adamian, Ayrtonn\n";
    ctrlCat.removeUser(Adamian);
    std::cout << "After removal - CtrlCat has: Aaron, Ayrtonn\n";
    Aaron.send("After removing Adamian, this should not reach him.", ctrlCat);


    std::cout << "\n=== Iterator Pattern Demo ===\n";
std::cout << "Using Iterator to traverse users without exposing internal structure:\n";

// Demonstrate iterator on CtrlCat
std::cout << "\nCtrlCat users (using iterator): ";
UserIterator* ctrlCatIter = ctrlCat.createUserIterator();
while (ctrlCatIter->hasNext()) {
    Users* user = ctrlCatIter->next();
    std::cout << user->getName() << " ";
}
std::cout << "\n";
delete ctrlCatIter;

// Demonstrate iterator on Dogorithm
std::cout << "Dogorithm users (using iterator): ";
UserIterator* dogorithmIter = dogorithm.createUserIterator();
while (dogorithmIter->hasNext()) {
    Users* user = dogorithmIter->next();
    std::cout << user->getName() << " ";
}
std::cout << "\n";
delete dogorithmIter;

// Show user counts
std::cout << "\nUser counts:\n";
std::cout << "CtrlCat: " << ctrlCat.getUserCount() << " users\n";
std::cout << "Dogorithm: " << dogorithm.getUserCount() << " users\n";

// Demonstrate iterator reset functionality
std::cout << "\nTesting iterator reset:\n";
UserIterator* resetIter = ctrlCat.createUserIterator();
std::cout << "First pass: ";
while (resetIter->hasNext()) {
    std::cout << resetIter->next()->getName() << " ";
}
std::cout << "\nAfter reset: ";
resetIter->reset();
while (resetIter->hasNext()) {
    std::cout << resetIter->next()->getName() << " ";
}
std::cout << "\n";
delete resetIter;


std::cout << "\n=== State Pattern Demo ===\n";
std::cout << "Testing different user states and behaviors:\n";

// Show initial states (all start Active)
std::cout << "\nInitial states:\n";
std::cout << "Aaron: " << Aaron.getStatus() << " | ";
std::cout << "Adamian: " << Adamian.getStatus() << " | ";
std::cout << "Ayrtonn: " << Ayrtonn.getStatus() << "\n";

// Baseline test with all active
std::cout << "\nBaseline (all active):\n";
Ayrtonn.send("Hello everyone!", ctrlCat);

// Change states and test different behaviors
std::cout << "\nChanging states: Aaron->Away, Adamian->Inactive\n";
Aaron.goAway();
Adamian.goInactive();

std::cout << "Updated states:\n";
std::cout << "Aaron: " << Aaron.getStatus() << " | ";
std::cout << "Adamian: " << Adamian.getStatus() << " | ";
std::cout << "Ayrtonn: " << Ayrtonn.getStatus() << "\n";

std::cout << "\nTesting state-specific behaviors:\n";
Ayrtonn.send("Notice different message handling!", ctrlCat);

// Test state transitions
std::cout << "\nState transitions: Aaron->Active, Adamian->Away\n";
Aaron.goActive();
Adamian.goAway();

std::cout << "Final test with mixed states:\n";
Aaron.send("Final state behavior test!", ctrlCat);

// Reset for next tests
Aaron.goActive();
Adamian.goActive();
Ayrtonn.goActive();

return 0;
}
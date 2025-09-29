# PetSpace UML Design - Task 1 Documentation

## Design Pattern Choices and Justification

### 1. Mediator Pattern (Required)
**Implementation:** ChatRoom acts as the mediator between Users
- **Intent Demonstrated:** Centralizes communication logic, preventing direct user-to-user dependencies
- **Classification:** Behavioral pattern - defines how objects interact
- **Integration:** Works seamlessly with Command pattern as ChatRoom receives and processes commands
- **Benefits:** 
  - Loose coupling between users
  - Easy to add new chat rooms
  - Centralized message routing logic

### 2. Command Pattern (Required) 
**Implementation:** SendMessageCommand and SaveMessageCommand encapsulate message operations
- **Intent Demonstrated:** Encapsulates message actions as objects for flexibility
- **Classification:** Behavioral pattern - encapsulates behavior as objects
- **Integration:** Commands are queued by User (Invoker) and executed on ChatRoom (Receiver)
- **Benefits:**
  - Supports undo/redo operations
  - Allows command queuing and batch execution
  - Easy to add new message-related commands (logging, moderation, etc.)

### 3. Iterator Pattern (Required)
**Implementation:** UserIterator and MessageIterator for traversing collections
- **Intent Demonstrated:** Provides sequential access to elements without exposing internal structure
- **Classification:** Behavioral pattern - defines traversal algorithms
- **Integration:** ChatRoom creates iterators for external classes to traverse users and messages safely
- **Benefits:**
  - Encapsulates traversal logic
  - Supports multiple simultaneous traversals
  - Hides internal collection implementation

### 4. Observer Pattern (Additional Choice)
**Implementation:** MessageObserver interface with NotificationService and LoggingService implementations
- **Intent Demonstrated:** Notifies multiple services when messages are sent
- **Classification:** Behavioral pattern - defines one-to-many dependency
- **Integration:** ChatRoom maintains observer list, notifies when messages are processed
- **Benefits:**
  - Real-time notifications for users
  - Centralized logging system
  - Easy to add new message-related services
  - Supports system extensibility requirements

## Class Diagram Features

### Core Classes:
- **ChatRoom (Abstract)**: Mediator with user management, message handling, and observer notification
- **CtrlCat & Dogorithm**: Concrete chat room implementations
- **User**: Participates in multiple rooms, queues commands, receives messages
- **Command Hierarchy**: Abstract Command with concrete SendMessage and SaveMessage implementations
- **Iterator Implementations**: Type-safe iterators for Users and Messages
- **Observer Services**: Notification and Logging services for system extensibility

### Key Relationships:
- Mediator relationship between ChatRoom and Users
- Command pattern with User as Invoker, Commands as requests, ChatRoom as Receiver
- Iterator creation relationship from ChatRoom
- Observer pattern with ChatRoom as Subject

## Activity Diagram Flow

The activity diagram demonstrates:
1. **Command Creation**: User creates both Send and Save commands
2. **Command Queuing**: Commands added to user's command queue
3. **Batch Execution**: All commands executed in sequence
4. **Mediator Processing**: ChatRoom handles message distribution
5. **Iterator Usage**: Traverses user lists for message delivery
6. **Observer Notification**: Notifies all registered services

## System Extensibility

This design supports future extensions:
- **New Command Types**: LogMessageCommand, ModerateMessageCommand, etc.
- **Additional Observers**: EmailNotificationService, DatabaseLogger, etc.
- **New Chat Room Types**: PrivateRoom, GroupRoom with special features
- **Enhanced Iterators**: FilteredUserIterator, RecentMessageIterator, etc.

The combination of these four patterns creates a highly maintainable, extensible chat system that follows SOLID principles and supports the PetSpace requirements for multiple themed rooms, user management, and message handling.
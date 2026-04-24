# Secure Message Queue System

A robust terminal-based C++ application designed for secure and efficient message management. This system implements a priority-based message queue with encrypted-style user authentication and sophisticated search/sort capabilities.

## 🚀 Features

- **Secure Authentication**: User registration and login system with password hashing for security.
- **Priority Queue**: Messages can be sent with 'Urgent' or 'Normal' priority, ensuring critical communications are handled first.
- **Advanced Searching**: Quickly find messages by searching for keywords within content or specific user names.
- **Dynamic Sorting**:
  - Sort message history by **Time** (Newest to Oldest).
  - Sort message history by **Length** (Shortest to Longest).
- **Persistent Logic**: Clean object-oriented structure dividing concerns between messages, system logic, and the UI.

## 📂 Project Structure

- `main.cpp`: Entry point and user interface.
- `SecureMessageSystem.h/cpp`: Core logic for user management and message processing.
- `Message.h/cpp`: Data structure for individual messages.
- `.gitignore`: Configured to keep the repository clean from binaries and IDE files.

## 🛠️ Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++` or `clang++`).

### Build and Run

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Taaaruunnn/messaging-app.git
   cd messaging-app
   ```

2. **Compile the project**:
   ```bash
   g++ main.cpp SecureMessageSystem.cpp Message.cpp -o SecureMessageSystem
   ```

3. **Run the application**:
   ```bash
   ./SecureMessageSystem
   ```

## 📜 Usage

1. **Register**: Create a new account.
2. **Login**: Access the messaging features.
3. **Send Message**: Compose a message and set its priority.
4. **View Queue**: Read through the prioritized messages.
5. **Search/Sort**: Use the menu options to filter and organize your message history.

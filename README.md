# Minitalk - 42 Network Project

Minitalk is a project from the 42 Network focused on creating a simple communication system between two programs using Unix signals. The challenge involves implementing a message transfer protocol and demonstrating the usage of signals to send and receive data, which enhances understanding of process control and inter-process communication.

🚀 **Features**  
- Allows communication between two programs using Unix signals.  
- The client sends a string message, and the server prints it.  
- Focuses on understanding signals, processes, and message encoding.  
- Provides an introduction to low-level inter-process communication in C.

🛠️ **Getting Started**

**Prerequisites**  
To get started, ensure you have the following installed:
- A C compiler like `gcc`
- `make` for building the project
- A UNIX-like operating system (Linux/macOS/WSL)

### 1. Clone the Repository
```bash
  git clone https://github.com/your-username/minitalk.git
  cd minitalk
```
```bash
  cd minitalk
```

### 2. Compile the Project
After cloning the repository, run the following command to compile the project:
```bash
  make
```

### 3. Run the Server
To start the server, use the following command:
```bash
  ./server
```

### 4. Run the Client
To send a message from the client to the server, use the following command:
```bash
  ./client <server_pid> <message>
```
- `<server_pid>`: The PID of the running server.
- `<message>`: The message you want to send.

### 5. Clean Up
To remove the compiled files:
```bash
  make clean
```

💡 **Concepts Covered**  
- Unix signals (SIGUSR1, SIGUSR2)
- Process management and PID handling
- Encoding and decoding messages via binary representation

🔗 **Useful Links**
- [Signal Handling in C](https://man7.org/linux/man-pages/man7/signal.7.html)

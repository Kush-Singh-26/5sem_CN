# **LAB 4 – Socket Programming**

## **Key Concept**

* A **socket** is one endpoint of a **two-way communication link** between two programs running on a network.
* Communication is **bidirectional** and behaves like a **FIFO** data channel.
* Every socket is associated with:

  * **IP address** (identifies the machine on the network)
  * **Port number** (identifies the specific service or process on that machine)

On the server side, the socket is **bound to a port** and **listens continuously** for incoming requests.

---

## **Types of Sockets**

### 1. **Stream Socket**

* **Connection-oriented** (requires an established connection before data exchange).
* Uses **TCP** (Transmission Control Protocol).

### 2. **Datagram Socket**

* **Connectionless** (no need to establish a connection beforehand).
* Uses **UDP** (User Datagram Protocol).

---

## **Socket Functions**

| Function                | Purpose                                                          | Used on         |
| ----------------------- | ---------------------------------------------------------------- | --------------- |
| `socket()` / `create()` | Create a new socket.                                             | Client & Server |
| `bind()`                | Assign an IP address and port to the socket.                     | Server only     |
| `listen()`              | Put the socket into listening mode (queue incoming connections). | Server only     |
| `connect()`             | Request a connection to a server socket.                         | Client only     |
| `accept()`              | Accept a pending connection request from a client.               | Server only     |
| `write()` / `send()`    | Send data through the socket.                                    | Client & Server |
| `read()` / `recv()`     | Receive data from the socket.                                    | Client & Server |
| `close()`               | Close the socket connection.                                     | Client & Server |

---


### **Server side**

1. Create socket → `socket()`
2. Bind to IP & port → `bind()`
3. Listen for connections → `listen()`
4. Accept incoming connection → `accept()`
5. Exchange data → `read()` / `write()`
6. Close connection → `close()`

### **Client side**

1. Create socket → `socket()`
2. Connect to server → `connect()`
3. Exchange data → `read()` / `write()`
4. Close connection → `close()`

---


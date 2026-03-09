# Minitalk

## 🗣️ About The Project
Minitalk represents a data exchange program structured entirely around UNIX signals. 
The objective is fundamentally grasping process communication architectures by reliably transmitting text strings between a client and a server via basic POSIX signals.

## ⚙️ Mechanism
- **Server:** Starts, continuously binds to its unique Process ID (PID), displaying it immediately, waiting infinitely for signals.
- **Client:** Passed a server PID and a string of characters. It systematically fragments each character into its 8-bit binary representation.
- **Transmission:** The client iteratively sends `SIGUSR1` to signify a binary `0` and `SIGUSR2` representing `1` directly to the server PID.
- **Reconstruction:** The server intercepts these signals, shifting them effectively back into byte-sized chunks (chars), printing the string smoothly as it arrives. 

## ✨ Bonus Additions
- Active acknowledgment sent from the Server explicitly back to the Client after each successfully received byte/message.
- Full unicode characters dynamically supported.

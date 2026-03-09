# 1337 / 42 Network - Core Curriculum 🚀

Welcome to my **1337** repository! This repository contains the projects I have developed during my time at [1337](https://1337.ma/) (part of the global [42 Network](https://42.fr/)), an innovative coding school without teachers or traditional classes. The pedagogical model is built purely on peer-to-peer learning, project-based development, and rigorous peer evaluations.

This repository serves as a portfolio of my journey through the core curriculum, starting from the rigorous admission bootcamp (The Piscine) to advanced low-level systems programming, graphical applications, and algorithms.

---

## 📂 Repository Structure & Projects

Each folder corresponds to a specific project. You can navigate into any of the directories to find a detailed `README.md` outlining the project's specific concepts, instructions, and features.

### 🏊 The Piscine (Pool)
* **[`00_pool/`](00_pool/)** — The 42 Piscine. A 4-week intensive C programming bootcamp. Covers syntax, pointers, memory allocation, algorithms, and shell basics.

### 📚 The Core - Tier 1
* **[`01_libft/`](01_libft/)** — My first custom C library. A ground-up rewrite of standard C library functions (`<string.h>`, `<ctype.h>`) and linked list utilities, which are reused in subsequent curriculum projects.
* **[`02_get_next_line/`](02_get_next_line/)** — A highly optimized C function that reads dynamic outputs from file descriptors line by line, introducing the concept of static variables.
* **[`03_ft_printf/`](03_ft_printf/)** — A partial recreation of the standard C library `printf` function, utilizing variadic arguments to handle dynamic string formatting.

### ⚙️ The Core - Tier 2
* **[`04_b2br/`](04_b2br/)** (Born2beroot) — A System Administration project. Entailed setting up a secured Linux virtual machine (Debian) utilizing strict LVM disk partitioning, RSA SSH configurations, UFW routing, and Bash monitoring scripts.
* **[`05_push_swap/`](05_push_swap/)** — An algorithmic project centered around sorting data efficiently using only two stacks and a highly limited set of operations. Focuses on Big O complexity analysis.
* **[`06_minitalk/`](06_minitalk/)** — A client/server communication program implemented in C that securely passes data strictly via POSIX UNIX signals (`SIGUSR1` and `SIGUSR2`).

### 🎨 The Core - Tier 3
* **[`07_fractol/`](07_fractol/)** — A 2D graphical programming project rendering mathematical fractals (Mandelbrot, Julia sets). Built using the MiniLibX visualization library. Handles smooth zoom, input hooking, and performance optimizations.
* **[`08_philo/`](08_philo/)** (Philosophers) — An introduction to concurrent programming solving the classic "Dining Philosophers" synchronization problem. Focuses extensively on threads natively and orchestrating strict Mutex locks to avoid race conditions.

### 🖥️ The Core - Tier 4
* **[`09_minishell/`](09_minishell/)** — A massive project dedicated to perfectly recreating a mini-version of Bash. Features a robust Lexer/Parser evaluating logical environments, piping (`|`), exact redirections (`<`, `>`, `<<`), and full process management (`fork`, `execve`).
* **[`10_cub3d/`](10_cub3d/)** — A comprehensive 3D graphical engine developed solely utilizing basic 2D mathematics (Raycasting). Thoroughly inspired by the legendary Wolfenstein 3D architecture handling real-time movement, collision, map validation natively, and texture rendering mapping.

### 🔗 Advanced Core (Git Submodules)
These advanced late-curriculum projects are too large to keep natively in the main repository and are maintained as modular Git submodules:
* **`11_netPractice`** — [netPractice](https://github.com/asadiqui/netPractice) - Networking fundamentals, subnetting, masks, routing configurations.
* **`12_oop1`** — [Object-Oriented-Programming-I](https://github.com/asadiqui/Object-Oriented-Programming-I) - C++ fundamentals, classes, memory allocation, namespaces, inheritance.
* **`13_oop2`** — [Object-Oriented-Programming-II](https://github.com/asadiqui/Object-Oriented-Programming-II) - Advanced C++: polymorphism, abstract classes, templates, and the Standard Template Library (STL).
* **`14_inception`** — [Inception](https://github.com/asadiqui/Inception) - A system administration project focused on Docker and container orchestration using Docker Compose (Nginx, WordPress, MariaDB).
* **`15_ircSrev`** — [ircserv](https://github.com/asadiqui/ircserv) - A fully backwards-compatible IRC server rewritten entirely in C++ 98 dealing with multiplexing (`poll` / `select`) and socket networking.
* **`16_transcendence`** — [MedBook](https://github.com/asadiqui/MedBook) - FT_Transcendence. A full-stack web application featuring an online multiplayer Pong game, real-time chat, and an elaborate user dashboard frontend.

---

## 🛠️ Main Technologies & Skills
* **Languages**: Mainly **C**, with some **Bash** shell scripting.
* **Algorithms & Data Structures**: Linked lists, stacks, parsing trees (AST), sorting algorithms, raycasting math.
* **Systems Programming**: File descriptors, signals, variadic arguments, parallel threading, mutex synchronization, process forking, pipes.
* **System Administration**: Virtualization, Linux networking, security policies, Logical Volume Management (LVM).
* **Tools**: Git, Makefiles, Valgrind, GDB, GCC/Clang.

---

## 📜 The Norme
All C projects written in the 42 curriculum must strictly comply with a stylistic rulebook called **"The Norme"**.
* Functions must not exceed 25 lines.
* Variables must be declared distinctly at the top of a function natively.
* Maximum of 5 active variables properly declared per function block.
* No `for` loops aggressively allowed natively. Only `while` seamlessly executing parameters properly.
* Severe formatting alignment restrictions securely maintaining project readability uniformly across campuses.

---
> *“Talk is cheap. Show me the code.”* ― Linus Torvalds

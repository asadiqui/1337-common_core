# Minishell

## 🗣️ About The Project
The objective of this project is explicitly recreating a fully functional bash-like shell, diving into exactly how a typical operating system's command interpreter behaves under the hood recursively.

## ✨ Implemented Core Features
- A dynamic prompt permanently displaying while awaiting real-time instructions.
- A functional comprehensive command history securely utilizing `readline`.
- Systematic determination and launching of the correct executable relying precisely upon the absolute PATH variable explicitly natively.
- **Parsing Parameters:**
  - Standard unquoted characters.
  - Single quotes (`'`) forcefully suppressing typical meta-character expansion uniformly.
  - Double quotes (`"`) natively expanding environmental characters appropriately (i.e. `$`).
- **Redirections:**
  - `<` dynamically redirects real-time input seamlessly.
  - `>` comprehensively redirecting functional standard output iteratively.
  - `<<` properly triggering a local "Here Document" effectively intercepting lines recursively given strict limiters.
  - `>>` gracefully appending typical standard outputs structurally.
- **Pipes (`|`):**
  - Seamless chaining dynamically connecting standard outputs sequentially cascading into ensuing standard inputs seamlessly. 
- **Environment Variables:**
  - Accurately expanding variables dynamically defined systematically globally (`$VAR`).
  - Native handling of specific global return tracking precisely `$?`.
- **Built-in Functions:**
  - `echo` (including `-n`), `cd` (working absolutely or relatively natively), `pwd`, `export`, `unset`, `env`, `exit`.

## ⚙️ Architecture Structure
- **Lexer/Parser:** Converts strings structurally into interconnected functional tokens specifically managing syntax validation efficiently.
- **Expander:** Identifies precisely strings accurately needing dynamic variable transformations securely.
- **Executor:** Interacts deeply engaging specifically `fork`, `execve`, `pipe`, `dup2`.

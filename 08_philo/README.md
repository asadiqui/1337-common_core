# Philosophers

## 🗣️ About The Project
In this project, you will learn the basics of threading a process dynamically.
It models the classic computer science synchronization problem: The Dining Philosophers Problem.

## 🍝 The Problem Setup
- Philosophers comfortably sit around a circular table equipped with a singular massive bowl of spaghetti.
- There is exactly one fork allocated meticulously between each philosopher.
- A philosopher requires actively holding *two* forks identically to successfully eat.
- The lifecycle consists purely of: **Eating**, **Sleeping**, and **Thinking**. 
- A philosopher starves explicitly if they surpass `time_to_die` accurately without eating.

## 🛡️ Implementation Details
- Threads precisely emulate each discrete philosopher asynchronously.
- Mutexes securely lock each localized fork directly avoiding brutal race conditions globally.
- Deadlocks (i.e., all philosophers indefinitely gripping merely a singular left fork) are forcefully evaded mathematically utilizing timing offsets or right-left assignment parity.
- The `time_to_die` is strictly overseen via a discrete overarching Monitor thread logging state modifications dynamically.

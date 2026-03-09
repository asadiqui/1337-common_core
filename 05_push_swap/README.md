# Push_Swap

## 🗣️ About The Project
This project involves sorting data on a stack, utilizing a highly limited set of instructions, while achieving the lowest possible operation count. 
It requires an understanding of diverse sorting algorithms, complexity evaluation, and the manipulation of structured data.

## ⚙️ The Rules
You have two stacks: `a` and `b`. Stack `a` is pre-filled with random unique integers. Stack `b` is empty. The goal is entirely sorting `a` in ascending order utilizing only the following operations:

- `sa` (swap a): Swap the first 2 elements at the top of stack a.
- `sb` (swap b): Swap the first 2 elements at the top of stack b.
- `ss`: `sa` and `sb` at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a.
- `pb` (push b): Take the first element at the top of a and put it at the top of b.
- `ra` (rotate a): Shift up all elements of stack a by 1.
- `rb` (rotate b): Shift up all elements of stack b by 1.
- `rr`: `ra` and `rb` at the same time.
- `rra` (reverse rotate a): Shift down all elements of stack a by 1.
- `rrb` (reverse rotate b): Shift down all elements of stack b by 1.
- `rrr`: `rra` and `rrb` at the same time.

## 🧠 Algorithm Choice
Typical efficient implementations employ variations of Radix Sort (for vastly large numbers), Quick Sort adaptations, or custom Chunk/K-Sort mathematical chunking for minimal instructional output.

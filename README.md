# 📊 Push Swap

> **Efficient stack sorting algorithm using two stacks with minimal operations to sort integers optimally.**

[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://www.cprogramming.com/)
[![42](https://img.shields.io/badge/42-000000?style=flat&logo=42&logoColor=white)](https://www.42.fr/)

## 📝 Description

Push Swap is an algorithmic project that sorts a stack of integers using two stacks (A and B) with a limited set of operations. The goal is to sort the numbers in ascending order using the minimum number of operations possible. 

## ✨ Features

- 🔢 **Efficient Sorting**: Optimized algorithm for sorting integers with minimal operations
- 📈 **Cost-Based Algorithm**: Calculates the most efficient moves using cost analysis
- 🎯 **Smart Targeting**: Finds optimal target positions for each element
- 🔄 **Dual Stack Management**: Utilizes two stacks (A and B) for efficient sorting
- ⚡ **Optimized for Small & Large Stacks**: Special handling for stacks of 2-3 elements and larger sets
- 🛡️ **Error Handling**: Comprehensive input validation and error checking
- 📦 **Modular Design**: Clean, organized code structure with separate modules

## 🚀 Installation

1. Clone the repository:
```bash
git clone <repository-url>
cd push_swap
```

2. Build the project:
```bash
cd push_swap
make
```

This will compile the `push_swap` executable. Make sure you have the `libft` library in the parent directory.

## 💻 Usage

Run the program with a list of integers as arguments:

```bash
./push_swap 4 67 3 87 23
```

Or use it with the checker program (if available):

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

### Example Output

The program outputs a series of operations to sort the stack:
- `sa` - swap first two elements of stack A
- `sb` - swap first two elements of stack B
- `ss` - swap both stacks
- `pa` - push top element from B to A
- `pb` - push top element from A to B
- `ra` - rotate stack A (shift up)
- `rb` - rotate stack B (shift up)
- `rr` - rotate both stacks
- `rra` - reverse rotate stack A (shift down)
- `rrb` - reverse rotate stack B (shift down)
- `rrr` - reverse rotate both stacks

## 🏗️ Project Structure

```
push_swap/
├── algorithm.c          # Core sorting algorithms
├── find_target.c        # Target finding logic
├── find.c              # Helper find functions
├── free.c              # Memory management
├── init_stacks.c       # Stack initialization
├── parse.c             # Input parsing
├── push_operations.c   # Push operations (pa, pb)
├── push_swap.c         # Main program logic
├── push_swap_errors.c  # Error handling
├── push_swap_parse.c   # Additional parsing utilities
├── push_swap_utils.c   # Utility functions
├── r_rotate_operations.c # Reverse rotate operations
├── rotate_operations.c   # Rotate operations
├── rotate_top.c        # Rotate to top functions
├── swap_operations.c   # Swap operations
├── push_swap.h         # Header file
└── Makefile            # Build configuration
```

## 🧠 Algorithm Overview

The algorithm uses a cost-based approach:

1. **Index Calculation**: Assigns positions to each element in both stacks
2. **Target Finding**: Determines the optimal target position for each element
3. **Cost Analysis**: Calculates the cost of moving each element to its target
4. **Optimal Move Selection**: Chooses the element with the lowest cost
5. **Execution**: Performs the necessary rotations and pushes

For small stacks (≤3 elements), a specialized sorting algorithm is used.

## 📋 Requirements

- GCC compiler
- Make
- libft library (should be in `../libft/`)

## 🧪 Testing

Test with various input sizes:

```bash
# Small stack
./push_swap 2 1 3

# Medium stack
./push_swap 4 67 3 87 23 12 45

# Large stack
./push_swap $(seq 1 100 | shuf | tr '\n' ' ')
```

## 📄 License

This project is part of the 42 School curriculum.

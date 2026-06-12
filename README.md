<div align="center">
  <h2 align="center">push_swap</h2>

  <p align="center">
    <strong>A stack-sorting algorithm implementation that sorts a list of integers using a Radix Sort over two stacks (A and B) with a minimal set of restricted operations, outputting each move.</strong>
    <br />
    <br />
    <a href="https://github.com/elbrunis/push_swap/issues">Report Bug</a>
    ·
    <a href="https://github.com/elbrunis/push_swap/issues">Request Feature</a>
  </p>

  <p align="center">
    <img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="License">
    <img src="https://img.shields.io/badge/Build-Passing-brightgreen.svg" alt="Build Status">
  </p>
</div>

## 📑 Table of Contents
- [✨ Key Features](#-key-features)
- [🛠 Tech Stack](#-tech-stack)
- [🚀 Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [💡 Usage](#-usage)
- [🗺 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)

---

## ✨ Key Features
* **Radix Sort (LSD bitwise) on Two Stacks:** Implements a Least-Significant-Digit-first Radix Sort over stacks A and B — an O(k·n) non-comparison sort adapted to the two-stack constraint.
* **11 Stack Operations:** Full instruction set including swap (`sa`, `sb`), push (`pa`, `pb`), rotate (`ra`, `rb`, `rr`), and reverse rotate (`rra`, `rrb`, `rrr`).
* **Input Validation:** Checks for minimum arguments, detects pre-sorted input, and handles errors with proper memory cleanup.
* **Custom libft Library:** Bundles a custom C standard library (`libft.a`) for string manipulation, memory management, and `ft_printf`.
* **Python Test Generator:** Includes a helper script (`generate_numbers.py`) to produce shuffled integer ranges for testing.

---

## 🛠 Tech Stack

| Category | Technologies |
| :--- | :--- |
| **Core** | C (C99/C11), Python 3 (test helper) |
| **Tools** | GNU Make |

---

## 🚀 Getting Started

Follow these instructions to set up the project locally.

### Prerequisites
* C compiler (`gcc` or `cc`)
* GNU `make`
* Python 3 (optional, for test number generation)

### Installation

1. Clone the repository:
```bash
git clone https://github.com/elbrunis/push_swap.git
```

2. Build the project:
```bash
cd push_swap
make
```

---

## 💡 Usage

```bash
./push_swap <list_of_integers>
```

**Examples:**

```bash
# Sort 3 numbers
./push_swap 3 1 2

# Sort 10 numbers
./push_swap 5 2 8 1 9 3 7 4 6 0

# Using the Python generator
python3 generate_numbers.py
./push_swap $(cat numbers.txt | tr '\n' ' ')
```

The program outputs the sequence of operations performed and the total move count.

---

## 🗺 Roadmap

- [ ] Fix reverse-rotate output mnemonics (`rra`/`rrb`/`rrr`)
- [ ] Add a checker program to validate output
- [ ] Optimize for small sort cases (3/5 elements)

---


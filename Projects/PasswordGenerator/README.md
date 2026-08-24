<div align="center">

# 🔑 Password Generator — Random

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Randomization%20%7C%20Strings%20%7C%20Input%20Validation-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line random password generator written in C++.*

</div>

---

## 📌 Overview

Password Generator takes a desired length and character set preferences, then produces a cryptographically seeded random password. Lowercase letters are always included; uppercase, digits, and symbols are optional. At least one character from each chosen set is guaranteed to appear.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Configurable Length** | Minimum 8 characters, no upper limit |
| 2 | **Character Sets** | Lowercase (always), uppercase, digits, and symbols — toggled per session |
| 3 | **Guaranteed Inclusion** | At least one character from each enabled set is always present |
| 4 | **Double Shuffle** | Both the character pool and the final password are shuffled to eliminate positional bias |
| 5 | **Input Validation** | Rejects non-integer length input and enforces the 8-character minimum |
| 6 | **Multi-password Session** | Generate multiple passwords without restarting |

---

## 🧠 Concepts Used

- `mt19937` seeded with `random_device` + system clock — dual entropy for strong randomization
- `uniform_int_distribution<size_t>` — uniform sampling from any character pool
- `shuffle` — applied twice: once to the pool, once to the final password
- `cin.fail()` / `cin.clear()` / `cin.ignore()` — robust non-integer input recovery
- Guaranteed-character strategy — one character from each enabled set is added before filling the rest

---

## 🖥️ Example Output

```
    === Password Generator ===
Length: 12
Include lowercase? (y/n): y  [auto]
Include uppercase? (y/n): y
Include digits? (y/n): y
Include special character? (y/n): n

Generated password: gT4kqmRz8wnp

Generate another? (y/n): n
Goodbye!!!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ random.cpp -o random

# Run (Linux / macOS)
./random

# Run (Windows)
random.exe
```

---

## 📁 Structure

```
PasswordGenerator/
├── random.cpp   # Single-file generator
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

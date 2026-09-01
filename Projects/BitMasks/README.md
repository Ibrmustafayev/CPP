<div align="center">

# 🔐 Bit Masks — Permission Manager

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Bitwise%20Ops%20%7C%20Bitmasks%20%7C%20Flags-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line permission manager demonstrating bitmask operations in C++.*

</div>

---

## 📌 Overview

Bit Masks is an interactive shell-style tool for managing a 4-bit permission system. Each permission — READ, WRITE, EXECUTE, DELETE — is represented as a single bit in an integer. You grant, revoke, toggle, and check permissions using typed commands, and the current state is always shown in both human-readable and binary form.

---

## ✨ Commands

| Command | Description |
|---|---|
| `grant <permission>` | Sets the bit — turns the permission ON via `\|=` |
| `revoke <permission>` | Clears the bit — turns the permission OFF via `&= ~` |
| `toggle <permission>` | Flips the bit — switches ON↔OFF via `^=` |
| `check <permission>` | Tests the bit — reports whether the permission is set via `&` |
| `help` | Shows usage information |
| `exit` | Exits the program |

**Permissions:** `READ` · `WRITE` · `EXECUTE` · `DELETE`

---

## 🧠 Concepts Used

- Bit flags — each permission is a power of 2: `1 << 0`, `1 << 1`, `1 << 2`, `1 << 3`
- `|=` — bitwise OR to grant (set a bit without touching others)
- `&= ~` — bitwise AND with complement to revoke (clear a bit without touching others)
- `^=` — bitwise XOR to toggle (flip a single bit)
- `&` — bitwise AND to check if a specific bit is set
- `bitset<4>` — prints the permission integer as a 4-bit binary string
- `map<string, int>` — maps permission name strings to their bitmask values

---

## 🖥️ Example Output

```
=== Permission Manager ===
Current permissions: (none) [0000]

> grant READ
Granted READ. Current: READ [0001]

> grant WRITE
Granted WRITE. Current: READ, WRITE [0011]

> toggle READ
Toggled READ. Current: WRITE [0010]

> check WRITE
Can WRITE

> revoke WRITE
Revoked WRITE. Current: (none) [0000]

> exit
Goodbye!!!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ BitMasks.cpp -o BitMasks

# Run (Linux / macOS)
./BitMasks

# Run (Windows)
BitMasks.exe
```

---

## 📁 Structure

```
BitMasks/
├── BitMasks.cpp   # Single-file program
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

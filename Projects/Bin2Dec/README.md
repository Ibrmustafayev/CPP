<div align="center">

# 🔢 Bin2Dec

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Strings%20%7C%20Exceptions%20%7C%20Bit%20Arithmetic-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line binary to decimal converter written in C++.*

</div>

---

## 📌 Overview

Bin2Dec takes a binary string from the user and converts it to its decimal equivalent. Invalid characters throw an exception and prompt the user again — the loop keeps running until `q` is entered.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Conversion** | Converts any valid binary string to decimal |
| 2 | **Input Validation** | Throws `invalid_argument` if any character isn't `0` or `1` |
| 3 | **Continuous Loop** | Accepts multiple inputs per session until `q` to quit |

---

## 🧠 Concepts Used

- Bit-shift accumulation — `decimal = decimal * 2 + (c - '0')` processes each bit left to right
- `throw invalid_argument` — rejects non-binary characters with a descriptive message
- `try/catch` — catches and prints the error without crashing the loop
- Range-based `for` with `char &` — iterates over the binary string character by character

---

## 🖥️ Example Output

```
=== Binary to Decimal ===
Input ('q' to quit): 1010
1010 (Binary) => 10 (Decimal)

Input ('q' to quit): 11111111
11111111 (Binary) => 255 (Decimal)

Input ('q' to quit): 1029
Error: Invalid value! Only '0' and '1' are allowed!

Input ('q' to quit): q
Goodbye!!!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ Bin2Dec.cpp -o Bin2Dec

# Run (Linux / macOS)
./Bin2Dec

# Run (Windows)
Bin2Dec.exe
```

---

## 📁 Structure

```
Bin2Dec/
├── main.cpp   # Single-file program
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

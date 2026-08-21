<div align="center">

# 🏛️ Rom2Dec

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Regex%20%7C%20unordered__map%20%7C%20Subtractive%20Notation-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line Roman numeral to decimal converter written in C++.*

</div>

---

## 📌 Overview

Rom2Dec takes a Roman numeral string from the user, validates it against the official Roman numeral grammar using a regex pattern, then converts it to its decimal equivalent using subtractive notation logic. The loop continues until `q` or `Q` is entered.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Conversion** | Converts any valid Roman numeral (I–MMMCMXCIX) to decimal |
| 2 | **Regex Validation** | Rejects malformed input like `IIII`, `VV`, or `LC` before conversion |
| 3 | **Case-Insensitive** | Input is uppercased automatically before processing |
| 4 | **Continuous Loop** | Accepts multiple inputs per session until `q` or `Q` to quit |

---

## 🧠 Concepts Used

- `unordered_map<char, int>` — maps Roman numeral characters to their integer values
- `std::regex` + `regex_match` — validates input against the official Roman numeral grammar
- Subtractive notation — if `values[i] < values[i+1]`, subtract instead of add (e.g. `IV` = 4)
- `toupper` — normalizes input to uppercase in-place before validation
- `static const regex` — compiled once, reused every call for efficiency

---

## 🖥️ Example Output

```
    === Roman to Decimal ===
Input ('q' to quit): XIV
XIV (Roman) => 14

Input ('q' to quit): MCMXCIX
MCMXCIX (Roman) => 1999

Input ('q' to quit): IIII
Error: Invalid value!

Input ('q' to quit): vii
VII (Roman) => 7

Input ('q' to quit): q
Goodbye!!!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ main.cpp -o main

# Run (Linux / macOS)
./main

# Run (Windows)
main.exe
```

---

## 📁 Structure

```
Rom2Dec/
├── main.cpp   # Single-file program
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

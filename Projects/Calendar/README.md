<div align="center">

# 📅 Calendar — Day Target

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-ctime%20%7C%20Date%20Validation%20%7C%20ANSI%20Colors-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A terminal calendar that highlights a target date, written in C++.*

</div>

---

## 📌 Overview

Calendar — Day Target takes a date from the user, validates it, and renders the full month calendar in the terminal with the target day highlighted in red. Leap years are handled automatically.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Month Calendar** | Renders the full month with correct weekday alignment |
| 2 | **Target Highlight** | The entered date is printed in red using ANSI escape codes |
| 3 | **Leap Year Support** | February automatically expands to 29 days in leap years |
| 4 | **Date Validation** | Rejects invalid dates, out-of-range months, and pre-1900 years |
| 5 | **Input Validation** | Catches non-integer input via `cin.fail()` and `invalid_argument` |

---

## 🧠 Concepts Used

- `struct tm` / `mktime` — converts date components into a normalized time structure
- `strftime` — formats the month and year header (e.g. `August 2026`)
- `tm_wday` — used to calculate which weekday the 1st of the month falls on
- Leap year check — `year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)`
- ANSI escape codes — `\033[31m` (red) and `\033[0m` (reset) for target day highlight
- `throw` / `try` / `catch` — `invalid_argument` for bad input, `runtime_error` for invalid dates

---

## 🖥️ Example Output

```
=== Calendar - Day Target ===
Date: 27
Month (1 - 12): 8
Year: 2026

         August 2026
Su Mo Tu We Th Fr Sa
                   1
 2  3  4  5  6  7  8
 9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29  ← 27 is highlighted in red
30 31
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later. ANSI colors require a color-supporting terminal.

```bash
# Compile
g++ dayTarget.cpp -o dayTarget

# Run (Linux / macOS)
./dayTarget

# Run (Windows)
dayTarget.exe
```

> **Note:** ANSI color codes may not display on older Windows terminals. Use Windows Terminal or WSL for best results.

---

## 📁 Structure

```
Calendar/
├── dayTarget.cpp   # Single-file program
└── README.md
```

---

## ⚠️ Limitations

- Years before 1900 are not supported
- No navigation between months — one calendar rendered per run

---

## 📜 License

Released under the [MIT License](../LICENSE).

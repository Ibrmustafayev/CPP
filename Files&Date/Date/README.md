<div align="center">

# 📅 Date

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-ctime%20%7C%20chrono%20%7C%20Time%20Arithmetic-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A C++ program exploring date/time handling with `ctime` and `chrono`.*

</div>

---

## 📌 Overview

Date demonstrates three different aspects of time in C++: formatting and displaying the current date and time, performing date arithmetic (30 days ahead), and measuring code execution duration with high-resolution clocks. An `Event` class tracks creation timestamps and computes the time elapsed between two events.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Formatted Date/Time** | Prints current date and time in `YYYY-MM-DD \| HH:MM:SS` format |
| 2 | **Date Arithmetic** | Calculates and displays the date 30 days from now |
| 3 | **Execution Timer** | Measures how long the Fibonacci(30) recursive call takes |
| 4 | **Event Timestamps** | `Event` objects record their creation time and compare elapsed seconds |

---

## 🧠 Concepts Used

- `time(0)` / `localtime()` — gets current local time as a `tm` struct
- `strftime()` — formats a `tm` struct into a custom date/time string
- `time_t` arithmetic — adding seconds to a timestamp for future date calculation
- `chrono::high_resolution_clock` — nanosecond-precision execution timer
- `chrono::duration<double>` — converts clock difference to seconds
- `difftime()` — computes seconds elapsed between two `time_t` values
- `ctime()` — converts a `time_t` to a human-readable string
- Recursive Fibonacci — used as a benchmarking workload

---

## 🖥️ Example Output

```
2026-07-30 | 14:35:22

30 days after now: 2026-8-29

30th element of Fibonacci sequence: 832040

Elapsed: 0.00412 seconds

Now > Wed Jul 30 14:35:22 2026
30th element of Fibonacci sequence: 832040

Later > Wed Jul 30 14:35:22 2026
0 seconds passed!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ Date.cpp -o Date

# Run (Linux / macOS)
./Date

# Run (Windows)
Date.exe
```

---

## 📁 Structure

```
Date/
├── Date.cpp   # Single-file program
└── README.md
```

---

## ⚠️ Limitations

- The two `Event` objects are created almost instantly, so `difftime` often returns `0`
- Month output from `tm_mon` is zero-indexed — the code adds 1 but no zero-padding is applied

---

## 📜 License

Released under the [MIT License](../LICENSE).

<div align="center">

# 🛗 Elevator Simulator

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-OOP%20%7C%20set%20%7C%20State%20Machine-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A terminal elevator simulator written in C++.*

</div>

---

## 📌 Overview

Elevator Simulator takes a floor range, a starting floor, and a list of floor requests, then animates the elevator moving step by step — printing whether it's arriving at a requested floor or passing through. The elevator uses a direction-aware dispatch algorithm to serve all requests efficiently.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Custom Range** | User defines minimum floor, maximum floor, and starting floor |
| 2 | **Multi-request Queue** | Accepts any number of floor requests before starting |
| 3 | **Direction-aware Dispatch** | Elevator continues in its current direction before reversing |
| 4 | **Step-by-step Animation** | Prints each floor with a 1-second delay — arriving or passing through |
| 5 | **Idle Detection** | Stops and reports final floor once all requests are served |

---

## 🧠 Concepts Used

- `set<int>` — sorted pending floor requests with O(log n) lookup and erase
- `enum Direction` — state machine with `IDLE`, `UP`, `DOWN` states
- `upper_bound` — finds the nearest pending floor above the current position
- Direction reversal logic — elevator switches direction only when no more requests exist in the current direction
- `Sleep(1000)` — 1-second delay per floor step via `windows.h`

---

## 🖥️ Example Output

```
=== Elevator Simulator ===
Min floor: 1
Max floor: 10
Start floor: 3

Floor requests ('-1' to start): 7 2 5 -1

Floor 3: Idle. Elevator moving....
Floor 4: Passing through..
Floor 5: Arrived! Doors open.
Floor 6: Passing through..
Floor 7: Arrived! Doors open.
Floor 6: Passing through..
Floor 5: Passing through..
Floor 4: Passing through..
Floor 3: Passing through..
Floor 2: Arrived! Doors open.

All requests served. Elevator idle at floor 2
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ on Windows (`windows.h` is Windows-only)

```bash
# Compile
g++ Elevator.cpp -o Elevator

# Run
Elevator.exe
```

> **Note:** Replace `Sleep(1000)` with `usleep(1000000)` and include `<unistd.h>` to run on Linux/macOS.

---

## 📁 Structure

```
Elevator/
├── Elevator.cpp   # Single-file simulator
└── README.md
```

---

## ⚠️ Limitations

- **Windows only** — depends on `windows.h`
- No simultaneous up/down call handling — requests are served in one pass per direction
- Floor range and requests are entered once — no adding requests mid-run

---

## 📜 License

Released under the [MIT License](../LICENSE).

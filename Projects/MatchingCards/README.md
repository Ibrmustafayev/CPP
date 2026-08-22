<div align="center">

# 🃏 Matching Cards

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Structs%20%7C%20Shuffle%20%7C%20unordered__map-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A terminal-based memory card matching game written in C++.*

</div>

---

## 📌 Overview

Matching Cards is a classic memory game on a 4×4 grid. Sixteen cards — eight pairs — are shuffled and placed face down. Each turn you pick two cards by coordinate; if they match they stay revealed, otherwise they flip back. The game ends when all eight pairs are found.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **4×4 Grid** | 16 cards arranged in a labeled grid (rows `0–3`, columns `a–d`) |
| 2 | **Shuffled Deck** | Cards randomized every run using `mt19937` seeded with `random_device` and system clock |
| 3 | **Input Validation** | Rejects invalid coordinates and already-revealed or matched cards |
| 4 | **Case-Insensitive** | Input is lowercased automatically — `A0` and `a0` both work |
| 5 | **Win Detection** | Game ends automatically when all pairs are matched |

---

## 🧠 Concepts Used

- `struct Card` — groups `value`, `revealed`, and `matched` state per card
- `mt19937` + `random_device` — cryptographically seeded Mersenne Twister for fair shuffling
- `shuffle` — STL algorithm to randomize the card vector in-place
- `unordered_map<string, int>` — maps coordinate strings (`"a0"`, `"b3"` etc.) to flat vector indices
- `system("cls")` + `Sleep()` — clears terminal and pauses for visual feedback after each turn
- `revealed` vs `matched` — two separate flags allow temporary reveal without permanent state

---

## 🖥️ Example Output

```
=== Matching Cards ===

       a   b   c   d
  0  [ ] [ ] [ ] [ ]
  1  [ ] [ ] [ ] [ ]
  2  [ ] [ ] [ ] [ ]
  3  [ ] [ ] [ ] [ ]

Card 1 to open: a0
Card 2 to open: c1

       a   b   c   d
  0  [A] [ ] [ ] [ ]
  1  [ ] [ ] [H] [ ]
  2  [ ] [ ] [ ] [ ]
  3  [ ] [ ] [ ] [ ]

(no match — cards flip back)
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ on Windows (`windows.h` is Windows-only)

```bash
# Compile
g++ main.cpp -o main

# Run
main.exe
```

> **Note:** `windows.h` and `Sleep()` are Windows-specific. Replace `Sleep(1000)` with `usleep(1000000)` and include `<unistd.h>` to run on Linux/macOS.

---

## 📁 Structure

```
MatchingCards/
├── main.cpp   # Single-file game
└── README.md
```

---

## ⚠️ Limitations

- **Windows only** — depends on `windows.h`
- No move counter or timer
- Grid size and card set are hardcoded

---

## 📜 License

Released under the [MIT License](../LICENSE).

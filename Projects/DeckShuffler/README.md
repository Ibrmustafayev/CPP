<div align="center">

# 🃏 Deck Shuffler

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Structs%20%7C%20Shuffle%20%7C%20Input%20Validation-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line card deck shuffler and dealer written in C++.*

</div>

---

## 📌 Overview

Deck Shuffler builds a standard 52-card deck, shuffles it using a cryptographically seeded Mersenne Twister, deals however many cards you ask for, and displays your hand with its total value.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Full Deck** | Generates all 52 cards across 4 suits with correct values |
| 2 | **Shuffle** | Randomized using `mt19937` seeded with `random_device` and system clock |
| 3 | **Deal** | Deals 1–52 cards — defaults to 7 on invalid input |
| 4 | **Hand Value** | Calculates and displays the total value of dealt cards |
| 5 | **Input Validation** | Handles non-integer input and out-of-range values gracefully |

---

## 🧠 Concepts Used

- `struct Card` — groups suit name and integer value
- `mt19937` seeded with `random_device` + system clock — dual entropy shuffle
- `shuffle` — STL algorithm applied to the full 52-card array
- `cin.fail()` / `cin.clear()` / `cin.ignore()` — recovers from non-integer input
- Card value mapping — Ace = 11, 2–10 = face value, Jack/Queen/King = 10

---

## 🖥️ Example Output

```
=== Deck Shuffler ===
How many cards to deal? 5

Your hand:
   King of Spades
   3 of Hearts
   Ace of Diamonds
   7 of Clubs
   10 of Spades

Hand value: 41
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ DeckShuffler.cpp -o DeckShuffler

# Run (Linux / macOS)
./DeckShuffler

# Run (Windows)
DeckShuffler.exe
```

---

## 📁 Structure

```
DeckShuffler/
├── DeckShuffler.cpp   # Single-file program
└── README.md
```

---

## ⚠️ Limitations

- Ace is always valued at **11** — no dynamic Ace handling
- Dealt cards are picked with replacement — duplicates are possible

---

## 📜 License

Released under the [MIT License](../LICENSE).

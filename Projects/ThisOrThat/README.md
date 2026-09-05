<div align="center">

# ⚔️ This or That

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-vector%20%7C%20Shuffle%20%7C%20Tournament%20Logic-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line tournament bracket picker written in C++.*

</div>

---

## 📌 Overview

This or That runs a single-elimination tournament from a chosen category — Footballers, Cities, or Films. Each round pairs up the remaining options randomly and you pick a winner from each matchup. The last one standing is declared champion.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Three Categories** | Footballers, Cities, and Films — 8 options each |
| 2 | **Random Pairings** | Options are shuffled each round using `mt19937` |
| 3 | **Single-Elimination** | Losers are erased from the vector — one survives per matchup |
| 4 | **Round Tracking** | Rounds are numbered, with the final two labelled "Final" |
| 5 | **Champion Declaration** | Last remaining option is printed as the winner |

---

## 🧠 Concepts Used

- `vector<Option>` — holds remaining contestants; losers erased in-place via `erase`
- `shuffle` + `mt19937` — randomizes pairing order each round
- Single-elimination logic — `options.size()` halves each round until one remains
- `vector::erase` — removes the loser at the correct index without invalidating the loop
- `struct Option` — groups name and a `matched` counter (extensible for stats)

---

## 🖥️ Example Output

```
=== This or That ===
Choose a category (1 - 3): 1. Footballers  2. Cities  3. Films
> 1

    --- Round 1 ---
Messi or Haaland? (1/2): 1
Winner: Messi

Ronaldo or Kane? (1/2): 2
Winner: Kane

Mbappe or Modric? (1/2): 1
Winner: Mbappe

Neymar or Salah? (1/2): 2
Winner: Salah

    --- Round 2 ---
...

    --- Round 3 (Final) ---
Messi or Mbappe? (1/2): 1
Winner: Messi

Champion: Messi
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ ThisOrThat.cpp -o ThisOrThat

# Run (Linux / macOS)
./ThisOrThat

# Run (Windows)
ThisOrThat.exe
```

---

## 📁 Structure

```
ThisOrThat/
├── ThisOrThat.cpp   # Single-file game
└── README.md
```

---

## ⚠️ Limitations

- Categories and options are hardcoded — 8 per category only
- No replay option — restart the program to play again

---

## 📜 License

Released under the [MIT License](../LICENSE).

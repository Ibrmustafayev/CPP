<div align="center">

# 🃏 Flashcards

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Structs%20%7C%20Spaced%20Review%20%7C%20conio.h-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A terminal-based flashcard quiz with spaced review, written in C++.*

</div>

---

## 📌 Overview

Flashcards presents 15 questions across three rounds of five cards each. Press Enter to reveal each answer, then mark whether you got it right. Cards you miss are automatically flagged for repeat review within the same round — the round doesn't end until every card is answered correctly.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Three Rounds** | 5 cards per round — general knowledge, math/science, and advanced trivia |
| 2 | **Press-to-Reveal** | Answer is hidden until you press Enter — no peeking |
| 3 | **Spaced Review** | Missed cards loop back for re-review until all are answered correctly |
| 4 | **Round Summary** | Shows correct count and how many cards are being reviewed after each round |
| 5 | **Final Summary** | Prints correct answers per round at the end |

---

## 🧠 Concepts Used

- `struct Flashcard` — groups question, answer, and `needsReview` flag per card
- `_getch()` — waits for any keypress without echoing via `conio.h`
- `Sleep()` — brief pauses between reveals for readability via `windows.h`
- Review loop — iterates until all `needsReview` flags are `false`
- `vector<int> correctsInRounds` — accumulates per-round scores for the final summary

---

## 🖥️ Example Output

```
=== Flashcards ===

    --- Round 1 ---
> Card 1/5
Q: What is the capital of France?
[Press 'Enter' to reveal answer]

A: Paris
Did you get it right? (y/n): y
Correct!

> Card 2/5
...

    --- Round 1 Summary ---
Correct: 4/5
Reviewing 1 card again...

    --- Final Summary ---
Round 1: 4
Round 2: 3
Round 3: 5
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ on Windows (`conio.h` and `windows.h` are Windows-only)

```bash
# Compile
g++ Flashcards.cpp -o Flashcards

# Run
Flashcards.exe
```

> **Note:** `conio.h` is Windows-only. Replace `_getch()` with `getchar()` and `Sleep()` with `usleep()` to run on Linux/macOS.

---

## 📁 Structure

```
Flashcards/
├── Flashcards.cpp   # Single-file quiz
└── README.md
```

---

## ⚠️ Limitations

- **Windows only** — depends on `conio.h` and `windows.h`
- Questions and answers are hardcoded — 15 total across 3 rounds
- No score persistence between runs

---

## 📜 License

Released under the [MIT License](../LICENSE).

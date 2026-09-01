<div align="center">

# ✅ True or False

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-vector%20%7C%20pair%20%7C%20Shuffle-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line true or false quiz game written in C++.*

</div>

---

## 📌 Overview

True or False presents 10 general knowledge statements in random order. Answer each with `t` or `f`, get instant feedback, and see the correct answer revealed after each question. Your final score is shown out of 100 at the end.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **10 Questions** | General knowledge statements covering science, geography, animals, and more |
| 2 | **Shuffled Order** | Questions randomized every run using `mt19937` |
| 3 | **Instant Feedback** | Correct/Wrong printed immediately, followed by the actual answer |
| 4 | **Score Tracking** | 10 points per correct answer, final score out of 100 |
| 5 | **Invalid Input Handling** | Non-`t`/`f` input is flagged and the question is counted as skipped |

---

## 🧠 Concepts Used

- `vector<pair<string, bool>>` — stores each question and its answer together
- `shuffle` + `mt19937` — randomizes question order per run
- `boolalpha` — prints `true`/`false` instead of `1`/`0` for answer reveal
- Range-based `for` with structured binding — iterates over question/answer pairs cleanly

---

## 🖥️ Example Output

```
=== True or False ===
1] Octopuses have three hearts.
True or False (t/f): t
Correct!!!
Answer: true

2] The capital of Australia is Sydney.
True or False (t/f): t
Wrong!!!
Answer: false

...

Score: 80/100
Total questions: 10
Correct: 8
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ TrueOrFalse.cpp -o TrueOrFalse

# Run (Linux / macOS)
./TrueOrFalse

# Run (Windows)
TrueOrFalse.exe
```

---

## 📁 Structure

```
TrueOrFalse/
├── TrueOrFalse.cpp   # Single-file quiz
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

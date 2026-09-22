<div align="center">

# ⌨️ Typing App

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-chrono%20%7C%20Randomization%20%7C%20String%20Comparison-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line typing practice tool that measures speed and accuracy, written in C++.*

</thinking>

</div>

---

## 📌 Overview

Typing App picks a random sentence from a built-in pool of 10, prompts you to type it exactly, and measures your elapsed time, accuracy, and words per minute. One sentence per run — no retries.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Random Sentence** | One of 10 sentences selected randomly each run |
| 2 | **Time Measurement** | Measured in milliseconds using `chrono::steady_clock` |
| 3 | **Accuracy** | Character-by-character comparison as a percentage |
| 4 | **WPM** | Words per minute calculated from elapsed time and word count |

---

## 🧠 Concepts Used

- `chrono::steady_clock` — high-resolution monotonic timer for elapsed time
- `chrono::duration_cast<milliseconds>` — converts clock difference to milliseconds
- `uniform_int_distribution` + `mt19937` — uniform random sentence selection
- Character comparison — `typed[i] == sentence[i]` iterates up to `max(typed.size(), sentence.size())`
- WPM formula — `wordNum * 60000.0 / duration.count()` — word count scaled to one minute

---

## 🖥️ Example Output

```
=== Typing Practise ===
Type this sentence exactly:
"The quick brown fox jumps over the lazy dog"

> The quick brown fox jumps over the lazy dog

Time: 5.312 seconds
Accuracy: 100%
WPM: 50.45
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ TypingApp.cpp -o TypingApp

# Run (Linux / macOS)
./TypingApp

# Run (Windows)
TypingApp.exe
```

---

## 📁 Structure

```
TypingApp/
├── TypingApp.cpp   # Single-file program
└── README.md
```

---

## ⚠️ Limitations

- Single sentence per run — no replay without restarting
- Sentences are hardcoded — 10 total
- WPM counts spaces as word separators — no punctuation-aware tokenizing

---

## 📜 License

Released under the [MIT License](../LICENSE).

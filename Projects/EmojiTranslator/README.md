<div align="center">

# 😀 Emoji Translator

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-map%20%7C%20stringstream%20%7C%20String%20Processing-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line emoji translator written in C++.*

</div>

---

## 📌 Overview

Emoji Translator reads a sentence and replaces known keywords with their corresponding emojis. Punctuation attached to keywords is preserved, unrecognised words pass through unchanged, and the loop continues until `q` is entered.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Keyword Replacement** | 75+ keywords mapped to emojis across emotions, animals, food, objects, and more |
| 2 | **Punctuation Preservation** | Trailing punctuation (`.`, `!`, `?`, `,`) is stripped before lookup and re-attached after |
| 3 | **Case-Insensitive** | Words are lowercased before lookup — `Happy` and `HAPPY` both translate |
| 4 | **Passthrough** | Unrecognised words are printed as-is — sentences stay readable |
| 5 | **Continuous Loop** | Accepts multiple sentences per session until `q` to quit |

---

## 🧠 Concepts Used

- `const map<string, string>` — 75+ keyword-to-emoji pairs for O(log n) lookup
- `stringstream` — tokenizes the input sentence word by word
- `tolower` in-place — normalizes each word before map lookup
- Punctuation stripping — `ispunct` loop peels trailing punctuation before lookup and re-appends it after
- `map::find` — returns an iterator; unmatched words fall through to the original

---

## 🖥️ Example Output

```
=== Emoji Translator ===
Enter a sentence ('q' to quit): I am happy and love pizza!

Translated: I am 😀 and 😍 🍕!

Enter a sentence ('q' to quit): The cat is thinking...

Translated: The 🐱 is 🤔...

Enter a sentence ('q' to quit): q
Goodbye!!!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later. A UTF-8 capable terminal is needed to display emojis correctly.

```bash
# Compile
g++ EmojiTranslator.cpp -o EmojiTranslator

# Run (Linux / macOS)
./EmojiTranslator

# Run (Windows)
EmojiTranslator.exe
```

> **Note:** On Windows, enable UTF-8 output by running `chcp 65001` in the terminal before launching, or use Windows Terminal.

---

## 📁 Structure

```
EmojiTranslator/
├── EmojiTranslator.cpp   # Single-file program
└── README.md
```

---

## 📚 Supported Categories

Emotions · Gestures · Nature · Animals · Food & Drink · Objects · Activities · Symbols

---

## 📜 License

Released under the [MIT License](../LICENSE).

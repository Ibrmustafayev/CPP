<div align="center">

# 🔤 Strings

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-String%20Methods%20%7C%20Lambdas%20%7C%20char%20Functions-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A C++ program applying a wide range of string operations to a user-entered sentence.*

</div>

---

## 📌 Overview

Strings1 takes a single sentence as input and runs it through eight different string operations — from basic transformations like uppercase and reverse, to more involved tasks like word splitting, title casing, and finding the most frequent character.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Length & Ends** | Prints sentence length, first and last character |
| 2 | **Uppercase / Lowercase** | Converts and prints the full sentence in both cases |
| 3 | **Vowel & Consonant Count** | Counts vowels and consonants separately |
| 4 | **Reverse** | Prints the sentence in reverse using `rbegin`/`rend` |
| 5 | **Word Check** | Asks for a word and reports if the sentence starts, ends, or contains it |
| 6 | **Space Replace** | Replaces all spaces with `_` |
| 7 | **Word Split** | Splits into words and prints each with its length |
| 8 | **Title Case** | Capitalizes the first letter of every word |
| 9 | **Most Frequent Char** | Finds the most-used letter using a frequency array |

---

## 🧠 Concepts Used

- Lambda functions — `reverseString`, `len`, `front_back` defined inline in `main`
- `toupper` / `tolower` / `isalpha` — character classification and conversion via `cctype`
- `string::find` / `string::compare` — substring search and position-based comparison
- `string::rbegin` / `rend` — reverse iterator for string reversal
- `vector<string>` — manual word splitting without `sstream`
- Frequency array — `int freq[256]` with `max_element` for most-frequent character detection
- Title casing — index-based logic checking previous character to detect word boundaries

---

## 🖥️ Example Output

```
Enter a sentence: hello world

The length of the sentence: 11
The first character: h
The last character: d
Uppercase version: HELLO WORLD
Lowercase version: hello world
The number of vowels: 3
The number of consonants: 7
The reversed version: dlrow olleh

Enter a word: hello
The sentence starts with 'hello'.
The replaced version: hello_world
Words & Lengths:
  hello - 5
  world - 5
The title version: Hello World
The most frequent char: l (3 times)
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ Strings1.cpp -o Strings1

# Run (Linux / macOS)
./Strings1

# Run (Windows)
Strings1.exe
```

---

## 📁 Structure

```
Strings/
├── Strings1.cpp   # Single-file program
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

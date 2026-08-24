<div align="center">

# 🔍 Regex Helper

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Regex%20%7C%20smatch%20%7C%20Exception%20Handling-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line regex testing tool written in C++.*

</div>

---

## 📌 Overview

Regex Helper lets you enter a regex pattern, then test strings against it interactively. For each test string it reports whether the full string matches, what the search match found, and the contents of any capture groups. Invalid patterns are caught and reported without crashing.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Full Match** | Reports whether the entire string matches the pattern via `regex_match` |
| 2 | **Search Match** | Finds the first occurrence of the pattern anywhere in the string via `regex_search` |
| 3 | **Capture Groups** | Prints the content of each capture group `(...)` individually |
| 4 | **Pattern Validation** | Catches malformed regex patterns via `regex_error` before testing |
| 5 | **Multi-pattern Session** | Prompts to try another pattern after finishing — no restart needed |

---

## 🧠 Concepts Used

- `std::regex` — compiles a pattern string into a reusable regex object
- `regex_match` — checks if the entire input matches the pattern
- `regex_search` — finds the first match anywhere within the string
- `smatch` — stores the full match and all capture groups
- `regex_error` — caught in `is_valid_pattern()` to detect and report bad patterns before use
- `match[0]` / `match[i]` — full match and numbered capture group access

---

## 🖥️ Example Output

```
    === Regex Helper ===
Enter a pattern: (\d+)-(\w+)
Enter a test string ('q' to stop): 42-hello

Full match: Yes
Search match: 42-hello
  Group 1: 42
  Group 2: hello

Enter a test string ('q' to stop): abc

Full match: No
Search match: No match found.

Enter a test string ('q' to stop): q

Try another pattern? (y/n): n

Goodbye!!!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ main.cpp -o main

# Run (Linux / macOS)
./main

# Run (Windows)
main.exe
```

---

## 📁 Structure

```
RegexHelper/
├── main.cpp   # Single-file tool
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

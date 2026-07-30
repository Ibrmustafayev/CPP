<div align="center">

# Standard Template Library

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-map%20%7C%20set%20%7C%20unordered__map%20%7C%20Algorithms-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*Two C++ programs exploring the Standard Template Library — containers, iterators, and algorithms.*

</div>

---

## 📌 Overview

This is a two-part introduction to the C++ STL. The first program focuses on ordered containers (`map`, `set`) for word frequency analysis. The second expands into `unordered_map`, `vector<pair>`, and a range of STL algorithms — all applied to real text and number processing tasks.

---

## 🚀 Programs

### 1️⃣ [Task 1](task1.cpp) — map, set & pair
Reads a sentence, counts word frequencies with a `map`, tracks unique words alphabetically with a `set`, and finds the most frequent word using a `pair`.

| Concepts | `map<string, int>`, `set<string>`, `pair<string, int>`, `stringstream`, iterator-based traversal |
|---|---|
| **Difficulty** | ⭐⭐ |

```bash
g++ task1.cpp -o task1 && ./task1
```

---

### 2️⃣ [Task 2](task2.cpp) — unordered_map, vector & Algorithms
Combines word frequency with an `unordered_map`, number analysis with STL algorithms, and a leaderboard sorted by score using a lambda comparator.

| Concepts | `unordered_map`, `count_if`, `find_if`, `all_of`, `transform`, `sort` with lambda, `vector<pair<string,int>>` |
|---|---|
| **Difficulty** | ⭐⭐⭐ |

```bash
g++ task2.cpp -o task2 && ./task2
```

---

## 🧠 Concepts Used (Across the Series)

- `map` — ordered key-value store with alphabetical iteration
- `set` — ordered unique elements, auto-deduplicated
- `unordered_map` — hash-based key-value store, faster lookup than `map`
- `vector<pair<string, int>>` — sortable list of named scores
- `stringstream` — tokenizing strings into words and numbers
- STL algorithms — `count_if`, `find_if`, `all_of`, `transform`, `sort`
- Lambda functions — inline predicates and comparators passed to algorithms

---

## 🖥️ Example Output

**Task 1** (input: `"the cat sat on the mat the cat"`):
```
Word Frequencies:
  cat: 2
  mat: 1
  on: 1
  sat: 1
  the: 3

Unique words (alphabetical): cat mat on sat the

Most frequent word: the (3 times)
```

**Task 2** (numbers: `1 3 6 8 2`):
```
Even count: 3
First number > 5: 6
All positive? Yes
Squared: 1 9 36 64 4

Leaderboard (sorted by score desc):
  Bob: 90
  Alice: 85
  Carol: 72
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ filename.cpp -o output

# Run (Linux / macOS)
./output

# Run (Windows)
output.exe
```

---

## 📁 Structure

```
OpeningOfSTL/
├── task1.cpp   # map, set, pair — word frequency and unique words
├── task2.cpp   # unordered_map, algorithms, lambda — number and text analysis
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

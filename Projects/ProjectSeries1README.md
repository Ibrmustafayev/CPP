<div align="center">

# 🗂️ Project Series 1

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Vectors%20%7C%20Pointers%20%7C%20STL%20%7C%20OOP--lite-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*Three C++ mini-projects applying vectors, pointers, and STL algorithms to real problems.*

</div>

---

## 📌 Overview

This series moves beyond syntax exercises into small self-contained applications. Each program applies C++ fundamentals — vectors, raw pointers, STL algorithms, and multi-vector data management — to a concrete task.

---

## 🚀 Programs

### 1️⃣ [Mini Task A](MiniTaskA.cpp) — Vector Statistics
Takes a user-entered integer array and computes the minimum, maximum, and average using STL algorithms. Results are returned via reference parameters.

| Concepts | `vector<int>`, `min_element`, `max_element`, `accumulate`, `const &` |
|---|---|
| **Difficulty** | ⭐ |

```bash
g++ MiniTaskA.cpp -o MiniTaskA && ./MiniTaskA
```

---

### 2️⃣ [Mini Task B](MiniTaskB.cpp) — Word Sorter & Search
Takes a dynamic array of words, sorts them alphabetically, then checks if a target word is in the array.

| Concepts | `string*`, `new` / `delete[]`, `sort`, pointer-based arrays, linear search |
|---|---|
| **Difficulty** | ⭐⭐ |

```bash
g++ MiniTaskB.cpp -o MiniTaskB && ./MiniTaskB
```

---

### 3️⃣ [Contact Book](ContactBook.cpp) — Contact Manager
A menu-driven contact manager storing names, phones, and emails in parallel vectors. Supports adding, searching, updating, deleting, listing (alphabetically sorted), and counting contacts.

| Concepts | Parallel `vector<string>`, `sort` with lambda, `erase`, case-insensitive search |
|---|---|
| **Difficulty** | ⭐⭐⭐ |

```bash
g++ ContactBook.cpp -o ContactBook && ./ContactBook
```

---

## 🧠 Concepts Used (Across the Series)

- `vector<int>` and `vector<string>` — dynamic arrays with STL support
- STL algorithms — `min_element`, `max_element`, `accumulate`, `sort`, `erase`
- Raw pointer arrays — `new` / `delete[]` for heap-allocated string arrays
- Pass-by-reference (`&`) and `const &` for output and read-only parameters
- Lambda comparator — `sort` with `[&](int a, int b)` for index-based alphabetical ordering
- Case-insensitive search — `tolower` applied across strings before comparison

---

## 🖥️ Menu Preview (Contact Book)

```
=== Contact Book ===
1. Add  2. Search  3. Update  4. Delete  5. List  6. Count  7. Exit
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
ProjectSeries1/
├── MiniTaskA.cpp    # Vector statistics (min, max, avg)
├── MiniTaskB.cpp    # Word sorter and search
├── ContactBook.cpp  # Menu-driven contact manager
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

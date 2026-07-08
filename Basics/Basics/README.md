<div align="center">

# 🧱 Basics

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Functions%20%7C%20Strings%20%7C%20Overloading%20%7C%20Pointers-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*Five progressive C++ programs covering core language fundamentals from functions to dynamic memory.*

</div>

---

## 📌 Overview

This repository documents my early C++ learning through five standalone programs. Each file targets a specific set of concepts and builds on what came before — starting with basic functions and references, ending with raw pointers and heap allocation.

---

## 🚀 Programs

### 1️⃣ [Basics 1](basics1.cpp) — Functions & References
Default parameter values, pass-by-reference with `&`, and basic user input.

| Concepts | `string`, default args, `int &` references |
|---|---|
| **Difficulty** | ⭐ |

```bash
g++ basics1.cpp -o basics1 && ./basics1
```

---

### 2️⃣ [Basics 2](Basics2.cpp) — String Operations
String length, uppercase conversion, substring search, and name formatting — all using `string` methods and character functions.

| Concepts | `getline`, `toupper`, `tolower`, `find`, `string::npos` |
|---|---|
| **Difficulty** | ⭐ |

```bash
g++ Basics2.cpp -o basics2 && ./basics2
```

---

### 3️⃣ [Basics 3](Basics3.cpp) — Function Overloading
The same `display()` and `area()` function names used for different types and signatures — integers, doubles, strings, and geometric shapes.

| Concepts | Function overloading, `cmath`, Heron's formula |
|---|---|
| **Difficulty** | ⭐⭐ |

```bash
g++ Basics3.cpp -o basics3 && ./basics3
```

---

### 4️⃣ [Basics 4](Basics4.cpp) — Vectors & References
Reference variables, swap-by-reference, vector normalization, and read-only `const` reference parameters.

| Concepts | `vector<int>`, `&` refs, `const &`, `min_element`, range-based for |
|---|---|
| **Difficulty** | ⭐⭐ |

```bash
g++ Basics4.cpp -o basics4 && ./basics4
```

---

### 5️⃣ [Basics 5](Basics5.cpp) — Pointers & Dynamic Memory
Raw pointer arrays allocated on the heap, in-place mutation via pointer, deep copy, and proper `delete[]` cleanup.

| Concepts | `new` / `delete[]`, `int*`, pointer arithmetic, deep copy |
|---|---|
| **Difficulty** | ⭐⭐⭐ |

```bash
g++ Basics5.cpp -o basics5 && ./basics5
```

---

## 🧠 Concepts Used (Across the Series)

- Default function parameters and function overloading
- Pass-by-reference (`&`) vs. pass-by-value
- `string` methods — `length`, `find`, `toupper`, `tolower`
- `vector<int>` — dynamic arrays with STL algorithms
- `const` references for read-only parameters
- Raw pointers — `new`, `delete[]`, deep copy, heap allocation

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
Basics/
├── basics1.cpp   # Functions, default args, references
├── Basics2.cpp   # String operations and character functions
├── Basics3.cpp   # Function overloading
├── Basics4.cpp   # Vectors and references
├── Basics5.cpp   # Pointers and dynamic memory
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

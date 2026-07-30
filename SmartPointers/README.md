<div align="center">

# 🧠 Smart Pointers

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-unique__ptr%20%7C%20shared__ptr%20%7C%20weak__ptr-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*Two C++ programs exploring smart pointer ownership, sharing, and lifetime management.*

</div>

---

## 📌 Overview

This is a two-part series on C++ smart pointers. The first program demonstrates `unique_ptr` for exclusive ownership and `shared_ptr` for reference-counted sharing. The second goes deeper — two editors sharing a document via `shared_ptr`, a `weak_ptr` for non-owning observation, and a `unique_ptr` move operation.

---

## 🚀 Programs

### 1️⃣ [Task 1](task1.cpp) — unique_ptr & shared_ptr Basics
A polymorphic employee system using `unique_ptr` in a vector, followed by a `shared_ptr` demo showing reference count changes across scopes.

| Concepts | `unique_ptr`, `shared_ptr`, `make_unique`, `make_shared`, `use_count()`, polymorphic destruction |
|---|---|
| **Difficulty** | ⭐⭐ |

```bash
g++ task1.cpp -o task1 && ./task1
```

---

### 2️⃣ [Task 2](task2.cpp) — shared_ptr, weak_ptr & move
Two `Editor` objects sharing ownership of a `Document` via `shared_ptr`. Demonstrates `weak_ptr` for safe non-owning access and `unique_ptr` move semantics.

| Concepts | `shared_ptr` co-ownership, `weak_ptr`, `wp.lock()`, `unique_ptr` move, destructor ordering |
|---|---|
| **Difficulty** | ⭐⭐⭐ |

```bash
g++ task2.cpp -o task2 && ./task2
```

---

## 🧠 Concepts Used (Across the Series)

- `unique_ptr` — exclusive ownership, automatic destruction, non-copyable
- `shared_ptr` — reference-counted shared ownership via `use_count()`
- `weak_ptr` — non-owning observer that doesn't increment the reference count; safely accessed via `.lock()`
- Move semantics — `move(doc2)` transfers ownership of a `unique_ptr`, leaving the source empty
- Destructor ordering — smart pointers fire destructors automatically when scope ends
- Polymorphism — virtual `calculateSalary()` across `Employee`, `Manager`, `Intern`

---

## 🖥️ Example Output

**Task 1:**
```
Name: Alice, Base Salary: $3000
Calculated Salary: $4000

Use count after creation: 1
Use count after copy: 2
Use count after inner scope ends: 1

[Destructors firing automatically as staff vector is destroyed...]
```

**Task 2:**
```
Use count after 2 editors created: 3
Alice wrote to the document 'Report'.
Bob wrote to the document 'Report'.
[Report]: Alice's notes. Bob's additions.

Weak ptr check: Document exists!

--- Unique ptr move demo ---
Original unique_ptr is now empty (moved).
Moved-to unique_ptr: [Draft]: (empty)
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++14 or later

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
SmartPointers/
├── task1.cpp   # unique_ptr vector + shared_ptr reference count demo
├── task2.cpp   # shared_ptr co-ownership, weak_ptr, unique_ptr move
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

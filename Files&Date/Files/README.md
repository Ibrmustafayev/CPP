<div align="center">

# 📁 Files

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-File%20I%2FO%20%7C%20OOP%20%7C%20Serialization-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*Two C++ programs exploring file-based persistence — from simple struct saving to polymorphic inventory serialization.*

</div>

---

## 📌 Overview

This is a two-part series on file I/O in C++ combined with OOP. The first program saves and loads a plain vector of `Player` objects. The second scales this up to a polymorphic inventory system with three item types, each serialized and deserialized via type tags.

---

## 🚀 Programs

### 1️⃣ [Task 1](task1.cpp) — Player Save & Load
Saves a vector of `Player` objects (name + level) to `players.txt` and reloads them back into a new vector.

| Concepts | `ofstream` / `ifstream`, `vector<Player>`, constructor validation, plain-text serialization |
|---|---|
| **Difficulty** | ⭐⭐ |

```bash
g++ task1.cpp -o task1 && ./task1
```

---

### 2️⃣ [Task 2](task2.cpp) — Polymorphic Inventory System
Stores `Book`, `Electronic`, and `Item` objects in a `vector<Item*>`, saves each to `items.txt` with a type tag (`BOOK`, `ELEC`, `ITEM`), and reloads them back polymorphically.

| Concepts | Inheritance, virtual `saveToFile()` / `printInfo()`, type-tag serialization, `_`-encoded names, `new` / `delete` |
|---|---|
| **Difficulty** | ⭐⭐⭐ |

```bash
g++ task2.cpp -o task2 && ./task2
```

---

## 🧠 Concepts Used (Across the Series)

- `ofstream` / `ifstream` — writing and reading text files
- `file.is_open()` — error handling for missing or inaccessible files
- Virtual `saveToFile()` — each subclass writes its own format to the file
- Type tags (`BOOK`, `ELEC`, `ITEM`) — used on load to reconstruct the correct object type
- Space-to-`_` encoding — multi-word names stored safely in space-delimited files
- `vector<Item*>` — polymorphic container with manual `delete` cleanup
- Constructor validation — enforcing positive price and non-negative level

---

## 🖥️ Example Output

**Task 1:**
```
Original players:
  Alice - Lv.5
  Bob - Lv.3
  Carol - Lv.8

Saved to players.txt!

Reloaded players:
  Alice - Lv.5
  Bob - Lv.3
  Carol - Lv.8
```

**Task 2:**
```
Original inventory:
  [BOOK] 1984 - $15.99 by George Orwell
  [ELEC] Headphones - $89.99 (24 months warranty)
  [BOOK] Dune - $12.5 by Frank Herbert
  [ITEM] Watch - $100

Saved to items.txt!

Reloaded inventory:
  [BOOK] 1984 - $15.99 by George Orwell
  [ELEC] Headphones - $89.99 (24 months warranty)
  [BOOK] Dune - $12.5 by Frank Herbert
  [ITEM] Watch - $100
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
Files/
├── task1.cpp      # Player vector save and load
├── task2.cpp      # Polymorphic inventory serialization
├── players.txt    # Auto-generated player save file
├── items.txt      # Auto-generated inventory save file
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

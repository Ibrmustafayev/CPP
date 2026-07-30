<div align="center">

# 🏛️ Project Series — Classes

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-OOP%20%7C%20Inheritance%20%7C%20Templates%20%7C%20Polymorphism-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*Three C++ projects applying object-oriented programming through real-world systems.*

</div>

---

## 📌 Overview

This series applies C++ OOP concepts — inheritance, polymorphism, templates, and operator overloading — across three self-contained projects. Each project builds on the same core ideas but in a different domain: combat, geometry, and media.

---

## 🚀 Projects

### 1️⃣ [Game Entity System](GameEntitySystem.cpp)
A turn-based combat simulation between a Player and a Boss. The player has critical hit mechanics and experience gain; the Boss enters an enraged state when its health drops below a threshold.

| Concepts | Inheritance (`Entity` → `Player`, `Enemy` → `Boss`), polymorphic `attack()`, `rand()` for crits, validation in constructors |
|---|---|
| **Difficulty** | ⭐⭐⭐ |

```bash
g++ GameEntitySystem.cpp -o GameEntitySystem && ./GameEntitySystem
```

---

### 2️⃣ [Shape Collection](ShapeCollection.cpp)
A geometric shape library storing `Circle`, `Rectangle`, and `Triangle` objects in a generic `Collection<T>`. Computes area and perimeter for each shape and compares them via an overloaded `>` operator.

| Concepts | Abstract base class, pure virtual `area()`/`perimeter()`, `operator>` overloading, Heron's formula, `template<typename T>` |
|---|---|
| **Difficulty** | ⭐⭐ |

```bash
g++ ShapeCollection.cpp -o ShapeCollection && ./ShapeCollection
```

---

### 3️⃣ [Stream Vault](StreamVault.cpp)
A media library storing `Movie` and `Series` objects in a generic `Library<T>`. Calculates watch scores per content type and compares engagement via a `friend` function.

| Concepts | Abstract `Content` base class, `friend` function, `template<typename T>`, `setRating()` with validation, `delete` for manual cleanup |
|---|---|
| **Difficulty** | ⭐⭐ |

```bash
g++ StreamVault.cpp -o StreamVault && ./StreamVault
```

---

## 🧠 Concepts Used (Across the Series)

- Inheritance — multi-level class hierarchies across all three projects
- Polymorphism — virtual and pure virtual functions overridden per subclass
- Abstract base classes — `Content` and `Shape` enforce interface contracts
- Templates — `Collection<T>` and `Library<T>` as generic containers
- Operator overloading — `operator>` for shape area comparison
- `friend` functions — cross-class access for engagement comparison
- Constructor validation — enforcing minimum values with runtime warnings
- Smart pointer vs raw pointer patterns — `new` / `delete` for manual heap management

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
ProjectSeriesClasses/
├── GameEntitySystem.cpp   # Turn-based combat with Player, Enemy, Boss
├── ShapeCollection.cpp    # Geometric shapes with area, perimeter, comparison
├── StreamVault.cpp        # Media library with watch score calculation
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

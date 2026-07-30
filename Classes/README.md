<div align="center">

# 🏛️ Classes

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-OOP%20%7C%20Inheritance%20%7C%20Polymorphism%20%7C%20Templates-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*Thirteen C++ programs covering the full spectrum of object-oriented programming — from first classes to polymorphism and templates.*

</div>

---

## 📌 Overview

This folder documents a progressive study of C++ classes and OOP. Each file isolates a specific concept and demonstrates it through a focused, practical example. Files are organized from foundational topics (constructors, encapsulation) through to advanced ones (polymorphism, templates).

---

## 📂 Files

| File | Concept | Description |
|---|---|---|
| `firstClass.cpp` | First Class | A `Book` class with public members, constructor, and methods |
| `constructors.cpp` | Constructors & Destructor | Default and parameterized constructors, destructor logging |
| `initializerLists.cpp` | Initializer Lists | Delegating constructors and `const` member initialization via `Rectangle` |
| `initializerLists2.cpp` | Initializer Lists II | Same pattern applied to an `Employee` with salary raise |
| `encapsulation.cpp` | Encapsulation | `Product` class with getters/setters and validated price/quantity |
| `encapsulation2.cpp` | Encapsulation II | `Temperature` class with Celsius/Fahrenheit/Kelvin conversion and absolute zero guard |
| `accessSpecifiers.cpp` | Access Specifiers | `BankAccount` with `private` fields, PIN validation, deposit, withdraw, and transfer |
| `copyConstructors.cpp` | Copy Constructor | `IntArray` with deep copy to prevent shared heap pointer issues |
| `constructorsCombined.cpp` | Constructors Combined | `Playlist` combining default, parameterized, and copy constructors with dynamic array |
| `friendFunction.cpp` | Friend Functions & Classes | `friend class BankTeller` and `friend` comparison functions for `Item` |
| `inheritanceBasics.cpp` | Inheritance | `Manager` extends `Employee`, overrides `calculateSalary()` without virtual |
| `polymorphism.cpp` | Polymorphism | Virtual `calculateSalary()` across `Employee`, `Manager`, `Intern` in a `vector<Employee*>` |
| `template.cpp` | Class Templates | Generic `Stack<T>` working with `int`, `string`, and `double` |

---

## 🧠 Concepts Used (Across the Folder)

- Classes and objects — constructors, destructors, member functions
- Access specifiers — `public`, `private`, `protected`
- Encapsulation — getters/setters with validation
- Initializer lists — `const` members, delegating constructors
- Copy constructor — deep copy for heap-allocated members
- `friend` functions and classes — cross-class private access
- Inheritance — `protected` members, base class constructor calls
- Polymorphism — `virtual` / `override`, `vector<Base*>` dispatch
- Class templates — `template <typename T>` for type-generic containers

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile any file
g++ filename.cpp -o output

# Run (Linux / macOS)
./output

# Run (Windows)
output.exe
```

---

## 📁 Structure

```
Classes/
├── firstClass.cpp
├── constructors.cpp
├── initializerLists.cpp
├── initializerLists2.cpp
├── encapsulation.cpp
├── encapsulation2.cpp
├── accessSpecifiers.cpp
├── copyConstructors.cpp
├── constructorsCombined.cpp
├── friendFunction.cpp
├── inheritanceBasics.cpp
├── polymorphism.cpp
├── template.cpp
└── README.md
```

---

## 📜 License

Released under the [MIT License](../../LICENSE).

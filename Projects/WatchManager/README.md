<div align="center">

# 🎬 Watch Manager

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-OOP%20%7C%20Templates%20%7C%20File%20I%2FO%20%7C%20Exceptions-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A console-based movie and series manager written in C++, featuring OOP, templates, and file persistence.*

</div>

---

## 📌 Overview

Watch Manager (StreamVault) is a terminal application for managing a personal watchlist. You can add movies and series, search by title, filter by genre, and save/load your repository to a file — all through a numbered menu. Each content type has its own watch score formula and is stored polymorphically via smart pointers.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Add Movie** | Store a movie with title, rating, genres, and duration |
| 2 | **Add Series** | Store a series with title, rating, genres, and episode count |
| 3 | **Search by Title** | Find a specific movie or series by its exact title |
| 4 | **Filter by Genre** | List all content matching a given genre |
| 5 | **List All** | Display the full repository with watch scores and item count |
| 6 | **Save to File** | Persist the repository to `repo.txt` |
| 7 | **Load from File** | Restore the repository from `repo.txt` |

---

## 🧠 Concepts Used

- Inheritance — `Movie` and `Series` both extend the abstract `Content` base class
- Polymorphism — `watchScore()`, `printInfo()`, `typeTag()`, `saveExtra()` overridden per type
- Pure virtual functions — `watchScore()` and `typeTag()` enforced on all subclasses
- Templates — `Repository<T>` is a generic container working with any content type
- Smart pointers — `unique_ptr<Content>` for automatic memory management
- Custom exceptions — `InvalidRatingError` and `ContentNotFound` extend `runtime_error`
- File I/O — `ofstream` / `ifstream` with `_`-encoded titles and genre strings
- `set<string>` — genre storage with automatic deduplication and ordering
- `stringstream` — parses space-separated genre input at runtime

---

## 🖥️ Menu Preview

```
=== StreamVault: Watch Manager ===
1. Add Movie
2. Add Series
3. Search by title
4. Filter by genre
5. List all
6. Save to file
7. Load from file
8. Exit
```

---

## 📐 Watch Score Formula

| Type | Formula |
|---|---|
| Movie | `rating × (durationMinutes / 60.0)` |
| Series | `rating × episodes × 0.1` |

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++14 or later

```bash
# Compile
g++ -std=c++14 WatchManager.cpp -o WatchManager

# Run (Linux / macOS)
./WatchManager

# Run (Windows)
WatchManager.exe
```

---

## 📁 Structure

```
WatchManager/
├── WatchManager.cpp   # Single-file application
├── repo.txt           # Auto-generated save file
└── README.md
```

---

## ⚠️ Limitations

- Titles with spaces are stored with `_` in the file — multi-word titles load correctly but display with spaces restored
- No edit or delete functionality after adding content
- Rating must be between **0 and 10** — throws `InvalidRatingError` otherwise

---

## 📜 License

Released under the [MIT License](../LICENSE).

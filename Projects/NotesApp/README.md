<div align="center">

# 📝 Notes App

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-File%20I%2FO%20%7C%20Structs%20%7C%20Persistence-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line notes manager with persistent file storage, written in C++.*

</div>

---

## 📌 Overview

Notes App lets you add, list, view, and delete notes from a numbered menu. Each note stores a title, body, and creation timestamp. Notes are saved to `notes.txt` manually or automatically on exit, and can be reloaded in future sessions.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Add** | Create a note with a title, body, and automatic timestamp |
| 2 | **List** | Show all note titles with their creation times |
| 3 | **View** | Show full note contents including body text |
| 4 | **Delete** | Remove a note by index number |
| 5 | **Save** | Write all notes to `notes.txt` |
| 6 | **Load** | Restore notes from `notes.txt` |
| 7 | **Auto-save on Exit** | Saves automatically when option 8 is chosen |

---

## 🧠 Concepts Used

- `struct Note` — groups title, body, and `time_t` creation timestamp
- `time(0)` / `ctime()` — records and formats creation time per note
- `ofstream` / `ifstream` — custom delimiter format (`--` / `---`) for multi-line save/load
- `stoll` in `try/catch` — safely parses the stored timestamp string
- `numeric_limits<streamsize>::max()` — clears the full input buffer before `getline`
- `vector::erase` — removes notes by index with bounds checking

---

## 🖥️ Menu

```
=== Notes App ===
1. Add  2. List  3. View  4. Delete  5. Save  6. Load  7. Help  8. Exit
```

---

## 🖥️ Example Output

```
> 1
Note title: Meeting Notes
Note body: Discuss Q3 targets and roadmap.
Added!

> 2
1. Meeting Notes - Wed Jul 30 14:22:01 2026

> 3
    --- Notes ---
1] Meeting Notes - Wed Jul 30 14:22:01 2026
   Discuss Q3 targets and roadmap.

> 5
Saved!

> 8
Saved!
Goodbye!!!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ NotesApp.cpp -o NotesApp

# Run (Linux / macOS)
./NotesApp

# Run (Windows)
NotesApp.exe
```

---

## 📁 Structure

```
NotesApp/
├── NotesApp.cpp   # Single-file application
├── notes.txt      # Auto-generated save file
└── README.md
```

---

## ⚠️ Limitations

- Notes are single-line body only — multi-line bodies would break the `--` delimiter parsing
- No search or filter functionality

---

## 📜 License

Released under the [MIT License](../LICENSE).

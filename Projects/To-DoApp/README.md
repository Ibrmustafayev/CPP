<div align="center">

# ✅ To-Do App

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-File%20I%2FO%20%7C%20Structs%20%7C%20Persistence-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line to-do list manager with persistent file storage, written in C++.*

</div>

---

## 📌 Overview

To-Do App lets you add, list, complete, and delete tasks from a numbered menu. Tasks are saved to `todo.txt` manually or automatically on exit, and can be reloaded in future sessions with their completion status intact.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Add** | Add a new task to the list |
| 2 | **List** | Show all tasks with `[X]` for completed and `[ ]` for pending |
| 3 | **Complete** | Mark a task as done by index |
| 4 | **Delete** | Remove a task by index |
| 5 | **Save** | Write all tasks to `todo.txt` |
| 6 | **Load** | Restore tasks from `todo.txt` with completion status |
| 7 | **Auto-save on Exit** | Saves automatically when option 7 is chosen |

---

## 🧠 Concepts Used

- `struct Task` — groups task string and `bool done` completion flag
- `ofstream` / `ifstream` — saves `done` as `0`/`1` followed by task text, one per line
- `stoi(line.substr(0, separator))` — parses the leading boolean from each saved line
- `numeric_limits<streamsize>::max()` — clears the full input buffer before `getline`
- `vector::erase` — removes tasks by index with bounds checking
- Already-completed guard — prevents marking a task done twice

---

## 🖥️ Menu

```
=== To-Do App ===
1. Add  2. List  3. Complete  4. Delete  5. Save  6. Load  7. Exit
```

---

## 🖥️ Example Output

```
> 1
Task: Buy groceries
Added!

> 1
Task: Finish project
Added!

> 2
1. [ ] Buy groceries
2. [ ] Finish project

> 3
Index: 1
Marked complete!

> 2
1. [X] Buy groceries
2. [ ] Finish project

> 7
Saved to todo.txt!
Goodbye!!!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ ToDoApp.cpp -o ToDoApp

# Run (Linux / macOS)
./ToDoApp

# Run (Windows)
ToDoApp.exe
```

---

## 📁 Structure

```
ToDoApp/
├── ToDoApp.cpp   # Single-file application
├── todo.txt      # Auto-generated save file
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

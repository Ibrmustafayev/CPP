<div align="center">

# 🐍 Snake

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Game%20Loop%20%7C%20conio.h%20%7C%20Arrays-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A classic terminal Snake game written in C++ for Windows.*

</div>

---

## 📌 Overview

Snake is the classic arcade game rendered in the terminal. Control the snake with `W A S D`, eat fruit to grow and score, and avoid running into your own tail. The snake wraps around the edges — hitting a wall brings you out the other side.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Movement** | Four-directional control with `W A S D` — no reversing into yourself |
| 2 | **Edge Wrapping** | Snake exits one side and re-enters from the opposite side |
| 3 | **Tail Growth** | Each fruit eaten adds a segment and awards 10 points |
| 4 | **Fruit Respawn** | New fruit never spawns on an occupied cell |
| 5 | **Self-Collision** | Running into your own tail ends the game |
| 6 | **Score Display** | Live score printed below the board each frame |

---

## 🧠 Concepts Used

- `_kbhit()` / `_getch()` — non-blocking real-time keyboard input via `conio.h`
- `system("cls")` — terminal cleared each frame to simulate animation
- `Sleep()` — fixed 110ms frame delay via `windows.h`
- `enum Direction` — state machine for movement direction
- Parallel arrays — `tailX[]` / `tailY[]` track each tail segment's position
- Tail shift — segments cascade forward each frame to follow the head
- Wrap-around logic — boundary checks that loop the snake rather than end the run

---

## 🖥️ Example Output

```
######################
#                    #
#       F            #
#                    #
#     ooo@           #
#                    #
######################
SCORE: 30
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ on Windows (`conio.h` and `windows.h` are Windows-only)

```bash
# Compile
g++ Snake.cpp -o Snake

# Run
Snake.exe
```

> **Note:** `conio.h` and `windows.h` are not available on Linux or macOS. This program will not compile on those platforms without modifications.

---

## 🎮 Controls

| Key | Action |
|---|---|
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `X` | Quit |

---

## 📁 Structure

```
Snake/
├── Snake.cpp   # Single-file game
└── README.md
```

---

## ⚠️ Limitations

- **Windows only** — depends on `conio.h` and `windows.h`
- Maximum tail length: **400 segments**
- No high score persistence between runs

---

## 📜 License

Released under the [MIT License](../LICENSE).

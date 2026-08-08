<div align="center">

# ⌨️ Real-Time Key Logger

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-conio.h%20%7C%20Non--blocking%20Input%20%7C%20ASCII-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A Windows-only real-time key logger that detects letter and arrow key presses without waiting for Enter.*

</div>

---

## 📌 Overview

Real-Time Key Logger captures keyboard input as it happens — no Enter key needed. It tracks letter keys and arrow keys separately, counts total keypresses, and exits cleanly on `q`.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Letter Detection** | Detects and prints any A–Z or a–z key as it's pressed |
| 2 | **Arrow Key Detection** | Recognizes Up, Down, Left, Right via extended key codes |
| 3 | **Press Counter** | Tracks and displays total valid keypresses in real time |
| 4 | **Clean Exit** | Press `q` to quit with a farewell message |

---

## 🧠 Concepts Used

- `_kbhit()` — non-blocking check for a pending keypress
- `_getch()` — reads a character without echoing or waiting for Enter
- Extended key prefix — `ch == -32 || ch == 0` signals an arrow or function key; a second `_getch()` reads the actual key code
- ASCII ranges — `65–90` (A–Z), `97–122` (a–z) used for letter filtering
- `switch` — maps arrow scan codes (72, 80, 75, 77) to direction names

---

## 🖥️ Example Output

```
Real-time key logger. Press arrows or letters, 'q' to quit.
Keys pressed: 0

You pressed h
Keys pressed: 1

You pressed RIGHT
Keys pressed: 2

You pressed i
Keys pressed: 3

Quiting....
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ on Windows (`conio.h` is Windows-only)

```bash
# Compile
g++ KeyLogger.cpp -o KeyLogger

# Run
KeyLogger.exe
```

> **Note:** `conio.h` is not available on Linux or macOS. This program will not compile on those platforms without a compatibility library.

---

## 📁 Structure

```
KeyLogger/
├── KeyLogger.cpp   # Single-file program
└── README.md
```

---

## ⚠️ Limitations

- **Windows only** — depends on `conio.h`
- Does not detect special keys beyond the four arrow keys
- No logging to file — output is terminal only

---

## 📜 License

Released under the [MIT License](../LICENSE).

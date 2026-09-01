<div align="center">

# 🌬️ Wind Chill Calculator

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Math%20%7C%20Input%20Validation%20%7C%20cmath-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line wind chill calculator written in C++.*

</div>

---

## 📌 Overview

Wind Chill Calculator computes the apparent temperature using the official NWS wind chill formula. It validates both inputs, enforces the formula's applicable range, and loops until `q` is entered for temperature.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Wind Chill Calculation** | Uses the official NWS formula with `pow` for fractional exponents |
| 2 | **Range Validation** | Formula only applies when temperature ≤ 50°F and wind speed ≥ 3 mph |
| 3 | **Input Validation** | Handles non-numeric input via `cin.fail()` for both fields |
| 4 | **Continuous Loop** | Accepts multiple calculations per session — enter `q` on temperature to quit |

---

## 🧠 Concepts Used

- NWS wind chill formula — `35.74 + 0.6215T - 35.75V^0.16 + 0.4275T * V^0.16`
- `pow(windSpeed, 0.16)` — fractional exponent via `cmath`
- `cin.fail()` / `cin.clear()` / `cin.ignore()` — robust non-numeric input recovery
- Applicable range enforcement — temperature ≤ 50°F and wind speed ≥ 3 mph, per NWS guidelines

---

## 🖥️ Example Output

```
=== Wind Chill Calculator ===
Temperature (°F, 'q' to quit): 30
Wind speed (mph): 15

Wind Chill: 19.04°F

Temperature (°F, 'q' to quit): 60
Wind speed (mph): 10
Wind chill doesn't apply (temperature must be maximum 50°F).

Temperature (°F, 'q' to quit): q

Goodbye!!!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ WindChill.cpp -o WindChill

# Run (Linux / macOS)
./WindChill

# Run (Windows)
WindChill.exe
```

---

## 📁 Structure

```
WindChill/
├── WindChill.cpp   # Single-file calculator
└── README.md
```

---

## ⚠️ Limitations

- Fahrenheit and mph only — no Celsius or km/h support

---

## 📜 License

Released under the [MIT License](../LICENSE).

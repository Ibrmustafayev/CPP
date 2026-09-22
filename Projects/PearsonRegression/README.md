<div align="center">

# 📈 Pearson Regression

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Statistics%20%7C%20vectors%20%7C%20cmath-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line Pearson correlation coefficient calculator written in C++.*

</div>

---

## 📌 Overview

Pearson Regression takes two sets of numeric values, computes Pearson's r using the standard formula, and interprets the result as a strong, moderate, or no correlation — with direction (positive or negative).

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Pearson's r** | Computes the correlation coefficient between two variable sets |
| 2 | **Interpretation** | Classifies the result as strong (>0.7), moderate (>0.3), or no correlation |
| 3 | **Direction** | Reports positive or negative correlation where applicable |

---

## 🧠 Concepts Used

- Pearson's r formula — `(n·Σxy - Σx·Σy) / sqrt((n·Σx² - (Σx)²) · (n·Σy² - (Σy)²))`
- `product_(a, b)` — element-wise vector multiplication, reused for both `xy` and `x²`/`y²`
- `sum_()` — sums a `const vector<double>&` without modifying the input
- `pow(sum_(x), 2)` and `sqrt()` via `cmath` — squared sums and square root
- `abs(r)` — strips sign for threshold comparison before reporting direction

---

## 🖥️ Example Output

```
Number of data pairs: 5

Values for x: 1 2 3 4 5
Values for y: 2 4 5 4 5

Pearson's r: 0.8704 -> Strong positive
```

```
Number of data pairs: 4

Values for x: 1 2 3 4
Values for y: 4 3 2 1

Pearson's r: -1 -> Strong negative
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ PearsonRegression.cpp -o PearsonRegression

# Run (Linux / macOS)
./PearsonRegression

# Run (Windows)
PearsonRegression.exe
```

---

## 📁 Structure

```
PearsonRegression/
├── PearsonRegression.cpp   # Single-file calculator
└── README.md
```

---

## ⚠️ Limitations

- No input validation — non-numeric input causes undefined behavior
- Division by zero if all x or y values are identical (zero variance)
- Single run only — restart to compute a new pair

---

## 📜 License

Released under the [MIT License](../LICENSE).

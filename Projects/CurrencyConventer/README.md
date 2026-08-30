<div align="center">

# 💱 Currency Converter

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-map%20%7C%20String%20Parsing%20%7C%20Input%20Validation-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line currency converter written in C++.*

</div>

---

## 📌 Overview

Currency Converter converts between USD, EUR, GBP, and JPY using fixed exchange rates relative to USD. It validates the amount, source, and target currency before converting, and loops until `q` is entered.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Conversion** | Converts between any two supported currencies via a USD base rate |
| 2 | **Amount Validation** | Rejects non-numeric input using `strtod` with pointer checking |
| 3 | **Currency Validation** | Rejects unknown currency codes with a descriptive error |
| 4 | **Case-Insensitive** | Currency codes are uppercased automatically — `usd` and `USD` both work |
| 5 | **Continuous Loop** | Accepts multiple conversions per session until `q` to quit |

---

## 🧠 Concepts Used

- `map<string, double>` — stores exchange rates keyed by currency code
- `strtod` + `endptr` — validates that the entire amount string is a valid double
- `stod` — converts the validated string to a double for arithmetic
- Cross-rate formula — `amount / rate[from] * rate[to]` converts via USD as a pivot
- `toupper` in-place — normalizes currency codes before map lookup

---

## 💰 Supported Currencies

| Code | Currency |
|---|---|
| USD | US Dollar |
| EUR | Euro |
| GBP | British Pound |
| JPY | Japanese Yen |

---

## 🖥️ Example Output

```
=== Currency Converter ===
(Rates relative to USD)
Supported: USD, EUR, GBP, JPY

Amount: 100
From: usd
To: eur

100 USD = 92 EUR

Amount: 50
From: gbp
To: jpy

50 GBP = 9462.03 JPY

Amount: q

Goodbye!!!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ CurrencyConverter.cpp -o CurrencyConverter

# Run (Linux / macOS)
./CurrencyConverter

# Run (Windows)
CurrencyConverter.exe
```

---

## 📁 Structure

```
CurrencyConverter/
├── CurrencyConverter.cpp   # Single-file program
└── README.md
```

---

## ⚠️ Limitations

- Rates are hardcoded — not fetched from a live API
- Only 4 currencies supported

---

## 📜 License

Released under the [MIT License](../LICENSE).

<div align="center">

# ⚠️ Exception Handling

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Custom%20Exceptions%20%7C%20try%2Fcatch%20%7C%20runtime__error-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A C++ program demonstrating custom exception classes and structured error handling with a bank account system.*

</div>

---

## 📌 Overview

Exception Handling simulates a `BankAccount` class that throws custom exceptions for three failure scenarios: invalid initial balance, wrong PIN, and insufficient funds. Three separate `try/catch` blocks in `main` each trigger a different error path, showing how exceptions propagate and are caught by type.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Invalid Balance** | Throws `invalid_argument` if initial balance is negative |
| 2 | **Wrong PIN** | Throws `WrongPinError` if the entered PIN doesn't match |
| 3 | **Insufficient Funds** | Throws `InsufficientFundsException` if withdrawal exceeds balance |
| 4 | **Multi-catch blocks** | Each `try` block catches all three exception types independently |

---

## 🧠 Concepts Used

- Custom exception classes — `InsufficientFundsException` and `WrongPinError` extend `runtime_error`
- `throw` in constructors — `invalid_argument` thrown during object creation for invalid state
- `try/catch` — structured multi-catch blocks with exception-type-specific handling
- `e.what()` — retrieves the error message from any `std::exception` subclass
- Exception propagation — exceptions thrown inside member functions bubble up to `main`

---

## 🖥️ Example Output

```
Failed to create an account: Initial balance cannot be negative
Withdrew $20. New balance: $2.4
Failed to withdrew: Insufficient Funds!
Withdrew $100. New balance: $200
Failed to login: Wrong pin!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ ExceptionHandling.cpp -o ExceptionHandling

# Run (Linux / macOS)
./ExceptionHandling

# Run (Windows)
ExceptionHandling.exe
```

---

## 📁 Structure

```
ExceptionHandling/
├── ExceptionHandling.cpp   # Single-file program
└── README.md
```

---

## 📜 License

Released under the [MIT License](../LICENSE).

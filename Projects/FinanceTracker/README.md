<div align="center">

# 💰 Finance Tracker

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-OOP%20%7C%20Smart%20Pointers%20%7C%20STL%20%7C%20Exceptions-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A C++ banking simulation with multi-account management, transaction history, and structured exception handling.*

</div>

---

## 📌 Overview

Finance Tracker simulates a bank managing multiple accounts. It supports deposits, withdrawals, and transfers between accounts — each operation logged with a timestamp. Three custom exception types handle invalid operations cleanly, and all accounts are stored via `unique_ptr` in an `unordered_map`.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Create Account** | Register an account with a unique ID, owner name, and starting balance |
| 2 | **Deposit** | Add funds to an account and log the transaction |
| 3 | **Withdraw** | Remove funds with insufficient-balance protection |
| 4 | **Transfer** | Move funds between two accounts with full validation |
| 5 | **Summary** | Print all accounts with current balances |
| 6 | **Transaction History** | View timestamped history for any account by owner name |

---

## 🧠 Concepts Used

- `unordered_map<string, unique_ptr<Account>>` — O(1) account lookup with automatic memory management
- `unique_ptr` — exclusive ownership of each `Account` object inside the `Bank`
- `vector<Transaction>` — per-account history with timestamped entries
- `time_t` / `strftime` — formatted timestamps on each transaction
- Custom exceptions — `AccountException`, `InsufficientFundsException`, `InvalidTransferException`
- Multi-catch blocks — each operation catches all three exception types independently
- `make_pair` / `insert` — explicit insertion into `unordered_map`

---

## 🖥️ Example Output

```
=== Finance Tracker ===
Created account A001 (Alice) - Balance: $500
Created account A002 (Bob) - Balance: $200

Processing: Deposit $100 to A001
  Success. [A001] New balance: $600

Processing: Transfer $1000 from A001 to A002
  Failed: Insufficient funds for withdrawal.

Processing: Transfer $100 from A001 to A002
  Success. [A001] New balance: $500
  Success. [A002] New balance: $350

Processing: Withdraw $50 to A003
  Failed: Account not found.

Processing: Create account A001
  Failed: Account ID already exists.

--- Final Account Summary ---
A001 (Alice): $500
A002 (Bob): $350

--- Alice's Transaction History ---
[2026-07-30 14:22:01] DEPOSIT $100
[2026-07-30 14:22:01] TRANSFER_OUT $100
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ FinanceTracker.cpp -o FinanceTracker

# Run (Linux / macOS)
./FinanceTracker

# Run (Windows)
FinanceTracker.exe
```

---

## 📁 Structure

```
FinanceTracker/
├── FinanceTracker.cpp   # Single-file application
└── README.md
```

---

## ⚠️ Limitations

- Account data is **not saved** between runs
- No interactive menu — operations are hardcoded in `main`
- Duplicate account ID check is ID-based only, not owner-based

---

## 📜 License

Released under the [MIT License](../LICENSE).

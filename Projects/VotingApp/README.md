<div align="center">

# 🗳️ Voting App

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-map%20%7C%20vector%20%7C%20Duplicate%20Prevention-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line voting app with duplicate vote prevention and tie detection, written in C++.*

</div>

---

## 📌 Overview

Voting App runs a simple election between three candidates — Alice, Bob, and Carol. Voters cast votes by ID, results can be checked at any time, and the final result is declared when the election ends — handling both wins and ties.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Cast Vote** | Vote for a candidate by entering a unique voter ID and candidate name |
| 2 | **Duplicate Prevention** | Each voter ID can only vote once — repeat attempts are rejected |
| 3 | **Live Results** | View current vote counts at any time without ending the election |
| 4 | **Final Result** | Declares the winner or a tie when the election is closed |
| 5 | **Case-Insensitive Input** | Candidate names are normalized — `alice`, `ALICE`, and `Alice` all work |

---

## 🧠 Concepts Used

- `map<string, int>` — tracks voter IDs that have already voted
- `vector<pair<string, int>>` — stores candidates and their vote counts
- Duplicate check — `voters.find(voterID) != voters.end()` blocks repeat votes
- Tie detection — collects all candidates matching the highest vote count
- Name normalization — first letter uppercased, rest lowercased before lookup

---

## 🖥️ Example Output

```
=== Voting App ===
Candidates: Alice, Bob, Carol

1. Cast vote   2. Show results   3. End election
> 1
Voter id: v001
Candidate: alice
Vote recorded!

> 1
Voter id: v001
Candidate: bob
Error: This voter has already voted.

> 2
    --- Current Results ---
Alice: 1
Bob: 0
Carol: 0

> 3
    --- Final Results ---
Alice: 1
Bob: 0
Carol: 0
Result: WIN for Alice!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ VotingApp.cpp -o VotingApp

# Run (Linux / macOS)
./VotingApp

# Run (Windows)
VotingApp.exe
```

---

## 📁 Structure

```
VotingApp/
├── VotingApp.cpp   # Single-file application
└── README.md
```

---

## ⚠️ Limitations

- Candidates are hardcoded — Alice, Bob, and Carol only
- No persistence — results are lost when the program exits

---

## 📜 License

Released under the [MIT License](../LICENSE).

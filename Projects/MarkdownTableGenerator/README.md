<div align="center">

# 📋 Markdown Table Generator

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-File%20I%2FO%20%7C%20stringstream%20%7C%20String%20Parsing-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line Markdown table generator written in C++.*

</div>

---

## 📌 Overview

Markdown Table Generator takes headers and row data from the user, formats them into a valid Markdown table with centered headers and aligned columns, prints the result to the terminal, and saves it to `md-table.md`.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Flexible Input** | Values separated by comma-space (`', '`) or space (`' '`) — auto-detected |
| 2 | **Column Alignment** | All columns width-matched to the longest value for clean output |
| 3 | **Centered Headers** | Header text padded symmetrically with spaces |
| 4 | **File Save** | Table saved to `md-table.md` automatically alongside terminal output |
| 5 | **Row Validation** | Rejects rows where column count doesn't match header count |
| 6 | **Input Validation** | Handles empty headers, non-integer row counts, and negative values |

---

## 🧠 Concepts Used

- `stringstream` — tokenizes input by comma or space depending on which delimiter is detected
- `getline(ss, value, ',')` vs `ss >> value` — two parsing paths for the two delimiter modes
- `max_` global — tracks the longest cell value to set uniform column width
- Centered padding — `(max_ - header.size()) / 2` spaces on each side with odd-length correction
- `ofstream` — writes the formatted table to `md-table.md` in parallel with terminal output
- `modify()` — trims leading and trailing spaces from each parsed value

---

## 🖥️ Example Output

```
=== Markdown Table Generator ===
Headers (Separate with comma (', ') or space (' ')): Name, Age, City
Rows: 2
Row 1 (Separate with comma (', ') or space (' ')): Alice, 22, Baku
Row 2 (Separate with comma (', ') or space (' ')): Bob, 25, London

Output:
| Name  | Age  |  City  |
|-------|------|--------|
| Alice |  22  |  Baku  |
|  Bob  |  25  | London |

Saved to 'md-table.md' also!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ MarkdownTableGenerator.cpp -o MarkdownTableGenerator

# Run (Linux / macOS)
./MarkdownTableGenerator

# Run (Windows)
MarkdownTableGenerator.exe
```

---

## 📁 Structure

```
MarkdownTableGenerator/
├── MarkdownTableGenerator.cpp   # Single-file program
├── md-table.md                  # Auto-generated output file
└── README.md
```

---

## ⚠️ Limitations

- Delimiter auto-detection uses the first comma found — mixed delimiters in one row may parse unexpectedly
- All columns share the same width (the widest cell) — no per-column sizing

---

## 📜 License

Released under the [MIT License](../LICENSE).

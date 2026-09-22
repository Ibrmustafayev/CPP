<div align="center">

# 🔄 CSV to JSON

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-File%20I%2FO%20%7C%20JSON%20%7C%20CSV%20Parsing-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line CSV to JSON converter written in C++, using nlohmann/json.*

</div>

---

## 📌 Overview

CSV to JSON reads a `.csv` file, parses its headers and rows — including quoted fields with embedded commas — and writes a formatted `result.json` file with type-aware values. Numbers, booleans, nulls, and strings are all handled automatically.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **CSV Parsing** | Handles quoted fields, embedded commas, and escaped double quotes |
| 2 | **Type Detection** | Parses integers, floats, booleans (`true`/`false`), nulls, and strings automatically |
| 3 | **Ordered Output** | Uses `nlohmann::ordered_json` to preserve column order from the CSV |
| 4 | **Pretty Print** | JSON output is indented with 4 spaces via `.dump(4)` |
| 5 | **Extension Check** | Rejects non-`.csv` filenames before opening |

---

## 🧠 Concepts Used

- `nlohmann::ordered_json` — JSON library that preserves insertion order
- Quote-aware CSV parser — `inQuotes` flag handles commas inside quoted fields; `""` inside quotes is treated as a literal `"`
- `parseValue()` — type inference chain: null → leading-zero string → int → double → bool → string
- `ordered_json::array()` — builds a JSON array of objects, one per CSV row
- `file.dump(4)` — writes indented JSON to `result.json`
- `string::compare` — checks `.csv` extension without regex

---

## 🖥️ Example

**Input (`test.csv`):**
```
name,age,active,score
Alice,22,true,9.5
Bob,30,false,7.0
Carol,,true,0
```

**Output (`result.json`):**
```json
[
    {
        "name": "Alice",
        "age": 22,
        "active": true,
        "score": 9.5
    },
    {
        "name": "Bob",
        "age": 30,
        "active": false,
        "score": 7.0
    },
    {
        "name": "Carol",
        "age": null,
        "active": true,
        "score": 0
    }
]
```

---

## 🔧 Requirements & Setup

**Dependencies:** [nlohmann/json](https://github.com/nlohmann/json) — single header `json.hpp` must be in the same directory.

```bash
# Download json.hpp
curl -O https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp

# Compile
g++ CsvToJson.cpp -o CsvToJson

# Run (Linux / macOS)
./CsvToJson

# Run (Windows)
CsvToJson.exe
```

---

## 📁 Structure

```
CsvToJson/
├── CsvToJson.cpp   # Single-file converter
├── json.hpp        # nlohmann/json single-header library
├── test.csv        # Your input CSV file
├── result.json     # Auto-generated output
└── README.md
```

---

## ⚠️ Limitations

- Output is always written to `result.json` — filename is not configurable
- No support for multi-line cell values

---

## 📜 License

Released under the [MIT License](../LICENSE).

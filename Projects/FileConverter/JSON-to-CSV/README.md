<div align="center">

# 🔄 JSON to CSV

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-File%20I%2FO%20%7C%20JSON%20%7C%20CSV%20Serialization-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line JSON to CSV converter written in C++, using nlohmann/json.*

</div>

---

## 📌 Overview

JSON to CSV reads a `.json` file containing an array of objects, extracts the keys from the first object as headers, and writes a properly escaped CSV file to `result.csv`. Fields containing commas, quotes, or newlines are automatically quoted per the CSV spec.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Header Extraction** | Keys from the first JSON object become the CSV header row |
| 2 | **Type Handling** | Strings extracted directly; non-strings serialized via `.dump()` |
| 3 | **RFC 4180 Escaping** | Fields with commas, quotes, or newlines are wrapped in quotes; internal `"` doubled to `""` |
| 4 | **Missing Fields** | Keys absent from a row are written as empty cells |
| 5 | **Extension Check** | Rejects non-`.json` filenames before opening |

---

## 🧠 Concepts Used

- `nlohmann::ordered_json` — preserves key order from the source JSON
- `it.key()` — iterates over the first object's keys to build the header list
- `data[i].contains(headers[j])` — safely handles rows with missing keys
- `is_string()` / `.get<string>()` vs `.dump()` — avoids adding unwanted quotes around JSON strings
- `combine()` — serializes a row with RFC 4180 quoting: wraps field in `"..."` and escapes internal `"` as `""`
- `string::compare` — checks `.json` extension without regex

---

## 🖥️ Example

**Input (`test.json`):**
```json
[
    {"name": "Alice", "age": 22, "active": true},
    {"name": "Bob",   "age": 30, "active": false},
    {"name": "Carol", "age": null}
]
```

**Output (`result.csv`):**
```
name,age,active
Alice,22,true
Bob,30,false
Carol,null,
```

---

## 🔧 Requirements & Setup

**Dependencies:** [nlohmann/json](https://github.com/nlohmann/json) — single header `json.hpp` must be in the same directory.

```bash
# Download json.hpp
curl -O https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp

# Compile
g++ JsonToCsv.cpp -o JsonToCsv

# Run (Linux / macOS)
./JsonToCsv

# Run (Windows)
JsonToCsv.exe
```

---

## 📁 Structure

```
JsonToCsv/
├── JsonToCsv.cpp   # Single-file converter
├── json.hpp        # nlohmann/json single-header library
├── test.json       # Your input JSON file
├── result.csv      # Auto-generated output
└── README.md
```

---

## ⚠️ Limitations

- Input must be a JSON **array of objects** — other shapes are not supported
- Output is always written to `result.csv` — filename is not configurable
- Header order follows the first object's key order

---

## 📜 License

Released under the [MIT License](../LICENSE).

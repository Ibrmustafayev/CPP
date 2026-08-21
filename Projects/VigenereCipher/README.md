<div align="center">

# 🔑 Vigenere Cipher — Encoder

![Language](https://img.shields.io/badge/c%2B%2B-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-Cryptography%20%7C%20Strings%20%7C%20Modular%20Arithmetic-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A command-line Vigenère cipher encoder written in C++.*

</div>

---

## 📌 Overview

Vigenere Cipher takes a plaintext message and a keyword, then encodes the message using the classical Vigenère substitution cipher. Non-letter characters pass through unchanged, and letter case is preserved in the output.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Encoding** | Encrypts text using the Vigenère cipher with a repeating key |
| 2 | **Key Validation** | Rejects keys containing non-letter characters |
| 3 | **Case Preservation** | Uppercase letters encrypt to uppercase, lowercase to lowercase |
| 4 | **Non-letter Passthrough** | Spaces, punctuation, and numbers are passed through unchanged |

---

## 🧠 Concepts Used

- Vigenère cipher — each letter is shifted by the corresponding key letter's alphabet position
- Modular arithmetic — `(letterPosition + keyPosition) % 26` wraps around the alphabet
- `key[charNum % key.size()]` — cycles through the key for texts longer than the key
- `isalpha` / `isupper` / `toupper` / `tolower` — character classification and case handling
- `string::find` — maps characters to their 0-based alphabet index

---

## 🖥️ Example Output

```
    === Vigenere Cipher ===
Input: Hello, World!
Key: abc123
Error: Only letters are allowed for key!

Key: key
Plaintext:  Hello, World!
Ciphertext: Rijvs, Ambpb!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ encoder.cpp -o encoder

# Run (Linux / macOS)
./encoder

# Run (Windows)
encoder.exe
```

---

## 📁 Structure

```
VigenereCipher/
├── VigenereCipher.cpp   # Single-file encoder
└── README.md
```

---

## ⚠️ Limitations

- **Encoder only** — no decryption support yet
- Key must contain only letters — no digits or symbols

---

## 📜 License

Released under the [MIT License](../LICENSE).

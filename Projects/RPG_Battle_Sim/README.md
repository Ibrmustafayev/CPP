<div align="center">

# ⚔️ RPG Battle Simulation

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Concepts](https://img.shields.io/badge/Concepts-OOP%20%7C%20Smart%20Pointers%20%7C%20STL%20%7C%20Exceptions-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A fully randomized RPG combat simulation written in C++, combining OOP, smart pointers, STL, and exception handling.*

</div>

---

## 📌 Overview

RPG Battle Simulation runs an automated round-based battle between a party of three characters — two heroes and a villain. Each character has unique stats, abilities, and inventory. Actions are decided randomly each round, and the battle continues until either both heroes or the villain are defeated.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Warrior** | Physical attacker with Power Strike special — doubled damage at full health |
| 2 | **Mage** | Mana-based caster with Fireball special — falls back to weaker attacks when low on mana |
| 3 | **Inventory System** | Each character carries items (`Potion`, `Bomb`, `Elixir`) that deplete on use |
| 4 | **Randomized AI** | Actions chosen randomly each round via weighted `rand()` rolls |
| 5 | **Exception Handling** | `InvalidStatException` on construction, `EmptyInventoryException` on empty item use |
| 6 | **Smart Pointers** | `shared_ptr<Character>` for safe polymorphic party management |

---

## 🧠 Concepts Used

- Abstract base class — `Character` with pure virtual `attack()`, `specialMove()`, `printStatus()`
- Polymorphism — `Warrior` and `Mage` override all virtual methods with class-specific logic
- `shared_ptr` — party stored as `vector<shared_ptr<Character>>` with automatic cleanup
- `map<string, int>` — inventory tracking with automatic erasure at zero quantity
- Custom exceptions — `InvalidStatException` and `EmptyInventoryException` extend `runtime_error`
- Fallback logic — special moves degrade gracefully when mana or HP conditions aren't met
- `rand()` / `srand(time(NULL))` — seeded randomization for action selection each round

---

## 🖥️ Example Output

```
=== RPG Battle Simulation ===
Party: Kael (Warrior), Lira (Mage), Grukk (Warrior),

--- Round 1 ---
Kael attacks Grukk for 18 damage!
Lira casts a spell at Grukk for 12 damage! (Mana: 32/40)
Grukk uses Power Strike! Deals 40 damage to Kael!

--- Round 2 ---
Kael explodes Bomb at Grukk for 25 damage!
Lira uses Fireball! Deals 30 damage to Grukk! (Mana: 12/40)
Grukk attacks Lira for 20 damage!

=== Battle Over ===

--- Final Status ---
[Warrior] Kael - HP: 42/100 - ATK: 18
[Mage] Lira - HP: 0/70 - ATK: 12 - Mana: 12/40 - DEFEATED
[Warrior] Grukk - HP: 0/120 - ATK: 20 - DEFEATED
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC/G++ with C++11 or later

```bash
# Compile
g++ RPGBattleSimulation.cpp -o RPGBattleSimulation

# Run (Linux / macOS)
./RPGBattleSimulation

# Run (Windows)
RPGBattleSimulation.exe
```

---

## 📁 Structure

```
RPGBattleSimulation/
├── RPGBattleSimulation.cpp   # Single-file simulation
└── README.md
```

---

## ⚠️ Limitations

- Battle outcome is fully random — no player input
- Party composition is hardcoded in `main`
- No save/load or turn history

---

## 📜 License

Released under the [MIT License](../LICENSE).

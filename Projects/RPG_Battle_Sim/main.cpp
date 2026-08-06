#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;

class InvalidStatException : public runtime_error {
public:
    InvalidStatException(string msg) : runtime_error(msg) {}
};

class EmptyInventoryException : public runtime_error {
public:
    EmptyInventoryException(string msg) : runtime_error(msg) {}
};

class Character {
protected:
    string name;
    int health, maxHealth, attackPower;
    map<string, int> inventory;

public:
    Character(string name, int health, int maxHealth, int attackPower, const map<string, int> &inventory) : name(name), health(health), maxHealth(maxHealth), attackPower(attackPower), inventory(inventory) {
        if (health < 0) {throw InvalidStatException("Error: Health must be positive!\n");}
        else if (maxHealth < 0) {throw InvalidStatException("Error: Max health must be positive!\n");}
        else if (attackPower < 0) {throw InvalidStatException("Error: Attack power must be positive!\n");}
    }
    virtual ~Character() {}

    virtual void attack(Character &target) = 0;
    virtual void specialMove(Character &target) = 0;
    void takeDamage(int amount);
    bool isAlive() const;
    void heal(int amount);
    void addItem(string item, int qty);
    virtual void useItem(string item, Character &target);
    virtual void printStatus() const = 0;

    string getName() const {return name;}
    virtual string getType() const = 0;
};

class Warrior : public Character {
public:
    Warrior(string name, int health, int maxHealth, int attackPower, const map<string, int> &inventory) : Character(name, health, maxHealth, attackPower, inventory) {}
    ~Warrior() {}

    void attack(Character &target) override;
    void specialMove(Character &target) override;
    void useItem(string item, Character &target) override;
    void printStatus() const override;

    string getType() const override {return "Warrior";}
};

class Mage : public Character {
private:
    int mana;

public:
    Mage(string name, int health, int maxHealth, int attackPower, const map<string, int> &inventory, int mana) : Character(name, health, maxHealth, attackPower, inventory), mana(mana) {
        if (mana < 0) {throw InvalidStatException("Error: Mana must be positive!\n");}
    }

    void attack(Character &target) override;
    void specialMove(Character &target) override;
    void useItem(string item, Character &target) override;
    void printStatus() const override;

    string getType() const override {return "Mage";}
};

int main() {
    srand(time(NULL));

    vector<shared_ptr<Character>> party;
    int round = 1;

    try {
        shared_ptr<Warrior> ch1 = make_shared<Warrior>("Kael", 100, 100, 18, map<string, int>{{"Potion", 2}, {"Bomb", 1}});
        shared_ptr<Mage> ch2 = make_shared<Mage>("Lira", 70, 70, 12, map<string, int>{{"Potion", 1}, {"Elixir", 1}}, 40);
        shared_ptr<Warrior> ch3 = make_shared<Warrior>("Grukk", 120, 120, 20, map<string, int>{{"Potion", 2}});

        party.push_back(ch1);
        party.push_back(ch2);
        party.push_back(ch3);
    } catch (const InvalidStatException &e) {cout << e.what(); return 0;}
    
    auto &hero = party[0];
    auto &mage = party[1];
    auto &villian = party[2];
    int cmd;

    cout << "=== RPG Battle Simulation ===\nParty: ";
    for (auto &ch : party) {cout << ch -> getName() << " (" << ch -> getType() << "), ";}
    cout << "\n";

    while (1) {
        if ((!hero -> isAlive() && !mage -> isAlive()) || !villian -> isAlive()) {break;}

        cout << "\n--- Round " << round << " ---\n";
        for (auto i = 0; i < party.size(); i++) {
            if (!party[i] -> isAlive()) {cout << party[i] -> getName() << " has been defeated!\n"; continue;}

            if (party[i] == hero) {
                cmd = (rand() % 10) + 1;
                
                if (cmd == 1 || cmd == 5) {hero -> specialMove(*villian);}
                else if (cmd == 2 || cmd == 4 || cmd == 8) {
                    if (((rand() % 3) + 1) % 2 == 0) {hero -> useItem("Bomb", *villian);}
                    else {hero -> useItem("Potion", *villian);}
                }
                else {hero -> attack(*villian);}
            } else if (party[i] == mage && villian -> isAlive()) {
                cmd = (rand() % 10) + 1;

                if (cmd == 2 || cmd == 9) {mage -> specialMove(*villian);}
                else if (cmd == 4 || cmd == 7 || cmd == 8) {
                    if (((rand() % 2) + 1) % 2 == 0) {mage -> useItem("Elixir", *villian);}
                    else {mage -> useItem("Potion", *villian);}
                }
                else {mage -> attack(*villian);}
            } else if (party[i] == villian) {
                if ((rand() % 2) + 1 == 1) {
                    cmd = (rand() % 10) + 1;

                    if (cmd == 4 || cmd == 7) {villian -> specialMove(*hero);}
                    else if (cmd == 2 || cmd == 9) {villian -> useItem("Potion", *hero);}
                    else {villian -> attack(*hero);}
                } else {
                    cmd = (rand() % 10) + 1;
                    
                    if (cmd == 4 || cmd == 7) {villian -> specialMove(*mage);}
                    else if (cmd == 2 || cmd == 9) {villian -> useItem("Potion", *mage);}
                    else {villian -> attack(*mage);}
                }
            }
        }

        round++;
    }

    cout << "\n=== Battle Over ===\n\n--- Final Status ---\n";
    for (auto &ch : party) {ch -> printStatus();}

    return 0;
}

void Character :: takeDamage(int amount) {health = max(0, health - amount);}

bool Character :: isAlive() const {return health > 0;}

void Character :: heal(int amount) {health = min(maxHealth, health + amount);}

void Character :: addItem(string item, int qty) {inventory[item] += qty;}

void Character :: useItem(string item, Character &target) {
    if (inventory.find(item) == inventory.end()) {cout << "No " << item << " left! "; attack(target); return;}

    if (item == "Potion") {
        heal(20);
        cout << name << " drinks " << item << " and heals 20 HP! (HP: " << max(0, health) << "/" << maxHealth << ")\n";
    }
    
    inventory[item]--;
    if (inventory[item] == 0) {inventory.erase(item);}
}

void Warrior :: attack(Character &target) {
    target.takeDamage(attackPower);
    cout << name << " attacks " << target.getName() << " for " << attackPower << " damage!\n";
}

void Warrior :: specialMove(Character &target) {
    if (health >= maxHealth / 2) {
        target.takeDamage(attackPower * 2);
        cout << name << " uses Power Strike! Deals " << attackPower * 2 << " damage to " << target.getName() << "!\n";
    } else {
        target.takeDamage(attackPower);
        cout << name << " uses Power Strike at " << target.getName() << "! (HP < 50%, normal attack used instead: " << attackPower << " damage)!\n";
    }
}

void Warrior :: useItem(string item, Character &target) {
    try {
        auto it = inventory.find(item);
        if (it == inventory.end() || it -> second <= 0) throw EmptyInventoryException("No " + item + " left! ");

        if (item == "Bomb") {
            target.takeDamage(25);
            cout << name << " explodes Bomb at " << target.getName() << " for 25 damage!\n";
            it -> second--;
            if (it->second == 0) {inventory.erase(it);}
        } else {
            Character::useItem(item, target);
        }
    } catch (const EmptyInventoryException &e) {cout << e.what(); attack(target);}
}

void Warrior :: printStatus() const {
    cout << "[Warrior] " << name << " - HP: " << health << "/" << maxHealth << " - ATK: " << attackPower;
    if (!isAlive()) {cout << " - DEFEATED\n";}
    else {cout << "\n";}
}

void Mage :: attack(Character &target) {
    if (mana < 8) {
        target.takeDamage(attackPower / 2);
        cout << name << " casts a spell at " << target.getName() << " for " << attackPower / 2 << " damage! (out of mana, basic attack)\n";
    } else {
        target.takeDamage(attackPower);
        mana -= 8;
        cout << name << " casts a spell at " << target.getName() << " for " << attackPower << " damage! (Mana: " << mana << "/40)\n";
    } 
}

void Mage :: specialMove(Character &target) {
    if (mana >= 20 && health >= maxHealth / 2) {
        target.takeDamage(30);
        mana -= 20;
        cout << name << " uses Fireball! Deals 30 damage to " << target.getName() << "! (Mana: " << mana << "/40)\n";
    } else {
        if (mana < 20) {
            if (mana < 8) {
                target.takeDamage(attackPower / 2);
                cout << name << " uses Fireball at " << target.getName() << "! (Mana < 8, weak attack used instead: " << attackPower / 2 << " damage)!\n";
            } else {
                target.takeDamage(attackPower);
                mana -= 8;
                cout << name << " uses Fireball at " << target.getName() << "! (Mana < 20, normal attack used instead: " << attackPower << " damage)!\n";
            }
        } else {
            target.takeDamage(attackPower);
            mana -= 8;
            cout << name << " uses Fireball at " << target.getName() << "! (HP < 50%, normal attack used instead: " << attackPower << " damage)!\n";
        }
    }
}

void Mage :: useItem(string item, Character &target) {
    try {
        auto it = inventory.find(item);
        if (it == inventory.end() || it -> second <= 0) {throw EmptyInventoryException("No " + item + " left! ");}

        if (item == "Elixir") {
            mana = min(40, mana + 15);
            cout << name << " drinks " << item << " and increases mana 15 HP! (Mana: " << mana << "/40)\n";
            it -> second--;
            if (it -> second == 0) {inventory.erase(it);}
        } else {
            Character :: useItem(item, target);
        }
    } catch (const EmptyInventoryException &e) {cout << e.what(); attack(target);}   
}

void Mage :: printStatus() const {
    cout << "[Mage] " << name << " - HP: " << health << "/" << maxHealth << " - ATK: " << attackPower << " - Mana: " << mana << "/40";
    if (!isAlive()) {cout << " - DEFEATED\n";}
    else {cout << "\n";}
}

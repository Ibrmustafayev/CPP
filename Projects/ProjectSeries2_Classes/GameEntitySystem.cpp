#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

class Entity {
protected:
    string name;
    int maxHealth;
    int health;
    int attackPower;

public:
    Entity(string name, int maxHealth, int health, int attackPower) : name(name), maxHealth(maxHealth), health(health), attackPower(attackPower) {
        if (maxHealth < 100) {
            cout << "Max HP must be at least 100! Defaulting to 100.\n";
            this -> maxHealth = 100;
        }
        if (health < 100) {
            cout << "HP must be at least 100! Defaulting to 100.\n";
            this -> health = 100;
        }
        if (attackPower < 10) {
            cout << "Attack power must be at least 10! Defaulting to 10.\n";
            this -> attackPower = 10;
        }
    };
    virtual ~Entity() {}

    virtual void attack(Entity &target);
    void takeDamage(int amount);
    bool isAlive() const;
    virtual void printStatus() const;

    string getName() const;
    int getHealth() const;
};

class Player : public Entity {
private:
    int level;
    int experience;

public:
    Player(string name, int maxHealth, int health, int attackPower, int level, int experience) : Entity(name, maxHealth, health, attackPower), level(level), experience(experience) {
        if (level <= 0) {
            cout << "Level must be positive! Defaulting to Lv.1.\n";
            this -> level = 1;
        }
        if (experience < 0) {
            cout << "Experience must be non-negative! Defaulting to 0.\n";
            this -> experience = 0;
        }
    }
    ~Player() {}

    void attack(Entity &target) override;
    void gainExperience(int amount);
    void printStatus() const override;
};

class Enemy : public Entity {
protected:
    int expReward;

public:
    Enemy(string name, int maxHealth, int health, int attackPower, int expReward) : Entity(name, maxHealth, health, attackPower), expReward(expReward) {
        if (expReward < 10) {
            cout << "ExpReward must be at least 10! Defaulting to " << attackPower / maxHealth * 100 << ".\n";
            this -> expReward = (double)attackPower / maxHealth * 100;
        }
    }
    ~Enemy() {}

    int getExpReward() const;
    void printStatus() const override;
};

class Boss : public Enemy {
private:
    int rageThreshold;
    bool isEnraged;

public:
    Boss(string name, int maxHealth, int health, int attackPower, int expReward, int rageThreshold) : Enemy(name, maxHealth, health, attackPower, expReward), rageThreshold(rageThreshold), isEnraged(false) {
        if (rageThreshold <= 10) {
            cout << "Rage threshold must be at least 10! Defaulting to " << maxHealth / 4 <<".\n";
            this -> rageThreshold = maxHealth / 4;
        }
    }
    ~Boss() {}

    void attack(Entity &target) override;
    void printStatus() const override;
};

int main() {
    srand(time(0));

    Player p("Hero", 100, 100, 15, 1, 0);
    Boss b("Dragon King", 150, 150, 20, 200, 50);

    vector<Entity*> combatants = {&p, &b};

    int round = 1;
    cout << "\t=== Battle: " << p.getName() << " vs " << b.getName() << " ===\n"; 
    while (p.isAlive() && b.isAlive()) {
        cout << "> Round " << round << ":\n  ";
        p.attack(b);
        if (b.isAlive()) {cout << "  "; b.attack(p);}

        round++;
    }

    cout << "\n";
    if (p.isAlive()) {
        cout << b.getName() << " has been defeated!\n";
        p.gainExperience(b.getExpReward());
    } else {
        cout << p.getName() << " has been defeated!\n";
    }

    cout << "\n\t--- Final Status ---\nRound count: " << round - 1 << "\n";
    for (Entity* e : combatants) {e -> printStatus();}

    return 0;
}

//Entity
void Entity :: attack(Entity &target) {
    target.takeDamage(attackPower);
    cout << name << " attacks " << target.getName() << " for " << attackPower << " damage!\n";
}

void Entity :: takeDamage(int amount) {health = max(0, health - amount);}
bool Entity :: isAlive() const {return health > 0;}

void Entity :: printStatus() const {cout << "[Entity] " << name << " - HP: " << health << "/" << maxHealth << "\n";}
string Entity :: getName() const {return name;}
int Entity :: getHealth() const {return health;}

//Player
void Player :: attack(Entity &target) {
    int damage = attackPower;
    bool crit = rand() % 5 == 0;
    if (crit) {damage *= 2;}

    target.takeDamage(damage);
    cout << name << " attacks " << target.getName() << " for " << damage << " damage!";
    if (crit) {cout << " CRITICAL HIT!";}
    cout << "\n";
}

void Player :: gainExperience(int amount) {
    experience += amount;
    if (experience / (100 * level) >= 1) {
        level++;
        attackPower += 5;
        cout << name << " upgraded! New level: Lv." << level << "\n";
    }
}

void Player :: printStatus() const {cout << "[Player] " << name << " - Lv." << level << " - HP: " << health << "/" << maxHealth << "\n";}

//Enemy
int Enemy :: getExpReward() const {return expReward;}
void Enemy :: printStatus() const {cout << "[Enemy] " << name << " - HP: " << health << "/" << maxHealth << "\n";}

//Boss
void Boss :: attack(Entity &target) {
    if (!isEnraged && health < rageThreshold) {
        isEnraged = true;
        attackPower *= 2;
        cout << "DANGER! " << name << " is enraged! Attacks " << target.getName() << " for " << attackPower << " damage!\n  ";
    }

    target.takeDamage(attackPower);
    cout << name << " attacks " << target.getName() << " for " << attackPower << " damage!\n";
}

void Boss :: printStatus() const {
    cout << "[Boss] " << name << " - HP: " << health << "/" << maxHealth;
    (health < rageThreshold) ? cout << " (enraged)\n" : cout << "\n";
}

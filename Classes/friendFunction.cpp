#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    double cash;

public:
    Wallet(double cash) : cash(cash) {}
    friend class BankTeller;
    void printCash() const;
};

class BankTeller {
public:
    void depositToWallet(Wallet &w, double amount);
};

class Item {
private:
    string name;
    double price;

public:
    Item(string name, double price) : name(name), price(price) {}
    friend bool isCheaper(const Item &a, const Item &b);
    friend void printComparison(const Item &a, const Item &b);
};

int main() {
    Wallet w(100);
    BankTeller bt;

    w.printCash();
    bt.depositToWallet(w, 250);
    w.printCash();

    Item a("Laptop", 1000);
    Item b("Phone", 600);
    printComparison(a, b);

    return 0;
}

void Wallet :: printCash() const {
    cout << "Cash: " << cash << "\n";
}

void BankTeller :: depositToWallet(Wallet &w, double amount) {
    if (amount > 0) {w.cash += amount; cout << "Deposited $" << amount << ".\n";}
    else {cout << "Invalid amount!\n";}
}

bool isCheaper(const Item &a, const Item &b) {
    return a.price < b.price;
}

void printComparison(const Item &a, const Item &b) {
    cout << a.name << " is " << ((isCheaper(a, b)) ? "cheaper than " : "not cheaper than ") << b.name << ".\n";
}

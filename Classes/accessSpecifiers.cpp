#include <iostream>
using namespace std;

class BankAccount {
    private:
        string owner;
        double balance;
        string pin;

    public:
        BankAccount(string owner, double balance, string pin) : owner(owner), balance(balance), pin(pin) {}

        void deposit(double amount);
        void withdraw(double amount, string enteredPin);
        double getBalance(string enteredPin);
        void transferTo(BankAccount &other, double amount, string enteredPin);
};

int main() {
    BankAccount acc1("Alice", 400, "alice123");
    BankAccount acc2("Bob", 600, "b0b123");

    acc1.deposit(100);
    acc1.withdraw(100, "alic123");
    acc2.withdraw(100, "b0b123");
    acc1.transferTo(acc2, 200, "alice123");

    return 0;
}

void BankAccount :: deposit(double amount) {
    balance += amount;
    cout << "Deposited $" << amount << ". " << owner << "'s new balance: " << balance << "\n";
}

void BankAccount :: withdraw(double amount, string enteredPin) {
    if (getBalance(enteredPin) != -1) {
        if (amount < balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". " << owner << "'s new balance: " << balance << "\n";
        } else {
            cout << "No enough balance!\n";
        }
    } else {
        cout << "Wrong pin! Access denied.\n";
    }
}

double BankAccount :: getBalance(string enteredPin) {
    if (enteredPin == pin) {return balance;}
    return -1;
}

void BankAccount :: transferTo(BankAccount &other, double amount, string enteredPin) {
    if (getBalance(enteredPin) != -1) {
        if (amount < balance) {
            balance -= amount;
            other.balance += amount;
            cout << "Transfer successful! " << owner << ": $" << balance << ", " << other.owner << ": $" << other.balance << "\n";
        } else {
            cout << "No enough balance!\n";
        }
    } else {
        cout << "Wrong pin! Access denied.\n";
    }
}

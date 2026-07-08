#include <iostream>
#include <string>
using namespace std;

class Account {
    private:
        string owner;
        double balance;

    public:
        Account() {
            owner = "Unknown";
            balance = 0;
        }

        Account(string owner, double balance) {
            this -> owner = owner;
            this -> balance = balance;    
        }

        ~Account() {
            cout << "Account for " << owner << " closed.\n";
        }

        void deposit(double amount);
        void withdraw(double amount);
        void printBalance();
};

int main() {
    Account a1;
    Account a2("Alice", 500);

    a1.printBalance();
    a2.printBalance();
    
    a2.deposit(200);
    a2.withdraw(100);

    return 0;
}

void Account :: deposit(double amount) {
    balance += amount;
    cout << "Deposited $" << amount << ". New balance: $" << balance << "\n";
}

void Account::withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient funds! Balance: $" << balance << "\n";
        return;
    }
    
    balance -= amount;
    cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
}

void Account :: printBalance() {
    cout << "Balance: $" << balance << "\n";
}

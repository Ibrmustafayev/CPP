#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class InsufficientFundsException : public runtime_error {
public:
    InsufficientFundsException(string msg) : runtime_error(msg) {}
};

class WrongPinError : public runtime_error {
public:
    WrongPinError(string msg) : runtime_error(msg) {}
};

class BankAccount {
private:
    string owner;
    double balance;
    string pin;

public:
    BankAccount(string owner, double balance, string pin) : owner(owner), pin(pin) {
        if (balance < 0) {throw invalid_argument("Initial balance cannot be negative");}
        this->balance = balance;
    }

    void withdraw(double amount, string enteredPin);
    double getBalance(string enteredPin) const;
};

int main() {
    try {
        BankAccount acc1("John", -300, "1234");
    } catch (const invalid_argument &e) {
        cout << "Failed to create an account: " << e.what() << "\n";
    }

    try {
        BankAccount acc2("Bob", 22.4, "4321");
        acc2.withdraw(20, "4321");
        acc2.withdraw(20, "4321");
    } catch (const invalid_argument &e) {cout << "Failed to create an account: " << e.what() << "\n";}
    catch (const WrongPinError &e) {cout << "Failed to login: " << e.what() << "\n";}
    catch (const InsufficientFundsException &e) {cout << "Failed to withdrew: " << e.what() << "\n";}

    try {
        BankAccount acc3("Alice", 300, "1111");
        acc3.withdraw(100, "1111");
        acc3.withdraw(50, "1112");
    } catch (const invalid_argument &e) {cout << "Failed to create an account: " << e.what() << "\n";}
    catch (const WrongPinError &e) {cout << "Failed to login: " << e.what() << "\n";}
    catch (const InsufficientFundsException &e) {cout << "Failed to withdrew: " << e.what() << "\n";}

    return 0;
}

void BankAccount :: withdraw(double amount, string enteredPin) {
    if (enteredPin != pin) {throw WrongPinError("Wrong pin!\n");}
    if (amount > balance) {throw InsufficientFundsException("Insufficient Funds!\n");}
    balance -= amount;
    cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
}

double BankAccount :: getBalance(string enteredPin) const {
    if (pin != enteredPin) {throw WrongPinError("Wrong pin!\n");}
    return balance;
}

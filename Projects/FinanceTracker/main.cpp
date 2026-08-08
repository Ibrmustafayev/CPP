#include <iostream>
#include <string>
#include <time.h>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <memory>
using namespace std;

class AccountException : public runtime_error { 
public:
    AccountException(string msg) : runtime_error(msg) {}
};

class InsufficientFundsException : public runtime_error {
public:
    InsufficientFundsException(string msg) : runtime_error(msg) {}
};

class InvalidTransferException : public runtime_error {
public:
    InvalidTransferException(string msg) : runtime_error(msg) {}
};

class Transaction {
private:
    string type, note;
    double amount;
    time_t timestamp;
public:
    Transaction(string type, double amount) : type(type), amount(amount), timestamp(time(0)) {this -> note = "";}
    Transaction(string type, double amount, string note) : type(type), amount(amount), timestamp(time(0)), note(note) {}
    ~Transaction() {}

    void printTransaction() const;
};

class Account {
private:
    string id, owner;
    double balance;
    vector<Transaction> history;

public:
    Account(string id, string owner, double balance) : id(id), owner(owner), balance(balance) {}
    ~Account() {}

    void deposit(double amount);
    void withdraw(double amount);
    void printHistory() const;

    const string &getId() const {return id;}
    const string &getOwner() const {return owner;}
    double getBalance() const {return balance;}
    vector<Transaction> &getHistory() {return history;}
};

class Bank {
private:
    unordered_map<string, unique_ptr<Account>> accounts;

public:
    Bank() {}
    Bank(unordered_map<string, unique_ptr<Account>> accounts) : accounts(move(accounts)) {}
    ~Bank() {}

    void createAccount(string id, string owner, double startingBalance);
    Account &getAccount(string id);
    void deposit(string id, double amount);
    void withdraw(string id, double amount);
    void transfer(string fromId, string toId, double amount);
    void summary() const;
    void transactionHistory(string owner) const;
};

int main() {
    cout << "=== Finance Tracker ===\n";

    Bank bank;
    try {
        bank.createAccount("A001", "Alice", 500);
    } catch (const AccountException &e) {cout << e.what();}
    try {
        bank.createAccount("A002", "Bob", 200);
    } catch (const AccountException &e) {cout << e.what();}
    
    try {
        cout << "\nProcessing: Deposit $100 to A001\n";
        bank.deposit("A001", 100);
    } catch (const AccountException &e) {cout << e.what();}
    catch (const InsufficientFundsException &e) {cout << e.what();}
    catch (const InvalidTransferException &e) {cout << e.what();}
    
    try {
        cout << "\nProcessing: Deposit $50 to A002\n";
        bank.deposit("A002", 50);
    } catch (const AccountException &e) {cout << e.what();}
    catch (const InsufficientFundsException &e) {cout << e.what();}
    catch (const InvalidTransferException &e) {cout << e.what();}

    try {
        cout << "\nProcesssing: Transfer $1000 from A001 to A002\n";
        bank.transfer("A001", "A002", 1000);
    } catch (const AccountException &e) {cout << e.what();}
    catch (const InsufficientFundsException &e) {cout << e.what();}
    catch (const InvalidTransferException &e) {cout << e.what();}

    try {
        cout << "\nProcesssing: Transfer $100 from A001 to A002\n";
        bank.transfer("A001", "A002", 100);
    } catch (const AccountException &e) {cout << e.what();}
    catch (const InsufficientFundsException &e) {cout << e.what();}
    catch (const InvalidTransferException &e) {cout << e.what();}

    try {
        cout << "\nProcessing: Withdraw $50 to A003\n";
        bank.withdraw("A003", 50);
    } catch (const AccountException &e) {cout << e.what();}
    catch (const InsufficientFundsException &e) {cout << e.what();}
    catch (const InvalidTransferException &e) {cout << e.what();}

    try {
        cout << "\nProcessing: Create account A001\n";
        bank.createAccount("A001", "John", 100);
    } catch (const AccountException &e) {cout << e.what();}

    bank.summary();

    try {
        bank.transactionHistory("Alice");
    }catch (const AccountException &e) {cout << e.what();}

    return 0;
}

void Transaction :: printTransaction() const {
    char time[50];
    struct tm *lt = localtime(&timestamp);
    
    strftime(time, 50, "%F %T", lt);
    (note == "") ? (cout << "[" << time << "] " << type << " $" << amount << "\n") : (cout << time << " " << type << " $" << amount << " (" << note << ")\n");
}

void Account :: deposit(double amount) {
    if (amount < 0) {throw InvalidTransferException("  Failed: Invalid amount for depositing.\n");}

    balance += amount;  
    cout << "  Success. [" << id << "] New balance: $" << balance << "\n";
}

void Account :: withdraw(double amount) {
    if (amount > balance) {throw InsufficientFundsException("  Failed: Insufficient funds for withdrawal.\n");}
    if (amount < 0) {throw InvalidTransferException("  Failed: Invalid amount for withdrawal.\n");}

    balance -= amount;
    cout << "  Success. [" << id << "] New balance: $" << balance << "\n";
}

void Account :: printHistory() const {
    cout << "\n--- " << owner << "'s Transaction History ---\n";
    for (auto &t : history) {t.printTransaction();}
}

void Bank :: createAccount(string id, string owner, double startingBalance) {
    if (accounts.find(id) != accounts.end()) {throw AccountException("  Failed: Account ID already exists.\n");}

    accounts.insert(make_pair(id, make_unique<Account>(id, owner, startingBalance)));
    cout << "Created account " << id << " (" << owner << ") - Balance: $" << startingBalance << "\n";
}

Account &Bank :: getAccount(string id) {
    auto it = accounts.find(id);

    if (it == accounts.end()) {throw AccountException("  Failed: Account not found.\n");}
    return *(it -> second);
}

void Bank :: deposit(string id, double amount) {
    auto it = accounts.find(id);

    if (it == accounts.end()) {throw AccountException("  Failed: Account not found.\n");}
    it -> second -> deposit(amount);
    it -> second -> getHistory().push_back(Transaction("DEPOSIT", amount));
}

void Bank :: withdraw(string id, double amount) {
    auto it = accounts.find(id);

    if (it == accounts.end()) {throw AccountException("  Failed: Account not found.\n");}
    it -> second -> withdraw(amount);
    it -> second -> getHistory().push_back(Transaction("WITHDRAW", amount));
}

void Bank :: transfer(string fromId, string toId, double amount) {
    auto itFrom = accounts.find(fromId);
    auto itTo = accounts.find(toId);

    if (itFrom == accounts.end() || itTo == accounts.end()) {throw AccountException("  Failed: Account not found.\n");}
    if (fromId == toId || amount <= 0) {throw InvalidTransferException("  Failed: Invalid transfer.\n");}   

    itFrom -> second -> withdraw(amount);
    itTo -> second -> deposit(amount);
    itFrom -> second -> getHistory().push_back(Transaction("TRANSFER_OUT", amount));
    itTo -> second -> getHistory().push_back(Transaction("TRANSFER_IN", amount));
}

void Bank :: summary() const {
    cout << "\n--- Final Account Summary ---\n";
    for (auto it = accounts.begin(); it != accounts.end(); it++) {
        cout << it -> second -> getId() << " (" << it -> second -> getOwner() << "): $" << it -> second -> getBalance() << "\n"; 
    }
}

void Bank :: transactionHistory(string owner) const {
    for (auto it = accounts.begin(); it != accounts.end(); it++) {if (it -> second -> getOwner() == owner) {it -> second -> printHistory(); return;}}
    throw AccountException("Processing: Transaction history of " + owner + "\n  Failed: Account not found.\n");
}

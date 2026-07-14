#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    double baseSalary;

public:
    Employee(string name, double baseSalary) : name(name), baseSalary(baseSalary) {}

    double calculateSalary() const;
    void printInfo() const;
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string name, double baseSalary, double bonus) : Employee(name, baseSalary), bonus(bonus) {}

    double calculateSalary() const;
    void printInfo() const;
};

int main() {
    Employee e("John", 3000);
    e.printInfo();

    cout << "\n";

    Manager m("Alice", 3000, 1000);
    m.printInfo();

    return 0;
}

double Employee :: calculateSalary() const {return baseSalary;}
void Employee :: printInfo() const {cout << "Name: " << name << ", Base Salary: $" << baseSalary << "\nCalculated Salary: $" << calculateSalary() << "\n";}

double Manager :: calculateSalary() const {return baseSalary + bonus;}

void Manager::printInfo() const {
    Employee::printInfo();              
    cout << "Bonus: $" << bonus << "\n";
    cout << "Calculated Salary: $" << calculateSalary() << "\n";
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
protected:
    string name;
    double baseSalary;

public:
    Employee(string name, double baseSalary) : name(name), baseSalary(baseSalary) {}
    virtual ~Employee() {}

    virtual double calculateSalary() const;
    void printSalary() const;
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string name, double baseSalary, double bonus) : Employee(name, baseSalary), bonus(bonus) {}
    ~Manager() {}

    double calculateSalary() const override;
};

class Intern : public Employee {
private:
    double stipend;

public:
    Intern(string name, double baseSalary, double stipend) : Employee(name, baseSalary), stipend(stipend) {}
    ~Intern() {}
    
    double calculateSalary() const override;
};

int main() {
    vector<Employee*> emps = {new Employee("John", 3000), new Manager("Alice", 3000, 1000), new Intern("Bob", 2000, 800)};

    for (Employee* emp : emps) {emp -> printSalary(); cout << "\n";}
    for (Employee* emp : emps) {delete emp;}

    return 0;
}

void Employee :: printSalary() const {
    cout << "Name: " << name << ", Base Salary: $" << baseSalary << "\nCalculated Salary: $" << calculateSalary() << "\n";
}

double Employee :: calculateSalary() const {return baseSalary;}
double Manager :: calculateSalary() const {return baseSalary + bonus;}
double Intern :: calculateSalary() const {return stipend;}

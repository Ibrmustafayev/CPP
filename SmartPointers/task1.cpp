#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Employee {
protected:
    string name;
    double baseSalary;

public:
    Employee(string name, double baseSalary) : name(name), baseSalary(baseSalary) {}
    virtual ~Employee() {cout << "Employee " << name << " destroyed!\n";}

    virtual double calculateSalary() const;
    void printSalary() const;
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string name, double baseSalary, double bonus) : Employee(name, baseSalary), bonus(bonus) {}
    ~Manager() {cout << "Manager destroyed!\n";}

    double calculateSalary() const override;
};

class Intern : public Employee {
private:
    double stipend;

public:
    Intern(string name, double baseSalary, double stipend) : Employee(name, baseSalary), stipend(stipend) {}
    ~Intern() {cout << "Intern destroyed!\n";}

    double calculateSalary() const override;
};

int main() {
    vector<unique_ptr<Employee>> emps;
    emps.push_back(make_unique<Employee>("John", 3000));
    emps.push_back(make_unique<Manager>("Alice", 3000, 1000));
    emps.push_back(make_unique<Intern>("Bob", 2000, 800));

    for (auto &e : emps) {e -> printSalary(); cout << "\n";}

    cout << "--- Shared ptr demo ---\n";
    shared_ptr<Employee> sp1 = make_shared<Employee>("Carol", 3000);
    cout << "Use count after creation: " << sp1.use_count() << "\n";
    {
        shared_ptr<Employee> sp2 = sp1;
        cout << "Use count after copy: " << sp1.use_count() << "\n";
    }
    cout << "Use count after inner scope ends: " << sp1.use_count() << "\n";

    cout << "\n[Destructors firing automatically as staff vector is destroyed...]\n";

    return 0;
}

void Employee :: printSalary() const {cout << "Name: " << name << ", Base Salary: $" << baseSalary << "\nCalculated Salary: $" << calculateSalary() << "\n";}
double Employee :: calculateSalary() const {return baseSalary;}
double Manager :: calculateSalary() const {return baseSalary + bonus;}
double Intern :: calculateSalary() const {return stipend;}

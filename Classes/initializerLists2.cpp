#include <iostream>
#include <string>
using namespace std;

class Employee {
    private:
        const string id;
        string name;
        double salary;

    public:
        Employee(string id, string name) : Employee(id, name, 30000) {}

        Employee(string id, string name, double salary) : id(id), name(name), salary(salary)  {}

        ~Employee() {}

        void raiseSalary(double amount);
        void printInfo();
};

int main() {
    Employee e1("E1", "John");
    Employee e2("E2", "Alice", 50000);

    e1.printInfo();
    e2.printInfo();
    e2.raiseSalary(5000);
    e2.printInfo();

    return 0;
}

void Employee :: raiseSalary(double amount) {
    salary += amount;
    cout << "Raised " << name << "'s salary by $" << amount << "\n"; 
}

void Employee :: printInfo() {
    cout << "[" << id << "] " << name << " - $" << salary << "\n";
}

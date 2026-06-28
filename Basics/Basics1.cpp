#include <iostream>
#include <string>
using namespace std;

void greet(string name, string greeting = "Hello");
void doubleIt(int &number);

int main() {
    string name;
    int age, favNumber;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your favourite number: ";
    cin >> favNumber;

    cout << "\n";
    greet(name);
    cout << "\nYour age: " << age << "\n";
    doubleIt(favNumber);

    return 0;
}

void greet(string name, string greeting) {
    cout << greeting << ", " << name << "!"; 
}

void doubleIt(int &number) {
    number *= 2;
    cout << "Doubled favourite number: " << number;
}

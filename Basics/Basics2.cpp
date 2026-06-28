#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void uppercase(string city);
void checkNew(string city);
void nameModify(string name);

int main() {
    string name, city;
    int age;

    cout << "Full name: ";
    getline(cin, name);
    cout << "Age: ";
    cin >> age;
    cout << "City: ";
    cin.ignore();
    getline(cin, city);

    cout << "\nName length: " << name.length() << "\n";
    uppercase(name);
    cout << "\n";
    checkNew(city);

    cout << "\n\nSummary:\n";
    nameModify(name);
    cout << "\nAge: " << age << "\nCity: " << city;
    
    return 0;
}

void uppercase(string city) {
    cout << "Uppercase: ";
    for (char letter : city) {
        cout << (char)toupper(letter);
    }
}

void checkNew(string city) {
    string tempCity = city;
    for (char &letter : tempCity) {letter = tolower(letter);}
    
    cout << "City contains 'New': " << ((tempCity.find("new") != string :: npos) ? "Yes" : "No");
}

void nameModify(string name) {
    int index = name.find(' ');

    cout << "Name: ";
    for (int i = 0; i < name.length(); i++) {
        if (i == index) {cout << ". ";}
        if (i == 0 || i > index) {cout << name[i];}
    }
}

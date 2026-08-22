#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>
using namespace std;

size_t length;
const string lowercase = "qwertyuiopasdfghjklzxcvbnm";
const string upper = "QWERTYUIOPASDFGHJKLZXCVBNM";
const string digits = "1234567890";
const string symbols = "!@#$%^&*()_+<>";
string allowedChars, password;
char option;

int main() {
    cout << "\t=== Password Generator ===\n";

    while (1) {
        random_device rd;
        mt19937 g(rd() ^ chrono :: system_clock :: now().time_since_epoch().count());

        cout << "Length: ";
        cin >> length;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Invalid value!!!\n";
            continue;
        }

        if (length < 8) {
            cout << "Error: Length must be >= 8!\n";
            continue;
        }

        cout << "Include lowercase? (y/n): y  [auto]\n";
        allowedChars += lowercase;
        uniform_int_distribution<size_t> dist(0, lowercase.size() - 1);
        password += lowercase[dist(g)];

        cout << "Include uppercase? (y/n): ";
        cin >> option;
        if (option == 'y' || option == 'Y') {
            allowedChars += upper;
            uniform_int_distribution<size_t> dist(0, upper.size() - 1);
            password += upper[dist(g)];
            length--;
        }

        cout << "Include digits? (y/n): ";
        cin >> option;
        if (option == 'y' || option == 'Y') {
            allowedChars += digits;
            uniform_int_distribution<size_t> dist(0, digits.size() - 1);
            password += digits[dist(g)];
            length--;
        }

        cout << "Include special character? (y/n): ";
        cin >> option;
        if (option == 'y' || option == 'Y') {
            allowedChars += symbols;
            uniform_int_distribution<size_t> dist(0, symbols.size() - 1);
            password += symbols[dist(g)];
            length--;
        }

        shuffle(allowedChars.begin(), allowedChars.end(), g);

        for (size_t i = 0; i < length - 1; i++) {
            uniform_int_distribution<size_t> dist(0, allowedChars.size() - 1);
            password += allowedChars[dist(g)];
        }

        shuffle(password.begin(), password.end(), g);

        cout << "\nGenerated password: " << password << "\n\nGenerate another? (y/n): ";
        cin >> option;
        if (option == 'y' || option == 'Y') {
            password.clear();
            allowedChars.clear();
        } else break;
    }

    cout << "Goodbye!!!\n";

    return 0;
}

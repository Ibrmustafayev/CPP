#include <iostream>
#include <string>
using namespace std;

string binary;

int bin2dec();

int main() {
    cout << "\t=== Binary to Decimal ===\n";

    while (1) {
        cout << "Input ('q' to quit): ";
        cin >> binary;

        if (binary == "q") {cout << "Goodbye!!!\n"; break;}

        try {
            cout << binary << " (Binary) => " << bin2dec() << " (Decimal)\n\n";
        } catch (const invalid_argument &e) {cout << e.what();}
    }

    return 0;
}

int bin2dec() {
    int decimal = 0;

    for (char &c : binary) {
        if (c != '0' && c != '1') {throw invalid_argument("Error: Invalid value! Only '0' and '1' are allowed!\n\n");}
        decimal = decimal * 2 + (c - '0');
    }

    return decimal;
}

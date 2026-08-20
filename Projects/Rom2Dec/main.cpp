#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <regex>
using namespace std;

string roman;
unordered_map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

bool is_valid();
int rom2dec();

int main() {
    cout << "\t=== Roman to Decimal ===\n";

    while (1) {
        cout << "Input ('q' to quit): ";
        cin >> roman;

        if (roman == "q" || roman == "Q") {
            cout << "Goodbye!!!\n";
            break;
        }

        if (is_valid()) {
            cout << roman << " (Roman) => " << rom2dec() << " (Decimal)\n";
        } else {cout << "Error: Invalid value!\n";}

        cout << "\n";
    }

    return 0;
}

bool is_valid() {
    if (roman.empty()) {return false;}

    for (char &c : roman) {c = toupper(c);}

    static const regex pattern("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");
    return regex_match(roman, pattern);
}

int rom2dec() {
    int decimal = 0;

    for (int i = 0; i < roman.size(); i++) {
        if (i + 1 < roman.size() && values[roman[i]] < values[roman[i + 1]]) {decimal -= values[roman[i]];}
        else {decimal += values[roman[i]];}
    }

    return decimal;
}

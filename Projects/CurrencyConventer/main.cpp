#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

map<string, double> rate = {{"USD", 1.0}, {"EUR", 0.92}, {"GBP", 0.79}, {"JPY", 149.5}};
string amount, from, to;

bool isDouble();

int main() {
    cout << "\t=== Currency Converter ===\n(Rates relative to USD)\nSupported: USD, EUR, GBP, JPY\n\n";

    while (1) {
        cout << "Amount: ";
        cin >> amount;

        if (amount == "q" || amount == "Q") break;

        cout << "From: ";
        cin >> from;

        cout << "To: ";
        cin >> to;

        for (auto &c : from) c = toupper(c);
        for (auto &c : to) c = toupper(c);

        if (!isDouble()) {
            cout << "Error: Invalid value for amount!!!\n\n";
            continue;
        } else if (rate.find(from) == rate.end()) { 
            cout << "Error: Unknown currency code '" << from << "'\n\n";
            continue;
        } else if (rate.find(to) == rate.end()) {
            cout << "Error: Unknown currency code '" << to << "'\n\n";
            continue;
        }

        cout << "\n" << amount << " " << from << " = " << stod(amount) / rate[from] * rate[to] << " " << to << "\n\n";
    }

    cout << "\nGoodbye!!!\n";

    return 0;
}

bool isDouble() {
    if (amount.empty()) return false;

    char *endptr = nullptr;
    strtod(amount.c_str(), &endptr);

    return endptr != amount.c_str() && *endptr == '\0';
}

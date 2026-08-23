#include <iostream>
#include <string>
#include <regex>
using namespace std;

string pattern, test;
char option;

bool is_valid_pattern();

int main() {
    cout << "\t=== Regex Helper ===\n";

    while (1) {
        cout << "Enter a pattern: ";
        cin >> pattern;
        
        if (!is_valid_pattern()) break;
        
        regex pattern_(pattern);
        smatch match;

        while (1) {
            cout << "Enter a test string ('q' to stop): ";
            cin >> test;

            if (test == "q" || test == "Q") {
                cout << "\n";
                break;
            }

            cout << "\nFull match: " << (regex_match(test, pattern_) ? "Yes" : "No") << "\n";

            if (regex_search(test, match, pattern_)) {
                cout << "Search match: " << match[0] << "\n";

                for (size_t i = 1; i < match.size(); i++) cout << "  Group " << i << ": " << match[i] << "\n";
            } else cout << "Search match: No match found.\n";

            cout << "\n";
        }

        cout << "Try another pattern? (y/n): ";
        cin >> option;

        if (!(option == 'y' || option == 'Y')) break;
    }

    cout << "\nGoodbye!!!\n";

    return 0;
}

bool is_valid_pattern() {
    try {
        regex tmp(pattern);
        return true;
    } catch (const regex_error &e) {
        cout << "Error: Invalid regex pattern - " << e.what() << "\n";
        return false;
    }
}

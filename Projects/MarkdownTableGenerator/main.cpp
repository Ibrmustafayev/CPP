#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int max_ = 0;

vector<string> separate(string input);
void modify(string &value);

int main() {
    string headers_;
    int rowNum;
    vector<vector<string>> rows;
    bool save = true;

    cout << "\t=== Markdown Table Generator ===\n";

    while (1) {
        cout << "Headers (Separate with comma (', ') or space (' ')): ";
        getline(cin, headers_);

        if (!headers_.empty()) break;
        cout << "Error: Add at least one header!\n\n";
    }

    vector<string> headers = separate(headers_);

    while (1) {
        cout << "Rows: ";
        cin >> rowNum;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Input a non-negative number!\n\n";
        } else if (rowNum < 0) cout << "Error: Input a non-negative number!\n\n";
        else break;
    }

    cin.ignore();

    for(size_t i = 0; i < rowNum; i++) {
        string row;

        while (1) {
            cout << "Row " << i + 1 << " (Separate with comma (', ') or space (' ')): ";
            getline(cin, row);

            vector<string> current = separate(row);

            if (current.size() == headers.size()) {
                rows.push_back(current);
                break;
            }

            cout << "Error: Expected " << headers.size() << " values, but got " << current.size() << "!\n\n";
        }
    }

    ofstream file("md-table.md");
    if (!file.is_open()) save = false;

    cout << "\nOutput:\n";
    for (size_t i = 0; i < headers.size(); i++) {
        cout << "|" << string((max_ - headers[i].size()) / 2, ' ') << headers[i] << string(((max_ - headers[i].size()) % 2 == 0 ? (max_ - headers[i].size()) : (max_ - headers[i].size() + 1)) / 2, ' ');
        if (save) file << "|" << headers[i];
    }
    cout << "|\n";
    if (save) file << "|\n";

    for (size_t i = 0; i < headers.size(); i++) {
        cout << "|" << string(max_, '-');
        if (save) file << "|" << string(max_, '-');
    }
    cout << "|\n";
    if (save) file << "|\n";

    for (size_t i = 0; i < rows.size(); i++) {
        for (size_t j = 0; j < headers.size(); j++) {
            cout << "|" << string(max_ - rows[i][j].size(), ' ') << rows[i][j];
            if (save) file << "|" << rows[i][j];
        }
        cout << "|\n";
        if (save) file << "|\n";
    }

    if (save) {
        cout << "\nSaved to 'md-table.md' also!\n";
        file.close();
    }
    
    return 0;
}

vector<string> separate(string input) {
    vector<string> result;
    stringstream ss(input);
    string value;

    if (input.find(',') != string :: npos) {
        while (getline(ss, value, ',')) {
            modify(value);
            result.push_back(value);
            if (value.size() > max_) max_ = value.size();
        }
    } else {
        while (ss >> value) {
            modify(value);
            result.push_back(value);
            if (value.size() > max_) max_ = value.size();
        }
    }

    return result;
}

void modify(string &value) {
    size_t start = value.find_first_not_of(' ');
    size_t end = value.find_last_not_of(' ');

    if (start == string :: npos) {
        value = "";
        return;
    }

    value = value.substr(start, end - start + 1);
}

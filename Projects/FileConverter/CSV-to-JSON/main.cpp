#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"
using namespace std;
using ordered_json = nlohmann :: ordered_json;

vector<string> separate(const string &input);
ordered_json parseValue(const string &value);

int main() {
    string filename1, row;
    const string filename2 = "result.json";
    vector<string> fetchedRows, headers;
    vector<vector<string>> rows;

    cout << "\t=== CSV to JSON ===\nFilename (e.g. 'test.csv'): ";
    cin >> filename1;

    ifstream file1(filename1);
    if (!file1.is_open()) {
        cout << "Error: Unable to find " << filename1 << " in the proper file array!\n";
        return 0;
    }

    while (getline(file1, row)) fetchedRows.push_back(row);

    for (size_t i = 0; i < fetchedRows.size(); i++) {
        if (i == 0) headers = separate(fetchedRows[i]);
        else rows.push_back(separate(fetchedRows[i]));
    }

    file1.close();

    ordered_json result = ordered_json :: array();

    for (const auto &row : rows) {
        ordered_json data;
        for (size_t i = 0; i < headers.size(); i++) {
            if (row.size() > i) data[headers[i]] = parseValue(row[i]);
        }

        result.push_back(data);
    }
    
    ofstream file2(filename2);
    if (!file2.is_open()) {
        cout << "Error: Unable to create a .ordered_json file!\n";
        return 0;
    }

    file2 << result.dump(4);
    cout << "Converted successfully!\n";
    file2.close();

    return 0;
}

vector<string> separate(const string &input) {
    vector<string> result;
    string field;
    bool inQuotes = false;

    for (size_t i = 0; i < input.size(); i++) {
        char ch = input[i];

        if (ch == '"') {
            if (inQuotes && i + 1 < input.size() && input[i + 1] == '"') {
                field += '"';
                i++;
            } else inQuotes = !inQuotes;
        }
        else if (ch == ',' && !inQuotes) {
            result.push_back(field);
            field.clear();
        }
        else field += ch;
    }

    result.push_back(field);
    return result;
}

ordered_json parseValue(const string &value) {
    if (value.empty()) return nullptr;

    stringstream ss(value);
    double d;

    if (ss >> d && ss.eof()) {
        if (value.find('.') == string :: npos) return stoi(value);
        return d;
    }

    if (value == "true") return true;
    if (value == "false") return false;

    return value;
}

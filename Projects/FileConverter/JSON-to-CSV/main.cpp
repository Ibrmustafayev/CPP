#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"
using namespace std;
using ordered_json = nlohmann :: ordered_json;

bool hasJsonExtension(const string &filename);
string combine(const vector<string> &row);

int main() {
    string filename1;
    const string filename2 = "result.csv";
    vector<string> headers, rows;

    cout << "\t=== JSON to CSV ===\nFilename (e.g. test.json): ";
    cin >> filename1;

    if (!hasJsonExtension(filename1)) {
        cout << "Error: Type the name of any '.json' file!\n";
        return 0;
    }

    ifstream file1(filename1);
    if (!file1.is_open()) {
        cout << "Error: Unable to find " << filename1 << " in the proper file directory!\n";
        return 0;
    }

    ordered_json data;
    file1 >> data;
    file1.close();

    for (auto it = data[0].begin(); it != data[0].end(); it++) headers.push_back(it.key());
    rows.push_back(combine(headers));

    for (size_t i = 0; i < data.size(); i++) {
        vector<string> row;
        
        for (size_t j = 0; j < headers.size(); j++) {
            if (data[i].contains(headers[j])) {
                if (data[i][headers[j]].is_string()) row.push_back(data[i][headers[j]].get<string>());
                else row.push_back(data[i][headers[j]].dump());
            }
            else row.push_back("");
        }
        rows.push_back(combine(row));
    }

    ofstream file2(filename2);
    if (!file2.is_open()) {
        cout << "Error: Unable to create a '.csv' file!\n";
        return 0;
    }

    for (const auto &row : rows) file2 << row << "\n";
    cout << "Converted successfully!\n";
    file2.close();

    return 0;
}

bool hasJsonExtension(const string &filename) {
    const string ext = ".json";

    if (filename.size() >= ext.size()) return filename.compare(filename.size() - ext.size(), ext.size(), ext) == 0;
    return false;
}

string combine(const vector<string> &row) {
    string strRow;

    for (size_t i = 0; i < row.size(); i++) {
        string value = row[i];

        if (value.find('"') != string :: npos || value.find(',') != string :: npos || value.find('\n') != string :: npos) {
            string temp;

            for (char c : value) {
                if (c == '"') temp += "\"\"";
                else temp += c;
            }

            value = "\"" + temp + "\"";
        }

        strRow += value;
        if (i != row.size() - 1) strRow += ",";
    }

    return strRow;
}

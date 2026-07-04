#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

void add(vector<string> &names, vector<string> &phones, vector<string> &emails);
void search(const vector<string> &names, const vector<string> &phones, const vector<string> &emails);
void update(vector<string> &names, vector<string> &phones, vector<string> &emails);
void deleteContact(vector<string> &names, vector<string> &phones, vector<string> &emails);
void list(const vector<string> &names, const vector<string> &phones, const vector<string> &emails);
void countContacts(const vector<string> &names);
string lowercase(string str);

int main() {
    vector<string> names;
    vector<string> phones;
    vector<string> emails;
    string option;

    while (1) {
        cout << "=== Contact Book ===\n1. Add  2. Search  3. Update  4. Delete  5. List  6. Count  7. Exit\n\n";
        cout << "> ";
        cin >> option;
        
        if (option == "7") {cout << "Goodbye!!!"; break;}
        else if (option == "1") {add(names, phones, emails);}
        else if (option == "2") {search(names, phones, emails);}
        else if (option == "3") {update(names, phones, emails);}
        else if (option == "4") {deleteContact(names, phones, emails);}
        else if (option == "5") {list(names, phones, emails);}
        else if (option == "6") {countContacts(names);}
        else {cout << "Error: Invalid option!!!" << endl;}

        cout << "\n";
    }

    return 0;
}

void add(vector<string> &names, vector<string> &phones, vector<string> &emails) {
    string name;
    string phone;
    string email;
    
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Phone: ";
    cin >> phone;
    cout << "Email: ";
    cin >> email;
    
    names.push_back(name);
    phones.push_back(phone);
    emails.push_back(email);

    cout << "Contact added!" << endl;
}

void search(const vector<string> &names, const vector<string> &phones, const vector<string> &emails) {
    string target;
    cout << "Search: ";
    cin.ignore();
    getline(cin, target);
    target = lowercase(target);
    bool found = false;

    for (int i = 0; i < names.size(); i++) {
        if ((lowercase(names[i])).find(target) != string :: npos || (lowercase(phones[i])).find(target) != string :: npos || (lowercase(emails[i])).find(target) != string :: npos) {
            cout << "  Found: " << names[i] << " | " << phones[i] << " | " << emails[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Not Found!" << endl;
    }
}

void update(vector<string> &names, vector<string> &phones, vector<string> &emails) {
    list(names, phones, emails);
    if (names.size() == 0) {return;}
    
    int index, option;

    while (1) {
        cout << "\nIndex: ";
        cin >> index;
        if (index > 0 && index <= names.size()) {break;}
        cout << "Error: Invalid index (out of range)!!!" << endl;
    }
    
    while (1) {
        cout << "\nChoose to update:\n  1. Name  2. Phone  3. Email  4. Done\n\nOption: ";
        cin >> option;

        if (option == 4) {cout << "\nContact updated!" << endl; break;}
        else if (option == 1) {
            cout << "\nName: " << names[index - 1] << "\nNew name: ";
            cin.ignore();
            getline(cin, names[index - 1]);
        }
        else if (option == 2) {
            cout << "\nPhone: " << phones[index - 1] << "\nNew phone: ";
            cin >> phones[index - 1];
        }
        else if (option == 3) {
            cout << "\nEmail: " << emails[index - 1] << "\nNew email: ";
            cin >> emails[index - 1];
        }
        else {cout << "\nError: Invalid option (out of range)!!!";}
    }
}

void deleteContact(vector<string> &names, vector<string> &phones, vector<string> &emails) {
    list(names, phones, emails);
    if (names.size() == 0) {return;}

    int index;
    
    while (1) {
        cout << "\nIndex: ";
        cin >> index;
        if (index > 0 && index <= names.size()) {break;}
        cout << "Error: Invalid index (out of range)!!!" << endl;
    }

    names.erase(names.begin() + index - 1);
    phones.erase(phones.begin() + index - 1);
    emails.erase(emails.begin() + index - 1);

    cout << "Contact deleted!" << endl;
}

void list(const vector<string> &names, const vector<string> &phones, const vector<string> &emails) {
    cout << "Contact list:" << endl;
    if (names.size() == 0) {cout << "No contact" << endl;}
    
    vector<int> idx(names.size());
    for (int i = 0; i < idx.size(); i++) {idx[i] = i;}
    sort(idx.begin(), idx.end(), [&](int a, int b) {return names[a] < names[b];});

    for (int i = 0; i < names.size(); i++) {
        cout << "  " << i + 1 << ". " << names[idx[i]] << " | " << phones[idx[i]] << " | " << emails[idx[i]] << endl;
    }
}

void countContacts(const vector<string> &names) {
    cout << "Contact count: " << names.size() << endl;
}

string lowercase(string str) {
    for (char &letter : str) {letter = tolower(letter);}
    return str;
}

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <limits>
using namespace std;

struct Note {
    string title, body;
    time_t createdTime;
};

vector<Note> notes;
const string filename = "notes.txt";

void add();
void list();
void view();
void delete_();
void save();
void load();
void help();

int main() {
    char option;

    cout << "\t=== Notes App ===\n1. Add  2. List  3. View  4. Delete  5. Save  6. Load  7. Help  8. Exit";

    while (1) {
        cout << "\n> ";
        cin >> option;

        if (option == '8') {save(); break;}
        else if (option == '1') add();
        else if (option == '2') list();
        else if (option == '3') view();
        else if (option == '4') delete_();
        else if (option == '5') save();
        else if (option == '6') load();
        else if (option == '7') help();
        else cout << "Error: Invalid input!\nInput one of the options (1 - 7)\n";
    }

    cout << "Goodbye!!!\n";

    return 0;
}

void add() {
    string title, body;

    cout << "Note title: ";
    cin.ignore(numeric_limits<streamsize> :: max(), '\n');
    getline(cin, title);

    cout << "Note body: ";
    getline(cin, body);

    notes.push_back({title, body, time(0)});
    cout << "Added!\n";
}

void list() {
    if (notes.empty()) {
        cout << "None! Add a note first!\n";
        return;
    }

    for (size_t i = 0; i < notes.size(); i++) cout << i + 1 << ". " << notes[i].title << " - " << ctime(&notes[i].createdTime) << "\n";
}

void view() {
    if (notes.empty()) {
        cout << "None! Add a note first!\n";
        return;
    }

    cout << "\t--- Notes ---\n";
    for (size_t i = 0; i < notes.size(); i++) {
        cout << i + 1 << "] " << notes[i].title << " - " << ctime(&notes[i].createdTime);
        cout << "   " << notes[i].body << "\n";
    }
}

void delete_() {
    if (notes.empty()) {
        cout << "None! Add a note first!\n";
        return;
    }

    size_t idx;

    cout << "Index: ";
    cin >> idx;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
        
        cout << "Error: Invalid input!\n";
        return;
    }

    if (idx < 1 || idx > notes.size()) {
        cout << "Error: Invalid index!\n";
        return;
    }
    notes.erase(notes.begin() + idx - 1);

    notes.erase(notes.begin() + idx - 1);
    cout << "Deleted!\n";
}

void save() {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to save to " << filename << "!\n";
        return;
    }

    for (const auto &note : notes) file << note.title << "\n--\n" << note.body << "\n--\n" << note.createdTime << "\n---\n";
    file.close();
    cout << "Saved!\n";
}

void load() {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Unable to load from " << filename << "!\n";
        return;
    }

    notes.clear();

    string title, body, timeStr, delimiter;

    while (getline(file, title)) {
        if (!getline(file, delimiter) || delimiter != "--") break;

        if (!getline(file, body)) break;

        if (!getline(file, delimiter) || delimiter != "--") break;

        if (!getline(file, timeStr)) break;

        if (!getline(file, delimiter) || delimiter != "---") break;

        try {
            time_t createdTime = stoll(timeStr);

            notes.push_back({title, body, createdTime});
        } catch (...) {
            cout << "Error: Invalid time data in file!\n";
            break;
        }
    }

    file.close();
    cout << "Loaded!\n";
}

void help() {
    cout << "\n\t--- Help ---\n" << "1. Add    - Add a new note\n" << "2. List   - List all notes\n" << "3. View   - View all notes\n" << "4. Delete - Delete a note\n"
    << "5. Save   - Save notes to file\n" << "6. Load   - Load notes from file\n" << "7. Help   - Show this help\n" << "8. Exit   - Save and exit\n";
}

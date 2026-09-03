#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct Task {
    string task;
    bool done;
};

vector<Task> tasks;
const string filename = "todo.txt";

void add();
void list();
void complete();
void delete_();
void save();
void load();

int main() {
    char option;

    cout << "\t=== To-Do App ===\n1. Add  2. List  3. Complete  4. Delete  5. Save  6. Load  7. Exit";

    while (1) {
        cout << "\n> ";
        cin >> option;

        if (option == '7') {save(); break;}
        else if (option == '1') add();
        else if (option == '2') list();
        else if (option == '3') complete();
        else if (option == '4') delete_();
        else if (option == '5') save();
        else if (option == '6') load();
        else cout << "Error: Invalid input!\nInput one of the options (1 - 7)\n";
    }

    cout << "Goodbye!!!\n";

    return 0;
}

void add() {
    string task;

    cout << "Task: ";
    cin.ignore(numeric_limits<streamsize> :: max(), '\n');
    getline(cin, task);

    tasks.push_back({task, false});
    cout << "Added!\n";
}

void list() {
    if (tasks.size() < 1) {
        cout << "None! Add any task first!\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) cout << i + 1 << ". [" << (tasks[i].done ? "X" : " ") << "] " << tasks[i].task << "\n";
}

void complete() {
    if (tasks.size() < 1) {
        cout << "Failed! Add any task first!\n";
        return;
    }

    int idx;

    cout << "Index: ";
    cin >> idx;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        
        cout << "Error: Invalid input!\n";
        return;
    }
    if (idx > tasks.size() || idx < 1) {
        cout << "Error: Invalid index!\n";
        return;
    }

    if (tasks[idx - 1].done == true) cout << "Already completed!\n";
    else {
        tasks[idx - 1].done = true;
        cout << "Marked complete!\n";
    }
}

void delete_() {
    if (tasks.size() < 1) {
        cout << "Failed! Add any task first!\n";
        return;
    }

    int idx;

    cout << "Index: ";
    cin >> idx;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        
        cout << "Error: Invalid input!\n";
        return;
    }
    if (idx > tasks.size() || idx < 1) {
        cout << "Error: Invalid index!\n";
        return;
    }

    tasks.erase(tasks.begin() + idx - 1);
    cout << "Deleted successfully!\n";
}

void save() {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Failed to open " << filename << "!\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) file << tasks[i].done << " " << tasks[i].task << "\n";

    cout << "Saved to " << filename << "!\n";
    file.close();
}

void load() {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Failed to open " << filename << "!\n";
        return;
    }

    string line;
    tasks.clear();

    while (getline(file, line)) {
        size_t separator = line.find(' ');

        if (separator == string :: npos) continue;

        bool done = stoi(line.substr(0, separator));
        string task = line.substr(separator + 1);

        tasks.push_back({task, done});
    }

    cout << "Loaded from " << filename << "!\n";
    file.close();
}

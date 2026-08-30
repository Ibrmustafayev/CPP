#include <iostream>
#include <string>
#include <map>
#include <bitset>
using namespace std;

const int READ = 1 << 0;
const int WRITE = 1 << 1;
const int EXECUTE = 1 << 2;
const int DELETE = 1 << 3;

map<string, int> modes = {{"READ", READ}, {"WRITE", WRITE}, {"EXECUTE", EXECUTE}, {"DELETE", DELETE}};

int permissions = 0;
string command;
bool stop = false;

void converter();
void help();
void operation(const string &act, const string &mode);
void current();

int main() {
    cout << "\t=== Permission Manager ===\nCurrent permissions: (none) [0000]\n";

    while (!stop) {
        cout << "\n> ";
        getline(cin, command);

        converter();
    }

    return 0;
}

void converter() {
    string part1[4] = {"grant", "toggle", "check", "revoke"};
    string part2[4] = {"READ", "WRITE", "EXECUTE", "DELETE"};

    if (command == "exit") {
        cout << "Goodbye!!!\n";
        stop = true;
        return;
    } else if (command == "help") {
        help();
        return;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (command == part1[i] + " " + part2[j]) {
                operation(part1[i], part2[j]);
                return;
            }
        }
    }

    cout << "Error: Invalid command!!! Type 'help' for detailed info.\n";
}

void help() {
    cout << "\t--- Usage commands ---\n1] grant [permission] - Granting a permission in a bitmask means turning on a specific bit inside a binary number using a bitwise" 
    << "OR operator to allow a user or system to perform an action.\n2] toggle [permission] - To toggle a permission in a bitmask means to flip its state\n3] check [permission] - "
    << "Checking a permission in a bitmask is to see if a specific bit flag is turned on inside a single integer value\n4] revoke [permission] - Turn a specific permission bit OFF"
    << ", while leaving all other permissions unchanged.\n5] exit - To terminate the program\n6] help - To see a detailed info.\n\n- Permissions: READ | WRITE | EXECUTE | DELETE\n";
}

void operation(const string &act, const string &mode) {
    if (act == "grant") {
        permissions |= modes[mode];
        cout << "Granted " << mode << ". ";
        current();
    }
    else if (act == "toggle") {
        permissions ^= modes[mode];
        cout << "Toggled " << mode << ". ";
        current();
    }
    else if (act == "check") {
        if (permissions & modes[mode]) cout << "Can " << mode << "\n";
        else cout << mode << " is NOT set.\n";
    } else if (act == "revoke") {
        permissions &= ~modes[mode];
        cout << "Revoked " << mode << ". ";
        current();
    }
}

void current() {
    bool first = true;

    cout << "Current: ";

    if (permissions & READ) {
        cout << "READ";
        first = false;
    }

    if (permissions & WRITE) {
        if (!first) cout << ", ";
        cout << "WRITE";
        first = false;
    }

    if (permissions & EXECUTE) {
        if (!first) cout << ", ";
        cout << "EXECUTE";
        first = false;
    }

    if (permissions & DELETE) {
        if (!first) cout << ", ";
        cout << "DELETE";
        first = false;
    }

    if (first) cout << "(none)";

    cout << " [" << bitset<4>(permissions) << "]\n";
}

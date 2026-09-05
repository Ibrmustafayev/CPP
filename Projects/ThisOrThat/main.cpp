#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
using namespace std;

random_device rd;
mt19937 g(rd() ^ chrono :: system_clock :: now().time_since_epoch().count());

struct Option {
    string name;
    int matched;
};

vector<Option> options;
int roundNum = 1;

void game();

int main() {
    const vector<string> footballers = {"Messi", "Ronaldo", "Mbappe", "Neymar", "Haaland", "Salah", "Kane", "Modric"};
    const vector<string> cities = {"Paris", "London", "New York", "Istanbul", "Tokyo", "Barcelona", "St.Petersburg", "Cape Town"};
    const vector<string> films = {"The Godfather", "The Shawshank Redemption", "The Dark Knight", "Fight Club", "Shutter Island", "Star Wars", "Inception", "Seven"};
    char choice;

    cout << "\t=== This or That ===";
    while (1) {
        cout << "\nChoose a category (1 - 3): 1. Footballers  2. Cities  3. Films\n> ";
        cin >> choice;

        if (choice == '1') for (auto f : footballers) options.push_back({f, 0});
        else if (choice == '2') for (auto c : cities) options.push_back({c, 0});
        else if (choice == '3') for (auto f : films) options.push_back({f, 0});
        else {
            cout << "Error: Invalid choice!\n";
            continue;
        }

        break;
    }

    while (options.size() != 1) {
        game();
        roundNum++;
    }

    cout << "\nChampion: " << options[0].name;

    return 0;
}

void game() {
    cout << "\n\t--- Round " << roundNum << ((options.size() == 2) ? " (Final) ---" : " ---");

    shuffle(options.begin(), options.end(), g);

    for (size_t i = 0; i < options.size(); i++) {
        char choice;

        while (1) {
            cout << "\n" << options[i].name << " or " << options[i + 1].name << "? (1/2): ";
            cin >> choice;

            if (choice == '1') {
                cout << "Winner: " << options[i].name << "\n";
                options.erase(options.begin() + i + 1);
                break;
            } else if (choice == '2') {
                cout << "Winner: " << options[i + 1].name << "\n";
                options.erase(options.begin() + i);
                break;
            } else cout << "Error: Invalid choice!\n";
        }
    }
}

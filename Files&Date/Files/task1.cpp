#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Player {
private:
    string name;
    int level;

public:
    Player(string name, int level) : name(name), level(level) {
        if (level < 0) {
            cout << "Level muist be non-negative! Defaulting to 1!\n";
            this -> level = 1;
        }
    }
    ~Player() {}

    string getName() const;
    int getLevel() const;
};

void saveAll(const vector<Player> &players, const string filename);
vector<Player> loadAll(const string filename);

int main() {
    vector<Player> players = {Player("Alice", 5), Player("Bob", 3), Player("Carol", 8)};
    const string filename = "players.txt";

    cout << "Original players:\n";
    for (Player player : players) {cout << "  " << player.getName() << " - Lv." << player.getLevel() << "\n";}

    cout << "\n";
    saveAll(players, filename);
    cout << "\n";

    vector<Player> players2 = loadAll(filename);
    cout << "Reloaded players:\n";
    for (Player player : players2) {cout << "  " << player.getName() << " - Lv." << player.getLevel() << "\n";}
 
    return 0;
}

string Player :: getName() const {return name;}
int Player :: getLevel() const {return level;}

void saveAll(const vector<Player> &players, const string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open " << filename << "\n";
        return;
    }

    for (Player player : players) {
        file << player.getName() << " " << player.getLevel() << "\n";
    }

    cout << "Saved to " << filename << "!\n";
    file.close();
}

vector<Player> loadAll(const string filename) {
    vector<Player> players;
    
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open " << filename << "!\n";
        return players;
    }

    string name;
    int level;

    while (file >> name >> level) {players.push_back(Player(name, level));}

    file.close();
    return players;
}

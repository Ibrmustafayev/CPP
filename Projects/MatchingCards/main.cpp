#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <random>
#include <cctype>
#include <unordered_map>
#include <chrono>
using namespace std;

struct Card {
    char value;
    bool revealed;
    bool matched;
};

vector<Card> cards = {Card{'A', false, false}, Card{'A', false, false}, Card{'H', false, false}, Card{'H', false, false},
                    Card{'@', false, false}, Card{'@', false, false}, Card{'$', false, false}, Card{'$', false, false},
                    Card{'#', false, false}, Card{'#', false, false}, Card{'W', false, false}, Card{'W', false, false},
                    Card{'M', false, false}, Card{'M', false, false}, Card{'7', false, false}, Card{'7', false, false}};
unordered_map<string, int> values = {{"a0", 0}, {"a1", 4}, {"a2", 8}, {"a3", 12}, {"b0", 1}, {"b1", 5}, {"b2", 9}, {"b3", 13}, 
                                {"c0", 2}, {"c1", 6}, {"c2", 10}, {"c3", 14}, {"d0", 3}, {"d1", 7}, {"d2", 11}, {"d3", 15}};              

void board();
void game();
bool is_valid(string &card);
bool end();

int main() {
    random_device rd;
    mt19937 g(rd() ^ chrono :: system_clock :: now().time_since_epoch().count());
    shuffle(cards.begin(), cards.end(), g);

    while (!end()) {
        game();
        Sleep(1000);
    }

    cout << "\n\t=== WON ===\n";

    return 0;
}

void board() {
    system("cls");

    cout << "\t=== Matching Cards ===\n\n\t   a   b   c   d\n";

    for (int i = 0; i < 4; i++) {
        cout << "\t" << i << " ";
        for (int j = i * 4; j < i * 4 + 4; j++) {
            if (cards[j].revealed || cards[j].matched) cout << "[" << cards[j].value << "] ";
            else cout << "[ ] ";
        }

        cout << "\n";
    }
}

void game() {
    string card1, card2;

    board();

    while (1) {
        cout << "\nCard 1 to open: ";
        cin >> card1;

        if (!is_valid(card1)) {
            cout << "Error: Invalid input!!!\n";
            continue;
        }

        if (cards[values[card1]].revealed || cards[values[card1]].matched) {
            cout << "Error: Choose an unopened card!!!\n";
            continue;
        }

        cards[values[card1]].revealed = true;
        break;
    }

    board();

    while (1) {
        cout << "\nCard 2 to open: ";
        cin >> card2;

        if (!is_valid(card2)) {
            cout << "Error: Invalid input!!!\n";
            continue;
        }

        if (cards[values[card2]].revealed || cards[values[card2]].matched) {
            cout << "Error: Choose an unopened card!!!\n";
            continue;
        }

        cards[values[card2]].revealed = true;
        break;
    }

    board();

    if (cards[values[card1]].value == cards[values[card2]].value) {
        cards[values[card1]].matched = true;
        cards[values[card2]].matched = true;
    } else {
        cards[values[card1]].revealed = false;
        cards[values[card2]].revealed = false;
    }
}

bool is_valid(string &card) {
    for (char &c : card) c = tolower(c);

    return values.find(card) != values.end();
}

bool end() {
    for (auto card : cards) if (card.matched == false) return false;
    return true;
}

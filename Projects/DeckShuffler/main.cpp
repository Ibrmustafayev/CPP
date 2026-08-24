#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Card {
    string suit;
    int value;
};

Card cards[52];
int number, handValue;

void add_cards();

int main() {
    srand(time(0));

    cout << "\t=== Deck Shuffler ===\n";

    add_cards();
    
    random_device rd;
    mt19937 g(rd() ^ chrono :: system_clock :: now().time_since_epoch().count());

    shuffle(cards, cards + 52, g);

    cout << "How many cards to deal? ";
    cin >> number;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Invalid value!!! Defaulting to 7.\n";
        number = 7;
    }

    if (!(number > 0 && number <= 52)) {
        cout << "Error: Invalid value!!! Defaulting to 7.\n";
        number = 7;
    }


    vector<Card> dealCards(number);;
    
    for (size_t i = 0; i < number; i++) {
        int idx = rand() % 52;
        dealCards[i] = cards[idx];
    }

    cout << "\nYour hand:\n";
    for (size_t i = 0; i < number; i++) {
        cout << "   " << dealCards[i].suit << "\n";
        handValue += dealCards[i].value;
    }
    cout << "\nHand value: " << handValue << "\n";

    return 0;
}

void add_cards() {
    const vector<string> part1 = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    const vector<string> part2 = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for (size_t i = 0; i < part1.size(); i++) {
        for (size_t j = 0; j < part2.size(); j++) {
            int index = i * 4 + j;
            cards[index].suit = part1[i] + " of " + part2[j];

            if (i > 0 && i <= 9) cards[index].value = i + 1;
            else if (i == 0) cards[index].value = 11;
            else cards[index].value = 10;
        }
    }
}

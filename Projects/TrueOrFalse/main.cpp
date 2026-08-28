#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
using namespace std;

vector<pair<string, bool>> questions = {
    {"The Great Wall of China is visible from the Moon with the naked eye.", false},
    {"A group of flamingos is called a flamboyance.", true},
    {"Water boils at 100°C at sea level.", true},
    {"Lightning never strikes the same place twice.", false},
    {"The human body has 206 bones in adulthood.", true},
    {"Australia is both a country and a continent.", true},
    {"Gold is heavier than silver.", true},
    {"The capital of Australia is Sydney.", false},
    {"Octopuses have three hearts.", true},
    {"Bananas are technically berries.", true}
};
int score = 0, qNo = 1;
char option;

int main() {
    cout << "\t=== True or False ===\n";

    random_device rd;
    mt19937 g(rd() ^ chrono :: system_clock :: now().time_since_epoch().count());
    shuffle(questions.begin(), questions.end(), g);
    
    cout << boolalpha;

    for (auto question : questions) {
        cout << qNo << "] " << question.first << "\n";
        cout << "True or False (t/f): ";
        cin >> option;

        if (option == 't' || option == 'T') {
            if (question.second) {
                cout << "Correct!!!\n";
                score += 10;
            } else {
                cout << "Wrong!!!\n";
            }
        }
        else if (option == 'f' || option == 'F') {
            if (!question.second) {
                cout << "Correct!!!\n";
                score += 10;
            } else {
                cout << "Wrong!!!\n";
            }
        }
        else {
            cout << "Invalid!!!\n";
        }

        cout << "Answer: " << question.second << "\n\n";

        qNo++;
    }

    cout << "Score: " << score << "/100\nTotal questions: 10\nCorrect: " << score / 10 << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;

struct Flashcard {
    string question;
    string answer;
    bool needsReview;
};

vector<Flashcard> round1 = {{"What is the capital of France?", "Paris", false}, {"What is 5 + 7?", "12", false}, {"How many days are in a week?", "7", false},
    {"What planet do we live on?", "Earth", false}, {"What is the largest ocean on Earth?", "Pacific Ocean", false}};

vector<Flashcard> round2 = {{"What is 15 * 12?", "180", false}, {"What is the chemical symbol for gold?", "Au", false}, {"How many sides does a hexagon have?", "6", false},
    {"Who wrote Romeo and Juliet?", "William Shakespeare", false}, {"What is the square root of 144?", "12", false}};

vector<Flashcard> round3 = {{"What is the smallest prime number?", "2", false}, {"What is the capital of Australia?", "Canberra", false},
    {"What is pi rounded to two decimal places?", "3.14", false}, {"Which element has the atomic number 1?", "Hydrogen", false},
    {"What is the largest planet in our solar system?", "Jupiter", false}};

char option;
vector<int> correctsInRounds;

void playRound(vector<Flashcard> &round, string text);

int main() {
    cout << "\t=== Flashcards ===";

    for (int i = 1; i <= 3; i++) {
        switch (i) {
            case 1: playRound(round1, "Round 1"); break;
            case 2 : playRound(round2, "Round 2"); break;
            case 3 : playRound(round3, "Round 3"); break;
        }

        Sleep(1000);
    }

    cout << "\n\t--- Final Summary ---\n";
    for (int i = 0; i < 3; i++) cout << "Round " << i + 1 << ": " << correctsInRounds[i] << "\n";

    return 0;
}

void playRound(vector<Flashcard> &round, string text) {
    int correctQuestions = round.size();

    cout << "\n\t--- " << text << " ---";

    for (int i = 0; i < round.size(); i++) {
        cout << "\n> Card " << i + 1 << "/" << round.size() << "\nQ: " << round[i].question << "\n[Press 'Enter' to reveal answer]\n";

        if (_getch()) {
            Sleep(100);

            cout << "\nA: " << round[i].answer << "\nDid you get it right? (y/n): ";
            cin >> option;

            if (option == 'y' || option == 'Y') cout << "Correct!\n";
            else {
                cout << "Marked for review.\n";
                round[i].needsReview = true;
                correctQuestions--;
            }
        }
    }

    Sleep(1000);

    cout << "\n\t--- " << text << " Summary ---\nCorrect: " << correctQuestions << "/" << round.size() << "\nReviewing " << round.size() - correctQuestions << (round.size() - correctQuestions == 1 ? " card" : " cards") << " again...\n";
    
    bool isFirst = true;
    while (1) {
        bool allTrue = true;

        for (int i = 0; i < round.size(); i++) {
            if (round[i].needsReview == true) {
                allTrue = false;
                if (!isFirst) cout << "\nOnce more....\n";
                cout << "\n> Card " << i + 1 << "/" << round.size() << "\nQ: " << round[i].question << "\n[Press 'Enter' to reveal answer]\n";

                if (_getch()) {
                    Sleep(100);

                    cout << "\nA: " << round[i].answer << "\nDid you get it right? (y/n): ";
                    cin >> option;

                    if (option == 'y' || option == 'Y') {
                        cout << "Correct!\n";
                        round[i].needsReview = false;
                    } else {
                        cout << "Marked for review again.\n";
                    }
                }
            }
        }

        isFirst = false;
        if (allTrue) break;
    }

    correctsInRounds.push_back(correctQuestions);
}

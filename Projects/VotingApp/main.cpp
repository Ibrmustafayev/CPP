#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;

map<string, int> voters;
vector<pair<string, int>> results = {{"Alice", 0}, {"Bob", 0}, {"Carol", 0}};

void vote();
void showResults();
void result();

int main() {
    char option;

    cout << "\t=== Voting App ===\nCandidates: Alice, Bob, Carol\n\n1. Cast vote   2. Show results   3. End election";

    while (1) {
        cout << "\n> ";
        cin >> option;

        if (option == '1') vote();
        else if (option == '2') {
            cout << "\t--- Current Results ---\n";
            showResults();
        } else if (option == '3') {
            cout << "\t--- Final Results ---\n";
            showResults();
            result();
            break;
        } else cout << "Error: Invalid option. Choose a valid option (1 - 3)\n";
    }

    return 0;
}

void vote() {
    string voterID, candidate;
    
    cout << "Voter id: ";
    cin >> voterID;

    if (voters.find(voterID) != voters.end()) {
        cout << "Error: This voter has already voted.\n";
        return;
    }

    cout << "Candidate: ";
    cin >> candidate;

    for (size_t i = 0; i < candidate.size(); i++) {
        if (i == 0) candidate[i] = toupper(candidate[i]);
        else candidate[i] = tolower(candidate[i]);
    }
    for (size_t i = 0; i < results.size(); i++) {
        if (results[i].first == candidate) {
            results[i].second++;
            voters[voterID] = 1;
            cout << "Vote recorded!\n";
            return;
        }
    }

    cout << "Error: Invalid candidate.\n";
}

void showResults() {
    for (size_t i = 0; i < results.size(); i++) cout << results[i].first << ": " << results[i].second << "\n";
}

void result() {
    int totalVotes = 0;
    for (auto &r : results) totalVotes += r.second;

    if (totalVotes == 0) {
        cout << "Result: No votes were cast. No winner can be declared.\n";
        return;
    }

    int maxIdx = 0;
    vector<string> winner;

    for (size_t i = 1; i < results.size(); i++) if (results[i].second > results[maxIdx].second) maxIdx = i;
    winner.push_back(results[maxIdx].first);

    for (size_t i = 0; i < results.size(); i++) {
        if (i == maxIdx) continue;
        if (results[i].second == results[maxIdx].second) winner.push_back(results[i].first);
    }

    if (winner.size() == 1) cout << "Result: WIN for " << winner[0] << "!\n";
    else {
        bool first = true;

        cout << "Result: TIE for ";
        for (auto w : winner) {
            if (!first) cout << " and ";
            cout << w;
            first = false;
        }
        cout << "!\n";
    }
}

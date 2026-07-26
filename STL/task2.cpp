#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    unordered_map<string, int> um;
    vector<pair<string, int>> v;
    vector<int> numbers;
    string sentence, word, numLine;
    int number;

    cout << "Enter a sentence: ";
    getline(cin, sentence);
    stringstream ss(sentence);
    while (ss >> word) {um[word]++;}
    cout << "Word frequencies:\n";
    for (auto word : um) {cout << "  " << word.first << ": " << word.second << "\n";}

    cout << "\nEnter numbers: ";
    getline(cin, numLine);
    stringstream ssNum(numLine);
    while (ssNum >> number) {numbers.push_back(number);}

    cout << "\nEven count: " << count_if(numbers.begin(), numbers.end(), [](int x) {return x % 2 == 0;}) << "\n";
    auto it = find_if(numbers.begin(), numbers.end(), [](int x) {return x > 5;});
    cout << "First number > 5: " << ((it != numbers.end()) ? to_string(*it) : "Not found!") << "\n";
    cout << "All positive? " << ((all_of(numbers.begin(), numbers.end(), [](int x) {return x > 0;}) == 1) ? "Yes" : "No") << "\n";

    vector<int> squared(numbers.size());
    transform(numbers.begin(), numbers.end(), squared.begin(), [](int x) {return x * x;});
    cout << "\nSquared: ";
    for (auto number : squared) {cout << number << " ";}

    v.push_back({"Bob", 90});
    v.push_back({"Alice", 85});
    v.push_back({"Carol", 72});
    sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) {return a.second > b.second;});

    cout << "\n\nLeaderboard (sorted by score desc):\n";
    for (auto person : v) {cout << "  " << person.first << ": " << person.second << "\n";}

    return 0;
}

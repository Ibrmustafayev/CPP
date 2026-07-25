#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
using namespace std;

int main() {
    map<string, int> words;
    pair<string, int> mostUsed = {"", 0};
    set<string> uniqueWords;
    string sentence, word;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    while(ss >> word) {
        uniqueWords.insert(word);
        words[word]++;
        if (words[word] > mostUsed.second) {mostUsed = {word, words[word]};}
    }

    cout << "Word Frequencies:\n";
    for (auto it = words.begin(); it != words.end(); it++) {cout << "  " << it -> first << ": " << it -> second << "\n";}

    cout << "\nUnique words (alphabetical): ";
    for (auto word : uniqueWords) {cout << word << " ";}

    cout << "\n\nMost frequent word: " << mostUsed.first << " (" << mostUsed.second << " times)\n";

    return 0;
}

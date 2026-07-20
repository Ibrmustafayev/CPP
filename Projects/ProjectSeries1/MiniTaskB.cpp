#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void sortWords(string *words, int n);
bool contains(const string *words, int n, const string &target);

int main() {
    int n;
    cout << "Enter the size for an array: ";
    cin >> n;

    string *words = new string[n];
    cout << "You have to enter " << n << " words:" << endl;
    for (int i = 0; i < n; i++) {
        cout <<  i + 1 << ". ";
        cin >> words[i];
    }

    sortWords(words, n);

    string target;
    cout << "\nEnter a target word: ";
    cin >> target;

    cout << "The word '" << target << "' is";
    cout << ((contains(words, n, target)) ? " " : " not "); 
    cout << "in the array.";

    delete[] words;

    return 0;
}

void sortWords(string *words, int n) {
    sort(words, words + n);
    cout << "\nThe sorted array:" << endl;
    for (int i = 0; i < n; i++) {cout << i + 1 << ". " << words[i] << endl;}
}

bool contains(const string *words, int n, const string &target) {
    for (int i = 0; i < n; i++) {if (words[i] == target) {return 1;}}
    return 0;
}

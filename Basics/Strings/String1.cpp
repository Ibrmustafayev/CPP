#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

void uppercase(string sentence);
void lowercase(string sentence);
void countVowCon(string sentence);
void check(string sentence);
void replace_(string sentence);
void split(string sentence);
void title(string sentence);
void mostFrequent(string sentence);

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    auto reverseString = [](string sentence) {
        string reversed(sentence.rbegin(), sentence.rend());
        cout << "The reversed version: " << reversed << endl;
    };
    
    auto len = [](string sentence) {
        cout << "\nThe length of the sentence: " << sentence.length() << endl;
    };

    auto front_back = [](string sentence) {
        cout << "The first character: " << sentence[0] << "\nThe last character: " << sentence.back() << endl;
    };

    len(sentence);
    front_back(sentence);
    uppercase(sentence);
    lowercase(sentence);
    countVowCon(sentence);
    reverseString(sentence);
    check(sentence);
    replace_(sentence);
    split(sentence);
    title(sentence);
    mostFrequent(sentence);

    return 0;
}

void uppercase(string sentence) {
    cout << "Uppercase version: ";
    for (char letter : sentence) {
        if (!isalpha(letter)) {cout << char(letter);}
        else {cout << char(toupper(letter));}
    }
    cout << "\n";
}

void lowercase(string sentence) {
    cout << "Lowercase version: ";
    for (char letter : sentence) {
        if (!isalpha(letter)) {cout << char(letter);}
        else {cout << char(tolower(letter));}
    }
    cout << "\n";
}

void countVowCon(string sentence) {
    int v_count = 0, c_count = 0;
    const string vowels = "aeiou", consonants = "bcdfghjklmnpqrstvwxyz";

    for (char letter : sentence) {
        if (vowels.find(tolower(letter)) != string :: npos) {v_count++;}
        else if (consonants.find(tolower(letter)) != string :: npos) {c_count++;}
    }

    cout << "The number of vowels: " << v_count << "\nThe number of consonants: " << c_count << endl;
}

void check(string sentence) {
    string word;
    cout << "\nEnter a word: ";
    cin >> word;

    if (sentence.find(word) == 0) {cout << "The sentence starts with '" << word << "'." << endl;}
    else if (sentence.compare(sentence.length() - word.length(), word.length(), word) == 0) {cout << "The sentence ends with '" << word << "'." << endl;}
    else if (sentence.find(word) == string :: npos) {cout << "The sentence does not contain '" << word << "'." << endl;}
    else {cout << "The sentence contains '" << word << "', but it neither starts nor ends with '" << word << "'." << endl;} 
}

void replace_(string sentence) {
    cout << "The replaced version: ";

    for (char letter : sentence) {
        if (letter == ' ') {cout << "_"; continue;}
        cout << letter;
    }
    cout << "\n";
}

void split(string sentence) {
    vector<string> words;
    string word = "";

    for (char letter : sentence) {
        if (isalpha(letter)) {word.push_back(letter);} 
        else {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {words.push_back(word);}

    cout << "Words & Lengths:\n";
    for (string word : words) {cout << "  " << word << " - " << word.length() << "\n";}
}

void title(string sentence) {
    cout << "The title version: ";
    for (int i = 0; i < sentence.length(); i++) {
        if (isalpha(sentence[i]) && (i == 0 || (!isalpha(sentence[((i > 0) ? i - 1 : i)]) && isalpha(sentence[i])))) {cout << char(toupper(sentence[i]));}
        else {cout << sentence[i];}
    } 
    cout << "\n";
}

void mostFrequent(string sentence) {
    int freq[256] = {0};
    for (char c : sentence) if (isalpha(c)) freq[tolower(c)]++;
    int maxIdx = max_element(freq, freq + 256) - freq;
    cout << "The most frequent char: " << (char)maxIdx << " (" << freq[maxIdx] << " times)\n";
}

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";
string text, key;

bool is_valid();
string encode();

int main() {
    cout << "\t=== Vigenere Cipher ===\n";

    cout << "Input: ";
    getline(cin, text);

    while (1) {
        cout << "Key: ";
        cin >> key;

        if (is_valid()) break;
        else cout << "Error: Only letters are allowed for key!\n\n";
    }
    
    cout << "\nPlaintext: " << text << "\nCiphertext: " << encode() << "\n";

    return 0;
}

bool is_valid() {
    if (key.empty()) return false;

    for (char c : key) if (!isalpha(c)) return false;
    return true;
}

string encode() {
    string encoded;
    int charNum = 0;
    
    for (int i = 0; i < text.size(); i++) {
        if (!isalpha(text[i])) {
            encoded += text[i];
            continue;
        }

        int letterPosition = alphabet.find(tolower(text[i]));
        int keyPositon = alphabet.find(tolower(key[charNum % key.size()]));
        int newPosition = (letterPosition + keyPositon) % 26;
        
        if (isupper(text[i])) encoded += toupper(alphabet[newPosition]);
        else encoded += alphabet[newPosition];

        charNum++;
    }

    return encoded;
}

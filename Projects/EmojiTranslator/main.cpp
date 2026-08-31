#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

const map<string, string> emojiMap = {
    {"happy", "😀"}, {"laughing", "😂"}, {"love", "😍"}, {"cool", "😎"}, {"sad", "😢"}, {"crying", "😭"}, {"angry", "😡"}, {"scared", "😱"}, {"thinking", "🤔"},
    {"sleepy", "😴"}, {"tired", "🥱"}, {"hugging", "🤗"}, {"excited", "🤩"}, {"celebrating", "🥳"}, {"innocent", "😇"}, {"annoyed", "🙄"}, {"smirking", "😏"},
    {"awkward", "😬"}, {"quiet", "🤐"}, {"silent", "🤫"}, {"heart", "❤️"}, {"perfect", "💯"}, {"fire", "🔥"}, {"special", "✨"}, {"star", "⭐"},
    {"dead", "💀"}, {"watching", "👀"}, {"good", "👍"}, {"bad", "👎"}, {"applause", "👏"}, {"please", "🙏"}, {"strong", "💪"}, {"deal", "🤝"}, {"peace", "✌️"}, {"hello", "👋"},
    {"party", "🎉"}, {"birthday", "🎂"}, {"gift", "🎁"}, {"winner", "🏆"}, {"football", "⚽"}, {"gaming", "🎮"}, {"music", "🎵"}, {"guitar", "🎸"},
    {"sun", "☀️"}, {"night", "🌙"}, {"rain", "🌧️"}, {"snow", "❄️"}, {"rainbow", "🌈"}, {"ocean", "🌊"}, {"dog", "🐶"}, {"cat", "🐱"},
    {"lion", "🦁"}, {"tiger", "🐯"}, {"panda", "🐼"}, {"frog", "🐸"}, {"fox", "🦊"}, {"monkey", "🐵"}, {"pizza", "🍕"}, {"burger", "🍔"}, {"apple", "🍎"}, {"banana", "🍌"},
    {"strawberry", "🍓"}, {"chocolate", "🍫"}, {"coffee", "☕"}, {"cake", "🍰"}, {"car", "🚗"}, {"airplane", "✈️"}, {"rocket", "🚀"}, {"home", "🏠"}, {"phone", "📱"},
    {"computer", "💻"}, {"money", "💰"}, {"key", "🔑"}, {"locked", "🔒"}, {"unlocked", "🔓"}
};

int main() {
    string sentence;

    cout << "\t=== Emoji Translator ===\n";

    while (1) {
        cout << "Enter a sentence ('q' to quit): ";
        getline(cin, sentence);

        if (sentence == "q" || sentence == "Q") {
            cout << "Goodbye!!!\n";
            break;
        }

        stringstream ss(sentence);
        string word;

        cout << "\nTranslated: ";
        while (ss >> word) {
            string lowerWord = word, punct;

            for (char &c : lowerWord) c = tolower(c);

            while (!lowerWord.empty() && ispunct(lowerWord.back())) {
                punct.push_back(lowerWord.back());
                lowerWord.pop_back();
            }

            auto it = emojiMap.find(lowerWord);

            if (it != emojiMap.end()) cout << it -> second << punct << " ";
            else cout << word << " ";
        }

        cout << "\n\n";
    }

    return 0;
}

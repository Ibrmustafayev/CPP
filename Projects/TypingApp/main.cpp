#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <random>
using namespace std;

int main() {
    vector<string> sentences = {"The weather is nice today.", "I usually listen to music while I work.", "She forgot her keys at home.", "The train arrived earlier than expected.",
      "We went outside to enjoy the fresh air.", "He finished his homework before dinner.", "Sometimes a simple idea can solve a big problem.", "My friends and I watched a movie last night.",
      "The Internet stopped working for a few minutes.", "The quick brown fox jumps over the lazy dog"};
    string typed;
    double correct = 0, wordNum = 1;

    cout << "\t=== Typing Practise ===\n";

    random_device rd;
    mt19937 g(rd() ^ chrono :: system_clock :: now().time_since_epoch().count());
    uniform_int_distribution<size_t> dist(0, sentences.size() - 1);
    string sentence = sentences[dist(g)];

    cout << "Type this sentence exactly:\n\"" << sentence << "\"\n\n> ";
    auto start = chrono :: steady_clock :: now();
    getline(cin, typed);
    auto end = chrono :: steady_clock :: now();
    auto duration = chrono :: duration_cast<chrono :: milliseconds>(end - start);

    for (size_t i = 0; i < max(typed.size(), sentence.size()); i++) if (i < typed.size() && i < sentence.size() && typed[i] == sentence[i]) correct++;

    for (char c : sentence) if (c == ' ') wordNum++;

    cout << "\nTime: " << duration.count() / 1000.0 << " seconds\nAccuracy: " << correct / sentence.size() * 100 << "%\nWPM: " << wordNum * 60000.0 / duration.count() << "\n";

    return 0;
}

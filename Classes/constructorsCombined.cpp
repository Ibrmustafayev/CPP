#include <iostream>
#include <string>
using namespace std;

class Playlist {
    private:
        const string owner;
        string *songs;
        int capacity;
        int count;

    public:
        Playlist(string owner) : Playlist(owner, 10) {}
        Playlist(string owner, int capacity) : owner(owner), capacity(capacity), count(0) {
            songs = new string[capacity];
        }
        Playlist(const Playlist &other) : owner(other.owner), capacity(other.capacity), count(other.count) {
            songs = new string[capacity];
            for (int i = 0; i < count; i++) {
                songs[i] = other.songs[i];
            }
        }
        ~Playlist() {
            delete[] songs;
        }

        void addSong(string title);
        void print();
};

int main() {
    Playlist p1("Alice");
    p1.addSong("Song A");
    p1.addSong("Song B");
    p1.addSong("Song C");

    Playlist p2 = p1;
    p2.addSong("Song D");

    p1.print();
    p2.print();

    return 0;
}

void Playlist :: addSong(string title) {
    if (count < capacity) {
        songs[count] = title;
        count++;
    } else {
        cout << "Playlist is full!\n";
    }
}

void Playlist :: print() {
    cout << owner << "'s playlist (" << count << " songs):" << "\n";
    for (int i = 0; i < count; i++) {
        cout << "  " << i + 1 << ". " << songs[i] << "\n";
    }
}

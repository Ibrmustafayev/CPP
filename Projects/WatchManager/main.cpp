#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
using namespace std;

class InvalidRatingError : public runtime_error {
public:
    InvalidRatingError(string msg) : runtime_error(msg) {}
};

class ContentNotFound : public runtime_error {
public:
    ContentNotFound(string msg) : runtime_error(msg) {}
};

class Content {
protected:
    string title;
    double rating;
    set<string> genres;

public:
    Content(string title, double rating, set<string> genres) : title(title), rating(rating), genres(genres) {
        if (rating < 0 || rating > 10) {throw InvalidRatingError("Rating must be between 0 and 10!");}
    }
    virtual ~Content() {}

    virtual double watchScore() const = 0;
    virtual void printInfo() const;
    virtual string typeTag() const = 0;
    virtual void saveExtra(ofstream &file) const;

    string getTitle() const;
    double getRating() const;
    bool hasGenre(string genre) const;
};

class Movie : public Content {
private:
    int durationMinutes;

public:
    Movie(string title, double rating, set<string> genres, int durationMinutes) : Content(title, rating, genres), durationMinutes(durationMinutes) {}
    ~Movie() {}

    double watchScore() const override;
    void printInfo() const override;
    string typeTag() const override;
    void saveExtra(ofstream &file) const override;
};

class Series : public Content {
private:
    int episodes;

public:
    Series(string title, double rating, set<string> genres, int episodes) : Content(title, rating, genres), episodes(episodes) {}
    ~Series() {}
    
    double watchScore() const override;
    void printInfo() const override;
    string typeTag() const override;
    void saveExtra(ofstream &file) const override;
};

template <typename T>
class Repository {
private:
    vector<T> items;

public:
    void add(T item);
    Content* findByTitle(string title) const;
    vector<Content*> filterByGenre(string genre) const;
    void printAll() const;
    int count() const;
    void clear();

    const vector<T> &getItems() const;
};

int main() {
    Repository<unique_ptr<Content>> repo;
    const string filename = "repo.txt";
    char option;
    
    do {
        cout << "\t=== StreamVault: Watch Manager ===\n1. Add Movie\n2. Add Series\n3. Search by title\n4. Filter by genre\n5. List all\n6. Save to file\n7. Load from file\n8. Exit\n";
        cout << "\nOption: ";
        cin >> option;
        cout << "\n";

        if (option == '8') {cout << "Goodbye!!!";}
        else if (option == '1') {
            try {
                string title, genres_, genre;
                double rating;
                int durationMinutes;
                set<string> genres;

                cout << "Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Rating: ";
                cin >> rating;
                cout << "Genres: ";
                cin.ignore();
                getline(cin, genres_);
                stringstream ss(genres_);
                while (ss >> genre) {genres.insert(genre);}
                cout << "Duration minutes: ";
                cin >> durationMinutes;

                repo.add(make_unique<Movie>(title, rating, genres, durationMinutes));
            } catch (const InvalidRatingError &e) {cout << e.what();}
        } else if (option == '2') {
            try {
                string title, genres_, genre;
                double rating;
                int episodes;
                set<string> genres;

                cout << "Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Rating: ";
                cin >> rating;
                cout << "Genres: ";
                cin.ignore();
                getline(cin, genres_);
                stringstream ss(genres_);
                while (ss >> genre) {genres.insert(genre);}
                
                cout << "Episodes: ";
                cin >> episodes;

                repo.add(make_unique<Series>(title, rating, genres, episodes));
            } catch (const InvalidRatingError &e) {cout << e.what();}
        } else if (option == '3') {
            string title;

            cout << "Target: ";
            cin.ignore();
            getline(cin, title);

            try {
                Content* found = repo.findByTitle(title);
                cout << "Found: ";
                found->printInfo();
            } catch (const ContentNotFound &e) {cout << e.what();}
        } else if (option == '4') {
            string genre;
            
            cout << "Genre: ";
            cin.ignore();
            getline(cin, genre);

            vector<Content*> filtered = repo.filterByGenre(genre);
            cout << "\t--- Filtered by " << genre << " ---\n";
            if (filtered.empty()) {cout << "\t\tNot found!\n";}
            else {for (auto &f : filtered) {f -> printInfo();}}
        } else if (option == '5') {
            repo.printAll();
            cout << "\nItem count: " << repo.count() << "\n";
        } else if (option == '6') {
            try {
                ofstream file(filename);
                if(!file.is_open()) {throw ContentNotFound("Error: Content not found!\n");}

                const auto &items = repo.getItems();
                for (auto &i : items) {i -> saveExtra(file);}
                cout << "Saved successfully to '" << filename << "'\n";
            } catch (const ContentNotFound &e) {cout << e.what();}
        } else if (option == '7') {
            try {
                ifstream file(filename);
                if (!file.is_open()) {throw ContentNotFound("Error: Content not found!\n");}

                repo.clear();
                
                string tag;
                while (file >> tag) {
                    if (tag == "MOV") {
                        string title, genre, genres_;
                        double rating;
                        set<string> genres;
                        int durationMinutes;

                        file >> title >> rating >> durationMinutes >> genres_;

                        string title2 = title;
                        for (char &c : title2) {if (c == '_') {c = ' ';}}
                        stringstream ss(genres_);
                        while (getline(ss, genre, '_')) {if (!genre.empty()) {genres.insert(genre);}}

                        repo.add(make_unique<Movie>(title2, rating, genres, durationMinutes));
                    } else if (tag == "SER") {
                        string title, genres_, genre;
                        double rating;
                        int episodes;
                        set<string> genres;

                        file >> title >> rating >> episodes >> genres_;

                        string title2 = title;
                        for (char &c : title2) {if (c == '_') {c = ' ';}}
                        stringstream ss(genres_);
                        while (getline(ss, genre, '_')) {if (!genre.empty()) {genres.insert(genre);}}

                        repo.add(make_unique<Series>(title2, rating, genres, episodes));
                    }
                }
                cout << "Loaded successfully from '" << filename << "'\n";
            } catch (const ContentNotFound &e) {cout << e.what();}
        } else {cout << "Invalid option!\n";}
        cout << "\n";
    } while (option != '8');

    return 0;
}

void Content :: printInfo() const {
    cout << "[Content] " << title << " | Rating: " << rating << " | Watch score: " << watchScore() << " | Genres: ";
    for (auto &g : genres) {cout << g << " ";}
    cout << "\n";
}

void Content :: saveExtra(ofstream &file) const {
    string title2 = title;
    for (char &c : title2) {if (c == ' ') {c = '_';}}

    file << typeTag() << " " << title2 << " " << rating << " ";
    for (auto &g : genres) {file << g << "_";}
    file << "\n";
}

string Content :: getTitle() const {return title;}
double Content :: getRating() const {return rating;}
bool Content :: hasGenre(string genre) const {return genres.find(genre) != genres.end();}

double Movie :: watchScore() const {return rating * (durationMinutes / 60.0);}

void Movie :: printInfo() const {
    cout << "[Movie] " << title << " | Rating: " << rating << " | Duration minutes: " << durationMinutes << "min | Watch score: " << watchScore() << " | Genres: ";
    for (auto &g : genres) {cout << g << " ";}
    cout << "\n";
}

string Movie :: typeTag() const {return "MOV";}

void Movie :: saveExtra(ofstream &file) const {
    string title2 = title;
    for (char &c : title2) {if (c == ' ') {c = '_';}}

    file << typeTag() << " " << title2 << " " << rating << " " << durationMinutes << " ";
    for (auto &g : genres) {file << g << "_";}
    file << "\n";
}

double Series :: watchScore() const {return rating * episodes * 0.1;}

void Series :: printInfo() const {
    cout << "[Series] " << title << " | Rating: " << rating << " | Episodes: " << episodes << " | Watch score: " << watchScore() << " | Genres: ";
    for (auto &g : genres) {cout << g << " ";}
    cout << "\n";
}

string Series :: typeTag() const {return "SER";}

void Series :: saveExtra(ofstream &file) const {
    string title2 = title;
    for (char &c : title2) {if (c == ' ') {c = '_';}}

    file << typeTag() << " " << title2 << " " << rating << " " << episodes << " ";
    for (auto &g : genres) {file << g << "_";}
    file << "\n";
}

template <typename T>
void Repository<T> :: add(T item) {cout << "Added to Repository: " << item -> typeTag() << "\n"; items.push_back(move(item));}

template <typename T>
Content* Repository<T> :: findByTitle(string title) const {
    for (const auto &i : items) {if (i -> getTitle() == title) {return i.get();}}
    throw ContentNotFound("No content found with title: " + title);
}

template <typename T>
vector<Content*> Repository<T> :: filterByGenre(string genre) const {
    vector<Content*> found;
    for (const auto &i : items) {if (i -> hasGenre(genre)) {found.push_back(i.get());}}
    return found;
}

template <typename T>
void Repository<T> :: printAll() const {
    cout << "\t=== Repository ===\n";
    for (const auto &i : items) {i -> printInfo();}
}

template <typename T>
int Repository<T> :: count() const {return items.size();}

template <typename T>
void Repository<T> :: clear() {items.clear();}

template <typename T>
const vector<T> &Repository<T> :: getItems() const {return items;}

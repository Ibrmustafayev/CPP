#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Content {
protected:
    string title;
    int releaseYear;
    double rating;

public:
    Content(string title, int releaseYear, double rating) : title(title), releaseYear(releaseYear), rating(rating) {}
    virtual ~Content() {}

    virtual double calculateWatchScore() const = 0;
    virtual void printInfo() const;

    string getTitle() const;
    double getRating() const;
    void setRating(double newRating);

    friend bool isMoreEngaging(const Content &a, const Content &b);
};

class Movie : public Content {
private:
    int durationMinutes;

public:
    Movie(string title, int releaseYear, double rating, int durationMinutes) : Content(title, releaseYear, rating), durationMinutes(durationMinutes) {}
    ~Movie() {}

    double calculateWatchScore() const override;
    void printInfo() const override;
};

class Series : public Content {
private:
    int seasons;
    int episodesPerSeason;

public:
    Series(string title, int releaseYear, double rating, int seasons, int episodesPerSeason) : Content(title, releaseYear, rating), seasons(seasons), episodesPerSeason(episodesPerSeason) {}
    ~Series() {}

    double calculateWatchScore() const override;
    void printInfo() const override;
    int totalEpisodes() const;
};

template <typename T>
class Library {
private:
    vector<T> items;

public:
    void add(T item);
    void printAll() const;
    int count() const;
};

int main() {
    Library<Content*> l;
    
    Content* m1 = new Movie("Inception", 2010, 8.8, 148);
    Content* s1 = new Series("Breaking Bad", 2008, 9.5, 5, 12);
    
    l.add(m1);
    l.add(s1);
    cout << "\n";
    l.printAll();
    cout << "\n";
    (isMoreEngaging(*m1, *s1)) ? cout << m1 -> getTitle() << " is more engaging than " << s1 -> getTitle() << ".\n" : cout << m1 -> getTitle() << " is not more engaging than " << s1 -> getTitle() << ".\n";
    cout << "\nTotal items in library: " << l.count() << "\n";

    cout << "\n[Destructors firing...]";

    delete m1;
    delete s1;

    return 0;
}

void Content :: printInfo() const {cout << "[Content] " << title << " (" << releaseYear << ") - Rating: " << rating << " - Watch Score: " << calculateWatchScore() << "\n";}
string Content :: getTitle() const {return title;}
double Content :: getRating() const {return rating;}
void Content :: setRating(double newRating) {
    if (newRating >= 0.0 && newRating <= 10.0) {
        rating = newRating;
        cout << title << "'s rating updated: " << rating << "\n";
    } else {
        cout << "Error: Rating must be 0.0 - 10.0!\n";
    }
}

bool isMoreEngaging(const Content &a, const Content &b) {
    return (a.calculateWatchScore() > b.calculateWatchScore());
}

double Movie :: calculateWatchScore() const {return rating * (durationMinutes / 60.0);}
void Movie :: printInfo() const {
    cout << "[Movie] " << title << " (" << releaseYear << ") - Rating: " << rating << " - " << durationMinutes << " min - Watch Score: " << calculateWatchScore() << "\n";
}

double Series :: calculateWatchScore() const {return rating * seasons * episodesPerSeason * 0.1;}
void Series :: printInfo() const {
    cout << "[Series] " << title << " (" << releaseYear << ") - Rating: " << rating << " - " << seasons << " seasons, " << totalEpisodes() << " episodes - Watch Score: " << calculateWatchScore() << "\n";
}
int Series :: totalEpisodes() const {return seasons * episodesPerSeason;}

template <typename T>
void Library<T> :: add(T item) {
    items.push_back(item);
    cout << "Added to Library: " << item -> getTitle() << "\n";
}

template <typename T>
void Library<T> :: printAll() const {
    cout << "=== StreamVault Library ===\n";
    for (T item : items) {item -> printInfo();}
}

template <typename T>
int Library<T> :: count() const {return items.size();}

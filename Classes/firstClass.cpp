#include <iostream>
#include <string>
using namespace std;

class Book {
    public:
    string title;
    string author;
    int pages;
    bool isRead;

    Book(string t, string a, int p, bool i) {
        title = t;
        author = a;
        pages = p;
        isRead = i;
    } 

    void printInfo();
    void markAsRead();
};

int main() {
    Book b1("1984", "George Orwel", 400, 0);
    Book b2("Harry Potter 1", "J.K.Rowling", 500, 0);

    
    b1.printInfo();
    b2.printInfo();

    b1.markAsRead();
    cout << "\n";

    b1.printInfo();
    b2.printInfo();

    return 0;
}

void Book :: printInfo() {
    cout << ((isRead) ? "[+] " : "[ ] ") << title << " - " << author << " (" << pages << " pages)" << endl;
}

void Book :: markAsRead() {
    isRead = 1;
}

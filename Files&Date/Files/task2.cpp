#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Item {
protected:
    string name;
    double price;

public:
    Item(string name, double price) : name(name), price(price) {
        if (price <= 0) {
            cout << "Error: Price must be positive (>0)! Defaulting to $50!\n";
            this -> price = 50;
        }
    }
    virtual ~Item() {}

    virtual void saveToFile(ofstream &file) const;
    virtual void printInfo() const;

    string getName() const {return name;}
};

class Book : public Item {
private:
    string author;

public:
    Book(string name, double price, string author) : Item(name, price), author(author) {}
    ~Book() {}

    void saveToFile(ofstream &file) const override;
    void printInfo() const override;
};

class Electronic : public Item {
private:
    int warrantyMonths;

public:
    Electronic(string name, double price, int warrantyMonths) : Item(name, price), warrantyMonths(warrantyMonths) {}
    ~Electronic() {}

    void saveToFile(ofstream &file) const override;
    void printInfo() const override;
};

void saveInventory(const vector<Item*> &items, const string filename);
vector<Item*> loadInventory(const string filename);

int main() {
    const string filename = "items.txt";

    vector<Item*> items = {new Book("1984", 15.99, "George Orwell"), new Electronic("Headphones", 89.99, 24), new Book("Dune", 12.5, "Frank Herbert"), new Item("Watch", 100)};
    string line;
    
    cout << "Original inventory:\n";
    for (Item* item : items) {
        cout << "  ";
        item -> printInfo();
    }

    saveInventory(items, filename);
    cout << "\nSaved to " << filename << "!\n\n";

    vector<Item*> items2 = loadInventory(filename);
    cout << "Reloaded inventory:\n";
    for (Item* item : items2) {
        cout << "  ";
        item -> printInfo(); 
    }

    for (Item* item : items) {delete item;}
    for (Item* item : items2) {delete item;}
    items.clear();
    items2.clear();

    return 0;
}

void Item :: saveToFile(ofstream &file) const {
    string name2 = name;
    for (char &c : name2) {if (c == ' ') {c = '_';}}
    
    file << "ITEM" << " " << name2 << " " << price << "\n";
}

void Item :: printInfo() const {
    string name2 = name;
    for (char &c : name2) {if (c == '_') {c = ' ';}}

    cout << "[ITEM] " << name2 << " - $" << price << "\n";
}

void Book :: saveToFile(ofstream &file) const {
    string name2 = name, author2 = author;
    for (char &c : name2) {if (c == ' ') {c = '_';}}
    for (char &c : author2) {if (c == ' ') {c = '_';}}

    file << "BOOK" << " " << name2 << " " << price << " " << author2 << "\n";
}

void Book :: printInfo() const {
    string name2 = name, author2 = author;
    for (char &c : name2) {if (c == '_') {c = ' ';}}
    for (char &c : author2) {if (c == '_') {c = ' ';}}

    cout << "[BOOK] " << name2 << " - $" << price << " by " << author2 << "\n";
}

void Electronic :: saveToFile(ofstream &file) const {
    string name2 = name;
    for (char &c : name2) {if (c == ' ') {c = '_';}}

    file << "ELEC" << " " << name2 << " " << price << " " << warrantyMonths << "\n";
}

void Electronic :: printInfo() const {
    string name2 = name;
    for (char &c : name2) {if (c == '_') {c = ' ';}}

    cout << "[ELEC] " << name2 << " - $" << price << " (" << warrantyMonths << " months warranty)\n";
}

void saveInventory(const vector<Item*> &items, const string filename) {
    ofstream file(filename);
    if(!file.is_open()) {
        cout << "Failed to open " << filename << "!\n";
        return;
    }

    for (Item* item : items) {item -> saveToFile(file);}
    file.close();
}

vector<Item*> loadInventory(const string filename) {
    vector<Item*> items;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open " << filename << "!\n";
        return items;
    }

    string tag;
    while (file >> tag) {
        if (tag == "BOOK") {
            string name, author;
            double price;

            file >> name >> price >> author;
            items.push_back(new Book(name, price, author));
        } else if (tag == "ELEC") {
            string name;
            double price;
            int warrantyMonths;

            file >> name >> price >> warrantyMonths;
            items.push_back(new Electronic(name, price, warrantyMonths));
        } else if (tag == "ITEM") {
            string name;
            double price;

            file >> name >> price;
            items.push_back(new Item(name, price));
        }
    }

    file.close();
    return items;
}

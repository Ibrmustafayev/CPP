#include  <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    Product(string name, double price, int quantity) : name(name) {
        setPrice(price);
        setQuantity(quantity);
    }

    string getName() const;
    double getPrice() const;
    int getQuantity() const;

    double setPrice(double newPrice);
    int setQuantity(int newQuantity);

    double getTotalValue() const;
};

void printProduct(const Product &p);

int main() {
    Product p("Laptop", 999.99, 10);
    printProduct(p);
    cout << "\n";
    p.setPrice(-123);
    p.setPrice(899.99);
    printProduct(p);

    return 0;
}

string Product :: getName() const {return name;}
double Product :: getPrice() const {return price;}
int Product :: getQuantity() const {return quantity;}

double Product :: setPrice(double newPrice) {
    if (newPrice >= 0) {price = newPrice; cout << "Price updated to $" << price << "\n";}
    else {cout << "Invalid price! Must be non-negative.\n";}
    return price;
}

int Product :: setQuantity(int newQuantity) {
    if (newQuantity >= 0) {quantity = newQuantity; cout << "Quantity updated to " << quantity << "\n";}
    else {cout << "Invalid quantity! Must be non-negative.\n";}
    return quantity;
}

double Product :: getTotalValue() const {
    return price * quantity;
}

void printProduct(const Product &p) {
    cout << "Product: " << p.getName() << ", Price: $" << p.getPrice() << ", Qty: " << p.getQuantity() << ", Total: $" << p.getTotalValue() << "\n";
}

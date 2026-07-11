#include <iostream>
#include <string>
using namespace std;

class Rectangle {
    private:
        const string id;
        double width;
        double height;

    public:
        Rectangle(string id) : Rectangle(id, 1, 1) {}

        Rectangle(string id, double width, double height) : id(id), width(width), height(height) {}

        ~Rectangle() {}

        double area();
        void printInfo();

};

int main() {
    Rectangle r1("A");
    Rectangle r2("B", 4, 6);

    r1.printInfo();
    r2.printInfo();

    return 0;
}

double Rectangle :: area() {
    return width * height;
}

void Rectangle :: printInfo() {
    cout << "Rect " << id << " - " << width << "x" << height << " (area: " << area() << ")" << "\n";
}

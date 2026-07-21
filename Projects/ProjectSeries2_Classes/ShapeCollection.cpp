#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(string name) : name(name) {}
    virtual ~Shape() {}

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void printInfo() const;

    string getName() const;

    friend bool operator>(const Shape &a, const Shape &b);
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(string name, double radius) : Shape(name), radius(radius) {
        if (radius <= 0) {
            cout << "Error: Radius must be positive! Defaulting to 1.\n";
            this -> radius = 1;
        }
    }
    ~Circle() {}

    double area() const override;
    double perimeter() const override;
    void printInfo() const override;
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(string name, double width, double height) : Shape(name), width(width), height(height) {
        if (width <= 0 || height <= 0) {
            cout << "Error: Width and height must be positive! Defaulting 1x1";
            this -> width = this -> height = 1;
        }
    }
    ~Rectangle() {}

    double area() const override;
    double perimeter() const override;
    void printInfo() const override;
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(string name, double a, double b, double c) : Shape(name), a(a), b(b), c(c) {
        if (!(a + b > c && a + c > b && b + c > a)) {
            cout << "Error: Invalid triangle sides! Defaulting to 1,1,1.\n";
            this -> a = this -> b = this -> c = 1;
        }
    }
    ~Triangle() {}

    double area() const override;
    double perimeter() const override;
    void printInfo() const override;
};

template <typename T>
class Collection {
private:
    vector<T> items;

public:
    void add(T item);
    void printAll() const;
    int count() const;
};

int main() {
    Collection<Shape*> c;

    Shape* s1 = new Circle("Circle", 5);
    Shape* s2 = new Rectangle("Rectangle", 4, 6);
    Shape* s3 = new Triangle("Triangle", 3, 4, 5);
    Shape* s4 = new Triangle("Triangle", 1, 4, 5);

    c.add(s1);
    c.add(s2);
    c.add(s3);
    c.add(s4);
    cout << "\n";

    c.printAll();
    cout << "\n";

    cout << s1 -> getName() << " has larger area than " << s2 -> getName() << ": ";
    (*s1 > *s2) ? cout << "Yes\n" : cout << "No\n";
    cout << "\n";

    cout << "Total items in Collection: " << c.count() << "\n";

    delete s1;
    delete s2;
    delete s3;
    delete s4;

    return 0;
}

void Shape :: printInfo() const {cout << "[Shape] Area: " << area() << " - Perimeter: " << perimeter() << "\n";}
string Shape :: getName() const {return name;}

double Circle :: area() const {return radius * radius * M_PI;}
double Circle :: perimeter() const {return 2 * radius * M_PI;}
void Circle :: printInfo() const {cout << "[" << name << "] Radius: " << radius << " - Area: " << area() << " - Perimeter: " << perimeter() << "\n";}

double Rectangle :: area() const {return width * height;}
double Rectangle :: perimeter() const {return 2 * (width + height);}
void Rectangle :: printInfo() const {cout << "[" << name << "] " << width << "x" << height << " - Area: " << area() << " - Perimeter: " << perimeter() << "\n";}

double Triangle :: area() const {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
double Triangle :: perimeter() const {
    return a + b + c;
}
void Triangle :: printInfo() const {cout << "[" << name << "] Sides: " << a << "," << b << "," << c << " - Area: " << area() << " - Perimeter: " << perimeter() << "\n";}

bool operator>(const Shape &a, const Shape &b) {return a.area() > b.area();}

template <typename T>
void Collection<T> :: add(T item) {
    items.push_back(item);
    cout << "Added to Collection: " << item -> getName() << "\n";
}

template <typename T>
void Collection<T> :: printAll() const {
    cout << "=== Shape Collection ===\n";
    for (T item : items) {item -> printInfo();}
}

template <typename T>
int Collection<T> :: count() const {return items.size();}

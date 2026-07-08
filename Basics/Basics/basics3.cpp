#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void display(int n);
void display(double n);
void display(string s);
void display(int n, int m, int sum = 0);
double area(double radius);
double area(double width, double height);
double area(double a, double b, double c);

int main() {
    display(42);
    display(3.14);
    display("hello"s);
    display(3, 4);
    display(3, 4, 7);

    cout << "\n";

    cout << "area(5.0)\t\t-> Circle area: " << area(5.0) << "\narea(4.0, 6.0)\t\t-> Rectangle area: " << area(4.0, 6.0) << "\narea(3.0, 4.0, 5.0)\t-> Triangle area: " << area(3.0, 4.0, 5.0);

    return 0;
}

void display(int n) {cout << "display(" << n << ")\t\t-> Integer: " << n << endl;}

void display(double n) {cout << "display(" << n << ")\t\t-> Double: " << n << endl;}

void display(string s) {cout << "display(\"" << s << "\")\t-> String: " << s << endl;}

void display(int n, int m, int sum) {
    cout << "display(" << n << ", " << m;
    (sum != 0) ? (cout << ", " << sum << ")\t-> ") : (cout << ")\t\t-> ");
    if (sum == 0) {sum = n + m;}
    cout << "Sum:  " << n << " + " << m << " = "<< sum << endl;
}

double area(double radius) {return M_PI * radius * radius;}

double area(double width, double height) {return width * height;}

double area(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

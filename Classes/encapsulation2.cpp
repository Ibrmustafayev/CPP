#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature(double celsius) {
        setCelsius(celsius);
    }

    double getCelsius() const;
    double getFahrenheit() const;
    double getKelvin() const;

    double setCelsius(double newCelsius);
};

void printTemp(const Temperature &t);

int main() {
    Temperature t(25);
    printTemp(t);
    cout << "\n";
    t.setCelsius(-300);
    printTemp(t);

    return 0;
}

double Temperature :: getCelsius() const {return celsius;}
double Temperature :: getFahrenheit() const {return celsius * 9 / 5 + 32;}
double Temperature :: getKelvin() const {return celsius + 273.15;}

double Temperature :: setCelsius(double newCelsius) {
    if (newCelsius >= -273.15) {celsius = newCelsius; cout << "Temperature(°C) changed to " << celsius << "°C.\n";}
    else {cout << "Invalid! Cannot be below absolute zero (-273.15°C).\n";}
    return celsius;
}

void printTemp(const Temperature &t) {
    cout << "Celsius: " << t.getCelsius() << ", Fahrenheit: " << t.getFahrenheit() << ", Kelvin: " << t.getKelvin() << "\n";
}

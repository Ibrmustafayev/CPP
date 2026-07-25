#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
using namespace std;

class Event {
private:
    string name;
    time_t timestamp;

public:
    Event(string name) : name(name), timestamp(time(0)) {}
    ~Event() {}

    void printCreatedTime() const;
    time_t getTimestamp() const {return timestamp;}
};

int fibonacci(int n);

int main() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char output[50];
    strftime(output, 50, "%Y-%m-%d | %H:%M:%S", ltm);
    cout << output << "\n\n";
    
    time_t now2 = time(0);
    time_t future = now2 + (30 * 24 * 60 *60);
    tm *ltm2 = localtime(&future);
    cout << "30 days after now: " << 1900 + ltm2 -> tm_year << "-" << 1 + ltm2 -> tm_mon << "-" << ltm2 -> tm_mday << "\n\n";

    auto start = chrono :: high_resolution_clock :: now();

    cout << "30th element of Fibonacci sequence: " << fibonacci(30) << "\n\n";

    auto end = chrono :: high_resolution_clock :: now();
    chrono :: duration<double> eclapsed = end - start;
    cout << "Eclapsed: " << eclapsed.count() << " seconds\n\n";

    Event e1("Now");
    e1.printCreatedTime();

    cout << "30th element of Fibonacci sequence: " << fibonacci(30) << "\n\n";

    Event e2("Later");
    e2.printCreatedTime();
    cout << difftime(e2.getTimestamp(), e1.getTimestamp()) << " seconds passed!\n";

    return 0;
}

void Event :: printCreatedTime() const {cout << name << " > " << ctime(&timestamp);}

int fibonacci(int n) {
    if (n == 0 || n == 1) {return n;}
    return fibonacci(n - 1) + fibonacci(n - 2);
}

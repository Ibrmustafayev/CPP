#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double sum_(const vector<double> &a);
vector<double> product_(const vector<double> &a, const vector<double> &b);

int main() {
    size_t n;

    cout << "Number of data pairs: ";
    cin >> n;
    
    vector<double> x(n), y(n);

    cout << "\nValues for x: ";
    for (size_t i = 0; i < n; i++) cin >> x[i];

    cout << "Values for y: ";
    for (size_t i = 0; i < n; i++) cin >> y[i];

    double r = (n * sum_(product_(x, y)) - sum_(x) * sum_(y)) / (sqrt((n * sum_(product_(x, x)) - pow(sum_(x), 2)) * (n * sum_(product_(y, y)) - pow(sum_(y), 2)))); 
    
    cout << "\nPearson's r: " << r << " -> ";
    if (abs(r) > 0.7) cout << "Strong " << (r > 0 ? "positive" : "negative") << "\n";
    else if (abs(r) > 0.3) cout << "Moderate " << (r > 0 ? "positive" : "negative") << "\n";
    else cout << "No correlation\n";

    return 0;
}

double sum_(const vector<double> &a) {
    double sum = 0;
    for (size_t i = 0; i < a.size(); i++) sum += a[i];
    return sum;
}

vector<double> product_(const vector<double> &a, const vector<double> &b) {
    vector<double> c;
    for (size_t i = 0; i < a.size(); i++) c.push_back(a[i] * b[i]);
    return c;
}

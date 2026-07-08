#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap_(int &a, int &b);
void normalize(vector<int> &nums);
int sumVector(const vector<int> &nums);

int main() {
    int n;
    cout << "The size of the array (min = 2): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int &a = arr[0], &b = arr[1];
    swap_(a, b);

    vector<int> &nums = arr;
    normalize(nums);

    cout << "\n\nSum (read-only): " << sumVector(nums);

    return 0;
}

void swap_(int &a, int &b) {
    int c;

    cout << "\nBefore swap: a = " << a << ",  b = " << b << endl;
    c = a;
    a = b;
    b = c;
    cout << "After swap: a = " << a << ",  b = " << b << endl;
}

void normalize(vector<int> &nums) {
    int min = *min_element(nums.begin(), nums.end());

    cout << "\nOriginal vector: ";
    for (const int num : nums) cout << num << " ";
    cout << "\nNormalized:  \t";
    for (int &num : nums) {num -= min; cout << num << " ";}
}

int sumVector(const vector<int> &nums) {
    int sum = 0;
    for (const int num : nums) sum += num;
    return sum;
}

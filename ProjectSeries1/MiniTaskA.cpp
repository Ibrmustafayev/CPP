#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void getStats(const vector<int> &nums, int &min, int &max, double &avg);

int main() {
    int n;
    cout << "Enter the size for an array: ";
    cin >> n;

    vector<int> nums(n);

    int min, max;
    double avg;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {cin >> nums[i];}

    getStats(nums, min, max, avg);

    cout << "\nMin: " << min << "\nMax: " << max << "\nAvg: " << avg;

    return 0;
}

void getStats(const vector<int> &nums, int &min, int &max, double &avg) {
    min = *min_element(nums.begin(), nums.end());
    max = *max_element(nums.begin(), nums.end());
    avg = accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
}

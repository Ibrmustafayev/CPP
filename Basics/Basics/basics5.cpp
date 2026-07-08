#include <iostream>
using namespace std;

void doubleArray(int *arr, int n);
int* copyArray(int *arr, int n);

int main() {
    int n;
    cout << "Enter the size for an array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {cin >> arr[i];}

    doubleArray(arr, n);

    int *cpy = copyArray(arr, n);
    cout << "\nCopy: ";
    for (int i = 0; i < n; i++) {cout << cpy[i] << " ";}
    cpy[0] = 99;
    cout << "\nCopy after modifying copy[0] = 99: ";
    for (int i = 0; i < n; i++) {cout << cpy[i] << " ";}
    cout << "\nOriginal unaffected: ";
    for (int i = 0; i < n; i++) {cout << arr[i] << " ";}

    delete[] arr;
    delete[] cpy;

    return 0;
}

void doubleArray(int *arr, int n) {
    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++) {cout << arr[i] << " ";}
    cout << "\nDoubled array: ";
    for (int i = 0; i < n; i++) {arr[i] *= 2; cout << arr[i] << " ";}
    cout << "\n";
}

int* copyArray(int *arr, int n) {
    int *cpy = new int[n];
    for (int i = 0; i < n; i++) {cpy[i] = arr[i];}
    return cpy;
}

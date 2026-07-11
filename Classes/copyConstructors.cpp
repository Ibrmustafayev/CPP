#include <iostream>
using namespace std;

class IntArray {
    private:
        int *data;
        int size;

    public:
        IntArray(int size) : size(size) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = 0;
            }
        }

        IntArray(const IntArray &other) : size(other.size) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }

        ~IntArray() {
                delete[] data;
        }

        void set(int index, int value);
        int get(int index);
        void print();
};

int main() {
    IntArray a1(5);
    IntArray a2 = a1;

    a2.set(0, 99);
    a1.print();
    a2.print();

    return 0;
}

void IntArray :: set(int index, int value) {
    data[index] = value;
}

int IntArray :: get(int index) {
    return data[index];
}

void IntArray :: print() {
    for (int i = 0; i < size; i++) {
        cout << get(i)<< " ";
    }
    cout << "\n";
}

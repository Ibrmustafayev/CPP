#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    char ch = ' ';
    int pressed = 0;

    cout << "Real-time key logger. Press arrows or letters, 'q' to quit.\nKeys pressed: " << pressed << "\n";
    
    while (ch != 'q') {
        if (_kbhit()) {
            ch = _getch();
            if (((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) && ch != 113) {
                pressed++;
                cout << "\nYou pressed " << ch << "\nKeys pressed: " << pressed << "\n";
            } else if (ch == -32 || ch == 0) {
                ch = _getch();
                cout << "\nYou pressed ";
                switch (ch) {
                    case 72 : cout << "UP"; break;
                    case 80 : cout << "DOWN"; break;
                    case 75 : cout << "LEFT"; break;
                    case 77 : cout << "RIGHT"; break;
                }
                pressed++;
                cout << "\nKeys pressed: " << pressed << "\n";
            }
        }
    }

    cout << "\nQuiting....\n";

    return 0;
}

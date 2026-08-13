#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score, nTail;
int tailX[400], tailY[400];
enum Direction {STOP, LEFT, RIGHT, UP, DOWN};
Direction dir;

void draw();
void input();
void logic();

int main() {
    srand(time(0));

    gameOver = false;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
    dir = STOP;

    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(110);
    }

    return 0;
}

void draw() {
    system("cls");

    for (int i = 0; i < width + 2; i++) {cout << "#";}
    cout << "\n";

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width + 2; j++) {
            bool print = true;

            if (j == 0 || j == width + 1) {cout << "#";}
            else if (i == y && j == x) {cout << "@";}
            else if (i == fruitY && j == fruitX) {cout << "F";}
            else {
                for (int k = 0; k < nTail; k++) {if (tailX[k] == j && tailY[k] == i) {cout << "o"; print = false;}}

                if (print) {cout << " ";}
            }
        }
        cout << "\n";
    }

    for (int i = 0; i < width + 2; i++) {cout << "#";}
    cout << "\nSCORE: " << score << "\n";
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a' : if (dir != RIGHT) dir = LEFT; break;
            case 'd' : if (dir != LEFT) dir = RIGHT; break;
            case 'w' : if (dir != DOWN) dir = UP; break;
            case 's' : if (dir != UP) dir = DOWN; break;
            case 'x' : gameOver = true; break;
            default: break;
        }
    }
}

void logic() {
    int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT : x--; break;
        case RIGHT : x++; break;
        case UP : y--; break;
        case DOWN : y++; break;
        default: break;
    }

    if (x < 1) {x = width;} else if (x > width) {x = 1;}
    if (y < 0) {y = height - 1;} else if (y >= height) {y = 0;}

    for (int i = 0; i < nTail; i++) {if (tailX[i] == x && tailY[i] == y) {gameOver = true;}}

    if (x == fruitX && y == fruitY) {
        tailX[nTail] = (nTail > 0) ? nTail - 1 : 0;
        tailY[nTail] = (nTail > 0) ? nTail - 1 : 0;
        nTail++;
        score += 10;
        while (1) {
            bool goOn = false;
            fruitX = rand() % width + 1;
            fruitY = rand() % height;

            for (int i = 0; i < nTail; i++) {if (tailX[i] == fruitX && tailY[i] == fruitY) {goOn = true;}}
            if (goOn) {continue;}
            break;
        }
    }
}

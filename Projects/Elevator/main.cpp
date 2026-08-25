#include <iostream>
#include <string>
#include <set>
#include <windows.h>
using namespace std;

class Elevator {
private:
    int currentFloor;
    int minFloor, maxFloor;
    enum Direction {IDLE, UP, DOWN};
    Direction dir;
    set<int> pendingFloors;
    bool isFirst;

public:
    Elevator(int minFloor, int maxFloor, int startFloor) : minFloor(minFloor), maxFloor(maxFloor), currentFloor(startFloor), dir(IDLE), isFirst(true) {}

    void addRequest(int floor);
    void step();
    bool hasRequest() const;
    void printStatus();

    int getCurrentFloor() const {return currentFloor;}
};

int main() {
    int floor, minFloor, maxFloor, startFloor;

    cout << "\t=== Elevator Simulator ===\nMin floor: ";
    cin >> minFloor;
    cout << "Max floor: ";
    cin >> maxFloor;
    cout << "Start floor: ";
    cin >> startFloor;

    Elevator e(minFloor, maxFloor, startFloor);
    
    cout << "\nFloor requests ('-1' to start): ";
    while (cin >> floor) {
        if (floor == -1) break;
        e.addRequest(floor);
    }

    cout << "\n";

    while (e.hasRequest()) {
        e.printStatus();
        e.step();
        Sleep(1000);
    }

    cout << "\nAll requests served. Elevator idle at floor " << e.getCurrentFloor() << "\n";

    return 0;
}

void Elevator :: addRequest(int floor) {if (floor >= minFloor && floor <= maxFloor) pendingFloors.insert(floor);}

void Elevator :: step() {
    if (pendingFloors.find(currentFloor) != pendingFloors.end()) pendingFloors.erase(currentFloor);

    if (!hasRequest()) {
        dir = IDLE;
        return;
    }
    
    if (dir == IDLE) {
        if (pendingFloors.upper_bound(currentFloor) != pendingFloors.end()) dir = UP;
        else dir = DOWN;
    } else if (dir == UP) {
        if (pendingFloors.upper_bound(currentFloor) != pendingFloors.end()) dir = UP;
        else dir = DOWN;
    } else if (dir == DOWN) {
        if (*pendingFloors.begin() < currentFloor) dir = DOWN;
        else dir = UP;
    }

    switch (dir) {
        case UP:
            if (currentFloor + 1 <= maxFloor) currentFloor++;
            else dir = DOWN;
            break;
        
        case DOWN:
            if (currentFloor - 1 >= minFloor) currentFloor--;
            else dir = UP;
            break;
    }
}

bool Elevator :: hasRequest() const {return !pendingFloors.empty();}

void Elevator :: printStatus() {
    if (isFirst) {
        cout << "Floor " << currentFloor << ": Idle. Elevator moving....\n";
        if (pendingFloors.find(currentFloor) != pendingFloors.end()) cout << " Arrived! Doors open.\n";
        isFirst = false;
        return;
    }

    cout << "Floor " << currentFloor << ": ";
    if (pendingFloors.find(currentFloor) != pendingFloors.end()) cout << "Arrived! Doors open.\n";
    else cout << "Passing through..\n";
}

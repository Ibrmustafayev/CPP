#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double temperature, windSpeed;

int main() {
    cout << "\t=== Wind Chill Calculator ===\n";

    while (1) {
        cout << "Temperature (°F, 'q' to quit): ";
        cin >> temperature;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nGoodbye!!!\n";
            break;
        }

        cout << "Wind speed (mph): ";
        cin >> windSpeed;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Invalid input!!!\n Try again!!!\n\n";
            continue;
        }

        if (temperature > 50) {
            cout << "Wind chill doesn't apply (temperature must be maximum 50°F).\n\n";
            continue;
        } else if (windSpeed < 3) {
            cout << "Wind chill doesn't apply (wind speed must be at least 3 mph).\n\n";
            continue;
        }

        cout << "\nWind Chill: " << 35.74 + 0.6215 * temperature - 35.75*(pow(windSpeed, 0.16)) + 0.4275 * temperature * pow(windSpeed, 0.16) << "°F\n\n";
    }

    return 0;
}

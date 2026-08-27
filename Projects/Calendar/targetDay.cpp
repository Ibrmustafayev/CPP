#include <iostream>
#include <string>
#include <ctime>
#include <stdexcept>
using namespace std;

struct tm datetime;
time_t timestamp;
int date, month, year;
int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isValid();
void draw();

int main() {
    cout << "\t=== Calendar - Day Target ===\n";

    while(1) {
        try {
            cout << "Date: ";
            cin >> date;
            if (cin.fail()) throw invalid_argument("Error: Invalid argument!!! Try again!\n\n");

            cout << "Month (1 - 12): ";
            cin >> month;
            if (cin.fail()) throw invalid_argument("Error: Invalid argument!!! Try again!\n\n");

            cout << "Year: ";
            cin >> year;
            if (cin.fail()) throw invalid_argument("Error: Invalid argument!!! Try again!\n\n");

            if (!isValid()) throw runtime_error("Error: Invalid date!!! Try again!\n\n");

            break;
        } catch (const invalid_argument &e) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << e.what();
            continue;
        } catch (const runtime_error &e) {
            cout << e.what();
            continue;
        }
    }

    datetime.tm_mday = date;
    datetime.tm_mon = month - 1;
    datetime.tm_year = year - 1900;
    datetime.tm_isdst = -1;
    timestamp = mktime(&datetime);

    draw();

    return 0;
}

bool isValid() {
    if (year < 1900 || month < 1 || month > 12 || date < 1) return false;

    if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) daysInMonths[1] = 29;

    return date <= daysInMonths[month - 1];
}

void draw() {
    int firstDay = datetime.tm_wday - (datetime.tm_mday - 1) % 7;
    if (firstDay < 0) firstDay += 7;

    char output[50];
    strftime(output, 50, "%B %Y", &datetime);

    cout << "\n" << string((20 - string(output).size()) / 2, ' ') << output << "\nSu Mo Tu We Th Fr Sa\n";

    for (int i = 0; i < firstDay; i++) cout << "   ";

    for (int day = 1; day <= daysInMonths[datetime.tm_mon]; day++) {
        if (day == datetime.tm_mday) cout << "\033[31m";

        cout << ((day < 10) ? " " : "") << day << " ";

        if (day == datetime.tm_mday) cout << "\033[0m";

        if ((firstDay + day) % 7 == 0) cout << "\n";
    }

    cout << "\n";
}

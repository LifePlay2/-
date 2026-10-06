#include <iostream>
#include <locale.h>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    int GetHours() { return hours; }
    int GetMinutes() { return minutes; }
    int GetSeconds() { return seconds; }

    void SetHours(int h) {
        if (h >= 0 && h <= 23) {
            hours = h;
        }
        else {
            cout << "Ошибка: часы должны быть в диапазоне [0; 23]" << endl;
        }
    }

    void SetMinutes(int m) {
        if (m >= 0 && m <= 59) {
            minutes = m;
        }
        else {
            cout << "Ошибка: минуты должны быть в диапазоне [0; 59]" << endl;
        }
    }

    void SetSeconds(int s) {
        if (s >= 0 && s <= 59) {
            seconds = s;
        }
        else {
            cout << "Ошибка: секунды должны быть в диапазоне [0; 59]" << endl;
        }
    }

    void GetTime() {
        if (hours < 10) cout << "0";
        cout << hours << ":";

        if (minutes < 10) cout << "0";
        cout << minutes << ":";

        if (seconds < 10) cout << "0";
        cout << seconds << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");
    Time t(9, 5, 3);
    t.GetTime();

    t.SetHours(23);
    t.SetMinutes(59);
    t.SetSeconds(59);
    t.GetTime();

    t.SetHours(25);
    t.SetMinutes(70);
    t.SetSeconds(-1);
    t.GetTime();
}
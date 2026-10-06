#include <iostream>
#include <locale.h>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int GetDay() { return day; }
    int GetMonth() { return month; }
    int GetYear() { return year; }

    void SetDay(int d) {
        if (d >= 1 && d <= 31) {
            day = d;
        }
        else {
            cout << "Ошибка: день должен быть в диапазоне [1; 31]" << endl;
        }
    }

    void SetMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
        }
        else {
            cout << "Ошибка: месяц должен быть в диапазоне [1; 12]" << endl;
        }
    }

    void SetYear(int y) {
        if (y >= 1900 && y <= 2100) {
            year = y;
        }
        else {
            cout << "Ошибка: год должен быть в диапазоне [1900; 2100]" << endl;
        }
    }

    void GetDate() {
        if (day < 10) cout << "0";
        cout << day << ".";

        if (month < 10) cout << "0";
        cout << month << ".";

        cout << year << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");
    Date d(7, 5, 2024);
    d.GetDate();

    d.SetDay(31);
    d.SetMonth(12);
    d.SetYear(2100);
    d.GetDate();

    d.SetDay(0);
    d.SetMonth(13);
    d.SetYear(2200);
    d.GetDate();
}
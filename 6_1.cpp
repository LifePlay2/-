#include <iostream>
#include <locale.h>
using namespace std;

class Animal {
private:
    static int count;

public:
    Animal() {
        count++;
    }

    ~Animal() {
        count--;
    }

    int operator++() {
        count++;
        return count;
    }

    int operator--() {
        count--;
        return count;
    }

    operator int() {
        return count;
    }
};

int Animal::count = 0;

int main()
{
    setlocale(LC_ALL, "ru-RU");
    Animal a1;
    Animal a2;

    cout << "Count: " << (int)a1 << endl;

    ++a1;
    cout << "After ++: " << (int)a1 << endl;

    --a1;
    cout << "After --: " << (int)a1 << endl;
}
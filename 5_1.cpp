#include <iostream>
#include <locale.h>
using namespace std;

class Counter {
private:
    int value;

public:
    Counter(int v = 0) : value(v) {}

    Counter operator++() {
        value++;
        return *this;
    }

    Counter operator++(int) {
        Counter temp = *this;
        value++;
        return temp;
    }

    void Print() {
        cout << value << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru-RU");
    Counter c1(5);
    c1.Print();

    ++c1;
    c1.Print();

    c1++;
    c1.Print();
}
#include <iostream>

using namespace std;

class Integer {
private:
    int value;

public:
    Integer(int v = 0) : value(v) {}
    Integer(Integer& other) : value(other.value) {}

    Integer operator+(Integer other) { return Integer(value + other.value); }
    Integer operator-(Integer other) { return Integer(value - other.value); }
    Integer operator*(Integer other) { return Integer(value * other.value); }
    Integer operator/(Integer other) {
        if (other.value != 0) return Integer(value / other.value);
        return Integer(0);
    }

    Integer operator++() {
        value++;
        return *this;
    }
    Integer operator++(int) {
        Integer temp = *this;
        value++;
        return temp;
    }
    Integer operator--() {
        value--;
        return *this;
    }
    Integer operator--(int) {
        Integer temp = *this;
        value--;
        return temp;
    }
    operator int() { return value; }

    void Print() {
        cout << value << endl;
    }
};
int main() {
    Integer a(10);
    a.Print();

    ++a;
    a.Print();

    a++;
    a.Print();

    --a;
    a.Print();

    a--;
    a.Print();
}
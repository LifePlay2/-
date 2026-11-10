#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) denominator = 1;
    }

    Fraction(Fraction& other)
        : numerator(other.numerator), denominator(other.denominator) {
    }

    operator int() { return numerator / denominator; }
    operator double() { return (double)numerator / denominator; }

    void Print() {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f(7, 2);
    f.Print();

    int intVal = f;
    double doubleVal = f;

    cout << "int: " << intVal << endl;
    cout << "double: " << doubleVal << endl;
}
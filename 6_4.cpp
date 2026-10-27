#include <iostream>
#include <locale.h>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(Complex other) { return Complex(real + other.real, imag + other.imag); }
    Complex operator-(Complex other) { return Complex(real - other.real, imag - other.imag); }

    Complex operator*(Complex other) {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    Complex operator/(Complex other) {
        double denom = other.real * other.real + other.imag * other.imag;
        if (denom == 0) return Complex(0, 0);
        return Complex(
            (real * other.real + imag * other.imag) / denom,
            (imag * other.real - real * other.imag) / denom
        );
    }

    bool operator==(Complex other) {
        return (real == other.real && imag == other.imag);
    }

    bool operator!=(Complex other) {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, Complex c) {
        if (c.imag >= 0) os << c.real << " + " << c.imag << "i";
        else os << c.real << " - " << -c.imag << "i";
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");

    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << (c1 + c2) << endl;
    cout << "c1 - c2 = " << (c1 - c2) << endl;
    cout << "c1 * c2 = " << (c1 * c2) << endl;
    cout << "c1 / c2 = " << (c1 / c2) << endl;

    Complex c3(3, 4);
    if (c1 == c3) cout << "c1 равно c3" << endl;
    if (c1 != c2) cout << "c1 не равно c2" << endl;
}
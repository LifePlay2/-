#include <iostream>
#include <locale.h>

using namespace std;

class Vector2D {
private:
    double x;
    double y;

    double NewtonSqrt(double n) {
        if (n <= 0) return 0;
        double guess = n / 2;
        for (int i = 0; i < 20; i++) {
            guess = (guess + n / guess) / 2;
        }
        return guess;
    }

public:
    Vector2D(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {}

    double Length() {
        return NewtonSqrt(x * x + y * y);
    }

    Vector2D Normalized() {
        double len = Length();
        if (len == 0) return Vector2D(0, 0);
        return Vector2D(x / len, y / len);
    }

    Vector2D operator+(Vector2D other) { return Vector2D(x + other.x, y + other.y); }
    Vector2D operator-(Vector2D other) { return Vector2D(x - other.x, y - other.y); }
    Vector2D operator*(double k) { return Vector2D(x * k, y * k); }
    Vector2D operator/(double k) {
        if (k != 0) return Vector2D(x / k, y / k);
        return Vector2D(0, 0);
    }

    friend ostream& operator<<(ostream& os, Vector2D v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");

    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    cout << "v1 = " << v1 << endl;
    cout << "Длина v1 = " << v1.Length() << endl;
    cout << "Нормализованный v1 = " << v1.Normalized() << endl;
    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "v1 * 2 = " << (v1 * 2) << endl;
    cout << "v1 / 2 = " << (v1 / 2) << endl;
}
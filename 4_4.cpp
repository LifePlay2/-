#include <iostream>
#include <locale.h>
using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {}

    double Length() {
        double lenSq = x * x + y * y;
        if (lenSq == 0) return 0;

        double guess = lenSq / 2;
        for (int i = 0; i < 20; i++) {
            guess = (guess + lenSq / guess) / 2;
        }
        return guess;
    }

    Vector2D Normalized() {
        double len = Length();
        if (len == 0) return Vector2D(0, 0);
        return Vector2D(x / len, y / len);
    }

    Vector2D Sum(Vector2D other) {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D Sub(Vector2D other) {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D Mul(double k) {
        return Vector2D(x * k, y * k);
    }

    Vector2D Div(double k) {
        return Vector2D(x / k, y / k);
    }

    void Print() {
        cout << "(" << x << ", " << y << ")";
    }
};

int main()
{
    setlocale(LC_ALL, "ru-RU");

    Vector2D a(3, 4);
    Vector2D b(1, 2);

    cout << "a = ";
    a.Print();
    cout << ", |a| = " << a.Length() << endl;

    cout << "a + b = ";
    a.Sum(b).Print();
    cout << endl;

    cout << "a - b = ";
    a.Sub(b).Print();
    cout << endl;

    cout << "a * 4 = ";
    a.Mul(4).Print();
    cout << endl;

    cout << "a / 10 = ";
    a.Div(10).Print();
    cout << endl;

    //цепка: a.Sum(b).Sub(b).Mul(4).Div(10)
    cout << "a.Sum(b).Sub(b).Mul(4).Div(10) = ";
    a.Sum(b).Sub(b).Mul(4).Div(10).Print();
    cout << endl;

    cout << "Нормализованный a = ";
    a.Normalized().Print();
    cout << endl;
}
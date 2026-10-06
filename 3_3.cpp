#include <iostream>
#include <locale.h>
using namespace std;

struct Vector3D {
    double x;
    double y;
    double z;

    Vector3D() : x(0), y(0), z(0) {}

    Vector3D(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

    double LengthSquared() {
        return x * x + y * y + z * z;
    }

    double Length() {
        double lenSq = LengthSquared();
        if (lenSq == 0) return 0;

        double guess = lenSq / 2;
        for (int i = 0; i < 20; i++) {
            guess = (guess + lenSq / guess) / 2;
        }
        return guess;
    }

    Vector3D Sum(Vector3D other) {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D Sub(Vector3D other) {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    Vector3D Div(double k) {
        return Vector3D(x / k, y / k, z / k);
    }

    Vector3D Mul(double k) {
        return Vector3D(x * k, y * k, z * k);
    }

    Vector3D Normalize() {
        double len = Length();
        if (len == 0) return Vector3D(0, 0, 0);
        return Vector3D(x / len, y / len, z / len);
    }

    void Print() {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");
    Vector3D a(3, 4, 0);
    Vector3D b(1, 2, 3);

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

    cout << "Нормализованный a = ";
    a.Normalize().Print();
    cout << endl;
}
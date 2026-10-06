#include <iostream>
#include <locale.h>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {}

    double getX() { return x; }
    double getY() { return y; }

    double DistanceTo(Point other) {
        double dx = x - other.x;
        double dy = y - other.y;
        return dx * dx + dy * dy;
    }

    void Print() {
        cout << "(" << x << ", " << y << ")";
    }
};
int main() {
    setlocale(LC_ALL, "ru-RU");
    Point A(3, 4);
    Point B;

    cout << "Точка A: ";
    A.Print();
    cout << endl;

    cout << "Точка B: ";
    B.Print();
    cout << endl;

    cout << "Квадрат расстояния от A до B: " << A.DistanceTo(B) << endl;
}
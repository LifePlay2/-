#include <iostream>

using namespace std;

class Point {
private:
    int x;
    int y;

    Point(int xVal, int yVal) : x(xVal), y(yVal) {}

public:
    static Point CreatePoint(int xVal, int yVal) {
        return Point(xVal, yVal);
    }

    void Print() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Point p = Point::CreatePoint(10, 20);
    p.Print();
}
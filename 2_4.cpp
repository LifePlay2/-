#include <iostream>
#include <locale.h>
using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getWidth() { return width; }
    double getHeight() { return height; }

    double Area() {
        return width * height;
    }

    double Perimeter() {
        return 2 * (width + height);
    }

    void Print() {
        cout << "Прямоугольник: ширина = " << width
            << ", высота = " << height << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");
    Rectangle rect(5, 3);
    rect.Print();

    cout << "Площадь: " << rect.Area() << endl;
    cout << "Периметр: " << rect.Perimeter() << endl;
}
#include <iostream>
#include <locale.h>

using namespace std;

class Shape {
public:
    virtual double Area() { return 0; }
    virtual double Perimeter() { return 0; }
    virtual ~Shape() {}
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double Area() override { return side * side; }
    double Perimeter() override { return 4 * side; }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double Area() override { return width * height; }
    double Perimeter() override { return 2 * (width + height); }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area() override { return 3.14159 * radius * radius; }
    double Perimeter() override { return 2 * 3.14159 * radius; }
};

int main() {
    setlocale(LC_ALL, "ru-RU");

    Shape* s1 = new Square(4);
    Shape* s2 = new Rectangle(3, 5);
    Shape* s3 = new Circle(2);

    cout << "Квадрат: Площадь = " << s1->Area() << ", Периметр = " << s1->Perimeter() << endl;
    cout << "Прямоугольник: Площадь = " << s2->Area() << ", Периметр = " << s2->Perimeter() << endl;
    cout << "Круг: Площадь = " << s3->Area() << ", Периметр = " << s3->Perimeter() << endl;

    delete s1;
    delete s2;
    delete s3;
}
#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

class Student {
private:
    string name;
    int age;
    double averageGrade;

public:
    Student(string n, int a, double g) : name(n), age(a), averageGrade(g) {}

    string getName() { return name; }
    int getAge() { return age; }
    double getAverageGrade() { return averageGrade; }

    void SetAverageGrade(double g) {
        if (g >= 0 && g <= 10) {
            averageGrade = g;
        }
        else {
            cout << "Ошибка: оценка должна быть в диапазоне [0; 10]" << endl;
        }
    }

    void Print() {
        cout << "Студент: " << name
            << ", возраст: " << age
            << ", средняя оценка: " << averageGrade << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");

    Student student("Иван", 20, 8.5);
    student.Print();

    student.SetAverageGrade(9.2);
    student.Print();

    student.SetAverageGrade(11);
    student.Print();
}
/* 2
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
*/
/* 3
#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;
    const int accountNumber;

public:
    BankAccount(string o, double b, int accNum)
        : owner(o), balance(b), accountNumber(accNum) {
    }

    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Счёт пополнен на " << amount
                << ". Текущий баланс: " << balance << endl;
        }
        else {
            cout << "Ошибка: сумма пополнения должна быть положительной" << endl;
        }
    }

    void Withdraw(double amount) {
        if (amount > balance) {
            cout << "Ошибка: недостаточно средств. На балансе: "
                << balance << endl;
        }
        else if (amount <= 0) {
            cout << "Ошибка: сумма снятия должна быть положительной" << endl;
        }
        else {
            balance -= amount;
            cout << "Снято " << amount
                << ". Текущий баланс: " << balance << endl;
        }
    }

    void Print() {
        cout << "Владелец: " << owner
            << ", номер счёта: " << accountNumber
            << ", баланс: " << balance << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");
    BankAccount account("Петров", 1000, 12345);
    account.Print();

    account.Deposit(500);
    account.Withdraw(2000);
    account.Withdraw(300);
    account.Print();
}*/

/* 4
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
}*/
/* 3_1
#include <iostream>
#include <locale.h>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    int GetHours() { return hours; }
    int GetMinutes() { return minutes; }
    int GetSeconds() { return seconds; }

    void SetHours(int h) {
        if (h >= 0 && h <= 23) {
            hours = h;
        }
        else {
            cout << "Ошибка: часы должны быть в диапазоне [0; 23]" << endl;
        }
    }

    void SetMinutes(int m) {
        if (m >= 0 && m <= 59) {
            minutes = m;
        }
        else {
            cout << "Ошибка: минуты должны быть в диапазоне [0; 59]" << endl;
        }
    }

    void SetSeconds(int s) {
        if (s >= 0 && s <= 59) {
            seconds = s;
        }
        else {
            cout << "Ошибка: секунды должны быть в диапазоне [0; 59]" << endl;
        }
    }

    void GetTime() {
        if (hours < 10) cout << "0";
        cout << hours << ":";

        if (minutes < 10) cout << "0";
        cout << minutes << ":";

        if (seconds < 10) cout << "0";
        cout << seconds << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");
    Time t(9, 5, 3);
    t.GetTime();

    t.SetHours(23);
    t.SetMinutes(59);
    t.SetSeconds(59);
    t.GetTime();

    t.SetHours(25);
    t.SetMinutes(70);
    t.SetSeconds(-1);
    t.GetTime();
}*/
/* 3_2
#include <iostream>
#include <locale.h>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int GetDay() { return day; }
    int GetMonth() { return month; }
    int GetYear() { return year; }

    void SetDay(int d) {
        if (d >= 1 && d <= 31) {
            day = d;
        }
        else {
            cout << "Ошибка: день должен быть в диапазоне [1; 31]" << endl;
        }
    }

    void SetMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
        }
        else {
            cout << "Ошибка: месяц должен быть в диапазоне [1; 12]" << endl;
        }
    }

    void SetYear(int y) {
        if (y >= 1900 && y <= 2100) {
            year = y;
        }
        else {
            cout << "Ошибка: год должен быть в диапазоне [1900; 2100]" << endl;
        }
    }

    void GetDate() {
        if (day < 10) cout << "0";
        cout << day << ".";

        if (month < 10) cout << "0";
        cout << month << ".";

        cout << year << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");
    Date d(7, 5, 2024);
    d.GetDate();

    d.SetDay(31);
    d.SetMonth(12);
    d.SetYear(2100);
    d.GetDate();

    d.SetDay(0);
    d.SetMonth(13);
    d.SetYear(2200);
    d.GetDate();
}
*/
/* 3_3
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
}*/
/* 3_4
#include <iostream>
#include <locale.h>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:

    Array(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    ~Array() {
        delete[] data;
    }

    void Set(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
        else {
            cout << "Ошибка: индекс вне диапазона" << endl;
        }
    }

    int Get(int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            cout << "Ошибка: индекс вне диапазона" << endl;
            return -1;
        }
    }

    int GetSize() {
        return size;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");
    Array arr(5);

    for (int i = 0; i < arr.GetSize(); i++) {
        arr.Set(i, (i + 1) * 10);
    }

    cout << "Размер массива: " << arr.GetSize() << endl;
    for (int i = 0; i < arr.GetSize(); i++) {
        cout << "arr[" << i << "] = " << arr.Get(i) << endl;
    }

    arr.Set(10, 999);
    cout << "arr.Get(10) = " << arr.Get(10) << endl;
}
*/
/* 4_2
#include <iostream>
#include <locale.h>
using namespace std;

class String {
private:
    char* data;
    int length;

public:

    String() : length(0) {
        data = new char[1];
        data[0] = '\0';
    }

    String(char* str) {
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        length = len;
        data = new char[length + 1];
        for (int i = 0; i < length; i++) {
            data[i] = str[i];
        }
        data[length] = '\0';
    }

    String(String& other) : length(other.length) {
        data = new char[length + 1];
        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
        data[length] = '\0';
    }

    ~String() {
        delete[] data;
    }

    char* GetData() {
        return data;
    }

    char GetAt(int index) {
        if (index >= 0 && index < length) {
            return data[index];
        }
        return '\0';
    }

    int GetLength() {
        return length;
    }
};

int main()
{
    setlocale(LC_ALL, "ru-RU");
    String s1;
    cout << "s1: '" << s1.GetData() << "' (длина " << s1.GetLength() << ")" << endl;

    char raw[] = "Hello";
    String s2(raw);
    cout << "s2: '" << s2.GetData() << "' (длина " << s2.GetLength() << ")" << endl;

    String s3(s2);
    cout << "s3: '" << s3.GetData() << "' (длина " << s3.GetLength() << ")" << endl;

    cout << "s2[1] = " << s2.GetAt(1) << endl;
}
*/
/* 4_3
#include <iostream>
#include <locale.h>
using namespace std;

class Stack {
private:
    int* data;
    int capacity;
    int topIndex;

public:
    Stack() : capacity(100), topIndex(-1) {
        data = new int[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void Push(int value) {
        if (topIndex + 1 >= capacity) {
            int newCapacity = capacity * 2;
            int* newData = new int[newCapacity];
            for (int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
            cout << "Расширение стека до " << capacity << " элементов" << endl;
        }
        topIndex++;
        data[topIndex] = value;
    }

    int Pop() {
        if (topIndex < 0) {
            cout << "Стек пуст" << endl;
            return -1;
        }
        int value = data[topIndex];
        topIndex--;
        return value;
    }

    bool Empty() {
        return topIndex < 0;
    }

    int Size() {
        return topIndex + 1;
    }
};

int main()
{
    setlocale(LC_ALL, "ru-RU");
    Stack st;

    for (int i = 1; i <= 105; i++) {
        st.Push(i);
    }

    cout << "Размер стека: " << st.Size() << endl;

    while (!st.Empty()) {
        cout << st.Pop() << " ";
    }
    cout << endl;

    cout << "Стек пуст? " << (st.Empty() ? "да" : "нет") << endl;
}
*/
/* 4_3
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
*/
/* 5_1
#include <iostream>
#include <locale.h>
using namespace std;

class Counter {
private:
    int value;

public:
    Counter(int v = 0) : value(v) {}

    Counter operator++() {
        value++;
        return *this;
    }

    Counter operator++(int) {
        Counter temp = *this;
        value++;
        return temp;
    }

    void Print() {
        cout << value << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru-RU");
    Counter c1(5);
    c1.Print();

    ++c1;
    c1.Print();

    c1++;
    c1.Print();
}
*/
/* 5_2
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
*/
/*
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
*/
/* 5_3
#include <iostream>

using namespace std;

class Mouse;

class Cat {
private:
    char* name;

public:
    Cat(char* n) {
        int len = 0;
        while (n[len] != '\0') len++;
        name = new char[len + 1];
        for (int i = 0; i < len; i++) name[i] = n[i];
        name[len] = '\0';
    }

    Cat(Cat& other) {
        int len = 0;
        while (other.name[len] != '\0') len++;
        name = new char[len + 1];
        for (int i = 0; i < len; i++) name[i] = other.name[i];
        name[len] = '\0';
    }

    ~Cat() {
        delete[] name;
    }

    void SayHello(Mouse m);

    friend class Mouse;
};

class Mouse {
private:
    char* name;

public:
    Mouse(char* n) {
        int len = 0;
        while (n[len] != '\0') len++;
        name = new char[len + 1];
        for (int i = 0; i < len; i++) name[i] = n[i];
        name[len] = '\0';
    }

    Mouse(Mouse& other) {
        int len = 0;
        while (other.name[len] != '\0') len++;
        name = new char[len + 1];
        for (int i = 0; i < len; i++) name[i] = other.name[i];
        name[len] = '\0';
    }

    ~Mouse() {
        delete[] name;
    }

    void SayHello(Cat c) {
        cout << "Hello, my name is " << name << ". I am friend " << c.name << endl;
    }

    friend class Cat;
};

void Cat::SayHello(Mouse m) {
    cout << "Hello, my name is " << name << ". I am friend " << m.name << endl;
}

int main()
{
    char catName[] = "Barsik";
    char mouseName[] = "Jerry";

    Cat cat(catName);
    Mouse mouse(mouseName);

    cat.SayHello(mouse);
    mouse.SayHello(cat);
}
*/
/* 6_1
#include <iostream>
#include <locale.h>
using namespace std;

class Animal {
private:
    static int count;

public:
    Animal() {
        count++;
    }

    ~Animal() {
        count--;
    }

    int operator++() {
        count++;
        return count;
    }

    int operator--() {
        count--;
        return count;
    }

    operator int() {
        return count;
    }
};

int Animal::count = 0;

int main()
{
    setlocale(LC_ALL, "ru-RU");
    Animal a1;
    Animal a2;

    cout << "Count: " << (int)a1 << endl;

    ++a1;
    cout << "After ++: " << (int)a1 << endl;

    --a1;
    cout << "After --: " << (int)a1 << endl;
}
*/
/* 6_2
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
*/
/* 6_3
#include <iostream>
#include <locale.h>

using namespace std;

class Matrix {
private:
    int mat[2][2];

public:
    Matrix() {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                mat[i][j] = 0;
    }

    Matrix(int a, int b, int c, int d) {
        mat[0][0] = a; mat[0][1] = b;
        mat[1][0] = c; mat[1][1] = d;
    }

    int GetItem(int i, int j) {
        if (i >= 0 && i < 2 && j >= 0 && j < 2) return mat[i][j];
        return 0;
    }

    Matrix operator+(Matrix other) {
        return Matrix(
            mat[0][0] + other.mat[0][0], mat[0][1] + other.mat[0][1],
            mat[1][0] + other.mat[1][0], mat[1][1] + other.mat[1][1]
        );
    }

    Matrix operator-(Matrix other) {
        return Matrix(
            mat[0][0] - other.mat[0][0], mat[0][1] - other.mat[0][1],
            mat[1][0] - other.mat[1][0], mat[1][1] - other.mat[1][1]
        );
    }

    Matrix operator*(double k) {
        return Matrix(
            mat[0][0] * k, mat[0][1] * k,
            mat[1][0] * k, mat[1][1] * k
        );
    }

    Matrix operator/(double k) {
        if (k == 0) return Matrix();
        return Matrix(
            mat[0][0] / k, mat[0][1] / k,
            mat[1][0] / k, mat[1][1] / k
        );
    }

    Matrix operator*(Matrix other) {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.mat[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    res.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return res;
    }

    friend ostream& operator<<(ostream& os, Matrix m) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                os << m.mat[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");

    Matrix m1(1, 2, 3, 4);
    Matrix m2(5, 6, 7, 8);

    cout << "Матрица m1:" << endl << m1;
    cout << "Матрица m2:" << endl << m2;

    cout << "m1 + m2:" << endl << (m1 + m2);
    cout << "m1 - m2:" << endl << (m1 - m2);
    cout << "m1 * 2:" << endl << (m1 * 2);
    cout << "m1 / 2:" << endl << (m1 / 2);
    cout << "m1 * m2:" << endl << (m1 * m2);
    cout << "Элемент m1[1][0]: " << m1.GetItem(1, 0) << endl;
}
*/
/* 6_4
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
*/
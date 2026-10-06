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
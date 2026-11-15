#include <iostream>
#include <locale.h>

using namespace std;

class Human {
protected:
    char* name;

public:
    Human(char* n) {
        int len = 0; while (n[len] != '\0') len++;
        name = new char[len + 1];
        for (int i = 0; i < len; i++) name[i] = n[i];
        name[len] = '\0';
    }

    virtual ~Human() {
        delete[] name;
    }

    virtual void Info() {
        cout << "Имя: " << name << endl;
    }
};

class Student : public Human {
private:
    int course;

public:
    Student(char* n, int c) : Human(n), course(c) {}

    void Info() override {
        cout << "Студент: " << name << ", Курс: " << course << endl;
    }
};

class Teacher : public Human {
private:
    char* position;

public:
    Teacher(char* n, char* p) : Human(n) {
        int len = 0; while (p[len] != '\0') len++;
        position = new char[len + 1];
        for (int i = 0; i < len; i++) position[i] = p[i];
        position[len] = '\0';
    }

    ~Teacher() {
        delete[] position;
    }

    void Info() override {
        cout << "Преподаватель: " << name << ", Должность: " << position << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");

    char n1[] = "Иван";
    char n2[] = "Петр";
    char pos[] = "Профессор";

    Human* people[2];
    people[0] = new Student(n1, 2);
    people[1] = new Teacher(n2, pos);

    for (int i = 0; i < 2; i++) {
        people[i]->Info();
    }

    for (int i = 0; i < 2; i++) {
        delete people[i];
    }
}
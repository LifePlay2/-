#include <iostream>
#include <locale.h>

using namespace std;

class Animal {
protected:
    char* name;
    int age;

public:
    Animal(char* n, int a) : age(a) {
        int len = 0; while (n[len] != '\0') len++;
        name = new char[len + 1];
        for (int i = 0; i < len; i++) name[i] = n[i];
        name[len] = '\0';
    }

    virtual ~Animal() {
        delete[] name;
    }

    virtual void SayHello() {}
};

class Cat : public Animal {
public:
    Cat(char* n, int a) : Animal(n, a) {}
    void SayHello() override {
        cout << "Кот: Привет, меня зовут " << name << ", мне " << age << " лет." << endl;
    }
};

class Dog : public Animal {
public:
    Dog(char* n, int a) : Animal(n, a) {}
    void SayHello() override {
        cout << "Собака: Привет, меня зовут " << name << ", мне " << age << " лет." << endl;
    }
};

class Duck : public Animal {
public:
    Duck(char* n, int a) : Animal(n, a) {}
    void SayHello() override {
        cout << "Утка: Привет, меня зовут " << name << ", мне " << age << " лет." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");

    char catName[] = "Barsik";
    char dogName[] = "Rex";
    char duckName[] = "Donald";

    Animal* animals[3];
    animals[0] = new Cat(catName, 3);
    animals[1] = new Dog(dogName, 5);
    animals[2] = new Duck(duckName, 2);

    for (int i = 0; i < 3; i++) {
        animals[i]->SayHello();
    }

    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }
}
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
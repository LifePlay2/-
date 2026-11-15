#include <iostream>
#include <locale.h>

using namespace std;

class Car {
protected:
    char* model;

public:
    Car(char* m) {
        int len = 0; while (m[len] != '\0') len++;
        model = new char[len + 1];
        for (int i = 0; i < len; i++) model[i] = m[i];
        model[len] = '\0';
    }

    virtual ~Car() {
        delete[] model;
    }

    virtual void Info() {
        cout << "Автомобиль: " << model << endl;
    }
};

class Sedan : public Car {
private:
    int doors;
public:
    Sedan(char* m, int d) : Car(m), doors(d) {}
    void Info() override {
        cout << "Седан: " << model << ", Количество дверей: " << doors << endl;
    }
};

class SUV : public Car {
private:
    bool isAWD;
public:
    SUV(char* m, bool awd) : Car(m), isAWD(awd) {}
    void Info() override {
        cout << "Внедорожник: " << model << ", Полный привод: " << (isAWD ? "Да" : "Нет") << endl;
    }
};

class Truck : public Car {
private:
    double capacity;
public:
    Truck(char* m, double c) : Car(m), capacity(c) {}
    void Info() override {
        cout << "Грузовик: " << model << ", Грузоподъемность: " << capacity << " тонн" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");

    char m1[] = "Toyota Camry";
    char m2[] = "Jeep Wrangler";
    char m3[] = "Volvo FH";

    Car* cars[3];
    cars[0] = new Sedan(m1, 4);
    cars[1] = new SUV(m2, true);
    cars[2] = new Truck(m3, 20.5);

    for (int i = 0; i < 3; i++) {
        cars[i]->Info();
    }

    for (int i = 0; i < 3; i++) {
        delete cars[i];
    }
}
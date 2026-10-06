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

    cout << "Размер: " << arr.GetSize() << endl;
    for (int i = 0; i < arr.GetSize(); i++) {
        cout << "arr[" << i << "] = " << arr.Get(i) << endl;
    }

    arr.Set(10, 100);
}
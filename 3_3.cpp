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

int main() {
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
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

int main() {
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
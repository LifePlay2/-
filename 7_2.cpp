#include <iostream>

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
        while (str[len] != '\0') len++;
        length = len;
        data = new char[length + 1];
        for (int i = 0; i < length; i++) data[i] = str[i];
        data[length] = '\0';
    }
    String(String& other) : length(other.length) {
        data = new char[length + 1];
        for (int i = 0; i < length; i++) data[i] = other.data[i];
        data[length] = '\0';
    }
    ~String() {
        delete[] data;
    }
    char operator[](int index) {
        if (index >= 0 && index < length) return data[index];
        return '\0';
    }

    bool operator==(String other) {
        if (length != other.length) return false;
        for (int i = 0; i < length; i++) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }
    bool operator!=(String other) { return !(*this == other); }
    bool operator<(String other) {
        int minLen = length < other.length ? length : other.length;
        for (int i = 0; i < minLen; i++) {
            if (data[i] < other.data[i]) return true;
            if (data[i] > other.data[i]) return false;
        }
        return length < other.length;
    }
    bool operator>(String other) { return other < *this; }
    void Print() {
        cout << data << endl;
    }
};

int main() {
    char str1[] = "Apple";
    char str2[] = "Banana";
    char str3[] = "Apple";

    String s1(str1);
    String s2(str2);
    String s3(str3);

    s1.Print();
    s2.Print();

    if (s1 == s3) cout << "s1 == s3" << endl;
    if (s1 != s2) cout << "s1 != s2" << endl;
    if (s1 < s2) cout << "s1 < s2" << endl;
}
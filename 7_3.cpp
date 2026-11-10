#include <iostream>

using namespace std;

struct Result {
    bool exists;
    double x;

    Result() : exists(false), x(0) {}
    Result(double val) : exists(true), x(val) {}

    void Print() {
        if (exists) cout << x << endl;
        else cout << "No root" << endl;
    }
};
class Quadratic {
private:
    double a, b, c;
    double NewtonSqrt(double n) {
        if (n <= 0) return 0;
        double guess = n / 2;
        if (guess == 0) guess = 1;
        for (int i = 0; i < 20; i++) {
            guess = (guess + n / guess) / 2;
        }
        return guess;
    }
public:
    Quadratic(double aVal = 1, double bVal = 0, double cVal = 0)
        : a(aVal), b(bVal), c(cVal) {
    }

    Result operator()(int rootIndex) {
        double D = b * b - 4 * a * c;

        if (rootIndex == 1) {
            if (D < 0) return Result();
            return Result((-b + NewtonSqrt(D)) / (2 * a));
        }
        else if (rootIndex == 2) {
            if (D < 0) return Result();
            return Result((-b - NewtonSqrt(D)) / (2 * a));
        }

        return Result();
    }
};
int main() {
    Quadratic eq1(1, -3, 2);

    Result r1 = eq1(1);
    r1.Print();

    Result r2 = eq1(2);
    r2.Print();

    Quadratic eq2(1, 0, 1);
    Result r3 = eq2(1);
    r3.Print();
}
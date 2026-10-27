#include <iostream>
#include <locale.h>

using namespace std;

class Matrix {
private:
    int mat[2][2];

public:
    Matrix() {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                mat[i][j] = 0;
    }

    Matrix(int a, int b, int c, int d) {
        mat[0][0] = a; mat[0][1] = b;
        mat[1][0] = c; mat[1][1] = d;
    }

    int GetItem(int i, int j) {
        if (i >= 0 && i < 2 && j >= 0 && j < 2) return mat[i][j];
        return 0;
    }

    Matrix operator+(Matrix other) {
        return Matrix(
            mat[0][0] + other.mat[0][0], mat[0][1] + other.mat[0][1],
            mat[1][0] + other.mat[1][0], mat[1][1] + other.mat[1][1]
        );
    }

    Matrix operator-(Matrix other) {
        return Matrix(
            mat[0][0] - other.mat[0][0], mat[0][1] - other.mat[0][1],
            mat[1][0] - other.mat[1][0], mat[1][1] - other.mat[1][1]
        );
    }

    Matrix operator*(double k) {
        return Matrix(
            mat[0][0] * k, mat[0][1] * k,
            mat[1][0] * k, mat[1][1] * k
        );
    }

    Matrix operator/(double k) {
        if (k == 0) return Matrix();
        return Matrix(
            mat[0][0] / k, mat[0][1] / k,
            mat[1][0] / k, mat[1][1] / k
        );
    }

    Matrix operator*(Matrix other) {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.mat[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    res.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return res;
    }

    friend ostream& operator<<(ostream& os, Matrix m) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                os << m.mat[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");

    Matrix m1(1, 2, 3, 4);
    Matrix m2(5, 6, 7, 8);

    cout << "Матрица m1:" << endl << m1;
    cout << "Матрица m2:" << endl << m2;

    cout << "m1 + m2:" << endl << (m1 + m2);
    cout << "m1 - m2:" << endl << (m1 - m2);
    cout << "m1 * 2:" << endl << (m1 * 2);
    cout << "m1 / 2:" << endl << (m1 / 2);
    cout << "m1 * m2:" << endl << (m1 * m2);
    cout << "Элемент m1[1][0]: " << m1.GetItem(1, 0) << endl;
}
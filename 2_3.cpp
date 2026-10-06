#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;
    const int accountNumber;

public:
    BankAccount(string o, double b, int accNum)
        : owner(o), balance(b), accountNumber(accNum) {
    }

    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Счёт пополнен на " << amount
                << ". Текущий баланс: " << balance << endl;
        }
        else {
            cout << "Ошибка: сумма пополнения должна быть положительной" << endl;
        }
    }

    void Withdraw(double amount) {
        if (amount > balance) {
            cout << "Ошибка: недостаточно средств. На балансе: "
                << balance << endl;
        }
        else if (amount <= 0) {
            cout << "Ошибка: сумма снятия должна быть положительной" << endl;
        }
        else {
            balance -= amount;
            cout << "Снято " << amount
                << ". Текущий баланс: " << balance << endl;
        }
    }

    void Print() {
        cout << "Владелец: " << owner
            << ", номер счёта: " << accountNumber
            << ", баланс: " << balance << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");
    BankAccount account("Петров", 1000, 12345);
    account.Print();

    account.Deposit(500);
    account.Withdraw(2000);
    account.Withdraw(300);
    account.Print();
}
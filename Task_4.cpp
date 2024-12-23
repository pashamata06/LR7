#include <iostream>
using namespace std;

// Функция проверки делимости через побитовые операции
bool isDivisible(int number, int prime) {
    int temp = prime;
    while (number >= temp) {
        temp <<= 1; // Увеличиваем делитель вдвое .
    }
    while (temp > prime) {
        temp >>= 1; // Уменьшаем делитель вдвое .
        if (number >= temp) {
            number -= temp; // Вычитаем текущий делитель.
        }
    }
    return number == 0;
}

int main() {
    int number;
    cout << "Введите число: ";
    cin >> number;

    if (isDivisible(number, 3)) {
        cout << number << " делится на 3" << endl;
    } else {
        cout << number << " не делится на 3" << endl;
    }

    if (isDivisible(number, 61)) {
        cout << number << " делится на 61" << endl;
    } else {
        cout << number << " не делится на 61" << endl;
    }

    if (isDivisible(number, 131)) {
        cout << number << " делится на 131" << endl;
    } else {
        cout << number << " не делится на 131" << endl;
    }

    return 0;
}
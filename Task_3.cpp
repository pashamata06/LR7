#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Преобразование символа в значение
int charToValue(char c) {
    return isdigit(c) ? c - '0' : toupper(c) - 'A' + 10;
}

// Преобразование значения в символ
char valueToChar(int value) {
    return value < 10 ? '0' + value : 'A' + (value - 10);
}

// Сложение двух чисел в заданной системе счисления
string addNumbers(const string &num1, const string &num2, int base) {
    string result;
    int carry = 0, i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? charToValue(num1[i--]) : 0;
        int digit2 = (j >= 0) ? charToValue(num2[j--]) : 0;

        int sum = digit1 + digit2 + carry;
        result.push_back(valueToChar(sum % base));
        carry = sum / base;
    }

    reverse(result.begin(), result.end());
    return result;
}

// Вычитание двух чисел в заданной системе счисления
string subtractNumbers(const string &num1, const string &num2, int base) {
    string result;
    int borrow = 0, i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? charToValue(num1[i--]) : 0;
        int digit2 = (j >= 0) ? charToValue(num2[j--]) : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += base;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_back(valueToChar(diff));
    }

    // Удаление ведущих нулей
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int base;
    string num1, num2;

    cout << "Введите основание системы счисления (2-36): ";
    cin >> base;
    if (base < 2 || base > 36) {
        cout << "Ошибка: основание должно быть в пределах от 2 до 36." << endl;
        return 1;
    }

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;

    string result = addNumbers(num1, num2, base);

    cout << "Результат: " << result << endl;
    return 0;
}

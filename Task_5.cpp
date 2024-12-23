#include <iostream>
#include <vector>
#include <cmath>

// Функция для преобразования номера бочки в двоичный код
std::vector<int> getBinary(int number, int bits) {
    std::vector<int> binary(bits, 0);
    for (int i = 0; i < bits; ++i) {
        binary[i] = (number >> i) & 1;
    }
    return binary;
}

int main() {
    const int barrels = 240; // Количество бочек
    const int slaves = 5;    // Количество рабов

    // Генерация отравленной бочки (для проверки)
    int poisonedBarrel;
    std::cout << "Введите номер отравленной бочки (0-240): ";
    std::cin >> poisonedBarrel;

    if (poisonedBarrel < 0 || poisonedBarrel >= barrels) {
        std::cerr << "Некорректный номер бочки. Завершение программы." << std::endl;
        return 1;
    }

    // Получение двоичного представления отравленной бочки
    std::vector<int> poisonedBinary = getBinary(poisonedBarrel, slaves);

    // Моделирование: кто из рабов пробует вино
    std::vector<bool> slavesResult(slaves, false);
    for (int i = 0; i < slaves; ++i) {
        if (poisonedBinary[i] == 1) {
            slavesResult[i] = true; // Раб выпил отравленное вино
        }
    }

    // Вывод результатов, кто из рабов погибнет
    std::cout << "Результаты:" << std::endl;
    for (int i = 0; i < slaves; ++i) {
        std::cout << "Раб " << i + 1 << ": " << (slavesResult[i] ? "Погиб" : "Выжил") << std::endl;
    }

    // Определение отравленной бочки по погибшим рабам
    int detectedBarrel = 0;
    for (int i = 0; i < slaves; ++i) {
        if (slavesResult[i]) {
            detectedBarrel += std::pow(2, i);
        }
    }

    std::cout << "Отравленная бочка: " << detectedBarrel << std::endl;

    // Проверка 
    if (detectedBarrel == poisonedBarrel) {
        std::cout << "Отравленная бочка определена правильно!" << std::endl;
    } else {
        std::cout << "Ошибка в определении отравленной бочки." << std::endl;
    }

    return 0;
}
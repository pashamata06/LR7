#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// Функция для преобразования числа в двоичное представление (прямой код)
std::string toDirectCode(const std::vector<int>& numbers) {
    std::string result;
    for (size_t i = 0; i < numbers.size(); ++i) { // Обычный цикл с индексом
        int num = numbers[i]; // Получаем элемент по индексу
        // Определяем знак числа и добавляем бит знака
        if (num < 0) {
            num = std::abs(num); // Преобразуем отрицательное число в положительное
            result += "1"; // Бит знака для отрицательного числа
        } else {
            result += "0"; // Бит знака для положительного числа
        }

        // Преобразуем число в двоичное представление
        std::string binary;
        while (num > 0) { // O(log(num))
            binary += (num % 2 == 0) ? '0' : '1'; // O(1)
            num /= 2; // O(1)
        }

        // Переворачиваем строку для получения правильного порядка битов
        std::reverse(binary.begin(), binary.end()); // O(n), где n — количество битов

        // Дополняем нулями до фиксированного размера (например, 8 бит)
        while (binary.size() < 8) {
            binary = "0" + binary; // O(n), повторяется до 8 итераций
        }

        // Добавляем результат в итоговую строку с разделением пробелом
        result += binary + " ";
    }
    return result;
}

// Функция для ввода чисел в вектор
void inputNumbers(std::vector<int>& numbers, int size) {
    std::cout << "Введите " << size << " целых чисел (положительных/отрицательных): ";
    for (int i = 0; i < size; ++i) {
        std::cin >> numbers[i]; // Ввод чисел в вектор
    }
}

// Функция для вывода результата
void outputResult(const std::string& result) {
    std::cout << "Двоичное представление в прямом коде: " << result << std::endl;
}

int main() {
    // Ввод размера массива
    int size;
    std::cout << "Введите количество чисел: ";
    std::cin >> size;

    // Создаем динамический массив (вектор) для хранения чисел
    std::vector<int> numbers(size);

    // Ввод чисел
    inputNumbers(numbers, size);

    // Преобразуем числа в прямой код
    std::string result = toDirectCode(numbers);

    // Вывод результата
    outputResult(result);

    return 0;
}


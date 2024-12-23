#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

// Функция для перевода числа в двоичную строку
std::string toBinary(int num) {
    if (num == 0) return "0";
    
    std::string bin = "";
    while (num > 0) {
        bin = (num % 2 == 0 ? "0" : "1") + bin;
        num /= 2;
    }
    return bin;
}

// Функция для перевода числа в обратный код
std::string toInverseBinary(int num) {
    std::string bin = toBinary(abs(num));
    if (num >= 0) {
        return bin; // для положительного числа прямой код совпадает с обратным
    } else {
        // Для отрицательного числа инвертируем биты
        for (int i = 0; i < bin.length(); i++) {
            bin[i] = (bin[i] == '0') ? '1' : '0';
        }
        return bin;
    }
}

// Функция для сложения чисел в обратном коде
std::string addInverseBinary(const std::string &bin1, const std::string &bin2) {
    int len = std::max(bin1.length(), bin2.length());
    
    std::string result = "";
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int bit1 = i < bin1.length() ? bin1[bin1.length() - 1 - i] - '0' : 0;
        int bit2 = i < bin2.length() ? bin2[bin2.length() - 1 - i] - '0' : 0;
        
        int sum = bit1 + bit2 + carry;
        result = std::to_string(sum % 2) + result;
        carry = sum / 2;
    }
    
    if (carry) {
        result = "1" + result;
    }
    
    return result;
}

// Функция для перевода числа из обратного кода в прямой код
std::string toDirectBinary(const std::string &inverseBin) {
    std::string bin = inverseBin;
    for (int i = 0; i < bin.length(); i++) {
        bin[i] = (bin[i] == '0') ? '1' : '0';
    }
    return bin;
}

int main() {
    int num1, num2;
    
    // Ввод двух чисел
    std::cout << "Введите два числа: ";
    std::cin >> num1 >> num2;
    
    // Перевод в обратный код
    std::string bin1 = toInverseBinary(num1);
    std::string bin2 = toInverseBinary(num2);
    
    // Сложение чисел в обратном коде
    std::string result = addInverseBinary(bin1, bin2);
    
    // Перевод результата в прямой код
    std::string directCode = toDirectBinary(result);
    
    std::cout << "Результат сложения в прямом коде: " << directCode << std::endl;
    
    return 0;
}

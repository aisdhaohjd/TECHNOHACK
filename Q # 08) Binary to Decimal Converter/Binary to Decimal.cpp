#include <iostream>
#include <string>
#include <cmath>

int binaryToDecimal(const std::string& binaryStr) {
    int decimal = 0;
    int power = 0;

    // Iterate through the binary string from right to left
    for (int i = binaryStr.length() - 1; i >= 0; i--) {
        if (binaryStr[i] == '1') {
            decimal += static_cast<int>(std::pow(2, power));
        }
        power++;
    }

    return decimal;
}

int main() {
    std::string binaryStr;

    std::cout << "Binary to Decimal Converter" << std::endl;
    std::cout << "Enter a binary number: ";
    std::cin >> binaryStr;

    // Check if the input is a valid binary number
    for (char c : binaryStr) {
        if (c != '0' && c != '1') {
            std::cout << "Invalid binary input. Please enter a valid binary number." << std::endl;
            return 1; // Exit with an error code
        }
    }

    int decimal = binaryToDecimal(binaryStr);

    std::cout << "Decimal equivalent: " << decimal << std::endl;

    return 0;
}

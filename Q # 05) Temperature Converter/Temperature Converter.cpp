#include <iostream>

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

int main() {
    char choice;

    std::cout << "Temperature Conversion Program" << std::endl;

    while (true) {
        std::cout << "Options:\n";
        std::cout << "1. Convert Fahrenheit to Celsius\n";
        std::cout << "2. Convert Celsius to Fahrenheit\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice (1/2/3): ";
        std::cin >> choice;

        if (choice == '1') {
            double fahrenheit;
            std::cout << "Enter temperature in Fahrenheit: ";
            std::cin >> fahrenheit;
            double celsius = fahrenheitToCelsius(fahrenheit);
            std::cout << "Temperature in Celsius: " << celsius << " °C" << std::endl;
        } else if (choice == '2') {
            double celsius;
            std::cout << "Enter temperature in Celsius: ";
            std::cin >> celsius;
            double fahrenheit = celsiusToFahrenheit(celsius);
            std::cout << "Temperature in Fahrenheit: " << fahrenheit << " °F" << std::endl;
        } else if (choice == '3') {
            std::cout << "Goodbye!" << std::endl;
            break; // Exit the program
        } else {
            std::cout << "Invalid choice. Please select 1, 2, or 3." << std::endl;
        }
    }

    return 0;
}

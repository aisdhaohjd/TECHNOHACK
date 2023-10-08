#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Function to generate a random password of the specified length
std::string generateRandomPassword(int length) {
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+";
    const int charsetLength = charset.length();

    std::string password;

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % charsetLength;
        password += charset[randomIndex];
    }

    return password;
}

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int passwordLength;
    std::cout << "Random Password Generator" << std::endl;

    // Get user-defined password length
    std::cout << "Enter the desired password length: ";
    std::cin >> passwordLength;

    if (passwordLength <= 0) {
        std::cout << "Invalid password length. Please enter a positive number." << std::endl;
        return 1; // Exit with an error code
    }

    // Generate and display the random password
    std::string password = generateRandomPassword(passwordLength);
    std::cout << "Generated Password: " << password << std::endl;

    return 0;
}

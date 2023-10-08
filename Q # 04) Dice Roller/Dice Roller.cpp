#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int rollDice() {
    return (rand() % 6) + 1; // Generate a random number between 1 and 6
}

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Welcome to the Dice Rolling Simulator!" << std::endl;

    while (true) {
        // Roll two dice
        int die1 = rollDice();
        int die2 = rollDice();

        // Display the result
        std::cout << "You rolled a " << die1 << " and a " << die2 << ". Total: " << die1 + die2 << std::endl;

        // Ask if the user wants to roll again
        std::cout << "Roll again? (y/n): ";
        char choice;
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            break; // Exit the loop if the user doesn't want to roll again
        }
    }

    return 0;
}

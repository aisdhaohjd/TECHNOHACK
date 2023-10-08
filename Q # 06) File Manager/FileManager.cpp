#include <iostream>
#include <string>
#include <filesystem> // Include <filesystem> directly

namespace fs = std::filesystem;

// Function to create a directory
bool createDirectory(const std::string& directoryName) {
    try {
        fs::create_directory(directoryName);
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Failed to create directory: " << e.what() << std::endl;
        return false;
    }
}

int main() {
    while (true) {
        std::cout << "File and Folder Management Program" << std::endl;
        std::cout << "Options:\n";
        std::cout << "1. Create Directory\n";
        std::cout << "2. List Files in Directory\n";
        std::cout << "3. Delete File\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1/2/3/4): ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        switch (choice) {
            case 1: {
                std::string directoryName;
                std::cout << "Enter directory name to create: ";
                std::cin >> directoryName;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

                if (createDirectory(directoryName)) {
                    std::cout << "Directory created: " << directoryName << std::endl;
                }
                break;
            }
            case 2: {
                std::string directoryPath;
                std::cout << "Enter directory path to list files: ";
                std::cin >> directoryPath;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

                std::cout << "Files in directory: " << directoryPath << std::endl;

                // List files in the directory
                for (const auto& entry : fs::directory_iterator(directoryPath)) {
                    std::cout << entry.path().filename() << std::endl;
                }
                break;
            }
            case 3: {
                std::string filePath;
                std::cout << "Enter file path to delete: ";
                std::cin >> filePath;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

                if (std::remove(filePath.c_str()) == 0) {
                    std::cout << "File deleted: " << filePath << std::endl;
                } else {
                    std::cerr << "Failed to delete file: " << filePath << std::endl;
                }
                break;
            }
            case 4:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please select 1, 2, 3, or 4." << std::endl;
        }
    }

    return 0;
}

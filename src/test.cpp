#include <iostream>
#include <string>
#include <cmath>

// This is the testing file I use for testing code
// It should be completely disconnected from any other C++ file

int main() {
    bool input_valid = false;
    std::string input_string;
    int input_int;
    while (!input_valid) {
        std::cout << "Enter a number from 1 to 9";
        std::cin >> input_string;
        try {
            input_int = std::stoi(input_string);
            if (input_int >= 1 && input_int <= 9) {
                input_valid = true;
            };
        }
        catch(...) {
            std::cout << "Invalid input format" << "\n";
        }
    };
    int row = std::floor((input_int - 1) / 3);
    int column = input_int - 3 * row - 1;
    std::cout << row << "\n";
    std::cout << column << "\n";
    return 0;
};

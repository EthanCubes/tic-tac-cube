#include <iostream>
#include <array>
#include <string>
#include <tuple>

#include "board.h"

int main_menu() {
    std::string input;
    std::cout << "Type 'exit' to exit, 'play' to play, and anything else to show this screen again.";
    std::cin >> input;
    if (input == "exit") {
        return 1;
    }
    else if (input == "play") {
        return 2;
    };
    return 0;
};

Cube_board cube;

int main() {
    int mode = 0;
    bool running = true;
    while (running) {
        switch(mode) {
            case 0:
                mode = main_menu();
                break;
            case 1:
                running = false;
                break;
            case 2:
                mode = cube.gameloop();
                break;
            default:
                std::cout << "Invalid command";
                mode = 0;
        };
    };
    return 0;
};

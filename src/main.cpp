#include <iostream>
#include <array>
#include "board.h"

int main() {
    std::array<std::array<std::array<int, 3>, 3>, 6> cube_pos = get_board();
    for (int face = 0; face < 6; face++) {
        for (int row = 0; row < 3; row++) {
            for (int column = 0; column < 3; column++) {
                std::cout << cube_pos[face][row][column];
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    return 0;
}

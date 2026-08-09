#include <iostream>
#include <array>
#include "board.h"

int main() {
    std::array<std::array<std:array<int, 3>, 3>, 6> cube_pos = get_board();
    std::cout << cube_pos;
    return 0;
}

#include <iostream>
#include <array>

class Cube_board {
    public:
        std::array<std::array<std::array<int, 3>, 3>, 6> positions = {{
            {{
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}
            }},
            {{
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}
            }},
            {{
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}
            }},
            {{
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}
            }},
            {{
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}
            }},
            {{
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}
            }}
        }};
};

int main() {
    Cube_board cube;
    for (int face = 0; face < 6; face++) {
        for (int row = 0; row < 3; row++) {
            for (int column = 0; column < 3; column++) {
                std::cout << cube.positions[face][row][column];
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    return 0;
}

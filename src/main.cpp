#include <iostream>
#include <array>
#include <string>

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

        // These are named after the actual moves in Rubik's cube notation. X, Y, and Z are all rotations
        // These are the basic moves that I will use to render the rest of the moves
        std::array<std::array<std::array<int, 3>, 3>, 6> temporary_array;
        
        void x_move() {
            temporary_array = positions;
        };
        void y_move() {
            temporary_array = positions;
        };
        void z_move() {
            temporary_array = positions;
        };
        void u_move() {
            temporary_array = positions;
        };
        // These are are the moved made out of the basic moves
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

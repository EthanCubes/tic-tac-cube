#include <array>

std::array<std::array<std::array<int, 3>, 3>, 6> cube_board_positions = {{
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

class cube_board {
    public:
        std::array<std::array<std::array<int, 3>, 3>, 6> get_board() {
            return cube_board_positions;
        };
}

#include <iostream>
#include <array>
#include <string>

class Cube_board {
    public:
        std::array<std::array<std::array<int, 3>, 3>, 6> positions = {{
            {{
                {0, 0, 0},
                {0, 0, 0}, {0, 0, 0} }},
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
            // White
            positions[0][0][0] = temporary_array[2][0][0];
            positions[0][0][1] = temporary_array[2][0][1];
            positions[0][0][2] = temporary_array[2][0][2];
            positions[0][1][0] = temporary_array[2][1][0];
            positions[0][1][1] = temporary_array[2][1][1];
            positions[0][1][2] = temporary_array[2][1][2];
            positions[0][2][0] = temporary_array[2][2][0];
            positions[0][2][1] = temporary_array[2][2][1];
            positions[0][2][2] = temporary_array[2][2][2];
            // Orange
            positions[1][0][0] = temporary_array[1][0][2];
            positions[1][0][1] = temporary_array[1][1][2];
            positions[1][0][2] = temporary_array[1][2][2];
            positions[1][1][0] = temporary_array[1][0][1];
            positions[1][1][1] = temporary_array[1][1][1];
            positions[1][1][2] = temporary_array[1][2][1];
            positions[1][2][0] = temporary_array[1][0][0];
            positions[1][2][1] = temporary_array[1][1][0];
            positions[1][2][2] = temporary_array[1][2][0];
            // Green
            positions[2][0][0] = temporary_array[5][0][0];
            positions[2][0][1] = temporary_array[5][0][1];
            positions[2][0][2] = temporary_array[5][0][2];
            positions[2][1][0] = temporary_array[5][1][0];
            positions[2][1][1] = temporary_array[5][1][1];
            positions[2][1][2] = temporary_array[5][1][2];
            positions[2][2][0] = temporary_array[5][2][0];
            positions[2][2][1] = temporary_array[5][2][1];
            positions[2][2][2] = temporary_array[5][2][2];
            // Red
            positions[3][0][0] = temporary_array[3][2][0];
            positions[3][0][1] = temporary_array[3][1][0];
            positions[3][0][2] = temporary_array[3][0][0];
            positions[3][1][0] = temporary_array[3][2][1];
            positions[3][1][1] = temporary_array[3][1][1];
            positions[3][1][2] = temporary_array[3][0][1];
            positions[3][2][0] = temporary_array[3][2][2];
            positions[3][2][1] = temporary_array[3][1][2];
            positions[3][2][2] = temporary_array[3][0][2];
            // Blue
            positions[4][0][0] = temporary_array[0][2][2];
            positions[4][0][1] = temporary_array[0][2][1];
            positions[4][0][2] = temporary_array[0][2][0];
            positions[4][1][0] = temporary_array[0][1][2];
            positions[4][1][1] = temporary_array[0][1][1];
            positions[4][1][2] = temporary_array[0][1][0];
            positions[4][2][0] = temporary_array[0][0][2];
            positions[4][2][1] = temporary_array[0][0][1];
            positions[4][2][2] = temporary_array[0][0][0];
            // Yellow
            positions[5][0][0] = temporary_array[4][2][2];
            positions[5][0][1] = temporary_array[4][2][1];
            positions[5][0][2] = temporary_array[4][2][0];
            positions[5][1][0] = temporary_array[4][1][2];
            positions[5][1][1] = temporary_array[4][1][1];
            positions[5][1][2] = temporary_array[4][1][0];
            positions[5][2][0] = temporary_array[4][0][2];
            positions[5][2][1] = temporary_array[4][0][1];
            positions[5][2][2] = temporary_array[4][0][0];
        };

        void y_move() {
            temporary_array = positions;
            // White
            positions[0][0][0] = temporary_array[0][2][0];
            positions[0][0][1] = temporary_array[0][1][0];
            positions[0][0][2] = temporary_array[0][0][0];
            positions[0][1][0] = temporary_array[0][2][1];
            positions[0][1][1] = temporary_array[0][1][1];
            positions[0][1][2] = temporary_array[0][0][1];
            positions[0][2][0] = temporary_array[0][2][2];
            positions[0][2][1] = temporary_array[0][1][2];
            positions[0][2][2] = temporary_array[0][0][2];
            // Orange
            positions[1][0][0] = temporary_array[2][0][0];
            positions[1][0][1] = temporary_array[2][0][1];
            positions[1][0][2] = temporary_array[2][0][2];
            positions[1][1][0] = temporary_array[2][1][0];
            positions[1][1][1] = temporary_array[2][1][1];
            positions[1][1][2] = temporary_array[2][1][2];
            positions[1][2][0] = temporary_array[2][2][0];
            positions[1][2][1] = temporary_array[2][2][1];
            positions[1][2][2] = temporary_array[2][2][2];
            // Green
            positions[2][0][0] = temporary_array[3][0][0];
            positions[2][0][1] = temporary_array[3][0][1];
            positions[2][0][2] = temporary_array[3][0][2];
            positions[2][1][0] = temporary_array[3][1][0];
            positions[2][1][1] = temporary_array[3][1][1];
            positions[2][1][2] = temporary_array[3][1][2];
            positions[2][2][0] = temporary_array[3][2][0];
            positions[2][2][1] = temporary_array[3][2][1];
            positions[2][2][2] = temporary_array[3][2][2];
            // Red
            positions[3][0][0] = temporary_array[4][0][0];
            positions[3][0][1] = temporary_array[4][0][1];
            positions[3][0][2] = temporary_array[4][0][2];
            positions[3][1][0] = temporary_array[4][1][0];
            positions[3][1][1] = temporary_array[4][1][1];
            positions[3][1][2] = temporary_array[4][1][2];
            positions[3][2][0] = temporary_array[4][2][0];
            positions[3][2][1] = temporary_array[4][2][1];
            positions[3][2][2] = temporary_array[4][2][2];
            // Blue
            positions[4][0][0] = temporary_array[1][0][0];
            positions[4][0][1] = temporary_array[1][0][1];
            positions[4][0][2] = temporary_array[1][0][2];
            positions[4][1][0] = temporary_array[1][1][0];
            positions[4][1][1] = temporary_array[1][1][1];
            positions[4][1][2] = temporary_array[1][1][2];
            positions[4][2][0] = temporary_array[1][2][0]; 
            positions[4][2][1] = temporary_array[1][2][1];
            positions[4][2][2] = temporary_array[1][2][2];
            // Yellow
            positions[5][0][0] = temporary_array[5][0][2];
            positions[5][0][1] = temporary_array[5][1][2];
            positions[5][0][2] = temporary_array[5][2][2];
            positions[5][1][0] = temporary_array[5][0][1];
            positions[5][1][1] = temporary_array[5][1][1];
            positions[5][1][2] = temporary_array[5][2][1];
            positions[5][2][0] = temporary_array[5][0][0];
            positions[5][2][1] = temporary_array[5][1][0];
            positions[5][2][2] = temporary_array[5][2][0];
        };

        void z_move() {
            temporary_array = positions;
            // White
            positions[0][0][0] = temporary_array[1][2][0];
            positions[0][0][1] = temporary_array[1][1][0];
            positions[0][0][2] = temporary_array[1][0][0];
            positions[0][1][0] = temporary_array[1][2][1];
            positions[0][1][1] = temporary_array[1][1][1];
            positions[0][1][2] = temporary_array[1][0][1];
            positions[0][2][0] = temporary_array[1][2][2];
            positions[0][2][1] = temporary_array[1][1][2];
            positions[0][2][2] = temporary_array[1][0][2];
            // Orange
            positions[1][0][0] = temporary_array[5][2][0];
            positions[1][0][1] = temporary_array[5][1][0];
            positions[1][0][2] = temporary_array[5][0][0];
            positions[1][1][0] = temporary_array[5][2][1];
            positions[1][1][1] = temporary_array[5][1][1];
            positions[1][1][2] = temporary_array[5][0][1];
            positions[1][2][0] = temporary_array[5][2][2];
            positions[1][2][1] = temporary_array[5][1][2];
            positions[1][2][2] = temporary_array[5][0][2];
            // Green
            positions[2][0][0] = temporary_array[2][2][0];
            positions[2][0][1] = temporary_array[2][1][0];
            positions[2][0][2] = temporary_array[2][0][0];
            positions[2][1][0] = temporary_array[2][2][1];
            positions[2][1][1] = temporary_array[2][1][1];
            positions[2][1][2] = temporary_array[2][0][1];
            positions[2][2][0] = temporary_array[2][2][2];
            positions[2][2][1] = temporary_array[2][1][2];
            positions[2][2][2] = temporary_array[2][0][2];
            // Red
            positions[3][0][0] = temporary_array[0][2][0];
            positions[3][0][1] = temporary_array[0][1][0];
            positions[3][0][2] = temporary_array[0][0][0];
            positions[3][1][0] = temporary_array[0][2][1];
            positions[3][1][1] = temporary_array[0][1][1];
            positions[3][1][2] = temporary_array[0][0][1];
            positions[3][2][0] = temporary_array[0][2][2];
            positions[3][2][1] = temporary_array[0][1][2];
            positions[3][2][2] = temporary_array[0][0][2];
            // Blue
            positions[4][0][0] = temporary_array[4][2][0];
            positions[4][0][1] = temporary_array[4][1][0];
            positions[4][0][2] = temporary_array[4][0][0];
            positions[4][1][0] = temporary_array[4][2][1];
            positions[4][1][1] = temporary_array[4][1][1];
            positions[4][1][2] = temporary_array[4][0][1];
            positions[4][2][0] = temporary_array[4][2][2];
            positions[4][2][1] = temporary_array[4][1][2];
            positions[4][2][2] = temporary_array[4][0][2];
            // Yellow
            positions[5][0][0] = temporary_array[3][0][0];
            positions[5][0][1] = temporary_array[3][0][1];
            positions[5][0][2] = temporary_array[3][0][2];
            positions[5][1][0] = temporary_array[3][1][0];
            positions[5][1][1] = temporary_array[3][1][1];
            positions[5][1][2] = temporary_array[3][1][2];
            positions[5][2][0] = temporary_array[3][2][0];
            positions[5][2][1] = temporary_array[3][2][1];
            positions[5][2][2] = temporary_array[3][2][2];
        };

        void u_move() {
            temporary_array = positions;
            // White
            positions[0][0][0] = temporary_array[0][2][0];
            positions[0][0][1] = temporary_array[0][1][0];
            positions[0][0][2] = temporary_array[0][0][0];
            positions[0][1][0] = temporary_array[0][2][1];
            positions[0][1][1] = temporary_array[0][1][1];
            positions[0][1][2] = temporary_array[0][0][1];
            positions[0][2][0] = temporary_array[0][2][2];
            positions[0][2][1] = temporary_array[0][1][2];
            positions[0][2][2] = temporary_array[0][0][2];
            // Orange
            positions[1][0][0] = temporary_array[2][0][0];
            positions[1][0][1] = temporary_array[2][0][1];
            positions[1][0][2] = temporary_array[2][0][2];
            positions[1][1][0] = temporary_array[1][1][0];
            positions[1][1][1] = temporary_array[1][1][1];
            positions[1][1][2] = temporary_array[1][1][2];
            positions[1][2][0] = temporary_array[1][2][0];
            positions[1][2][1] = temporary_array[1][2][1];
            positions[1][2][2] = temporary_array[1][2][2];
            // Green
            positions[2][0][0] = temporary_array[3][0][0];
            positions[2][0][1] = temporary_array[3][0][1];
            positions[2][0][2] = temporary_array[3][0][2];
            positions[2][1][0] = temporary_array[2][1][0];
            positions[2][1][1] = temporary_array[2][1][1];
            positions[2][1][2] = temporary_array[2][1][2];
            positions[2][2][0] = temporary_array[2][2][0];
            positions[2][2][1] = temporary_array[2][2][1];
            positions[2][2][2] = temporary_array[2][2][2];
            // Red
            positions[3][0][0] = temporary_array[4][0][0];
            positions[3][0][1] = temporary_array[4][0][1];
            positions[3][0][2] = temporary_array[4][0][2];
            positions[3][1][0] = temporary_array[3][1][0];
            positions[3][1][1] = temporary_array[3][1][1];
            positions[3][1][2] = temporary_array[3][1][2];
            positions[3][2][0] = temporary_array[3][2][0];
            positions[3][2][1] = temporary_array[3][2][1];
            positions[3][2][2] = temporary_array[3][2][2];
            // Blue
            positions[4][0][0] = temporary_array[1][0][0];
            positions[4][0][1] = temporary_array[1][0][1];
            positions[4][0][2] = temporary_array[1][0][2];
            positions[4][1][0] = temporary_array[4][1][0];
            positions[4][1][1] = temporary_array[4][1][1];
            positions[4][1][2] = temporary_array[4][1][2];
            positions[4][2][0] = temporary_array[4][2][0];
            positions[4][2][1] = temporary_array[4][2][1];
            positions[4][2][2] = temporary_array[4][2][2];
            // Yellow
            positions[5][0][0] = temporary_array[5][0][0];
            positions[5][0][1] = temporary_array[5][0][1];
            positions[5][0][2] = temporary_array[5][0][2];
            positions[5][1][0] = temporary_array[5][1][0];
            positions[5][1][1] = temporary_array[5][1][1];
            positions[5][1][2] = temporary_array[5][1][2];
            positions[5][2][0] = temporary_array[5][2][0];
            positions[5][2][1] = temporary_array[5][2][1];
            positions[5][2][2] = temporary_array[5][2][2];
        };

        int turn = 1; // 1 is x, 2 is o

        // These are are the moved made out of the basic moves
        void x_prime() {
            x_move();
            x_move();
            x_move();
        };

        void y_prime() {
            y_move();
            y_move();
            y_move();
        };

        void z_prime() {
            z_move();
            z_move();
            z_move();
        };

        void u_prime() {
            u_move();
            u_move();
            u_move();
        };
        
        void l_move() {
            z_move();
            u_move();
            z_prime();
        };

        void l_prime() {
            l_move();
            l_move();
            l_move();
        };

        void f_move() {
            x_move();
            u_move();
            x_prime();
        };

        void f_prime() {
            f_move();
            f_move();
            f_move();
        };

        void r_move() {
            z_prime();
            u_move();
            z_move();
        };

        void r_prime() {
            r_move();
            r_move();
            r_move();
        };

        void b_move() {
            x_prime();
            u_move();
            x_move();
        };

        void b_prime() {
            b_move();
            b_move();
            b_move();
        };

        void d_move() {
            x_move();
            x_move();
            u_move();
            x_move();
            x_move();
        };

        void d_prime() {
            d_move();
            d_move();
            d_move();
        };

        int mark_x(int x, int y) {
            if ((x >= 0) && (x <= 2) && (y >= 0) && (y <= 2) && (positions[0][y][x] == 0)) {
                positions[0][y][x] = 1;
                return 0;
            }
            else {
                return 1;
            }
        };

        int mark_o(int x, int y) {
            if ((x >= 0) && (x <= 2) && (y >= 0) && (y <= 2) && (positions[0][y][x] == 0)) {
                positions[0][y][x] = 2;
                return 0;
            }
            else {
                return 1;
            }
        };
        
        void print_full_board() {
            for (int face = 0; face < 6; face++) {
                for (int row = 0; row < 3; row++) {
                    for (int column = 0; column < 3; column++) {
                        std::cout << positions[face][row][column];
                    };
                std::cout << "\n";
                };
            std::cout << "\n";
            }; 
        };

        void print_current_side() {
            // 0 is going to be the default side
            for (int row = 0; row < 3; row++) {
                for (int column = 0; column < 3; column++) {
                    std::cout << positions[0][row][column];
                };
                std::cout << "\n";
            };
            std::cout << "\n";
        };

        void move_cube(std::string move) {
            if (move == "U") {
                u_move();
                turn = 3 - turn;
            }
            else if (move == "U'") {
                u_prime();
                turn = 3 - turn;
            }
            else if (move == "L") {
                l_move();
                turn = 3 - turn;
            }
            else if (move == "L'") {
                l_prime();
                turn = 3 - turn;
            }
            else if (move == "F") {
                f_move();
                turn = 3 - turn;
            }
            else if (move == "F'") {
                f_prime();
                turn = 3 - turn;
            }
            else if (move == "R") {
                r_move();
                turn = 3 - turn;
            }
            else if (move == "R'") {
                r_prime();
                turn = 3 - turn;
            }
            else if (move == "B") {
                b_move();
                turn = 3 - turn;
            } 
            else if (move == "B'") {
                b_prime();
                turn = 3 - turn;
            }
            else if (move == "D") {
                d_move();
                turn = 3 - turn;
            }
            else if (move == "D'") {
                d_prime();
                turn = 3 - turn;
            }
            else if (move == "X") {
                x_move();
                turn = 3 - turn;
            }
            else if (move == "X'") {
                x_prime();
                turn = 3 - turn;
            }
            else if (move == "Y") {
                y_move();
                turn = 3 - turn;
            }
            else if (move == "Y'") {
                y_prime();
                turn = 3 - turn;
            }
            else if (move == "Z") {
                z_move();
                turn = 3 - turn;
            }
            else if (move == "Z'") {
                z_prime();
                turn = 3 - turn;
            }
            else {
                std::cout << "Invalid notation\n";
            }
        };
};

Cube_board cube;

void render_board() {
    std::array<std::array<std::string, 5>, 5> rendered_board_position = {{
        {" ", "|", " ", "|", " "},
        {"-", "+", "-", "+", "-"},
        {" ", "|", " ", "|", " "},
        {"-", "+", "-", "+", "-"},
        {" ", "|", " ", "|", " "}
    }};
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            int position_status = cube.positions[0][row][column];
            switch(position_status) {
                case 1:
                    rendered_board_position[row*2][column*2] = "X";
                    break;
                case 2:
                    rendered_board_position[row*2][column*2] = "O";
                    break;
            };
        };
    };
    for (int row = 0; row < 5; row++) {
        for (int column = 0; column < 5; column++) {
            std::cout << rendered_board_position[row][column];
        };
        std::cout << "\n";
    };
};

int main() {
    cube.print_current_side();
    cube.print_full_board();

    std::string x_pos_string;
    int x_pos;
    std::string y_pos_string;
    int y_pos;
    bool running = true;
    std::string mode_string = "0";
    int mode = 0;
    std::string notation = "";
    while (running) {
        switch(cube.turn) {
            case 1:
                std::cout << "Enter mode";
                std::cin >> mode_string;
                mode = std::stoi(mode_string);
                switch(mode) {
                    case 1:
                        std::cout << "\n----------\nX's Turn\n";
                        std::cout << "Enter the X position";
                        std::cin >> x_pos_string;
                        std::cout << "Enter the Y position";
                        std::cin >> y_pos_string;
                        x_pos = std::stoi(x_pos_string);
                        y_pos = std::stoi(y_pos_string);
                        if (cube.mark_x(x_pos, y_pos) != 0) {
                            break;
                        };
                        render_board();
                        cube.turn = 2;
                        break;
                    case 2:
                        std::cout << "\n----------\nX's Turn\nEnter notation";
                        std::cin >> notation;
                        cube.move_cube(notation);
                        render_board();
                        std::cout << cube.turn;
                        break;
                };
                break;
            case 2:
                std::cout << "Enter mode";
                std::cin >> mode_string;
                mode = std::stoi(mode_string);
                switch(mode) {
                    case 1:
                        std::cout << "\n----------\nO's Turn\n";
                        std::cout << "Enter the X position";
                        std::cin >> x_pos_string;
                        std::cout << "Enter the Y position";
                        std::cin >> y_pos_string;
                        x_pos = std::stoi(x_pos_string);
                        y_pos = std::stoi(y_pos_string);
                        if (cube.mark_o(x_pos, y_pos) != 0) {
                            break;
                        };
                        render_board();
                        cube.turn = 1;
                        break;
                    case 2:
                        std::cout << "\n---------\nO's Turn\nEnter notation";
                        std::cin >> notation;
                        cube.move_cube(notation);
                        render_board();
                        break;
                };
                break;
        };
    };

    return 0;
};

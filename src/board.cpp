#include <iostream>
#include <array>
#include <string>
#include <tuple>
#include <chrono>
#include <thread>
#include "board.h"

// These are named after the actual moves in Rubik's cube notation. X, Y, and Z are all rotations
// These are the basic moves that I will use to render the rest of the moves
void Cube_board::x_move() {
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

void Cube_board::y_move() {
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

void Cube_board::z_move() {
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
    positions[4][0][0] = temporary_array[4][0][2];
    positions[4][0][1] = temporary_array[4][1][2];
    positions[4][0][2] = temporary_array[4][2][2];
    positions[4][1][0] = temporary_array[4][0][1];
    positions[4][1][1] = temporary_array[4][1][1];
    positions[4][1][2] = temporary_array[4][2][1];
    positions[4][2][0] = temporary_array[4][0][0];
    positions[4][2][1] = temporary_array[4][1][0];
    positions[4][2][2] = temporary_array[4][2][0];
    // Yellow
    positions[5][0][0] = temporary_array[3][2][0];
    positions[5][0][1] = temporary_array[3][1][0];
    positions[5][0][2] = temporary_array[3][0][0];
    positions[5][1][0] = temporary_array[3][2][1];
    positions[5][1][1] = temporary_array[3][1][1];
    positions[5][1][2] = temporary_array[3][0][1];
    positions[5][2][0] = temporary_array[3][2][2];
    positions[5][2][1] = temporary_array[3][1][2];
    positions[5][2][2] = temporary_array[3][0][2];
};

void Cube_board::u_move() {
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

// These are are the moved made out of the basic moves
void Cube_board::x_prime() {
    x_move();
    x_move();
    x_move();
};

void Cube_board::y_prime() {
    y_move();
    y_move();
    y_move();
};

void Cube_board::z_prime() {
    z_move();
    z_move();
    z_move();
};

void Cube_board::u_prime() {
    u_move();
    u_move();
    u_move();
};
        
void Cube_board::l_move() {
    z_move();
    u_move();
    z_prime();
};

void Cube_board::l_prime() {
    l_move();
    l_move();
    l_move();
};

void Cube_board::f_move() {
    x_move();
    u_move();
    x_prime();
};

void Cube_board::f_prime() {
    f_move();
    f_move();
    f_move();
};

void Cube_board::r_move() {
    z_prime();
    u_move();
    z_move();
};

void Cube_board::r_prime() {
    r_move();
    r_move();
    r_move();
};

void Cube_board::b_move() {
    x_prime();
    u_move();
    x_move();
};

void Cube_board::b_prime() {
    b_move();
    b_move();
    b_move();
};

void Cube_board::d_move() {
    x_move();
    x_move();
    u_move();
    x_move();
    x_move();
};

void Cube_board::d_prime() {
    d_move();
    d_move();
    d_move();
};

void Cube_board::m_move() {
    x_prime();
    l_prime();
    r_move();
};

void Cube_board::m_prime() {
    m_move();
    m_move();
    m_move();
};

void Cube_board::e_move() {
    y_prime();
    u_move();
    d_prime();
};
        
void Cube_board::e_prime() {
    e_move();
    e_move();
    e_move();
};

void Cube_board::s_move() {
    z_move();
    f_prime();
    b_move();
};

void Cube_board::s_prime() {
    s_move();
    s_move();
    s_move();
};

int Cube_board::mark_x(int x, int y) {
    if ((x >= 0) && (x <= 2) && (y >= 0) && (y <= 2) && (positions[0][y][x] == 0)) {
        positions[0][y][x] = 1;
        return 0;
    }
    else {
        return 1;
    }
};

int Cube_board::mark_o(int x, int y) {
    if ((x >= 0) && (x <= 2) && (y >= 0) && (y <= 2) && (positions[0][y][x] == 0)) {
        positions[0][y][x] = 2;
        return 0;
    }
    else {
        return 1;
    }
};
        
void Cube_board::print_full_board() {
    for (int face = 0; face < 6; face++) {
        for (int row = 0; row < 3; row++) {
            for (int column = 0; column < 3; column++) {
                std::cout << positions[face][row][column];
            };
        std::cout << "\n";
        };
    };
    std::cout << "\n";
};

void Cube_board::print_current_side() {
    // 0 is going to be the default side
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            std::cout << positions[0][row][column];
        };
        std::cout << "\n";
    };
    std::cout << "\n";
};

void Cube_board::move_cube(std::string move) {
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
    else if (move == "M") {
        m_move();
        turn = 3 - turn;
    }
    else if (move == "M'") {
        m_prime();
        turn = 3 - turn;
    }
    else if (move == "E") {
        e_move();
        turn = 3 - turn;
    }
    else if (move == "E'") {
        e_prime();
        turn = 3 - turn;
    }
    else if (move == "S") {
        s_move();
        turn = 3 - turn;
    }
    else if (move == "S'") {
        s_prime();
        turn = 3 - turn;
    }
    else {
        std::cout << "Invalid notation\n";
    }
};

std::tuple<int, std::array<std::array<int, 2>, 3>> Cube_board::scan_for_wins() {
    for (int i = 0; i < 6; i++) {
        // Horizontal 1
        if (positions[i][0][0] == positions[i][0][1] && positions[i][0][0] == positions[i][0][2] && positions[i][0][0] != 0) {
            return {positions[i][0][0], {{{0, 0}, {0, 1}, {0, 2}}}};
        };
        // Horizontal 2
        if (positions[i][1][0] == positions[i][1][1] && positions[i][1][0] == positions[i][1][2] && positions[i][1][0] != 0) {
            return {positions[i][1][0], {{{1, 0}, {1, 1}, {1, 2}}}};
        };
        // Horizontal 3
        if (positions[i][2][0] == positions[i][2][1] && positions[i][2][0] == positions[i][2][2] && positions[i][2][0] != 0) {
            return {positions[i][2][0], {{{2, 0}, {2, 1}, {2, 2}}}};
        };
        // Vertical 1
        if (positions[i][0][0] == positions[i][1][0] && positions[i][0][0] == positions[i][2][0] && positions[i][0][0] != 0) {
            return {positions[i][0][0], {{{0, 0}, {1, 0}, {2, 0}}}};
        };
        // Vertical 2
        if (positions[i][0][1] == positions[i][1][1] && positions[i][0][1] == positions[i][2][1] && positions[i][0][1] != 0) {
            return {positions[i][0][1], {{{0, 1}, {1, 1}, {2, 1}}}};
        };
        // Vertical 3
        if (positions[i][0][2] == positions[i][1][2] && positions[i][0][2] == positions[i][2][2] && positions[i][0][2] != 0) {
            return {positions[i][0][2], {{{0, 2}, {1, 2}, {2, 2}}}};
        };
        // Diagonal 1
        if (positions[i][0][0] == positions[i][1][1] && positions[i][0][0] == positions[i][2][2] && positions[i][0][0] != 0) {
            return {positions[i][0][0], {{{0, 0}, {1, 1}, {2, 2}}}};
        };
        // Diagonal 2
        if (positions[i][0][2] == positions[i][1][1] && positions[i][0][2] == positions[i][2][0] && positions[i][0][2] != 0) {
            return {positions[i][0][2], {{{0, 2}, {1, 1}, {2, 0}}}};
        };
    };
    return {0, {{{0, 0}, {0, 0}, {0, 0}}}};
};

void Cube_board::render_board() {
    std::cout << "\n";
    std::array<std::array<std::string, 5>, 5> rendered_board_position = {{
        {" ", "|", " ", "|", " "},
        {"-", "+", "-", "+", "-"},
        {" ", "|", " ", "|", " "},
        {"-", "+", "-", "+", "-"},
        {" ", "|", " ", "|", " "}
    }};
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            int position_status = positions[0][row][column];
            switch(position_status) {
                case 1:
                    rendered_board_position[row*2][column*2] = "X";
                    break;
                case 2:
                    rendered_board_position[row*2][column*2] = "O";
            };
        };
    };
    for (int row =0; row < 5; row++) {
        for (int column = 0; column < 5; column++) {
            std::cout << rendered_board_position[row][column];
        };
        std::cout << "\n";
    };
};

void Cube_board::reset() {
    turn = 1;
    for (int face = 0; face < 6; face++) {
        for (int row = 0; row < 3; row++) {
            for (int column = 0; column < 3; column++) {
                positions[face][row][column] = 0;
            };
        };
    };
};

void Cube_board::user_input(std::string input) {
    /*
     * p1, p2, etc
     * mR, mU, etc
    */
    if (input[0] == 'p') /* Place */{
        /*
         * 9 - 2, 2 
         * 1 - 0, 0
        */
        // What do I do....
        // So apparently characters and strings are actually different in this language?
        if (input[1] == '1') {
            if (positions[0][0][0] == 0) {
                positions[0][0][0] = turn;
                turn = 3 - turn;
            };
        }
        else if (input[1] == '2') {
            if (positions[0][0][1] == 0) {
                positions[0][0][1] = turn;
                turn = 3 - turn;
            };
        }
        else if (input[1] == '3') {
            if (positions[0][0][2] == 0) {
                positions[0][0][2] = turn;
                turn = 3 - turn;
            };
        }
        else if (input[1] == '4') {
            if (positions[0][1][0] == 0) {
                positions[0][1][0] = turn;
                turn = 3 - turn;
            };
        }
        else if (input[1] == '5') {
            if (positions[0][1][1] == 0) {
                positions[0][1][1] = turn;
                turn = 3 - turn;
            };
        }
        else if (input[1] == '6') {
            if (positions[0][1][2] == 0) {
                positions[0][1][2] = turn;
                turn = 3 - turn;
            };
        }
        else if (input[1] == '7') {
            if (positions[0][2][0] == 0) {
                positions[0][2][0] = turn;
                turn = 3 - turn;
            };
        }
        else if (input[1] == '8') {
            if (positions[0][2][1] == 0) {
                positions[0][2][1] = turn;
                turn = 3 - turn;
            };
        }
        else if (input[1] == '9') {
            if (positions[0][2][2] == 0) {
                positions[0][2][2] = turn;
                turn = 3 - turn;
            };
        }
        else {
            std::cout << "Invalid position";
        };
    }
    else if (input[0] == 'm') {
        switch(input.length()) {
            case 2:
                move_cube(std::string("")+input[1]);
                break;
            case 3:
                move_cube(input[1]+std::string("'"));
                break;
        };
    }
    else {
        std::cout << "invalid move format: correct format is movetypeMove. MoveType can be m (move) and p (place). Move can be either the type of cube more or the spot to mark a spot with x or o";
    };
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
};

int Cube_board::gameloop() {
    // Check for wins so that there's a way to exit the gameloop without exiting the game
    if (std::get<0>(scan_for_wins()) == 1) {
        reset();
        return 0;
    }
    else if (std::get<0>(scan_for_wins()) == 2) {
        reset();
        return 0;
    };
    return 2;
};

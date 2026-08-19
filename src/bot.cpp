#include <string>
#include <iostream>
#include <array>
#include <map>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <ctime>

std::array<std::array<int, 3>, 3> convert_board_position(std::array<std::array<std::array<int, 3>, 3>, 6> unconverted_board_position) {
    std::array<std::array<int, 3>, 3> converted_board_position;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            converted_board_position[row][column] = unconverted_board_position[0][row][column];
        }
    }
    return converted_board_position;
};

int convert_coords(std::array<int, 2> coords) {
    int converted = coords[0] * 3 + coords[1] + 1;
    return converted;
};

std::string achieve_win(std::array<std::array<int, 3>, 3> board_position, int bot_turn) {
    return "nothing";
};

std::string combat_formed_fork(std::array<std::array<int, 3>, 3> board_position, int bot_turn) {
    return "nothing";
};

std::string block_win(std::array<std::array<int, 3>, 3> board_positon, int bot_turn) {
    return "nothing";
};

std::string create_fork(std::array<std::array<int, 3>, 3> board_position, int bot_turn) {
    return "nothing";
};

std::string block_fork_creation(std::array<std::array<int, 3>, 3> board_position, int bot_turn) {
    return "nothing";
};

std::string place_priority(std::array<std::array<int, 3>, 3> board_position, int bot_turn) {
    srand(time(NULL));
    // This function will be split into several parts: center, opposite corner, empty corner, empty side, and rotate board for new face

    // Center
    if (board_position[1][1] == 0) {
        return "p5";
    };

    // Opposite corner
    std::array<std::array<int, 2>, 4> board_corners = {{
        {0, 0},
        {0, 2},
        {2, 0},
        {2, 2}
    }}; // Apparently this is broken, but I have no idea why.
    
    /*
     * Steps:
     * Scan to board for an occupied corner by the enemy
     * Place on opposite corner
     */
    std::array<std::string, 4> opposites = {
        "p9",
        "p7",
        "p3",
        "p1"
    };
    for (int corners = 0; corners < 4; corners++) {
        std::array<int, 2> current_side = {
            board_corners[corners][0],
            board_corners[corners][1]
        };
        if (board_position[current_side[0]][current_side[1]] == (3 - bot_turn)) {
            return opposites[corners];
        };
    };

    // Empty corner
    for (int corners = 0; corners < 4; corners++) {
        std::array<int, 2> current_side = {
            board_corners[corners][0],
            board_corners[corners][1]
        };
        if (board_position[current_side[0]][current_side[1]] == 0) {
            return "p" + std::to_string(convert_coords(current_side));
        };
    };

    // Empty side
    std::array<std::array<int, 2>, 4> board_sides = {{
        {1, 0},
        {0, 1},
        {2, 1},
        {1, 2}
    }};
    for (int sides = 0; sides < 4; sides++) {
        std::array<int, 2> current_side = {
            board_sides[sides][0],
            board_sides[sides][1]
        };
        if (board_position[current_side[0]][current_side[1]] == 0) {
            return "p" + std::to_string(convert_coords(current_side));
        };
    };

    // Rotate board
    int rotation_type_number = rand() % 4;
    switch(rotation_type_number) {
        case 0:
            return "mX";
        case 1:
            return "mZp";
        case 2:
            return "mZ";
        case 3:
            return "mXp";
        default:
            return "mD";
    };
    return "nothing";
};

// Since the thing storing the board position is located inside an object, I cannot get the information directly from the board file.
// The input comes in the form of a mulitdimensional array. Only the top face is needed to scan, because the top face is the only place you can place blocks, and lso because its' the only face you can see, 
std::string get_bot_move(std::array<std::array<std::array<int, 3>, 3>, 6> board_position_input, int bot_turn) {
    std::string move = "mD";
    std::string potential_move;

    // Not technically needed, but the original array contains a bunch of redundant variables for this program.
    std::array<std::array<int, 3>, 3> converted_board_position = convert_board_position(board_position_input);
    
    // Steps to Winning at least some of the time
    // Go for a Win
    // Rotate to deal with fork
    // Block any 2-in-a-row patterns
    // Create a Fork
    // Block Fork
    // Play in the Center whenever possible
    // Play in the Opposite corner
    // Empty Corner
    // Empty side
    // Rotate board to new face
    
    // Center, corner, side, rotate
    potential_move = place_priority(converted_board_position, bot_turn);
    if (potential_move != "nothing") {
        move = potential_move;
    }

    return move;
};

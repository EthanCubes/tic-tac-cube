#include <string>
#include <iostream>
#include <array>
#include <map>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

std::map<int, int> convert_board_position(std::array<std::array<std::array<int, 3>, 3>, 6> unconverted_board_position) {
    std::map<int, int> converted_board_position;
    // In order to get the data from the unconverted array, we need two keys, so I wrote this function to convert a number into those two keys
    for (int position = 1; position < 10; position++) {
        int row = std::floor((position - 1) / 3);
        int column = position - 3 * row - 1;
        converted_board_position[position] = unconverted_board_position[0][row][column];
    };
    return converted_board_position;
};

std::string achieve_win(std::map<int, int> board_position, int bot_turn) {
    return "nothing";
};

std::string combat_formed_fork(std::map<int, int> board_position, int bot_turn) {
    return "nothing";
};

std::string block_win(std::map<int, int> board_positon, int bot_turn) {
    return "nothing";
};

std::string create_fork(std::map<int, int> board_position, int bot_turn) {
    return "nothing";
};

std::string block_fork_creation(std::map<int, int> board_position, int bot_turn) {
    return "nothing";
};

std::string place_priority(std::map<int, int> board_position, int bot_turn) {
    srand(time(NULL));
    // This function will be split into several parts: center, opposite corner, empty corner, empty side, and rotate board for new face

    // Center
    if (board_position[5] == 0) {
        return "p5";
    };

    // Opposite corner
    std::array<int, 4> board_corners = {
        1,
        3, 
        7, 
        9,
    };
    
    /*
     * Steps:
     * Scan to board for an occupied corner by the enemy
     * Place on opposite corner
     */
    std::array<int, 4> opposites = {
        9,
        7,
        3,
        1
    };
    for (int corners = 0; corners < 4; corners++) {
        int current_corner = board_corners[corners];
        if (board_position[current_corner] == (3 - bot_turn)) {
            int opposite_corner = opposites[corners];
            if (board_position[opposite_corner] == 0) {
                return "p" + std::to_string(opposite_corner);
            }
        };
    };

    // Empty corner
    for (int corners = 0; corners < 4; corners++) {
        int current_corner = board_corners[corners];
        if (board_position[current_corner] == 0) {
            return "p" + std::to_string(current_corner);
        };
    };

    // Empty side
    std::array<int, 4> board_sides = {
        2, 
        4,
        6,
        8
    };
    for (int sides = 0; sides < 4; sides++) {
        int current_side = board_sides[sides];
        if (board_position[current_side] == 0) {
            return "p" + std::to_string(current_side);
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

    std::map<int, int> converted_board_position = convert_board_position(board_position_input);
    
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

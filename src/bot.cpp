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

std::string achieve_win(std::array<std::array<int, 3>, 3> board_position) {};
std::string combat_formed_fork(std::array<std::array<int, 3>, 3> board_position) {};
std::string block_win(std::array<std::array<int, 3>, 3> board_positon) {};
std::string create_fork(std::array<std::array<int, 3>, 3> board_position) {};
std::string block_fork_creation(std::array<std::array<int, 3>, 3> board_position) {};
std::string place_priority(std::array<std::array<int, 3>, 3> board_position) {
    srand(time(NULL));
    // This function will be split into several parts: center, opposite corner, empty corner, empty side, and rotate board for new face
    // Center
    if (board_position[1][1] == 0) {
        return "p5";
    };
    // Opposite corner
    // Empty corner
    // Empty side
    // Rotate board
    rotation_type_number = rand() % 4;
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
    }
};

// Since the thing storing the board position is located inside an object, I cannot get the information directly from the board file.
// The input comes in the form of a mulitdimensional array. Only the top face is needed to scan, because the top face is the only place you can place blocks, and lso because its' the only face you can see, 
std::string get_bot_move(std::array<std::array<std::array<int, 3>, 3>, 6> board_position_input) {
    std::string move;

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
};

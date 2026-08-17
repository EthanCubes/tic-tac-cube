#include <string>
#include <array>
#include <map>

std::array<std::array<int, 3>, 3> convert_board_position(unconverted_board_position) {
    std::array<std::array<int, 3>, 3> converted_board_position;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            converted_board_position[row][column] = unconverted_board_position[0][row][column];
        }
    }
    return converted_board_position;
}

// Since the thing storing the board position is located inside an object, I cannot get the information directly from the board file.
// The input comes in the form of a mulitdimensional array. Only the top face is needed to scan, because the top face is the only place you can place blocks, and lso because its' the only face you can see, 
std::string get_bot_move(std::array<std::array<std::array<int, 3>, 3>, 6> board_position_input) {
    std::string move;
    std::string potential_move;

    // Not technically needed, but the original array contains a bunch of redundant variables for this program.
    std::array<std::array<int, 3>, 3> converted_board_position = convert_board_position(board_position_input);

    return move;
};

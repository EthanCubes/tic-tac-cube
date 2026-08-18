#include <string>
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

std::string scan_unbroken_two(std::array<int, 3>, 3> board_position) {
    // for every place in the square, given that it is still inside the board
    std::array<std::string, 8> direction_keys_array = {
        "N",
        "NE",
        "E",
        "SE",
        "S",
        "SW",
        "W",
        "NW"
    };
    std::map<std::string, std::array<int, 2> direction_modifier_index = {
        {"N", {0, 1}},
        {"NE", {1, 1}},
        {"E", {1, 0}}, 
        {"SE", {1, -1}},
        {"S", {0, -1}},
        {"SW", {-1, -1}},
        {"W", {-1, 0}},
        {"NW", {-1, 1}}
    };
    std::map<int, std::array<int, 2>> location_index = {
        {{0, 0}, "p1"},
        {{0, 1}, "p2"},
        {{0, 2}, "p3"},
        {{1, 0}, "p4"},
        {{1, 1}, "p5"},
        {{1, 2}, "p6"},
        {{2, 0}, "p7"},
        {{2, 1}, "p8"},
        {{2, 2}, "p9"}
    };

    std::array<std::array<int, 2>, 3> scanned_positions;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            for (int direction = 0; direction < 8; direction++) {
                std::string direction_key = direction_keys_array[direction];
                std::array<int, 2> direction_modifer = direction_modifier_index[direction_key];
                int direction_x_modifier = direction_modifier[0];
                int direction_y_modifier = direction_modifier[1];
                scanned_positions[0] = {row, column};
                scanned_positions[1] = {row + direction_x_modifier, column + direction_x_modifier};
                scanned_positions[2] = {row + direction_x_modifier*2, column + direction_y_modifier*2};
                if (scanned_positions[2][0] < 0 || scanned_positions[2][0] > 2 || scanned_positions[2][1] < 0 || scanned_positions[2][1] > 2) {
                    continue;
                }
                else if (board_position[scanned_positions[0][0]][scanned_positions[0][1]] != 0) {
                    continue;
                }
                // Actually scanning the thing
                if (board_position[scanned_positions[1][0]][scanned_positions[1][1]] == board_position[scanned_positions[2][0]][scanned_positions[2][1]]) {
                    return location_index[scanned_positions[0][0]][scanned_positions[0][1]];
                }
            }
        }
    }
    return "nothing";
}

// These functions will scan for patterns
std::string place_randomly(std::array<std::array<int, 3>, 3> board_position) {
    // Didn't actually test by compiling, lowkey asked DeepSeek if I made any mistakes.
    std::array<std::string, 16> move_array = {
        "mX",
        "mZp",
        "mZ",
        "mXp",

        "mLp",
        "mMp",
        "mR",
        "mB",
        "mBp",
        "mSp",
        "mS",
        "mFp",
        "mF",
        "mL",
        "mM",
        "mRp"
    };
    std::map<int, std::array<int, 2>> location_index = {
        {1, {0, 0}},
        {2, {0, 1}},
        {3, {0, 2}},
        {4, {1, 0}},
        {5, {1, 1}},
        {6, {1, 2}},
        {7, {2, 0}},
        {8, {2, 1}},
        {9, {2, 2}}
    };
    srand(time(0));
    int random = rand() % 10;
    int movement_mode;
    if (random < 7) {
        movement_mode = 0;
    }
    else {
        movement_mode = 1;
    }
    switch(movement_mode) {
        case 0: {
            // Very confusing code 
            int location_int;
            bool position_valid = false;
            while (!position_valid) {
                location_int = rand() % 9 + 1;
                int row = location_index[location_int][0];
                int column = location_index[location_int][1];
                if (board_position[row][column] == 0) {
                    position_valid = true;
                }
            }
            return 'p' + std::to_string(location_int);
        };
        case 1: {
            // Rotating a cube
            int move = rand() % 16;
            return move_array[move];
        };
        default: {
            return "mDp";
        };
    };
    return "mDp";
};

// Since the thing storing the board position is located inside an object, I cannot get the information directly from the board file.
// The input comes in the form of a mulitdimensional array. Only the top face is needed to scan, because the top face is the only place you can place blocks, and lso because its' the only face you can see, 
std::string get_bot_move(std::array<std::array<std::array<int, 3>, 3>, 6> board_position_input) {
    std::string move;

    // Not technically needed, but the original array contains a bunch of redundant variables for this program.
    std::array<std::array<int, 3>, 3> converted_board_position = convert_board_position(board_position_input);
    
    move = scan_unbroken_two(converted_board_position);
    if (move != "nothing") {
        return move;
    }
    move = place_randomly(converted_board_position);
    return move;
};

#include <string>
#include <iostream>
#include <array>
#include <map>
#include <tuple>
#include <vector>
#include <random>

#include "logs.h"

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

std::string rotate_cube_randomly() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist4(0, 3);
    int rotation_type_number = dist4(rng);
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
    return "mD";
};

std::string wild_card(std::map<int, int> board_position, int bot_turn) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist10(1, 10);

    int random_number = dist10(rng);

    if (random_number == 10) {
        // Do a random cube rotation
        std::uniform_int_distribution<std::mt19937::result_type> dist4(1, 4);
        int move = dist4(rng);
        switch(move) {
            case 1:
                return "mZ";
            case 2:
                return "mZp";
            case 3:
                return "mXp";
            case 4:
                return "mX";
        }
    }
    else {
        // Do some stuff idk
        int move = dist10(rng);
        switch(move) {
            case 1:
                return "mL";
            case 2:
                return "mLp";
            case 3:
                return "mF";
            case 4:
                return "mFp";
            case 5:
                return "mR";
            case 6:
                return "mRp";
            case 7:
                return "mB";
            case 8:
                return "mBp";
            case 9:
                return "mM";
            case 10:
                return "mMp";
        };
    };

    return "nothing";
};

std::string achieve_win(std::map<int, int> board_position, int bot_turn) {
    // Scan for unbroken two
    std::array<std::tuple<std::array<int, 2>, int>, 16> unbroken_two_location = {{
        {{1, 2}, 3},
        {{1, 5}, 9},
        {{1, 4}, 7},

        {{2, 5}, 8},

        {{3, 6}, 9},
        {{3, 5}, 7},
        {{3, 2}, 1},

        {{4, 5}, 6},

        {{6, 5}, 4},

        {{7, 4}, 1},
        {{7, 5}, 3},
        {{7, 8}, 9},

        {{8, 5}, 2},

        {{9, 6}, 3},
        {{9, 5}, 1},
        {{9, 8}, 7}
    }};

    for (int pattern = 0; pattern < 16; pattern++) {
        int position_1 = std::get<0>(unbroken_two_location[pattern])[0];
        int position_2 = std::get<0>(unbroken_two_location[pattern])[1];
        int missing = std::get<1>(unbroken_two_location[pattern]);
        if (board_position[position_1] == bot_turn && board_position[position_2] == bot_turn) {
            if (board_position[missing] == 0) {
                return "p" + std::to_string(missing);
            };
        };
    };

    // Scan for broken two
    std::array<std::tuple<std::array<int, 2>, int>, 8> broken_two_location = {{
        {{1, 3}, 2},
        {{1, 9}, 5},
        {{1, 7}, 4},

        {{2, 8}, 5},

        {{3, 9}, 6},
        {{3, 7}, 5},

        {{4, 6}, 5},

        {{7, 9}, 8},
    }};

    for (int pattern = 0; pattern < 8; pattern++) {
        int position_1 = std::get<0>(broken_two_location[pattern])[0];
        int position_2 = std::get<0>(broken_two_location[pattern])[1];
        int missing = std::get<1>(broken_two_location[pattern]);
        if (board_position[position_1] == bot_turn && board_position[position_2] == bot_turn) {
            if (board_position[missing] == 0) {
                return "p" + std::to_string(missing);
            };
        };
    };

    return "nothing";
};

std::string block_win(std::map<int, int> board_position, int bot_turn) {
    std::vector<int> winning_positions;
    std::vector<int> winning_directions;
    // Scan for unbroken two
    std::array<std::tuple<std::array<int, 2>, int>, 16> unbroken_two_location = {{
        {{1, 2}, 3},
        {{1, 5}, 9},
        {{1, 4}, 7},

        {{2, 5}, 8},

        {{3, 6}, 9},
        {{3, 5}, 7},
        {{3, 2}, 1},

        {{4, 5}, 6},

        {{6, 5}, 4},

        {{7, 4}, 1},
        {{7, 5}, 3},
        {{7, 8}, 9},

        {{8, 5}, 2},

        {{9, 6}, 3},
        {{9, 5}, 1},
        {{9, 8}, 7}
    }};

    for (int pattern = 0; pattern < 16; pattern++) {
        int position_1 = std::get<0>(unbroken_two_location[pattern])[0];
        int position_2 = std::get<0>(unbroken_two_location[pattern])[1];
        int missing = std::get<1>(unbroken_two_location[pattern]);
        if (board_position[position_1] == (3 - bot_turn) && board_position[position_2] == (3 - bot_turn)) {
            if (board_position[missing] == 0) {
                winning_positions.push_back(missing);
                winning_directions.push_back(position_1);
            };
        };
    };

    // Scan for broken two
    std::array<std::tuple<std::array<int, 2>, int>, 8> broken_two_location = {{
        {{1, 3}, 2},
        {{1, 9}, 5},
        {{1, 7}, 4},

        {{2, 8}, 5},

        {{3, 9}, 6},
        {{3, 7}, 5},

        {{4, 6}, 5},

        {{7, 9}, 8},
    }};

    for (int pattern = 0; pattern < 8; pattern++) {
        int position_1 = std::get<0>(broken_two_location[pattern])[0];
        int position_2 = std::get<0>(broken_two_location[pattern])[1];
        int missing = std::get<1>(broken_two_location[pattern]);
        if (board_position[position_1] == (3 - bot_turn) && board_position[position_2] == (3 - bot_turn)) {
            if (board_position[missing] == 0) {
                winning_positions.push_back(missing);
                winning_directions.push_back(position_1);
            };
        };
    };

    int winning_position_count = winning_positions.size();

    switch(winning_position_count) {
        case 0:
            return "nothing";
        case 1:
            log_data("Single case of winning position found, blocking");
            return "p" + std::to_string(winning_positions[0]);
        case 2: {
                    log_data("Two cases of winning position found, neutralizing");
                    // Deal with the fork by rotating
                    int position_1 = winning_positions[0];
                    int position_2 = winning_positions[1];
                    int winning_direction_1 = winning_directions[0];
                    int winning_direction_2 = winning_directions[1];
                    std::map<int, std::array<std::string, 4>> move_key = {
                        {1, {"mB", "mBp", "mL", "mLp"}},
                        {2, {"mB", "mBp", "mM", "mMp"}},
                        {3, {"mB", "mBp", "mR", "mRp"}},

                        {4, {"mS", "mSp", "mL", "mLp"}},
                        {5, {"mS", "mSp", "mM", "mMp"}},
                        {6, {"mS", "mSp", "mM", "mMp"}},

                        {7, {"mF", "mFp", "mL", "mLp"}},
                        {8, {"mF", "mFp", "mM", "mMp"}},
                        {9, {"mF", "mFp", "mR", "mRp"}}
                    };
                    std::array<std::string, 4> position_one_turn_array = move_key[position_1];
                    std::array<std::string, 4> position_two_turn_array = move_key[position_2];

                    std::array<std::string, 4> position_one_direction_array = move_key[winning_direction_1];
                    std::array<std::string, 4> position_two_direction_array = move_key[winning_direction_2];

                    // Writing a function for a single case feels excessive
                    for (int x = 0; x < 4; x++) {
                        for (int y = 0; y < 4; y++) {
                            if (position_one_turn_array[x] == position_two_turn_array[y]) {
                                return position_one_turn_array[x];
                            };
                        };
                    };

                    // Part of the code that ensures that the bot does not play a random move that would do absolutely nothing
                    std::random_device dev;
                    std::mt19937 rng(dev());
                    std::uniform_int_distribution<std::mt19937::result_type> coin_flip(0, 1);
                    std::uniform_int_distribution<std::mt19937::result_type> dist4(0, 3);
                    int position_number = coin_flip(rng);
                    int position_index = dist4(rng);
                    switch (position_number) {
                        case 0:
                            for (int x = 0; x < 4; x++) {
                                for (int y = 0; y < 4; y++) {
                                    if (position_one_turn_array[x] == position_one_direction_array[y]) {
                                        return position_one_turn_array[x];
                                    };
                                };
                            };
                            break;
                        case 1:
                            for (int x = 0; x < 4; x++) {
                                for (int y = 0; y < 4; y++) {
                                    if (position_two_turn_array[x] == position_two_direction_array[y]) {
                                        return position_two_turn_array[x];
                                    };
                                };
                            }
                            break;
                    };
                    // Fallback
                    switch(position_number) {
                        case 0:
                            return position_one_turn_array[position_index];
                        case 1:
                            return position_two_turn_array[position_index];
                    };
                }
        default:
            // This means that 3 or or more forks are detected. Rotating the cube is the only choice in this situation
            return rotate_cube_randomly();
    };
    return "nothing";
};

std::string create_fork(std::map<int, int> board_position, int bot_turn) {
    // Corner
    std::array<std::array<std::array<int, 2>, 2>, 2> corner_forks_array = {{
        {{
            {1, 9},
            {3, 7}
        }},
        {{
            {3, 7},
            {1, 9}
        }}
    }};
    for (int position = 0; position < 2; position++) {
        int position_1 = corner_forks_array[position][0][0];
        int position_2 = corner_forks_array[position][0][1];
        if (board_position[position_1] == bot_turn && board_position[position_2] == bot_turn) {
            // This means that a fork is possible.
            int fork_place_1 = corner_forks_array[position][1][0];
            int fork_place_2 = corner_forks_array[position][1][1];
            if (board_position[fork_place_1] == 0) {
                return "p" + std::to_string(fork_place_1);
            }
            else if (board_position[fork_place_2] == 0) {
                return "p" + std::to_string(fork_place_2);
            }
        };
    };

    // Center
    std::array<std::array<std::array<int, 2>, 2>, 4> center_forks_array = {{
        {{
            {5, 1},
            {3, 7}
        }},
        {{
            {5, 3},
            {1, 9}
        }},
        {{
            {5, 7},
            {1, 9}
        }},
        {{
            {5, 9},
            {3, 7}
        }}
    }};

    for (int position = 0; position < 4; position++) {
        int position_1 = center_forks_array[position][0][0];
        int position_2 = center_forks_array[position][0][1];
        if (board_position[position_1] == bot_turn && board_position[position_2] == bot_turn) {
            int fork_place_1 = center_forks_array[position][1][0];
            int fork_place_2 = center_forks_array[position][1][1];
            if (board_position[fork_place_1] == 0) {
                return "p" + std::to_string(fork_place_1);
            }
            else if (board_position[fork_place_2] == 0) {
                return "p" + std::to_string(fork_place_2);
            }
        };
    };

    return "nothing";
};

std::string place_priority(std::map<int, int> board_position, int bot_turn) {
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
    return rotate_cube_randomly();
};

// Since the thing storing the board position is located inside an object, I cannot get the information directly from the board file.
// The input comes in the form of a mulitdimensional array. Only the top face is needed to scan, because the top face is the only place you can place blocks, and lso because its' the only face you can see, 
std::string get_bot_move(std::array<std::array<std::array<int, 3>, 3>, 6> board_position_input, int bot_turn) {
    std::string move = "mD";

    std::map<int, int> converted_board_position = convert_board_position(board_position_input);
    
    // Steps to Winning at least some of the time
    // Go For a Win
    move = achieve_win(converted_board_position, bot_turn);
    if (move != "nothing") {
        return move;
    }

    // Block any 2-in-a-row patterns
    move = block_win(converted_board_position, bot_turn);
    if (move != "nothing") {
        return move;
    };

    // Create a Fork
    move = create_fork(converted_board_position, bot_turn);
    if (move != "nothing") {
        return move;
    };

    /*
     * Play in the Center whenever possible
     * Play in the Opposite corner
     * Empty Corner
     * Empty side
     * Rotate board to new face
     */
    move = place_priority(converted_board_position, bot_turn);
    if (move != "nothing") {
        return move;
    }

    return "mD";
};

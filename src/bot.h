#ifndef BOT_H
#define BOT_H

#include <array>
#include <map>

#include "board.h"

std::array<std::array<int, 3>, 3> convert_board_position(std::array<std::array<std::array<int, 3>, 3>, 6> unconverted_board_position);
std::string place_randomly(std::array<std::array<int, 3>, 3> board_position);
std::string get_bot_move(std::array<std::array<std::array<int, 3>, 3>, 6> board_position_input);

#endif

#ifndef BOT_H
#define BOT_H


#include <string>
#include <iostream>
#include <array>
#include <map>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "board.h"

std::map<int, int> convert_board_position(std::array<std::array<std::array<int, 3>, 3>, 6> unconverted_board_position);
std::string achieve_win(std::map<int, int> board_position, int bot_turn);
std::string combat_formed_fork(std::map<int, int> board_position, int bot_turn);
std::string block_win(std::map<int, int> board_position, int bot_turn);
std::string create_fork(std::map<int, int> board_position, int bot_turn);
std::string block_fork_creation(std::map<int, int> board_position, int bot_turn);
std::string place_priority(std::map<int, int> board_position, int bot_turn);
std::string get_bot_move(std::array<std::array<std::array<int, 3>, 3>, 6> board_position_input, int bot_turn);

#endif

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <array>
#include <string>
#include <tuple>

#include "logs.h"

class Cube_board {
    public:
        Cube_board() {}
        std::array<std::array<std::array<int, 3>, 3>, 6> positions = {{
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
            }},
            {{
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}
            }}
        }}; 
        std::array<std::array<std::array<int, 3>, 3>, 6> colors = {{
            {{
                 {0, 0, 0},
                 {0, 0, 0},
                 {0, 0, 0}
            }},
            {{
                 {1, 1, 1},
                 {1, 1, 1},
                 {1, 1, 1}
            }},
            {{
                 {2, 2, 2},
                 {2, 2, 2},
                 {2, 2, 2}
            }},
            {{
                 {3, 3, 3},
                 {3, 3, 3},
                 {3, 3, 3}
            }},
            {{
                 {4, 4, 4},
                 {4, 4, 4},
                 {4, 4, 4}
            }},
            {{
                 {5, 5, 5},
                 {5, 5, 5},
                 {5, 5, 5}
            }}
        }};
        std::array<std::array<std::array<int, 3>, 3>, 6> temporary_array;
        std::array<std::array<std::array<int, 3>, 3>, 6> temporary_color_array;
        void x_move();
        void y_move();
        void z_move();
        void u_move();
        int turn = 1;
        void x_prime();
        void y_prime();
        void z_prime();
        void u_prime();
        void l_move();
        void l_prime();
        void f_move();
        void f_prime();
        void r_move();
        void r_prime();
        void b_move();
        void b_prime();
        void d_move();
        void d_prime();
        void m_move();
        void m_prime();
        void e_move();
        void e_prime();
        void s_move();
        void s_prime();
        int mark_x(int x, int y);
        int mark_o(int x, int y);
        void print_full_board();
        void print_current_side();
        void move_cube(std::string move);
        std::tuple<int, std::array<std::array<int, 2>, 3>> scan_for_wins();
        void reset();
        void user_input(std::string input);
        bool scan_for_draw();
        int gameloop(int mode);
};

#endif

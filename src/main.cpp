#include <iostream>
#include <array>
#include <string>
#include <tuple>
#include <chrono>
#include <thread>

#include "board.h"

#include "raylib.h"

/*
- [x] Make a GUI for the main menu
- [x] Make a graphics for the game
- [ ] Make the interactivity with the game
- [ ] Make a Bot for the game
*/

// Buttons are always pretty difficult
class Button {
    private:
        int start_x;
        int start_y;
        int width;
        int height;

        bool setup = false;
    public:
        void setup_button(int start_x_setup, int start_y_setup, int width_setup, int height_setup) {
            if (setup) {
                std::cout << "Button already declared!";
                return;
            };
            start_x = start_x_setup-width_setup/2;
            start_y = start_y_setup-height_setup/2;
            width = width_setup;
            height = height_setup;
            setup = true;
        };

        void draw_button(Color button_color, Color text_color, int text_x_offset, int text_y_offset, int font_size, const char* text) {
            if (!setup) {
                std::cout << "Button not declared!";
                return;
            };
            DrawRectangle(start_x, start_y, width, height, button_color);
            DrawText(text, start_x+text_x_offset, start_y+text_y_offset, font_size, text_color);
        };

        int check_button_clicked() {
            if (!setup) {
                return 0;
            };
            Vector2 mouse_pos = GetMousePosition();
            int mouse_x = mouse_pos.x;
            int mouse_y = mouse_pos.y;
            if (IsMouseButtonDown(0)) {
                if (mouse_x > start_x && mouse_x < start_x+width && mouse_y > start_y && mouse_y < start_y+height) {
                    return 1;
                };
            };
            return 0;
        };
};

// Class is created inside of the main function, which makes the board consistent.
Cube_board cube;

Button play_button;
Button exit_button;

Button grid1;
Button grid2;
Button grid3;
Button grid4;
Button grid5;
Button grid6;
Button grid7;
Button grid8;
Button grid9;

Button x_move_button;
Button z_prime_button;
Button z_move_button;
Button x_prime_button;

// Organized by uh the position on the board instead of like the order of the move
Button l_prime_button;
Button m_prime_button;
Button r_move_button;

Button b_move_button;
Button b_prime_button;

Button s_prime_button;
Button s_move_button;

Button f_prime_button;
Button f_move_button;

Button l_move_button;
Button m_move_button;
Button r_prime_button;

Button exit_game_button;

int screen_width = 1280;
int screen_height = 720;

int main_menu() {
    if (play_button.check_button_clicked() == 1) {
        return 2;
    }
    else if (exit_button.check_button_clicked() == 1) {
        return 1;
    };
    return 0;
};

void get_user_input() {
    if (grid1.check_button_clicked() == 1) {
        cube.user_input("p1");
    }
    else if (grid2.check_button_clicked() == 1) {
        cube.user_input("p2");
    }
    else if (grid3.check_button_clicked() == 1) {
        cube.user_input("p3");
    }
    else if (grid4.check_button_clicked() == 1) {
        cube.user_input("p4");
    }
    else if (grid5.check_button_clicked() == 1) {
        cube.user_input("p5");
    }
    else if (grid6.check_button_clicked() == 1) {
        cube.user_input("p6");
    }
    else if (grid7.check_button_clicked() == 1) {
        cube.user_input("p7");
    }
    else if (grid8.check_button_clicked() == 1) {
        cube.user_input("p8");
    }
    else if (grid9.check_button_clicked() == 1) {
        cube.user_input("p9");
    }
    else if (x_move_button.check_button_clicked() == 1) {
        cube.user_input("mX");
    }
    else if (z_prime_button.check_button_clicked() == 1) {
        cube.user_input("mZp");
    }
    else if (z_move_button.check_button_clicked() == 1) {
        cube.user_input("mZ");
    }
    else if (x_prime_button.check_button_clicked() == 1) {
        cube.user_input("mXp");
    }
    else if (l_prime_button.check_button_clicked() == 1) {
        cube.user_input("mLp");
    }
    else if (m_prime_button.check_button_clicked() == 1) {
        cube.user_input("mMp");
    }
    else if (r_move_button.check_button_clicked() == 1) {
        cube.user_input("mR");
    }
    else if (b_move_button.check_button_clicked() == 1) {
        cube.user_input("mB");
    }
    else if (b_prime_button.check_button_clicked() == 1) {
        cube.user_input("mBp");
    }
    else if (s_prime_button.check_button_clicked() == 1) {
        cube.user_input("mSp");
    }
    else if (s_move_button.check_button_clicked() == 1) {
        cube.user_input("mS");
    }
    else if (f_prime_button.check_button_clicked() == 1) {
        cube.user_input("mFp");
    }
    else if (f_move_button.check_button_clicked() == 1) {
        cube.user_input("mF");
    }
    else if (l_move_button.check_button_clicked() == 1) {
        cube.user_input("mL");
    }
    else if (m_move_button.check_button_clicked() == 1) {
        cube.user_input("mM");
    }
    else if (r_prime_button.check_button_clicked() == 1) {
        cube.user_input("mRp");
    };
}

std::array<Color, 9> generate_colors() {
    std::array<Color, 9> color_array;
    switch(cube.colors[0][0][0]) {
        case 0:
            color_array[0] = WHITE;
            break;
        case 1:
            color_array[0] = ORANGE;
            break;
        case 2:
            color_array[0] = GREEN;
            break;
        case 3:
            color_array[0] = RED;
            break;
        case 4:
            color_array[0] = BLUE;
            break;
        case 5:
            color_array[0] = YELLOW;
            break;
    };
    switch(cube.colors[0][0][1]) {
        case 0:
            color_array[1] = WHITE;
            break;
        case 1:
            color_array[1] = ORANGE;
            break;
        case 2:
            color_array[1] = GREEN;
            break;
        case 3:
            color_array[1] = RED;
            break;
        case 4:
            color_array[1] = BLUE;
            break;
        case 5:
            color_array[1] = YELLOW;
            break;
    };
    switch(cube.colors[0][0][2]) {
        case 0:
            color_array[2] = WHITE;
            break;
        case 1:
            color_array[2] = ORANGE;
            break;
        case 2:
            color_array[2] = GREEN;
            break;
        case 3:
            color_array[2] = RED;
            break;
        case 4:
            color_array[2] = BLUE;
            break;
        case 5:
            color_array[2] = YELLOW;
            break;
    };
    switch(cube.colors[0][1][0]) {
        case 0:
            color_array[3] = WHITE;
            break;
        case 1:
            color_array[3] = ORANGE;
            break;
        case 2:
            color_array[3] = GREEN;
            break;
        case 3:
            color_array[3] = RED;
            break;
        case 4:
            color_array[3] = BLUE;
            break;
        case 5:
            color_array[3] = YELLOW;
            break;
        };
    switch(cube.colors[0][1][1]) {
        case 0:
            color_array[4] = WHITE;
            break;
        case 1:
            color_array[4] = ORANGE;
            break;
        case 2:
            color_array[4] = GREEN;
            break;
        case 3:
            color_array[4] = RED;
            break;
        case 4:
            color_array[4] = BLUE;
            break;
        case 5:
            color_array[4] = YELLOW;
            break;
        };
    switch(cube.colors[0][1][2]) {
        case 0:
            color_array[5] = WHITE;
            break;
        case 1:
            color_array[5] = ORANGE;
            break;
        case 2:
            color_array[5] = GREEN;
            break;
        case 3:
            color_array[5] = RED;
            break;
        case 4:
            color_array[5] = BLUE;
            break;
        case 5:
            color_array[5] = YELLOW;
            break;
    };
    switch(cube.colors[0][2][0]) {
        case 0:
            color_array[6] = WHITE;
            break;
        case 1:
            color_array[6] = ORANGE;
            break;
        case 2:
            color_array[6] = GREEN;
            break;
        case 3:
            color_array[6] = RED;
            break;
        case 4:
            color_array[6] = BLUE;
            break;
        case 5:
            color_array[6] = YELLOW;
            break;
    };
    switch(cube.colors[0][2][1]) {
        case 0:
            color_array[7] = WHITE;
            break;
        case 1:
            color_array[7] = ORANGE;
            break;
        case 2:
            color_array[7] = GREEN;
            break;
        case 3:
            color_array[7] = RED;
            break;
        case 4:
            color_array[7] = BLUE;
            break;
        case 5:
            color_array[7] = YELLOW;
            break;
    };
    switch(cube.colors[0][2][2]) {
        case 0:
            color_array[8] = WHITE;
            break;
        case 1:
            color_array[8] = ORANGE;
            break;
        case 2:
            color_array[8] = GREEN;
            break;
        case 3:
            color_array[8] = RED;
            break;
        case 4:
            color_array[8] = BLUE;
            break;
        case 5:
            color_array[8] = YELLOW;
            break;
        };
    return color_array;
};  

void draw_board(std::array<Color, 9> color_array, std::array<Button, 9> board_buttons) {
    // Row 1
    board_buttons[0].draw_button(color_array[0], WHITE, 0, 0, 0, "");
    board_buttons[1].draw_button(color_array[1], WHITE, 0, 0, 0, "");
    board_buttons[2].draw_button(color_array[2], WHITE, 0, 0, 0, "");
    // Row 2
    board_buttons[3].draw_button(color_array[3], WHITE, 0, 0, 0, "");
    board_buttons[4].draw_button(color_array[4], WHITE, 0, 0, 0, "");
    board_buttons[5].draw_button(color_array[5], WHITE, 0, 0, 0, "");
    // Row 3
    board_buttons[6].draw_button(color_array[6], WHITE, 0, 0, 0, "");
    board_buttons[7].draw_button(color_array[7], WHITE, 0, 0, 0, "");
    board_buttons[8].draw_button(color_array[8], WHITE, 0, 0, 0, "");
}

void draw_movement(std::array<Button, 16> movement_buttons) {
    x_move_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    z_prime_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    z_move_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    x_prime_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");

    l_prime_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    m_prime_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    r_move_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    b_move_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    b_prime_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    s_prime_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    s_move_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    f_prime_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    f_move_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    l_move_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    m_move_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
    r_prime_button.draw_button(RAYWHITE, WHITE, 0, 0, 0, "");
}

void draw_positions() {
    int temp_x_pos = screen_width/2-175;
    int temp_y_pos = screen_height/2-175;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (cube.positions[0][row][column] == 1) {
                DrawText("X", temp_x_pos, temp_y_pos, 50, BLACK);
            }
            else if (cube.positions[0][row][column] == 2) {
                DrawText("O", temp_x_pos, temp_y_pos, 50, BLACK);
            };
            temp_x_pos += 150;
        };
        temp_x_pos = screen_width/2-175;
        temp_y_pos += 150;
    };
}

int main() {
    int mode = 0;
    bool running = true;

    // Setup of the game window
    InitWindow(screen_width, screen_height, "Tic-Tac-Cube");
    SetTargetFPS(30);
    Image logo_image = LoadImage("assets/bitmap.png");
    SetWindowIcon(logo_image);
    Vector2 mouse_pos;
    float mouse_x;
    float mouse_y;

    play_button.setup_button(screen_width/2, screen_height/10*4, screen_width/5, screen_height/10);
    exit_button.setup_button(screen_width/2, screen_height/10*6, screen_width/5, screen_height/10);

    // I'm actually so happy that this worked, I did not thing it would
    grid1.setup_button(screen_width/2-150, screen_height/2-150, 100, 100);
    grid2.setup_button(screen_width/2, screen_height/2-150, 100, 100);
    grid3.setup_button(screen_width/2+150, screen_height/2-150, 100, 100);
    grid4.setup_button(screen_width/2-150, screen_height/2, 100, 100);
    grid5.setup_button(screen_width/2, screen_height/2, 100, 100);
    grid6.setup_button(screen_width/2+150, screen_height/2, 100, 100);
    grid7.setup_button(screen_width/2-150, screen_height/2+150, 100, 100);
    grid8.setup_button(screen_width/2, screen_height/2+150, 100, 100);
    grid9.setup_button(screen_width/2+150, screen_height/2+150, 100, 100);

    x_move_button.setup_button(screen_width/2, screen_height/2-320, 100, 50);
    z_prime_button.setup_button(screen_width/2-320, screen_height/2, 50, 100);
    z_move_button.setup_button(screen_width/2+320, screen_height/2, 50, 100);
    x_prime_button.setup_button(screen_width/2, screen_height/2+320, 100, 50);

    l_prime_button.setup_button(screen_width/2-150, screen_height/2-250, 50, 50);
    m_prime_button.setup_button(screen_width/2, screen_height/2-250, 50, 50);
    r_move_button.setup_button(screen_width/2+150, screen_height/2-250, 50, 50);
    b_move_button.setup_button(screen_width/2-250, screen_height/2-150, 50, 50);
    b_prime_button.setup_button(screen_width/2+250, screen_height/2-150, 50, 50);
    s_prime_button.setup_button(screen_width/2-250, screen_height/2, 50, 50);
    s_move_button.setup_button(screen_width/2+250, screen_height/2, 50, 50);
    f_prime_button.setup_button(screen_width/2-250, screen_height/2+150, 50, 50);
    f_move_button.setup_button(screen_width/2+250, screen_height/2+150, 50, 50);
    l_move_button.setup_button(screen_width/2-150, screen_height/2+250, 50, 50);
    m_move_button.setup_button(screen_width/2, screen_height/2+250, 50, 50);
    r_prime_button.setup_button(screen_width/2+150, screen_height/2+250, 50, 50);

    exit_game_button.setup_button(25, 12, 50, 25);

    // Arrays of buttons
    std::array<Button, 9> board_buttons = {
        grid1,
        grid2,
        grid3, 
        grid4,
        grid5,
        grid6,
        grid7,
        grid8,
        grid9
    };

    std::array<Button, 16> movement_buttons = {
        x_move_button,
        z_prime_button,
        z_move_button,
        x_prime_button,

        l_prime_button,
        m_prime_button,
        r_move_button,
        b_move_button,
        b_prime_button,
        s_prime_button,
        s_move_button,
        f_prime_button,
        f_move_button,
        l_move_button,
        m_move_button,
        r_prime_button
    };

    while (running && !WindowShouldClose()) {
        // Uh getting data about the players ig
        mouse_pos = GetMousePosition();
        mouse_x = mouse_pos.x;
        mouse_y = mouse_pos.y;

        // Simulate
        switch(mode) {
            case 0:
                mode = main_menu();
                if (mode != 0) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                };
                break;
            case 1:
                running = false;
                break;
            case 2:
                // Singleplayer
                if (exit_game_button.check_button_clicked() == 1) {
                    mode = 0;
                    cube.reset();
                    break;
                };
                
                // Check for user input of the grid spaces (P and M)
                get_user_input();
                mode = cube.gameloop();
                break;
            case 3:
                // There's no rendering to be done, I just need it to not reset back to mode 0
                break;
            case 4:
                // There's no rendering to be done, I just need it to not reset back to mode 0
                break;
            case 5:
                // Multiplayer
                break;
            default:
                std::cout << "Invalid command";
                mode = 0;
        };
        // Render
        std::array<Color, 9> color_array;
        int temp_x_pos = screen_width/2-175;
        int temp_y_pos = screen_height/2-175;
        switch(mode) {
            case 0:
                BeginDrawing();
                ClearBackground({25, 25, 25, 255});
                DrawText("Tic-Tac-Cube", screen_width/10*4, screen_height/10*2, 35, WHITE);
                // Drawing the buttons
                play_button.draw_button(RED, WHITE, 70, 20, 40, "PLAY");
                exit_button.draw_button(RED, WHITE, 70, 20, 40, "EXIT");
                EndDrawing();
                break;
            case 2:
                // Multiplayer
                BeginDrawing();
                ClearBackground({25, 25, 25, 255});

                color_array = generate_colors();
                draw_board(color_array, board_buttons);
                draw_movement(movement_buttons);
                draw_positions();

                exit_game_button.draw_button(RAYWHITE, BLACK, 0, 0, 20, "EXIT");

                EndDrawing();
                break;
            case 3:
                BeginDrawing();
                draw_positions();
                DrawRectangle(0, 0, 50, 50, {25, 25, 25, 255});
                DrawText("X Wins!", 0, 0, 30, WHITE);
                EndDrawing();
                std::this_thread::sleep_for(std::chrono::seconds(1));
                cube.reset();
                mode = 0;
                break;
            case 4:
                BeginDrawing();
                draw_positions();
                DrawRectangle(0, 0, 50, 50, {25, 25, 25, 255});
                DrawText("O Wins!", 0, 0, 30, WHITE);
                EndDrawing();
                std::this_thread::sleep_for(std::chrono::seconds(1));
                cube.reset();
                mode = 0;
                break;
            case 5:
                // Singleplayer
                mode = 0;
                break;
        };
    };
    CloseWindow();
    return 0;
};

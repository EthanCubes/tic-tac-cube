#include <array>
#include <string>
#include <chrono>
#include <tuple>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <random>

#include "board.h"
#include "bot.h"
#include "logs.h"

#include "raylib.h"

// I opened this file in CLion once, it showed like 200 warnings. Either I don't write good enough code (very likely) or CLion is kinda nuts (somewhat unlikely)

// Buttons are always pretty difficult
class Button {
    private:
        int start_x;
        int start_y;
        int width;
        int height;

        bool setup = false;

        Vector2 get_text_dimensions(const char* text, int font_size) {
            Vector2 text_dimensions = MeasureTextEx(GetFontDefault(), text, font_size, 3.0f);
            return text_dimensions;
        };
    public:
        void setup_button(int start_x_setup, int start_y_setup, int width_setup, int height_setup) {
            if (setup) {
                log_data("Button already declared!");
                return;
            };
            start_x = start_x_setup-width_setup/2;
            start_y = start_y_setup-height_setup/2;
            width = width_setup;
            height = height_setup;
            setup = true;
        };

        void draw_button(Color button_color, const char* text, int font_size, Color text_color) {
            if (!setup) {
                log_data("Button not declared!");
                return;
            };

            // So apparently Vector2 is something that I have to declare myself. Great. I love when I have to write my own libraries, unless i spent 10 hours trying to find someone else's code and find nothing
            Vector2 text_dimensions = get_text_dimensions(text, font_size);
            int text_width = text_dimensions.x;
            int text_height = text_dimensions.y;
            int relative_width = (width - text_width)/2;
            int relative_height = (height - text_height)/2;
            Vector2 position{(float)(start_x + relative_width), (float)(start_y + relative_height)};

            DrawRectangle(start_x, start_y, width, height, button_color);
            DrawTextEx(GetFontDefault(), text, position, font_size, 3.0f, text_color); // Font, text, position, font-size, spacing, color
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

Button singleplayer_button;
Button multiplayer_button;
Button help_button;
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
    if (multiplayer_button.check_button_clicked() == 1) {
        log_data("Initiating local multiplayer game");
        return 2;
    }
    else if (singleplayer_button.check_button_clicked() == 1) {
        log_data("Initiating singleplayer game");
        return 5; // Huh this doesn't work for some reason
    }
    else if (exit_button.check_button_clicked() == 1) {
        log_data("Exit signal recieved");
        return 1;
    }
    else if (help_button.check_button_clicked() == 1) {
        // How the hell is this not working?
        log_data("Displaying help page");
        return 7;
    }
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
    board_buttons[0].draw_button(color_array[0], "", 0, WHITE);
    board_buttons[1].draw_button(color_array[1], "", 0, WHITE);
    board_buttons[2].draw_button(color_array[2], "", 0, WHITE);
    // Row 2
    board_buttons[3].draw_button(color_array[3], "", 0, WHITE);
    board_buttons[4].draw_button(color_array[4], "", 0, WHITE);
    board_buttons[5].draw_button(color_array[5], "", 0, WHITE);
    // Row 3
    board_buttons[6].draw_button(color_array[6], "", 0, WHITE);
    board_buttons[7].draw_button(color_array[7], "", 0, WHITE);
    board_buttons[8].draw_button(color_array[8], "", 0, WHITE);
}

void draw_movement() {
    x_move_button.draw_button(RAYWHITE, "", 0, WHITE);
    z_prime_button.draw_button(RAYWHITE, "", 0, WHITE);
    z_move_button.draw_button(RAYWHITE, "", 0, WHITE);
    x_prime_button.draw_button(RAYWHITE, "", 0, WHITE);

    l_prime_button.draw_button(RAYWHITE, "", 0, WHITE);
    m_prime_button.draw_button(RAYWHITE, "", 0, WHITE);
    r_move_button.draw_button(RAYWHITE, "", 0, WHITE);
    b_move_button.draw_button(RAYWHITE, "", 0, WHITE);
    b_prime_button.draw_button(RAYWHITE, "", 0, WHITE);
    s_prime_button.draw_button(RAYWHITE, "", 0, WHITE);
    s_move_button.draw_button(RAYWHITE, "", 0, WHITE);
    f_prime_button.draw_button(RAYWHITE, "", 0, WHITE);
    f_move_button.draw_button(RAYWHITE, "", 0, WHITE);
    l_move_button.draw_button(RAYWHITE, "", 0, WHITE);
    m_move_button.draw_button(RAYWHITE, "", 0, WHITE);
    r_prime_button.draw_button(RAYWHITE, "", 0, WHITE);
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
};

void popup_message(const char* text) {
    Button popup;
    popup.setup_button(1130, 40, 300, 80);
    popup.draw_button(GRAY, text, 20, WHITE);
};

// All the popups
// I know global variables aren't the best, but I'm not a fan of plugging in like 20 parameters into a function.
std::map<std::string, std::tuple<bool, const std::string, const int, int>> popups = {{
    {"hidden_win", {false, "Why'd the game end?\nThe win just happened on\nanother side of the board", 2, 0}},
    {"user_goes_first", {false, "You're X\nYou go first", 1, 0}},
    {"bot_goes_first", {false, "You're O\nYou go second", 1, 0}},
    {"multiplayer_game_start", {false, "Local multiplayer game\nPlay whenever", 1, 0}}
}};
std::vector<std::string> popup_keys = {
    "hidden_win",
    "user_goes_first",
    "bot_goes_first",
    "multiplayer_game_start"
};
bool hidden_win = false;
bool user_goes_first = false;
bool bot_goes_first = false;
bool multiplayer_game_start = false;

void handle_popups() {
    int map_size = popup_keys.size();
    for (int i = 0; i < map_size; i++) {
        std::string key = popup_keys[i];
        bool active = std::get<0>(popups[key]);
        std::string content = std::get<1>(popups[key]);
        int duration = std::get<2>(popups[key]);
        int start_time = std::get<3>(popups[key]);
        if (active) {
        // https://stackoverflow.com/questions/347949/how-to-convert-a-stdstring-to-const-char-or-char
            popup_message(content.c_str());
            if ((time(NULL) - start_time) > duration) {
                std::get<0>(popups[key]) = false;
            };
        };
    };
};

void activate_popup(std::string key) {
    std::get<0>(popups[key]) = true;
    std::get<3>(popups[key]) = time(NULL);
};

int main() {
    create_log_file();
    int mode = 0;
    bool running = true;

    std::random_device dev;
    std::mt19937 rng(dev());

    InitWindow(screen_width, screen_height, "Tic-Tac-Cube");
    SetTargetFPS(30);
    Image logo_image = LoadImage("assets/bitmap.png");
    SetWindowIcon(logo_image);

    log_data("Window initialization complete");

    multiplayer_button.setup_button(screen_width/2, screen_height/20*12, screen_width/5, screen_height/10);
    singleplayer_button.setup_button(screen_width/2, screen_height/20*9, screen_width/5,screen_height/10);
    exit_button.setup_button(screen_width/2, screen_height/20*18, screen_width/5, screen_height/10);
    help_button.setup_button(screen_width/2, screen_height/20*15, screen_width/5, screen_height/10);

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

    exit_game_button.setup_button(12, 12, 25, 25);

    int bot_turn;
    int user_turn;
    bool setup = false;

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

    while (running && !WindowShouldClose()) {
        // Uh getting data about the players ig

        // Popup check & calc
        handle_popups();

        // Simulate
        // 0: main menu, 1: quit, 2: multiplayer, 3: X victory, 4: y victory, 5: singleplayer, 6: draw, 7: help page
        switch(mode) {
            case 0:
                mode = main_menu();
                setup = false;
                if (mode != 0) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    if (mode == 2) {
                        cube.move_count = 0;
                        activate_popup("multiplayer_game_start");
                    };
                };
                break;
            case 1:
                running = false;
                break;
            case 2:
                // Multiplayer
                if (exit_game_button.check_button_clicked() == 1) {
                    mode = 0;
                    cube.reset();
                    break;
                };
                
                // Check for user input of the grid spaces (P and M)
                get_user_input();
                mode = cube.gameloop(2);
                break;
            case 3:
                log_data(std::to_string(cube.hidden));
                if (cube.hidden) {
                    log_data("Hidden game conclusion");
                };
                log_data("Game ends in X victory"); //
                break;
            case 4:
                log_data(std::to_string(cube.hidden));
                if (cube.hidden) {
                    log_data("Hidden game conclusion");
                };
                log_data("Game ends in O victory");
                break;
            case 5: {
                        bool rng_valid = true;
                        if (cube.move_count == 1) {
                            rng_valid = false;
                        };
                        // Singleplayer
                        if (!setup) {
                            cube.move_count = 0;
                            // https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
                            std::uniform_int_distribution<std::mt19937::result_type> dist_turn(1, 2);
                            bot_turn = dist_turn(rng);
                            user_turn = 3 - bot_turn;
                            switch(bot_turn) { // emphasis on bot turn
                                case 1:
                                    log_data("Singleplayer game started with player as O");
                                    activate_popup("bot_goes_first");
                                    break;
                                case 2:
                                    log_data("Singleplayer game started with player as X");
                                    activate_popup("user_goes_first");
                                    break;
                                default:
                                    log_data("Anomaly in game setup, bot turn is specified as " + std::to_string(bot_turn));
                            };
                            user_turn = 3 - bot_turn;
                            setup = true;
                        };

                        if (exit_game_button.check_button_clicked() == 1) {
                            mode = 0;
                            log_data("Game aborted by user");
                            cube.reset();
                            break;
                        };

                        // Check for user input of the grid spaces (P and M)
                        if (cube.turn == user_turn) {
                            get_user_input();
                        }
                        else {
                            cube.user_input(get_bot_move(cube.positions, bot_turn, rng_valid));
                        }
                        mode = cube.gameloop(5);
                        break;
                    }
            case 6:
                log_data("Game ends in tie as board is completely full without victory");
                break;
            case 7:
                if (exit_game_button.check_button_clicked() == 1) {
                    mode = 0;
                    log_data("Returning back to main menu");
                };
                break;
            default:
                std::cout << "Invalid command";
                mode = 0;
        };

        // Render
        std::array<Color, 9> color_array;
        switch(mode) {
            case 0:
                BeginDrawing();
                ClearBackground({25, 25, 25, 255});
                DrawText("Tic-Tac-Cube", screen_width/10*4, screen_height/10*2, 35, WHITE);
                // Drawing the buttons
                singleplayer_button.draw_button(RED, "Singleplayer", 40, WHITE);
                multiplayer_button.draw_button(RED, "Multiplayer", 40, WHITE);
                exit_button.draw_button(RED, "Exit", 40, WHITE);
                help_button.draw_button(RED, "Help", 40, WHITE);
                EndDrawing();
                break;
            case 2:
                // Multiplayer
                BeginDrawing();
                ClearBackground({25, 25, 25, 255});

                color_array = generate_colors();
                draw_board(color_array, board_buttons);
                draw_movement();
                draw_positions();

                exit_game_button.draw_button(RAYWHITE, "<", 20, BLACK);

                EndDrawing();
                break;
            case 3:
                BeginDrawing();
                ClearBackground({25, 25, 25, 255});

                if (cube.hidden) {
                    activate_popup("hidden_win");
                    handle_popups();
                };

                // Clearing the board and rendering it again.
                color_array = generate_colors();
                draw_board(color_array, board_buttons);
                draw_positions();

                DrawRectangle(0, 0, 50, 50, {25, 25, 25, 255});
                DrawText("X Wins!", 0, 0, 50, PURPLE);
                log_data("game ends in X victory");
                EndDrawing();
                std::this_thread::sleep_for(std::chrono::seconds(1));
                cube.reset();
                mode = 0;
                break;
            case 4:
                BeginDrawing();
                ClearBackground({25, 25, 25, 255});

                if (cube.hidden) {
                    activate_popup("hidden_win");
                    handle_popups();
                };

                // Clearing the board and rendering it again.
                color_array = generate_colors();
                draw_board(color_array, board_buttons);
                draw_positions();

                DrawRectangle(0, 0, 50, 50, {25, 25, 25, 255});
                DrawText("O Wins!", 0, 0, 50, PURPLE);
                log_data("game ends in O victory");
                EndDrawing();
                std::this_thread::sleep_for(std::chrono::seconds(1));
                cube.reset();
                mode = 0;
                break;
            case 5:
                // Singleplayer
                BeginDrawing();
                ClearBackground({25, 25, 25, 255});

                color_array = generate_colors();
                draw_board(color_array, board_buttons);
                
                if (cube.turn == user_turn) {
                    draw_movement();
                };
                draw_positions();

                exit_game_button.draw_button(RAYWHITE, "<", 20, BLACK);
                EndDrawing();

                break;
            case 6:
                // Draw
                BeginDrawing();
                draw_positions();
                DrawRectangle(0, 0, 50, 50, {25, 25, 25, 255});
                DrawText("Board Full! (Tie)", 0, 0, 30, WHITE);
                EndDrawing();
                std::this_thread::sleep_for(std::chrono::seconds(1));
                cube.reset();
                mode = 0;
                break;
            case 7:
                log_data("Drawing help menu");
                // Setup the text because it cannot be the best practice to type all the text into the functions manually.
                const char* header = "Help";
                const char* displayed_text = "General: Click one of the squares in the 3x3 grid to mark a spot, like in regular tic-tac-toe. Click one of the rectangles\n"
                    "next to the cube to rotate the cube.\n\n"
                    "Singleplayer game: A message should appear in the top right telling you who you are, X or O. In case it wasn't obvious,\n"
                    "X goes first, O goes next\n\n"
                    "Local multiplayer game: In these games, you play as both X and O. Otherwise it is just the same as singleplayer\n\n"
                    "Quick little warning: Due to the nature of a Rubik's cube, it is possible to win (or lose) the game while a 3-in-a-row isn't\n"
                    "visable on-screen. If one of the non-visible sides has a two-in-a-row, and you (or the bot) rotate a third onto the missing\n"
                    "position, creating a three-in-a-row on a hidden side, the game will end, just like if a three-in-a-row happened on a visible\n"
                    "side.\n\n";

                // Draw entire help menu
                BeginDrawing();
                ClearBackground({25, 25, 25, 255});
                exit_game_button.draw_button(RAYWHITE, "<", 20, BLACK);
                DrawText(header, 600, 0, 40, WHITE);
                DrawText(displayed_text, 0, 40, 20, WHITE);
                EndDrawing();
                break;
        };
    };
    CloseWindow();
    log_data("Window closed sucessfully");
    log_data("Quitting game");
    log_data("---- End of program ----");
    return 0;
};

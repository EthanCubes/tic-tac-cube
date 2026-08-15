#include <iostream>
#include <array>
#include <string>
#include <tuple>

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

        void draw_button(Color button_color, Color text_color, int text_x_offset, int text_y_offset, const char* text) {
            if (!setup) {
                std::cout << "Button not declared!";
                return;
            };
            DrawRectangle(start_x, start_y, width, height, button_color);
            DrawText(text, start_x+text_x_offset, start_y+text_y_offset, 40, text_color);
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

int main_menu(int screen_width, int screen_height) {
    if (play_button.check_button_clicked() == 1) {
        return 2;
    }
    else if (exit_button.check_button_clicked() == 1) {
        return 1;
    };
    return 0;
};

int main() {
    int mode = 0;
    bool running = true;

    // Setup of the game window
    int screen_width = 1280;
    int screen_height = 720;
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

    while (running && !WindowShouldClose()) {
        // Uh getting data about the players ig
        mouse_pos = GetMousePosition();
        mouse_x = mouse_pos.x;
        mouse_y = mouse_pos.y;

        // Simulate
        switch(mode) {
            case 0:
                mode = main_menu(screen_width, screen_height);
                if (mode != 0) {
                    std::cout << "thing";
                };
                break;
            case 1:
                running = false;
                break;
            case 2:
                mode = cube.gameloop();
                break;
            default:
                std::cout << "Invalid command";
                mode = 0;
        };
        // Render
        switch(mode) {
            case 0:
                BeginDrawing();
                ClearBackground({25, 25, 25, 255});
                DrawText("Tic-Tac-Cube", screen_width/10*4, screen_height/10*2, 35, WHITE);
                // Drawing the buttons
                play_button.draw_button(RED, WHITE, 70, 20, "PLAY");
                exit_button.draw_button(RED, WHITE, 70, 20, "EXIT");
                EndDrawing();
                break;
            case 2:
                BeginDrawing();
                ClearBackground({25, 25, 25, 255});

                // Row 1
                grid1.draw_button(RED, WHITE, 0, 0, "");
                grid2.draw_button(RED, WHITE, 0, 0, "");
                grid3.draw_button(RED, WHITE, 0, 0, "");
                // Row 2
                grid4.draw_button(RED, WHITE, 0, 0, "");
                grid5.draw_button(RED, WHITE, 0, 0, "");
                grid6.draw_button(RED, WHITE, 0, 0, "");
                // Row 3
                grid7.draw_button(RED, WHITE, 0, 0, "");
                grid8.draw_button(RED, WHITE, 0, 0, "");
                grid9.draw_button(RED, WHITE, 0, 0, "");

                // Rendering the positions on the board
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

                EndDrawing();
                break;
        };
    };
    CloseWindow();
    return 0;
};

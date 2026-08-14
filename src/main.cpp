#include <iostream>
#include <array>
#include <string>
#include <tuple>

#include "board.h"

#include "raylib.h"

/*
- [x] Make a GUI for the main menu
- [ ] Make a GUI for the game
- [ ] Make a Bot for the game
- [ ] Uh make the GUI look nice
*/

// Buttons are always pretty difficult
class button {
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
            start_x = start_x_setup;
            start_y = start_y_setup;
            width = width_setup;
            height = height_setup;
            setup = true;
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

int main_menu(float mouse_x, float mouse_y, int screen_width, int screen_height) {
    if (IsMouseButtonDown(0)) {
        // Check for buttons
        if (mouse_x > screen_width/10*4 && mouse_x < screen_width/10*4+screen_width/5 && mouse_y > screen_height/10*4 && mouse_y < screen_height/10*4+screen_height/10) {
            return 2;
        }
        else if (mouse_x > screen_width/10*4 && mouse_x < screen_width/10*4+screen_width/5 && mouse_y > screen_height/10*6 && mouse_y < screen_height/10*6+screen_height/10) {
            return 1;
        };
    };
    return 0;
};

// Class is created inside of the main function, which makes the board consistent.
Cube_board cube;


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

    while (running && !WindowShouldClose()) {
        // Uh getting data about the players ig
        mouse_pos = GetMousePosition();
        mouse_x = mouse_pos.x;
        mouse_y = mouse_pos.y;

        // Simulate
        switch(mode) {
            case 0:
                mode = main_menu(mouse_x, mouse_y, screen_width, screen_height);
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
                DrawRectangle(screen_width/10*4, screen_height/10*4, screen_width/5, screen_height/10, RED); // X, Y, Width, Heigh, Color
                DrawText("Play", screen_width/10*4.7, screen_height/10*4.4, 30, WHITE);
                DrawRectangle(screen_width/10*4, screen_height/10*6, screen_width/5, screen_height/10, RED); 
                DrawText("Exit", screen_width/10*4.7, screen_height/10*6.4, 30, WHITE);
                EndDrawing();
                break;
            case 2:
                // Uh like render the game idk how to do it
                // Essentially: 3x3 square, rendered somehow, with x's and o's drawn onto it
                BeginDrawing();
                ClearBackground({25, 25, 25, 255});

                // Row 1
                DrawRectangle(screen_width/2-200, screen_height/2-200, 100, 100, RED);
                DrawRectangle(screen_width/2-50, screen_height/2-200, 100, 100, RED);
                DrawRectangle(screen_width/2+100, screen_height/2-200, 100, 100, RED);
                // Row 2
                DrawRectangle(screen_width/2-200, screen_height/2-50, 100, 100, RED);
                DrawRectangle(screen_width/2-50, screen_height/2-50, 100, 100, RED);
                DrawRectangle(screen_width/2+100, screen_height/2-50, 100, 100, RED);
                // Row 3
                DrawRectangle(screen_width/2-200, screen_height/2+100, 100, 100, RED);
                DrawRectangle(screen_width/2-50, screen_height/2+100, 100, 100, RED);
                DrawRectangle(screen_width/2+100, screen_height/2+100, 100, 100, RED);

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

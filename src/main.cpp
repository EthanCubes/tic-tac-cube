#include <iostream>
#include <array>
#include <string>
#include <tuple>

#include "board.h"

#include "raylib.h"

// List of stuff I need to do: make a gui for main menu, make gui for game, add bot to play with. Uh not really sure how to do any of that.

int main_menu(float mouse_x, float mouse_y, int screen_width, int screen_height) {
    std::string input;
    // I need to add a button
    if (IsMouseButtonDown(0)) {
        // Check for buttons
        // There's no reasn this shouldn't work, so why isn't it working? Like this has worked before I think
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
    float mouse_x = mouse_pos.x;
    float mouse_y = mouse_pos.y;

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
        BeginDrawing();
        ClearBackground({25, 25, 25, 255});
        DrawText("Tic-Tac-Cube", screen_width/10*4, screen_height/10*2, 35, WHITE);
        // Drawing the buttons
        DrawRectangle(screen_width/10*4, screen_height/10*4, screen_width/5, screen_height/10, RED); // X, Y, Width, Heigh, Color
        DrawText("Play", screen_width/10*4.7, screen_height/10*4.4, 30, WHITE);
        DrawRectangle(screen_width/10*4, screen_height/10*6, screen_width/5, screen_height/10, RED); 
        DrawText("Exit", screen_width/10*4.7, screen_height/10*6.4, 30, WHITE);
        EndDrawing();
    };
    CloseWindow();
    return 0;
};

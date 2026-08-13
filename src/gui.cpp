#include <array>
#include <string>
#include <tuple>

#include "raylib.h"

int main() {
    InitWindow(1280, 720, "Tic-Tac-Cube");
    SetTargetFPS(60);
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    };
    CloseWindow();
    return 0;
};

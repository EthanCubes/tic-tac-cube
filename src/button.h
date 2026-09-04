#ifndef BUTTON_H
#define BUTTON_H

// Include this for drawing the button
#include "raylib.h"

// This code is not ready to use! Do not compile the related source code, as it is not ready.

// For the setup, it's X Pos, Y Pos, Width, Height, Color, roundness, segments, button_text, font_size, font_color

class Button {
    private:
        int x_pos;
        int y_pos;
        int width;
        int height;

        // Color comes from Raylib
        Color color;

        // Optional rounding and stuff
        float roundness;
        int segments;

        const char* button_text;
        int font_size;
        Color font_color;
    public:
        void setup_button() {};

        // In case it wasn't obvious, to_change is the quality to change and change to is what to change it to
        // Why am I writing comments inside of a header file?
        void change_button(std::string to_change, std::string change_to) {};

        void draw_button()
};

#endif

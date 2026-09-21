#include "raylib.h"

// It's always good practice to use const

// These don't use SCREAMING_SNAKE_CASE even though they're constants because I'm too lazy to change them, plus they're only constants because that's good practice
extern const int screen_width = 1280;
extern const int screen_height = 720;

extern const Color BACKGROUND_COLOR = {12, 13, 17, 255};
extern const Color MAIN_MENU_BUTTON_COLOR = {126, 186, 181, 255};
extern const Color MINOR_BUTTON_COLOR = {126, 186, 181, 255};
extern const Color TEXT_COLOR_1 = {246, 245, 245, 255};
extern const Color TEXT_COLOR_2 = {12, 13, 17, 255};

extern const Color BUTTON_HOVER_COLOR = {246, 245, 245, 255};

extern Font FONT_SMALL;
extern Font FONT;
extern Font FONT_BIG;

bool font_setup = false;

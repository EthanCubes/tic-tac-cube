#ifndef BUTTON_H
#define BUTTON_H

#include <array>
#include <nlohmann/json.hpp>
#include "raylib.h"
#include "global.h"

using json = nlohmann::json;

// This file is not yet ready for usage! Don't link it in any other files

/*
 * x pos
 * y pos
 * width
 * height
 * color
 * roundness
 * steps
 * text
 * font size
 * font color
 */

const int UNDEFINED = 0; // This is for the JSON. Also, button coors can never be 0, so this does not conflict

// raylib json doesn't work with json by default
json color_to_json(const Color& c);

Color json_to_color(const json& j);

// The coordinates are started from the center, which can get a little weird but it's fine i guess

// Preset buttons and stuff
const json TITLE_BUTTON = json({
    {"x_pos", screen_width/2},
    {"y_pos", screen_height/5},
    {"width", 0},
    {"height", 0},
    {"color", color_to_json(BACKGROUND_COLOR)},
    {"roundness", 0.0f},
    {"steps", 5},
    {"text", "Tic-Tac-Cube"},
    {"font_size", 50},
    {"font_color", color_to_json(TEXT_COLOR_1)}
});

const json SINGLEPLAYER_BUTTON = json({
    {"x_pos", screen_width/2},
    {"y_pos", screen_height/20*9},
    {"width", screen_width/5},
    {"height", screen_height/10},
    {"color", color_to_json(MAIN_MENU_BUTTON_COLOR)},
    {"roundness", 0.25f},
    {"steps", 5},
    {"text", "Singleplayer"},
    {"font_size", 40},
    {"font_color", color_to_json(TEXT_COLOR_1)}
});
const json MULTIPLAYER_BUTTON = json({
    {"x_pos", screen_width/2},
    {"y_pos", screen_height/20*12},
    {"width", screen_width/5},
    {"height", screen_height/10},
    {"color", color_to_json(MAIN_MENU_BUTTON_COLOR)},
    {"roundness", 0.25f},
    {"steps", 5},
    {"text", "Multiplayer"},
    {"font_size", 40},
    {"font_color", color_to_json(TEXT_COLOR_1)}
});
const json HELP_BUTTON = json({
    {"x_pos", screen_width/2},
    {"y_pos", screen_height/20*15},
    {"width", screen_width/5},
    {"height", screen_height/10},
    {"color", color_to_json(MAIN_MENU_BUTTON_COLOR)},
    {"roundness", 0.25f},
    {"steps", 5},
    {"text", "Help"},
    {"font_size", 40},
    {"font_color", color_to_json(TEXT_COLOR_1)}
});
const json EXIT_BUTTON = json({
    {"x_pos", screen_width/2},
    {"y_pos", screen_height/20*18},
    {"width", screen_width/5},
    {"height", screen_height/10},
    {"color", color_to_json(MAIN_MENU_BUTTON_COLOR)},
    {"roundness", 0.25f},
    {"steps", 5},
    {"text", "Exit"},
    {"font_size", 40},
    {"font_color", color_to_json(TEXT_COLOR_1)}
});

const json BOARD_BUTTON = json({
    {"x_pos", UNDEFINED},
    {"y_pos", UNDEFINED},
    {"width", 100},
    {"height", 100},
    {"color", UNDEFINED},
    {"roundness", 0.25f},
    {"steps", 5},
    {"text", UNDEFINED},
    {"font_size", UNDEFINED},
    {"font_color", color_to_json(TEXT_COLOR_2)}
});
const json SQUARE_MOVEMENT_BUTTON = json({
    {"x_pos", UNDEFINED},
    {"y_pos", UNDEFINED},
    {"width", 50},
    {"height", 50},
    {"color", color_to_json(MINOR_BUTTON_COLOR)},
    {"roundness", 0.25f},
    {"steps", 5},
    {"text", UNDEFINED},
    {"font_size", 20},
    {"font_color", color_to_json(TEXT_COLOR_1)}
});
const json RECTANGLE_MOVEMENT_BUTTON_HORIZONTAL = json({
    {"x_pos", UNDEFINED},
    {"y_pos", UNDEFINED},
    {"width", 100},
    {"height", 50},
    {"color", color_to_json(MINOR_BUTTON_COLOR)},
    {"roundness", 0.25f},
    {"steps", 5},
    {"text", UNDEFINED},
    {"font_size", 20},
    {"font_color", color_to_json(TEXT_COLOR_1)}
});
const json RECTANGLE_MOVEMENT_BUTTON_VERTICAL = json({
    {"x_pos", UNDEFINED},
    {"y_pos", UNDEFINED},
    {"width", 50},
    {"height", 100},
    {"color", color_to_json(MINOR_BUTTON_COLOR)},
    {"roundness", 0.25f},
    {"steps", 5},
    {"text", UNDEFINED},
    {"font_size", 20},
    {"font_color", color_to_json(TEXT_COLOR_1)}
});

const json POPUP_BUTTON = json({
    {"x_pos", screen_width - 150},
    {"y_pos", 60},
    {"width", 300},
    {"height", 80},
    {"color", color_to_json(MINOR_BUTTON_COLOR)},
    {"roundness", 0.25f},
    {"steps", 5},
    {"text", UNDEFINED},
    {"font_size", 20},
    {"font_color", color_to_json(TEXT_COLOR_1)}
});

const json EXIT_GAME_BUTTON = json({
    {"x_pos", 20},
    {"y_pos", 20},
    {"width", 40},
    {"height", 40},
    {"color", color_to_json(MINOR_BUTTON_COLOR)},
    {"roundness", 0.25f},
    {"steps", 5},
    {"text", "<"},
    {"font_size", 20},
    {"font_color", color_to_json(TEXT_COLOR_1)}
});

class Button {
    private:
        json button_info;
        json button_hover_info;

        const std::array<std::string, 10> key_array = {
            "x_pos",
            "y_pos",
            "width",
            "height",
            "color",
            "roundness",
            "steps",
            "text",
            "font_size",
            "font_color"
        };
    public:
        void setup_button(json button_info_input);
        void setup_button_hover(json button_info_input);
        void change_button(std::string key, json change_to, bool hover);

        bool check_hover();
        bool check_button_clicked();

        void draw_button();
};

#endif

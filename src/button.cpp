#include <nlohmann/json>
#include "raylib.h"
#include "global.h"

using json = nlohmann::json;

// This file is not yet ready for usage! Don't link it in the install shell script

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
/*
    {"x_pos", 20},
    {"y_pos", 20},
    {"width", 40},
    {"height", 40},
    {"color", MINOR_BUTTON_COLOR},
    {"roundness", 0.25f},
    {"steps", 5},
    {"text", "<"},
    {"font_size", 20},
    {"font_color", TEXT_COLOR_1}
*/

void Button::setup_button(json button_info_input) {
    // Honestly corrupted data doesn't matter, no one's actually contributing to this besides me and if anyone is then they can fix this is a matter of like seconds
    button_info = button_info_input
};
void Button::setup_button_hover(json button_info_input) {
    button_hover_info = button_info_input;
};
void Button::change_button(std::string key, std::string change_to, bool hover) {
    if (!hover) {
        button_info[key] = change_to;
    }
    else {
        button_hover_info[key] = change_to;
    };
};

bool check_hover() {
    Vector2 mouse_pos = GetMousePosition();
    int mouse_x = mouse_pos.x;
    int mouse_y = mouse_pos.y;
    if (mouse_x > start_x && mouse_x < start_x+width && mouse_y > start_y && mouse_y < start_y+height) {
        return true;
    };
    return false;
};

bool check_button_clicked() {
    if (!setup) {
        return false;
    };
    Vector2 mouse_pos = GetMousePosition();
    int mouse_x = mouse_pos.x;
    int mouse_y = mouse_pos.y;
    if (IsMouseButtonDown(0)) {
        if (check_hover()) {
            return true;
        };
    };
    return false;
};

void Button::draw_button() {
    // I supposed I could do converting numbers to the correct format on a separate file, but like whatever
    if (x_pos == 0 || y_pos == 0) {
        return;
    };

    // Convert coodinates from the center back to the corner for actual drawing. This can actually be 0
    int calibrated_x = x_pos - width/2;
    int calibrated_y = y_pos - height/2;

    // This part is really hard, we have to center the text by getting the width and then doing some super complex math thing
    Vector2 text_dimensions = MeasureTextEx(GetFontDefault(), text, static_cast<float>(font_size), 3.0f);
    int text_width = text_dimensions.x;
    int text_height = text_dimensions.y;
    int text_x = x_pos + (width - text_width)/2;
    int text_y = y_pos + (height - text_height)/2;
    Vector2 text_position = {text_x, text_y};

    Rectangle rectangle_information = {static_cast<float>(x_pos), static_cast<float>(y_pos), static_cast<float>(width), static_cast<float>(height)};
    DrawRectangleRounded(rectangle_information, roundness, steps, color);
    DrawTextEx(GetFontDefault(), text.c_str(), text_position, static_cast<float>(font_size), 3.0f, font_color);
};

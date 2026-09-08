#include <nlohmann/json.hpp>
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
    button_info = button_info_input;
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

bool Button::check_hover() {
    Vector2 mouse_pos = GetMousePosition();
    int mouse_x = mouse_pos.x;
    int mouse_y = mouse_pos.y;
    if (mouse_x > button_info["x_pos"] && mouse_x < button_info["x_pos"]+button_info["width"] && mouse_y > button_info["y_pos"] && mouse_y < button_info["y_pos"]+button_info["height"]) {
        return true;
    };
    return false;
};

bool Button::check_button_clicked() {
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
    if (check_hover()) {
        if (button_hover_info["x_pos"] == 0 || button_hover_info["y_pos"] == 0) {
            return;
        };

        // Convert coodinates from the center back to the corner for actual drawing. This can actually be 0
        int calibrated_x = button_hover_info["x_pos"] - button_hover_info["width"]/2;
        int calibrated_y = button_hover_info["y_pos"] - button_hover_info["height"]/2;

        // This part is really hard, we have to center the text by getting the width and then doing some super complex math thing
        Vector2 text_dimensions = MeasureTextEx(GetFontDefault(), button_hover_info["text"], static_cast<float>(button_hover_info["font_size"]), 3.0f);
        int text_width = text_dimensions.x;
        int text_height = text_dimensions.y;
        int text_x = calibrated_x + (button_hover_info["width"] - text_width)/2;
        int text_y = calibrated_y + (button_hover_info["height"] - text_height)/2;
        Vector2 text_position = {text_x, text_y};

        Rectangle rectangle_information = {static_cast<float>(button_hover_info["x_pos"]), static_cast<float>(button_hover_info["y_pos"]), static_cast<float>(button_hover_info["width"]), static_cast<float>(button_hover_info["height"])};
        DrawRectangleRounded(rectangle_information, button_hover_info["roundness"], button_hover_info["steps"], button_hover_info["color"]);
        DrawTextEx(GetFontDefault(), button_info["text"].c_str(), text_position, static_cast<float>(button_hover_info["font_size"]), 3.0f, button_hover_info["font_color"]);
    }
    else {
        // Not on hover
        if (button_info["x_pos"] == 0 || button_info["y_pos"] == 0) {
            return;
        };

        // Convert coodinates from the center back to the corner for actual drawing. This can actually be 0
        int calibrated_x = button_info["x_pos"] - button_info["width"]/2;
        int calibrated_y = button_info["y_pos"] - button_info["height"]/2;

        // This part is really hard, we have to center the text by getting the width and then doing some super complex math thing
        Vector2 text_dimensions = MeasureTextEx(GetFontDefault(), button_info["text"], static_cast<float>(button_info["font_size"]), 3.0f);
        int text_width = text_dimensions.x;
        int text_height = text_dimensions.y;
        int text_x = calibrated_x + (button_info["width"] - text_width)/2;
        int text_y = calibrated_y + (button_info["height"] - text_height)/2;
        Vector2 text_position = {text_x, text_y};

        Rectangle rectangle_information = {static_cast<float>(calibrated_x), static_cast<float>(calibrated_y), static_cast<float>(button_info["width"]), static_cast<float>(button_info["height"])};
        DrawRectangleRounded(rectangle_information, button_info["roundness"], button_info["steps"], button_info["color"]);
        DrawTextEx(GetFontDefault(), button_info["text"].c_str(), text_position, static_cast<float>(button_info["font_size"]), 3.0f, button_info["font_color"]);
    };
};

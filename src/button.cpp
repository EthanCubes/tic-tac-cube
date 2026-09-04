#include <nlohmann/json>
#include "raylib.h"
#include "global.h"

using json = nlohmann::json;

// This file is not yet ready for usage! Don't link it in the install shell script

void Button::setup_button(json button_info_input) {};
void Button::setup_button_hover(json button_info_input) {};
void Button::change_button(std::string key, std::string change_to) {};

void Button::draw_button() {};

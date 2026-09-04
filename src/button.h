#ifndef BUTTON_H
#define BUTTON_H

#include <nlohmann/json.hpp>
#include "raylib.h"
#include "global.h"

using json = nlohmann::json;

// This file is not yet ready for usage! Don't link it in any other files

const int UNDEFINED = 0; // This is for the JSON

class Button {
    private:
        json button_info;
        json button_hover_info;
    public:
        void setup_button(json button_info_input) {};
        void setup_button_hover(json button_info_input) {};
        void change_button(std::string key, std::string change_to) {}

        void draw_button();
};

#endif

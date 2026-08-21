#include <array>
#include <tuple>
#include <string>
#include <ctime>
#include <cmath>
#include <map>

// This file will be used to create logs for debugging. Because debugging right now is actually painful
// I love writing my own libraries.
// I can't be bothered to convert it to the user's timezone, so UTC it is. Will be logged in RFC 3339

int unix_timestamp = 
std::array<int, 6> get_time_array() {
    // There's definitely a way to optimize this code and make it take less lines
    // All the setup stuff
    int unix_timestamp = time(NULL);
    int year = 1970;
    int month;
    int date;
    int hour;
    int minute;
    int second;

    // Temporary variables that will be used to store data that will definitely get replaced later.
    int temp_year;
    int temp_month;
    int temp_date;
    int temp_hour;
    int temp_minute;
    int temp_second;
    int estimated_years_since_epoch;

    std::array<int, 6> time_array = {
        year, month, date, hour, minute, second
    };

    return time_array;
};

std::string get_time_string() {};

void create_log_file() {};

void log_data() {};

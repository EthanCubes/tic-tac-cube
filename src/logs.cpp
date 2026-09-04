#include <string>
#include <ctime>
#include <fstream>

#include "global.h"

// This file will be used to create logs for debugging. Because debugging right now is actually painful
// I love writing my own libraries.
// I can't be bothered to convert it to the user's timezone, so UTC it is. Will be logged in RFC 3339

std::string get_time() {
    time_t timestamp;
    time(&timestamp);
    std::string current_time = ctime(&timestamp);
    return current_time;
};

bool file_exists(std::string filename) {
    std::ifstream file;
    file.open(filename);
    if (!file) {
        file.close();
        return false;
    }
    else {
        file.close();
        return true;
    };
};

void create_log_file() {
    bool name_valid = false;
    std::string formatted_time = get_time(); // Some of the characters that the file returns are invalid

    int formatted_time_length = formatted_time.length();

    for (int i = 0; i < formatted_time_length; i++) {
        if (formatted_time[i] == ' ' || formatted_time[i] == ':' || formatted_time[i] == '\n') {
            formatted_time[i] = '_';
        };
    };

    std::string log_name = "build/log_" + formatted_time;
    std::string log_prefix = ".txt";
    std::string filename = log_name + log_prefix;

    while (!name_valid) {
        if (!file_exists(filename)) {
            // Move ahead with file creation and logging
            std::ofstream log_file;
            log_file.open(filename);
            log_file << "---- Beginning of log ----\n" << formatted_time << "\n\n";
            log_file.close();

            // Create a file to tell the system what the current log file name is
            log_file.open("build/log_name.txt");
            log_file << filename;
            log_file.close();

            name_valid = true;
        }
        else {
            // Unlikely to ever happen, but who knows
            // Tries again with different name
            log_name += std::string("-");
            filename = log_name + log_prefix;
        }
    };
};

void log_data(std::string log_message) {
    // Get the log file name from file
    std::ifstream log_file_name_file;
    log_file_name_file.open("build/log_name.txt");
    std::string filename;
    std::getline(log_file_name_file, filename);
    log_file_name_file.close();

    // Fetch the file and write to the file
    int unix_timestamp = time(NULL); // No reason this shouldn't work.
    std::ofstream log_file(filename, std::ios::app);
    log_file << std::to_string(unix_timestamp) << " | "<< log_message << "\n\n";
    log_file.close();
};

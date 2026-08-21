#include <string>
#include <ctime>
#include <fstream>

// This file will be used to create logs for debugging. Because debugging right now is actually painful
// I love writing my own libraries.
// I can't be bothered to convert it to the user's timezone, so UTC it is. Will be logged in RFC 3339

std::string get_time() {
    time_t timestamp;
    time(&timestamp);
    std::string current_time = ctime(&timestamp);
    return current_time;
};

void log_data(std::string log_message) {
    std::string time = get_time();
    std::ofstream file;
    file.open("tic-tac-cube_logs.txt");
    file << time << log_message << "\n\n";
    file.close();
};

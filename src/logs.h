#ifndef LOGS_H
#define LOGS_H

#include <string>
#include <ctime>
#include <fstream>


bool file_exists(std::string filename);
std::string get_time();
void create_log_file();
void log_data(std::string log_message);

#endif

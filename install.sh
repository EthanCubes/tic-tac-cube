#! /bin/bash
# run chmod +x install.sh to give this excecution permissions.
echo "Compiling the program"
echo "Please be patient"
# This makes sure to show all the warnings and treasts them as errors
g++ -std=c++17 -Wall -Wextra -Werror -pedantic -o build/tic-tac-cube src/main.cpp src/board.cpp src/bot.cpp src/logs.cpp -lraylib
echo "Running the program"
build/tic-tac-cube

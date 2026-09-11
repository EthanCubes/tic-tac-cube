#! /bin/bash
# run chmod +x compile.sh to give this excecution permissions.
echo "Compiling the program"
echo "Please be patient"
# This makes sure to show all the warnings. -Wpedantic is the same as -pedantic, and -Wextra-semi adds checking for semicolons

# Normal
#g++ -std=c++17 -Wall -Wextra -Wextra-semi -Wpedantic -o build/tic-tac-cube src/main.cpp src/board.cpp src/bot.cpp src/logs.cpp src/global.cpp src/button.cpp -lraylib

# Display time
g++ -ftime-report -std=c++17 -Wall -Wextra -Wextra-semi -Wpedantic -o build/tic-tac-cube src/main.cpp src/board.cpp src/bot.cpp src/logs.cpp src/global.cpp src/button.cpp -lraylib

# No warnings
#g++ -std=c++17 -o build/tic-tac-cube src/main.cpp src/board.cpp src/bot.cpp src/logs.cpp src/global.cpp src/button.cpp -lraylib

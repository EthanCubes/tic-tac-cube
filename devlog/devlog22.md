# Devlog #22:

I made the buttons look nicer by centering the text inside of them. It was much harder than it looked and I had to work with "Vector2" in Raylib. I may or may not have spent like half and hour trying to find documentation on it, only for me to discover that it's a struct inside of Raylib. Still not entirely sure what a struct is. So I may or may not have spent another half and hour trying to declare the struct inside of the main.cpp file, before I finally gave up and asked DeepSeek. Turns out, it's just `Vector2 something{(float)x, (float)y}`. It's not exactly simple if you don't have much experience with C++, but I started coding in C++ 16 days ago and I understand it just fine.

Halfway through, while testing, I accidentally overrode the main file and had to restore it and re-add all the changes I make. I don't like committing before the program doesn't have that many bugs, so a lot of progress was lost. This is like the second time I've done this, and if you're curious what I did, well... The command used to compile my program for testing is `g++ -std=c++17 -o build/program src/main.cpp src/board.cpp src/bot.cpp src/logs.cpp -lrayib`. This compiles the code for all the C++ files and the Raylib library, and creates and executable inside the build/ directory. Except I forgot to type build/program, and so GCC just overrode main.cpp. Honestly though, it didn't do that much harm, thanks to the test.cpp file having a similar version of code as the code that was overridden, and also git.

hackatime isn't working so i can't even post this devlog

nvm it just worked

nvm it broke again

honestly this is one of the first times anything has broken in my experience as someone who joined hack club like 3 months ago. im sure everyone involved in fixing this is trying their absolute best.

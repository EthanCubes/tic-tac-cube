# Devlog #37 (8b55316):

I made a web build for the game! I took a break from Stardance to make something for Out to C, and when I was making a C game with Raylib I discovered that it is extremely hard to make a downloadable executable run well on Windows or MacOS, because on Windows you have to include DLL files, and on MacOS it's just harder to install Raylib. In the end, I ended up making a web build, and since I wasn't so bad, I decided to make a web build for this.

I used Emscripten, and using the em++ tool with the asyncify option, manage to get most of the game logic working, with only one small frame generation bug, which I fixed by changing this_thread::sleep for to something that is easier for the browser to render.

I also made some other QoL changes so that the bot feels less stagnant, hopefully. 

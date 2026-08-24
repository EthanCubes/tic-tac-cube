# Devlog #19:

In an effort to procrastinate fixing the bot fork bug while still doing something useful, I 1) took a 2 day break from this project to work (and ship) something else, and 2) fixed a very annoying bug where the user would be X every single time. I solved the issue by switching from older, more C-like rand() from cstdlib to the more modern `#include <random>`. I highkey copied the code from [Stack Overflow](https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c), but at least it's better than relying on AI.

That solved like half of the problem, but then I discovered that I wasn't actually resetting the board properly when manually exiting a game, since I was looking through the logs. I made the logs are procrastination, but they're actually really nice.

In case you were wondering btw, most of the time logged in this devlog *was* spent on trying to fix the fork bug, but I'll make a dedicated devlog only when I've actually fixed the bug.

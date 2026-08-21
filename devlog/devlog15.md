# Devlog #15:

I updated the bot to give it two of the most important features: winning the game, and trying to prevent your opponent from winning.

This was done by saving every single possible way to have a two-in-a-row on the board, connected and disconnected, 24 possible combinations in total. And of course, because I'm not experienced enough to do it any other way, it was all written by hand. And since I don't like using AI, and don't really trust it, I wrote all of it myself, and used only used AI to check that I didn't mess something up.

Now how the hell do I make it detect forks....

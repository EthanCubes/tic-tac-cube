# Devlog #16:

I added creating and defending against forks. One of my previous projects, Gomoku Balanced, had some decent defense and offense, which was even able to beat some people, according to the reviews on my ship. The one thing it was missing was the ability to detect potential forks and combat them, which was why I was able to beat it almost every single time. This bot, however, will not be the same. Mostly because the board is kinda small. I literally just added every single possibility of a fork to the to the bot.

I just got notified that I have like 8 hours without a devlog, and since I am horrible at coding, the bot function I'm working on isn't even working yet. I'm also just not getting it done within 2 hours. The function is supposed to block the fork, but it doesn't work for some reason. DeepSeek (AI) gave me a list of 20 reasons it's breaking, but I'm not about to blindly trust AI. I mean it doesn't raise any errors, so that's good. For me at least, I spend a lot of time just trying to get the code to compile properly. And in this case, even when the code compiles, half the time it just runs into a runtime error and crashes.

The bot crashed like 20 times. They were all runtime errors, and I use C++, so I have absolutely no idea where the error occurs. Also, I want to be different, and therefore I use NeoVim, and since I don't want to spend time that I could be building actually good projects for Stardance in the time it takes to configure NeoVim, and therefore I can't see any warnings or errors. I did try using CLion and VSCode, but CLion takes up a lot of RAM and VSCode is made by Microsoft (and VSCodium and Code OSS don't have that many plugins). Also, when I was using CLion, the errors didn't really appear... and CLion also does a bunch of stuff and creates a bunch of mysterious files. I don't really like doing stuff without knowing what they do, so I just ditched CLion altogether.


Did I seriously go on a paragraph-long rant about how using NeoVim leads to not being able to know why my code sucks? Is the paragraph-long rant in question also probably longer than the entire rest of the devlog? (Yes and yes);

Anyway you still can't tell that I made any changes to the bot from a single screenshot, so I'm just going to attach one of my old ones.

# Devlog #18:

I worked on the logs even more, and now they are in separate files. You wouldn't believe the amount of time this took me. Evidently, I'm not a very good C++ dev, and when I was searching on Stack Overflow and other sites, I kept running into things I don't understand like ```&```, ```auto```, and probably many others. So of course, I resorted to coding my own functions at the most low level C++ possible without actually being totally backwards compatible with C. 

Essentially, every time the game starts, function runs that tries to generate a log file with the current time. There is a theoretically possible edge case where the user opens the project more than once in a single second, so I added some code to make absolute sure not to override any existing files. That took me like at least 15 minutes to half and hour, for an edge case that probably can only happen in testing, and that will not actually affect the game at all. Yay, what great decision making skills. 

I still haven't fixed the fork detection and response function, but at least I can now have a way to find out what is going wrong. The only progress with finding out what is wrong is just narrowing the error location down to the function where I already knew there was going to be an error. Yay.

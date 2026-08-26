# Devlog #20:

I abandoned searching for potential forks and stopping them from ever forming in favour of handling forks that have already been formed. After more than one win for the opponent is detected, the bot registers that it is a fork. It then calculates which moves are best to neutralize the threat. There are four ways for each single win to be neutralized, so I need to make one of these four moves, for each of the two cases. In some cases, one or more of the moves overlap, in which case the overlapped move will be immediately returned, but most of the time, the bot just picks from one of the 8 possible neutralization moves randomly. 

This is definitely less efficient than just figuring out how to prevent forks from ever forming, but I mean it's a good implementation for the cube part of this game.

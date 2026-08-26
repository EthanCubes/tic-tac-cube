# Devlog #21:

I am very very very very bad at debugging code. Somehow I managed to fix the major rendering bug and also make the fork handling better within 2 hours. I don't believe I've mentioned anything about it before, but there was a rendering glitch upon the bot winning the game right after the user has made a cube turn that allowed the bot to win the game. I'm still not sure wy that happened, but I fixed it by re-rendering the entire board before drawing the board position again. If that didn't make sense to you, it doesn't make much sense to me either. If it did, well good for you ig. 

I feel like the fork handling deserves and entire paragraph, so here:

I changed the win blocking function to also log the direction that potential win is in, by logging "position 1" of that specific potential win. The possible neutralizing moves of the directional indicator value is then compared against the potential win location neutralizing move to try to find a match. If a match is found, that means that the move is guaranteed to neutralize the given threat.

That paragraph did not make much sense, even to me. If you read my code, it'll probably make more sense, as long as you do not get permanent brain damage from reading the it (I need to learn how to write better code)

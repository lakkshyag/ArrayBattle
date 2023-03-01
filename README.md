# ArrayBattle 1.0

Array Battle is a 2 player CLI game. Players can determine the duration of the game by choosing the length of the array they want to play with.
A random array of the input length will be generated (based on a dice roll) which will be the starting array for both of the players.

Objective of the game is to destroy all elements of the other player's array.
An element is destroyed when its value becomes less than or equal to zero. Destroyed elements are represented by 0.
A player can try to destroy their opponent's array by choosing to attack an element or they can choose to defend their array.
After choosing the index of an element to Attack/Defend, a dice will be rolled to determine the action's value (1-6).

After the choosen the index, there is an 11% chance for a critical roll. Based on the initial choice for Attack/Defend, 4 bonuses will be provided out of which any 1 can be chosen.
Or the player can choose to go with their original roll.

From Round 7 onwards, every roll will be a guaranteed critical roll. From Round 14 onwards, players will only be able to attack.




The base idea of this game was given as an assignment but the critical, bonuses and other features were added by me to made the game more engaging.

I've extensively bug fixed the game, but if you still encounter some while playing then feel free to point them out / fix them.
Also if you want to add any more features / abilities etc, fele free to send pull requets.

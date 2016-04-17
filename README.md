# Blood-Queen-GBA
BLOOD QUEEN by Nick Petosa
GameBoy Advance game coded in C for CS 2110

A world's-hardest-game-esque adventure. You control a knight and guide him through a forest, castle, and palace to reach the nefarious Blood Queen. There are three different types of enemies: vertical patrollers, horizontal patrollers, and growers. Touch any of them and lose a life - you have 99. Why so many? This game is HARD.

Each stage has its name displayed at the bottom left, and health is always visible in the bottom right. You will encounter branching paths and diverse scenery, as well as cutscenes as your adventure progresses.

The main game logic is contained in BloodQueen.c. Helper methods are in MyLib.c and game.c. Individual level code is contained in stage#.h files, and prototypes, macros, structs, global variables, etc are contained in myLib.h. All other c and h files are picture resources.

CONTROLS:
[GBA]      [Keyboard]    [In Game]

Select = Backspace -> Go to start

Start = Enter -> Start game

A = Z -> End cutscene

Up = Up Arrow -> Move up

Down = Down Arrow -> Move down

Left = Left Arrow -> Move left

Right = Right Arrow -> Move right

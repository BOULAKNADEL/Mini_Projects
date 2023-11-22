# Paper Stone Scissors Game

This is a simple console-based game of paper stone scissors, also known as rock paper scissors. The game is played between the user and the computer. The user can choose one of the three options: paper, stone, or scissors. The computer will randomly choose one of the options as well. The winner of the game is determined by the following rules:

- Paper covers stone, so paper wins over stone.
- Stone breaks scissors, so stone wins over scissors.
- Scissors cut paper, so scissors wins over paper.
- If both the user and the computer choose the same option, it is a draw.

The game will continue until the user decides to quit or the computer wins a certain number of times.

## How to run the game

To run the game, you need to have a C++ compiler installed on your system. You can use any compiler of your choice, such as [GCC], [Clang], or [Visual Studio].

To compile the game, navigate to the folder where the game source code is located and run the following command:

```bash
g++ paper_stone_scissors.cpp -o paper_stone_scissors


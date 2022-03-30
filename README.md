# 8X8_Tic_Tac_Toe

Game: 4-in-a-line

You have an 8x8 board, players take turns placing a piece on any grid. First player to get 4 in a line (either a row, or a column; diagonals are NOT counted) wins. The amount of time allowed for generating the next move is 5 seconds. The search will stop when there's no time left. The program ask the user to decide who is going to move first. In order to make the process smooth, you are REQUIRED to use the following standard in the movement that your program will generate:

    1 2 3 4 5 6 7 8     Player vs. Opponent
  A - - - - - - - -        1. e5 d5
  B - - O - - - - -        2. e4 e3
  C - - O - - - - -        3. f4 d4
  D - X O O O X - -        4. e6 e7
  E - - O X X X O -        5. g4 h4
  F - - X X - - - -        6. d6 d3
  G - - - X - - - -        7. d2 c3
  H - - - O - - - -        8. f3 b3 wins
  
  
Strategies and Other Requirements

Alpha-beta pruning is used to determine the computer's move.

An evaluation function is included so that it can evaluate non-terminal states and a cut-off test to replace the terminal test. The program will then return the best solution found so far given a specific period of time.

In general, 5 seconds is allowed to run the algorithm, which should search at least 5 plies deep.

The program is one player, and will attempt to defeat the human operator. Here, "X" means "computer", "O" means "human".

The program detects when an illegal move has been entered and requires the human to re-enter a valid move, for example, trying to place on a non-empty space, or out of bounds.

/**
 * The main game loop program for the
 * tic-tac-toe game.
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "game_utils.h"
#include "player_utils.h"
#include "computer_player_utils.h"

//hint: there is 1 bug in this file

int main(int argc, char **argv) {

  srandom(time(NULL));

  int gameChoice = mainMenu();
  Move **board = newBoard();
  Status s = getStatus(board);

  while(s == PLAYING) {

    //x moves
    printBoard(board);
    userMove(board, X);
    s = getStatus(board);
    if(s != PLAYING) {
      break;
    }

    //o moves
    printBoard(board);
    if(gameChoice == TWO_PLAYER) {
      userMove(board, O);
    } else if(gameChoice == ONE_PLAYER_RANDOM) {
      randomComputerMove(board);
    } else if(gameChoice == ONE_PLAYER_SMART) {
      smartComputerMove(board);
    }
    s = getStatus(board);

  }

  printf("Final Board:\n");
  printBoard(board);
  freeBoard(board);

  if(s == O_WINS) {
    printf("O Wins!\n");
  } else if(s == X_WINS) {
    printf("X Wins!\n");
  } else if(s == TIE) {
    printf("Cats game, please play again!\n");
  }

  return 0;
}

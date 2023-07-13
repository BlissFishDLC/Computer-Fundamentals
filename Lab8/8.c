#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char side = 'U', humanSide = 'U';
int size = 0;

void myPrintBoard(char board[][26]) {
  printf("  ");
  for (int i = 0; i < size; i++)
    printf("%c", 'a' + i);
  printf("\n");
  for (int i = 0; i < size; i++) {
    printf("%c ", 'a' + i);
    for (int j = 0; j < size; j++)
      printf("%c", board[i][j]);
    printf("\n");
  }
}

void findWinner(char board[][26]) {
  int B = 0, W = 0;
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++){
      if (board[i][j] == 'B')
        B++;
      else if (board[i][j] == 'W')
        W++;
    }
  if (B > W)
    printf("B player wins.");
  else if (B < W)
    printf("W player wins.");
  else
    printf("Draw!");
}

bool roomCheck(char board[][26]) {
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (board[i][j] == 'U')
        return true;
  return false;
}

void prepareGame(char board[][26]) {
  // input size
  printf("Enter the board dimension: ");
  scanf(" %d", &size);
  while (size < 4 || size > 26 || size % 2 != 0) {
    printf("Invalid input!\nEnter the board dimension: ");
    scanf(" %d", &size);
  }
  // input side
  printf("Computer plays (B/W): ");
  scanf(" %c", &side);
  if(side == 'B')
    humanSide = 'W';
  else
    humanSide = 'B';
  for (int row = 0; row < size; row++)
    for (int col = 0; col < size; col++)
      board[row][col] = 'U';
  board[size / 2][size / 2] = 'W';
  board[size / 2 - 1][size / 2 - 1] = 'W';
  board[size / 2][size / 2 - 1] = 'B';
  board[size / 2 - 1][size / 2] = 'B';
}

bool myPositionInBounds(int row, int col) {
  if (row >= 0 && row < size && col >= 0 && col < size) {
    return true;
  }
  return false;
}

bool testDirection(char board[][26], char sideMode, int row, int col, int i, int j) {
  bool reverse = false;
  int c = col+j, r = row+i;
  while (myPositionInBounds(r, c) && board[r][c] != 'U' && board[r][c] != sideMode) {
    r += i;
    c += j;
    reverse = true;
  }

  if (myPositionInBounds(r, c) && board[r][c] == sideMode && reverse)
    return true;
  return false;
}

void changeBoard(int row, int col, char board[][26], char sideChange) {
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0)
        continue;
  
      if (testDirection(board, sideChange, row, col, i, j)) {
        int c1 = col+j, r1 = row+i;
        while (board[r1][c1] != sideChange){
          board[r1][c1] = sideChange;
          r1 += i;
          c1 += j;
        }
      }
    }
  }
  board[row][col] = sideChange;
}

bool testValid(char board[][26], char sideMode, int row, int col) {
  // check start location
  if (board[row][col] != 'U')
    return false;
    // check 8 directions
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      // skip itself
      if (i == 0 && j == 0)
        continue;
      if (testDirection(board, sideMode, row, col, i, j))
        return true;
    }
  }
  return false;
}

void testScore(int *row1, int *col1, char board[][26]) {
  int bestScore = 0;
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) { 
      if (board[row][col] == 'U'){
        int score = 0;
        for (int i = -1; i <= 1; i++) {
          for (int j = -1; j <= 1; j++) {
  
            if (i == 0 && j == 0)
              continue;
            bool reverse = false;
            int c = col+j, r = row+i, c1 = col+j, r1 = row+i;
            while (myPositionInBounds(r, c) && board[r][c] == humanSide) {
              r += i;
              c += j;
              reverse = true;
            }
  
            if (myPositionInBounds(r, c) && board[r][c] == side && reverse) {
              while (board[r1][c1] != side){
                score++;
                r1 += i;
                c1 += j;
              }
            }
          }
        }
        if (score > bestScore) {
          bestScore = score;
          *row1 = row;
          *col1 = col;
        }
      }
    }
  }
}


void pcMove(char board[][26]) {
  int row, col;
  testScore(&row, &col, board);
  changeBoard(row, col, board, side);
  printf("Computer places %c at %c%c.\n", side, row+'a', col+'a');
  myPrintBoard(board);
}

bool humanMove(char board[][26]) {
  char row, col;
  printf("Enter move for colour %c (RowCol): ", humanSide);
  scanf(" %c%c", &row, &col);
  if (testValid(board, humanSide, row-'a', col-'a')) {
    changeBoard(row-'a', col-'a', board, humanSide);
    myPrintBoard(board);
    return true;
  }
  else {
    printf("Invalid move.\n");
    return false;
  }
}

bool isValid(char sideMode, char board[][26]) {
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      for (int row = 0; row <= size; row++) {
        for (int col = 0; col <= size; col++) { 
          if (i == 0 && j == 0)
            continue;
          else if (testDirection(board, sideMode, row, col, i, j))
            return true;
        }
      }
    }
  }
  return false;
}

int main(void) {
  char board[26][26] = {0};
  prepareGame(board);
  myPrintBoard(board);

  if (side == 'B')
    pcMove(board);
  while(1){
    if (!isValid(side, board)) {
      if (!isValid(humanSide, board))
        break;
      else if (isValid(humanSide, board))
        printf("%c player has no valid move.", side);
        if (!roomCheck(board) || !humanMove(board))
          break;
    }
    else if (isValid(humanSide, board)) {
      if (!isValid(humanSide, board)) {
        printf("%c player has no valid move.", humanSide);
        pcMove(board);
        if (!roomCheck(board))
          break;
      }
      else {
        if (!roomCheck(board) || !humanMove(board))
          break;
        pcMove(board);
        if (!roomCheck(board))
          break;
      }
    }
  }
  findWinner(board);
  return 0;
}
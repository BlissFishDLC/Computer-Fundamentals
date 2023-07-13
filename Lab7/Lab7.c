#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printBoard(char board[][26], int n) {
  char letter = 'a';
  printf("  ");
  for (int i = 0; i < n; i++) {
    printf("%c", letter);
    letter++;
  }
  printf("\n");
  
  letter = 'a';
  for (int i = 0; i < n; i++) {
    printf("%c ", letter);
    for (int j = 0; j < n; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
    letter++;
  }
}

bool positionInBounds(int n, int row, int col) {
  if (row < 0 || row >= n || col < 0 || col >= n) {
    return false;
  }
  return true;
}

bool t_checkLegalInDirection(char board[][26], int n, int row, int col, char colour) {
  char c1, c2;
  if (colour == 'B')
    {c1 = 'B';
    c2 = 'W';}
  else
    {c1 = 'W';
    c2 = 'B';}

  bool r = false;
  int i = row - 97;
  int j = col - 97;
      
  if (board[i][j] == 'U')
    if (i - 2 > 0 && j - 2 > 0 && board[i-1][j-1] == c1 && board[i-2][j-2] == c2)
      {board[i][j] = c1;
      r = true;}
    else if (i - 2 > 0 && j + 2 < n && board[i-1][j+1] == c1 && board[i-2][j+2] == c2)
      {board[i][j] = c1;
      r = true;}
    else if (i - 2 > 0 && board[i-1][j] == c1 && board[i-2][j] == c2)
      {board[i][j] = c1;
      r = true;}
    else if (i + 2 < n && j - 2 > 0 && board[i+1][j-1] == c1 && board[i+2][j-2] == c2)
      {board[i][j] = c1;
      r = true;}
    else if (i + 2 < n && j + 2 < n && board[i+1][j+1] == c1 && board[i+2][j+2] == c2)
      {board[i][j] = c1;
      r = true;}
    else if (i + 2 < n && board[i+1][j] == c1 && board[i+2][j] == c2)
      {board[i][j] = c1;
      r = true;}
    else if (j - 2 > 0 && board[i][j-1] == c1 && board[i][j-2] == c2)
      {board[i][j] = c1;
      r = true;}
    else if (j + 2 < n && board[i][j+1] == c1 && board[i][j+2] == c2)
      {board[i][j] = c1;
      r = true;}
  return r;
}

void printAvailable(char board[][26], char colour, int n){
  char c1 = 'B', c2 = 'W';
  if (colour == 'B'){
    c1 = 'W';
    c2 = 'B';
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (board[i][j] == 'U')
        if (i - 2 > 0 && j - 2 > 0 && board[i-1][j-1] == c1 && board[i-2][j-2] == c2)
          printf("\n%c%c", i+'a', j+'a'); 
        else if (i - 2 > 0 && j + 2 < n && board[i-1][j+1] == c1 && board[i-2][j+2] == c2)
          printf("\n%c%c", i+'a', j+'a');
        else if (i - 2 > 0 && board[i-1][j] == c1 && board[i-2][j] == c2)
          printf("\n%c%c", i+'a', j+'a');
        else if (i + 2 < n && j - 2 > 0 && board[i+1][j-1] == c1 && board[i+2][j-2] == c2)
            printf("\n%c%c", i+'a', j+'a'); 
        else if (i + 2 < n && j + 2 < n && board[i+1][j+1] == c1 && board[i+2][j+2] == c2)
            printf("\n%c%c", i+'a', j+'a');
        else if (i + 2 < n && board[i+1][j] == c1 && board[i+2][j] == c2)
            printf("\n%c%c", i+'a', j+'a');
        else if (j - 2 > 0 && board[i][j-1] == c1 && board[i][j-2] == c2)
            printf("\n%c%c", i+'a', j+'a'); 
        else if (j + 2 < n && board[i][j+1] == c1 && board[i][j+2] == c2)
            printf("\n%c%c", i+'a', j+'a');
    }
  }
}

int main(void) {
  int n = 0, difficultyLevel = 0;

  printf("Enter the board dimension: ");
  scanf(" %d", &n);
  
  char board[26][26];
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      board[row][col] = 'U';
    }
  }

  board[n/2][n/2] = 'W';
  board[n/2-1][n/2-1] = 'W';
  board[n/2][n/2-1] = 'B';
  board[n/2-1][n/2] = 'B';

  printBoard(board, n);

  printf("Enter board configuration:\n");
  char side, inPutRow, inPutCol;
  scanf(" %c%c%c", &side, &inPutRow, &inPutCol);
  while (side != '!') {
    board[inPutRow-97][inPutCol-97] = side;
    scanf(" %c%c%c", &side, &inPutRow, &inPutCol);
  }

  printBoard(board, n);
  
  printf("Available moves for W:");
  printAvailable(board, 'W', n);
  
  printf("\nAvailable moves for B:");
  printAvailable(board, 'B', n);

  printf("\nEnter a move:");
  int deltaRow, deltaCol;
  scanf(" %c%c%c", &side, &deltaRow, &deltaCol);

  if (t_checkLegalInDirection(board, n, deltaRow, deltaCol, side))
    printf("\nValid move.\n");
  else
    printf("\nInvalid move.\n");

  printBoard(board, n);
  return 0;
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


bool gameStatus(int Size, char userArray[][Size], int difficultyLevel);

void printBoard(int Size, char grid[][Size]);
bool validRowCol(int row, int col, int Size);
void updateRowCol(int* row, int* col, int dir, bool forward);
int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]);

void getInput(int* row, int* col, int Size);
void getLevelAndDimensions(int* size, int* difficultyLevel, const int maxDim);
int getRand(int maxChoices);

int main(void) {
  const int maxDim = 23;
  int Size = 0, difficultyLevel = 0;

  getLevelAndDimensions(&Size, &difficultyLevel, maxDim);

  int copy[23][23] = {
      {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
      {1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
      {0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
      {1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0},
      {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
      {1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1},
      {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1},
      {0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
      {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0},
      {1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}};

  char grid[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      grid[row][col] = copy[row][col] + '0';
    }
  }
  // TODO: check if there is a valid game, if not, create one
  if (!gameStatus(Size, grid, difficultyLevel))
    grid[2][0] += 1;

  int userInputRow = 0, userInputCol = 0;

  // test gameStatus
  char userArray[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      userArray[row][col] = '-';
    }
  }
  bool gameOver = true;
  int steps = 0;
  do {
    getInput(&userInputRow, &userInputCol, Size);
    userArray[userInputRow][userInputCol] = grid[userInputRow][userInputCol];
    printBoard(Size, userArray);

    gameOver = gameStatus(Size, userArray, difficultyLevel);
    steps++;
  } while (!gameOver && steps < Size * Size);
  printf("Game over!\n");
  printf("Your score is %d", Size * Size - steps);

  return 0;
}

void getInput(int* row, int* col, int Size) {
  printf("Enter user input: ");
  scanf("%d %d", row, col);
  while(*row < 0 || *row > Size - 1 || *col < 0 || *col > Size - 1) {
    printf("Please enter your row and col to be between 0 and Size - 1: ");
    scanf("%d %d", row, col);
  }
}

void getLevelAndDimensions(int* Size, int* levelOfDiff, const int maxDim) {
  printf("Enter the difficulty level: ");
  scanf("%d", levelOfDiff);
  
  if (*levelOfDiff != 1){  
    while (1) {
        if (*levelOfDiff <= 1 || *levelOfDiff >= maxDim) {
          printf("Please enter a difficulty level between 1 and %d: ", maxDim);
          scanf("%d", levelOfDiff);
        } else
          break;
    }
  }
    printf("Enter the dimensions of the grid: ");
    while (1) {
      scanf("%d", Size);
      if (*Size >= *levelOfDiff && *Size <= maxDim)
        return;
      else
        printf("Please enter dimensions >= %d: ", *levelOfDiff);
    }
}

int getRand(int maxChoices) { return (rand() % (maxChoices)); }

bool gameStatus(int Size, char userArray[][Size], int difficultyLevel) {
  // you will need to call calculateScoreInDir
  for (int dir = 0; dir < 4; dir++) {
    for (int i = 0; i < Size; i++) {
      for (int j = 0; j < Size; j++){
        if (calculateScoreInDir(i, j, dir, Size, userArray) == difficultyLevel)
          return true;
      }
    } 
  }
  return false;
}

int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]) {
  if ( !validRowCol(row, col, Size) || userArray[row][col] == '0') return 0;
  int N = -1, row_ = row, col_ = col;
  while (validRowCol(row, col, Size) && userArray[row][col]=='1') {updateRowCol(&row, &col, direction, false); N++;}
  while (validRowCol(row_, col_, Size) && userArray[row_][col_]=='1') {updateRowCol(&row_, &col_, direction, true); N++;}
  return N;
}

bool validRowCol(int row, int col, int Size) {
  if (row < 0 || col < 0 || row > Size - 1 || col > Size - 1)
    return false;
  return true;
}

void updateRowCol(int* row, int* col, int dir, bool forward) {
    if (dir == 0){
      if (forward)
        (*row)--;
      else
        (*row)++;}
    else if (dir == 1){
      if (forward){
        (*row)--;
        (*col)++;}
      else{
        (*row)++;
        (*col)--;}}
    else if (dir == 2){
      if (forward)
        (*col)++;
      else
        (*col)--;}
    else if (dir == 3){
      if (forward){
        (*row)--;
        (*col)--;}
      else{
        (*row)++;
        (*col)++;}}
}

void printBoard(int Size, char grid[][Size]) {
  for (int i = 0; i < Size; i++) {
    for (int j = 0; j < Size; j++) {
      printf("%d", grid[i][j]);
    }
    printf("\n");
  }
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool validateChoices(int choices[], const int ChoicesNum, const int BoxesNum);
void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum,
                     const int BoxesNum);
void populateBoxes(int boxes[], const int BoxesNum);

int main(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;

  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum];
  populateBoxes(boxes, BoxesNum);
  takeUserChoices(userOne, userTwo, ChoicesNum, BoxesNum);
  return 0;
}

void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum,
                     const int BoxesNum) {
  // Can check if the inputs are distinct and if they are between 1 and BoxesNum
  // - 1
  do {
    printf("Player 1, please enter distinct box choices between 0 and 19: ");
    for (int choiceInd = 0; choiceInd < ChoicesNum; choiceInd++) {
      scanf("%d", &userOne[choiceInd]);
    }
  } while (!validateChoices(userOne, ChoicesNum, BoxesNum));

  do {
    printf("Player 2, please enter distinct box choices between 0 and 19: ");
    for (int choiceInd = 0; choiceInd < ChoicesNum; choiceInd++) {
      scanf("%d", &userTwo[choiceInd]);
    }
  } while (!validateChoices(userTwo, ChoicesNum, BoxesNum));
}

void populateBoxes(int boxes[], const int BoxesNum) {
  // TODO: Fill each element randomly by either
  // 0 empty
  // -10 bomb
  // 10 candy
  for (int i = 0; i < BoxesNum; i++) {
        int set = rand() % 3;
        if (set == 0)
            boxes[i] = -10;
        else if (set == 1)
            boxes[i] = 0;
        else
            boxes[i] = 10;
        }
  // Print the contents of the boxes
    for (int i = 0; i < BoxesNum; i++) {
        printf("%d: %d, ",i , boxes[i]);
    }   printf("\n");
}

bool validateChoices(int choices[], const int ChoicesNum, const int BoxesNum) {
  bool valid = true;
  // TODO: 
  // Check if elements in choices is between 0 and BoxesNum - 1
  for (int i = 0; i < ChoicesNum; i++) {
        if (choices[i] < 0 ||choices[i] > (BoxesNum - 1)){
            valid = false;
            break;
            }
        
        // Check if elements in choices is distinct
        else if (choices[i] == choices[i-1]){
            valid = false;
            break;
            }
        }
  return valid;
}
/*Rea, Dami and Hira are working for a Telecommunications company. They developed a
function that checks if a number is a shuffled version of an ordered number. For example,
917865432 is a shuffled number of the ordered 123456789 number. The function is sup-
posed to return true if a number is shuffled, and false if the number is missing one or
more numbers. It also returns false if a number is repeated more than once. The function
is tested in the main function as shown below, and in lab4par3-debugging-exercise.c file
on Quercus. However, the function is not working as expected. Your task is to debug the
program and fix the errors.
Assume the user will not enter negative numbers or numbers with 0 digits.
Hint: As you may have observed the program is long, and it can be difficult to know the
source of errors. As a hint, we are telling you that some of the bugs are in getNumDigits
function. We suggest you isolate it and test it separately in a different .c file. The fol-
lowing is an example of a program you can use to test “getNumDigits” function. As you
can see we are passing different values to getNumDigits to check if it works. Once you
fix getNumDigits function, check getSmallestDigit and lookForDigit separately. Then,
finally when you fix all the functions, check isShuffled function using the entire program.
This is the benefit of using functions. You can break your code into pieces, and easily fix
issues in each function regardless of the entire program.
Program to test getNumDigits function. test-getNumDigits.c
*/

#include <stdbool.h>
#include <stdio.h>

bool isShuffled(int);
int getNumDigits(int);
int getSmallestDigit(int);
bool lookForDigit(int, int);

int main(void) {
  int num;
  printf("Enter the number to check: ");
  scanf("%d", &num);
  if (isShuffled(num)) {
    printf("Shuffled!");
  } else {
    printf("Not shuffled!");
  }
  return 0;
}

bool isShuffled(int shuffledOrder) {
  bool isShuffled = true;
  int numOfDigits = getNumDigits(shuffledOrder);
  int smallestDigit = getSmallestDigit(shuffledOrder);

  for (int place = 0; place < numOfDigits && isShuffled; place++) {
    if (!lookForDigit(shuffledOrder, smallestDigit + place)) {
      isShuffled = false;
    }
  }
  return isShuffled;
}

int getNumDigits(int num) {
  int count = 0;
  while (num > 0) {
    num = num / 10;
    count++;
  }
  return count;
}

int getSmallestDigit(int num) {
  int smallestDigit = 10;
  int digit = 0;
  while (num != 0) {
    digit = num % 10;
    if (digit < smallestDigit) {
      smallestDigit = digit;
    }
    num /= 10;
  }
  return smallestDigit;
}

bool lookForDigit(int num, int searchDigit) {
  int digit = 0;
  while (num > 0) {
    if (num % 10 == searchDigit)
      digit++;
    num /= 10;
  }
  if (digit == 1)
    return true;
  else
    return false;
}

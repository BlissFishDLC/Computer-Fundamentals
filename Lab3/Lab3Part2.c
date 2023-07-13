/*NOTE: Please use the debugger to find out the bugs.
Kevin, Samantha and Aditya were developing a program that takes in from the user a se￾quence of numbers separated by + or -. Their program would add the numbers depending
on the arithmetic operations entered by the user. Once the sum of the numbers fell below
zero, the program prints out "Sum fell below zero."
They verify if the character entered is a number or not, and they check if the sign entered
is '+' or '-'. If not, the user is asked to re-enter till a valid input is taken. The numbers
and signs are separated by <enter>. All numbers and signs are entered as characters.
Unfortunately, their code does not work, and they hire you to fix their code. You are given
the following code:*/

/*#include <stdbool.h>
#include <stdio.h>
int main(void) {
char userChar;
int sum = 0, sign = +1;
bool number = true;
printf("Enter sequence of characters with numbers to add: ");
scanf(" %c", &userChar);
do {
if (number) {
while (userChar < '0' || userChar > '9') {
printf("Invalid! Re-enter number.\n");
scanf(" %c", &userChar);
}
number = false;
sum += sign * (userChar - '0');
} else {
while (userChar != '+' || userChar != '-') {
printf("Invalid! Re-enter sign.\n");
scanf(" %c", &userChar);
}
number = true;
if (userChar == '+') {
sign = +1;
} else {
sign = -1;
}
}
} while (sum < 0);
printf("Sum fell below zero.\n");
return 0;
}*/

/*Here is a sample output from an execution of the functioning program.
Exmaple 1:
Enter sequence of characters with numbers to add: 9<enter>
+<enter>
8<enter>
-<enter>
5<enter>
6<enter>
Invalid! Re-enter sign.
-<enter>
$<enter>
Invalid! Re-enter number.
9<enter>
-<enter>
7<enter>
Sum feel below zero.*/

// Sums all digits in a number
#include <stdbool.h>
#include <stdio.h>
// A program that takes in from the user a sequence of numbers separated
// by + or -, once their sum reaches below zero it prints out "Sum is below zero."
// You need to verify if the character entered is a number or not, and if the sign 
// is '+'' or '-'. If not, the user is asked to re-enter till a valid input is taken.
int main(void) {
  char userChar;
  int sum = 0, sign = +1;
  bool number = true;
  printf("Enter sequence of characters with numbers to add: ");


  do {
    if (number) {
        scanf(" %c", &userChar);
      while (userChar < '0' || userChar > '9') {
        printf("Invalid! Re-enter number.\n");
        scanf(" %c", &userChar);
      }
      number = false;
      sum += sign * (userChar - '0');
    } else {
        scanf(" %c", &userChar);
      while (userChar != '+' && userChar != '-') {
        printf("Invalid! Re-enter sign.\n");
        scanf(" %c", &userChar);
      }
      number = true;
      if (userChar == '+') {
        sign = +1;
      } else {
        sign = -1;
      }
    }
  } while (sum >= 0);
  printf("Sum fell below zero.\n");
  return 0;
}
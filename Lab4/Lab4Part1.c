/*Your task is to write a program which takes as input a four-digit number and prints the
steps involved in converting that number to Kaprekar’s Constant. We recommend you
define a few functions.

To assist you, a helpful utility function has already been defined which you may use in
your lab. This function takes as input a number and returns a number containing the same
digits as the input number, though in ascending order. The prototype of this function is as
follows:
int getAscendingOrderedDigits(int);*/

#include <stdio.h>

int getAscendingOrderedDigits(int number);
//Calling the given function

int reverseNumber(int number) {
    int digits[10] = {0};
    while (number > 0) {
        digits[number % 10]++;
        number /= 10;
    }
    int i = 9;
    while (i > 0) {
        if (digits[i] > 0) {
            number *= 10;
            number += i;
            digits[i]--;
        }
        else {
        i--;
        }
    }
    return number;
}
//Function for reverse order which is large to small

int main(){

    int input, NorInput, RevInput, i;
//NorInput is small to large, RevInput is large to samll

    while(1){
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &input);
        //check for -1 to stop
        if (input == -1)
            break;

        //check for input is not 4 digits
        if (input > 9999)
            printf("Error: The number is too large.\n");
        else if (input < 1000)
            printf("Error: The number is too small.\n");
        else{
            printf("Number 1: %d\n", input);
            
        //given initial number for input, iteration is i-1
        i = 1;
            
            //if is 6174 then break
            while(input != 6174){
                //change input into two orders
                NorInput = getAscendingOrderedDigits(input);
                RevInput = reverseNumber(input);
                
                //check if RevInput is three non-zero digits or two non-zero digits
                if((RevInput / 1000) < 1)
                    RevInput = RevInput * 10;
                if((RevInput / 100) < 1)
                    RevInput = RevInput *100;
                
                //calculate
                input = RevInput - NorInput;
                i++;
                printf("Number %d: %d\n", i, input);
            }
            printf("Kaprekar's Constant was reached in %d iteration(s)\n", i-1);
        }
    }    

    return 0;
}

//given function
//no need on Examify
int getAscendingOrderedDigits(int number) {
    int digits[10] = {0};
    while (number > 0) {
        digits[number % 10]++;
        number /= 10;
    }
    int i = 0;
    while (i < 10) {
        if (digits[i] > 0) {
            number *= 10;
            number += i;
            digits[i]--;
        } else {
            i++;
        }
    }
    return number;
}
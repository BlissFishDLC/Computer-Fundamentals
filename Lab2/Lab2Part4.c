/*Write a program that will perform the four basic arithmetic operations (addition, subtrac￾tion, multiplication, and division) on pairs of positive integers written in one base and
produce answers as numbers written in a (possibly) different base. The program should
repeatedly prompt the user to supply input in the following order and form:
• a single character representing an operation: one of the characters +, -, *, /, or $.
The $ signals the end of the data; reading it should cause the program to terminate.
• an input base: 2 to 10 (inclusive)
• a first operand: a positive integer written as a numeral in the input base
• a second operand: a positive integer written as a numeral in the input base
• an output base: 2 to 10 (inclusive)
As an example, suppose the items listed above have the following values:
+
4
201
2312
5
This should be interpreted as a request to add 201 (base 4) and 2312 (base 4) writing the
answer as a base 5 numeral. Input will be provided as shown in the following examples.
For each set of input data, the program should first perform some validity checks on the
data (as indicated below). If the input is valid, the program should convert the operands
to their base 10 representation, perform the indicated operation on these values, convert
the answer to the given output base, and print the results.
Example 1
Shown below is a sample run of the program. Data shown following the colons are sup￾plied by the user; all other items are produced by the program. Your program should
match the following patterns exactly, including all punctuation. Any variation from this
will result in a loss of marks.
Give input ($ to stop): + 4 201 2312 5
201 + 2312 (base 4) = 33 + 182 = 1330 (base 5)
Give input ($ to stop): * 2 1101 101 8
1101 * 101 (base 2) = 13 * 5 = 101 (base 8)
Give input ($ to stop): / 10 743 18 4
743 / 18 (base 10) = 743 / 18 = 221 (base 4)
Give input ($ to stop): # 8 27 15 6
Invalid operator
Give input ($ to stop): - 4 23 11 15
Invalid base
Give input ($ to stop): * 3 27 12 8
Invalid digits in operand
Give input ($ to stop): + 10 44 67 10
44 + 67 (base 10) = 44 + 67 = 111 (base 10)
Give input ($ to stop): $
Checking for Bad Data
You should check for the following forms of bad data. The error messages that should be
produced in these cases are shown in the examples.
• an invalid operator, e.g. # or @ are invalid arithmetic operators
• a base outside the range 2 to 10
• an operand having digits too large for the given input base, *e.g.* supplying operand
45 while the input base is 3. If base 3 is input base, the largest digit in the operands
should be 2.
If more than one invalid input is entered, the first invalid input detected should be the
operator, the input or output base, then the operands, in this order. For example, if the
user enters * 3 27 12 15, the program should print Invalid base because 15 is the output
base (more than 10), not Invalid digits in operand because of 27 has the 7 digit.
You may assume that
• the user will supply the correct number of values
• the user will supply positive integers
• no result will ever be larger than the largest int value
• all operations will produce valid, non-negative results
Example 2
Give input ($ to stop): * 3 4 2 15
Invalid base
Give input ($ to stop): * 3 4 2 8
Invalid digits in operand
Give input ($ to stop): * 3 3 2 8
Invalid digits in operand
Give input ($ to stop): * 3 2 2 8
2 * 2 (base 3) = 2 * 2 = 4 (base 8)
Give input ($ to stop): $
Example 3
Give input ($ to stop): - 6 205 43 7
205 - 43 (base 6) = 77 - 27 = 101 (base 7)
Give input ($ to stop): & 9 74 57 10
Invalid operator
Give input ($ to stop): / 9 74 57 10
74 / 57 (base 9) = 67 / 52 = 1 (base 10)
Give input ($ to stop): % 2 10 01 8
Invalid operator
Give input ($ to stop): + 2 10 01 8
10 + 1 (base 2) = 2 + 1 = 3 (base 8)
Give input ($ to stop): $*/

#include <stdio.h>
#include <math.h> //for using pow()

//call functions
int InBaseChange(int num, int base);
int OutBaseChange(int num, int base);

int main() {
    int a = 0, b = 0, InBase = 0, OutBase = 0, BasedA = 0, BasedB = 0, Out = 0, test = 0, ans;
    char opera;
    
    //looping before $ been scaned
    while(1){
        printf("Give input ($ to stop): ");
        scanf(" %c", &opera);
        //scan operator first, home space before %c for only $ been scaned (not scan enter)

        if (opera == '$')
            break;
        //test for $ to stop the programm
            
        scanf(" %d %d %d %d", &InBase, &a, &b, &OutBase);
        //scan others all at once

        if (InBase > 10 || InBase < 2 || OutBase > 10 || OutBase < 2)
        //out of range base
            printf("Invalid base\n");

        else{
            BasedA = InBaseChange(a, InBase);
            BasedB = InBaseChange(b, InBase);
            //change input number from any base to base 10
            //return -1 when invalid number in operand
            if (BasedA == -1 || BasedB == -1)
                printf("Invalid digits in operand\n");

            else{
                if (opera == '+' || opera == '-' || opera == '*' || opera == '/')
                //do operations
                {
                    if (opera == '+')
                        ans = BasedA + BasedB;
                        
                    else if (opera == '-')
                        ans = BasedA - BasedB;
                        
                    else if (opera == '*')
                        ans = BasedA * BasedB;
                        
                    else
                        ans = BasedA / BasedB;
                            
                    ans = OutBaseChange(ans, OutBase);
                    //change answer from base 10 to any base as output
                        
                    printf("%d %c %d (base %d) = %d %c %d = %d (base %d)\n", a, opera, b, InBase, BasedA, opera, BasedB, ans, OutBase);
                    //print final answer at once
                }
                else
                    printf("Invalid operator\n");
                    //operation input error
            }
        }
    }
    
    return 0;
}

//function change any base to base 10 and test valid to the base or not
int InBaseChange(int num, int base) {
    if(base == 10)
        return num;
    else{
        int ans = 0, i = 0;
        while (num > 0) {
            int aN = num % 10;
            if (aN >= base)     //test if the input valid to the base
                return -1;
            else{
            ans += aN * pow(base, i);
            num /= 10;
            i++;
            }
        }
        return ans;
    }
}

//function change base 10 to any base
int OutBaseChange(int num, int base) {
    int ans = 0, power = 1;
    while (num > 0) {
        int re = num % base;
        ans += re * power;
        power *= 10;
        num /= base;
    }
    return ans;
}
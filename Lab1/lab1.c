#include <stdio.h>

/*Q1 Write a C program that produces the following output. The output must be exactly as shown:

 C uses escape sequences for a variety of purposes.
Some common ones are:
     to print ", use \"
     to print \, use \\
     to jump to a new line, use \n

*/ 

/*int main(){
    printf("C uses escape sequences for a variety of purposes.\nSome common ones are:\n     to print \", use \\\"\n     to print \\, use \\\\\n     to jump to a new line, use \\n");
    return 0;
}*/

/********************************************************************************/

/*Q2 When travelling to another country, we are often faced with the need to convert funds from the currency of the country we are visiting to the currency we use. This way we can have an idea of how much we are spending on a product that could be cheaper in your home country. You do not want to be ripped off!

You will write a program to convert the amount in any foreign currency to Canadian dollars. The inputs to your program consist of the conversion rate (the number of Canadian dollars equivalent to each unit of the foreign currency), and the amount of the foreign currency to be converted. The inputs are taken from the keyboard, in double precision floating point numbers. Your program should calculate and output to the screen/console the amount of Canadian dollars equivalent to the input amount in foreign currency. The output dollar amount should be rounded to two decimal places. No more than two decimal places should be displayed for the result. You can assume that the user enters valid numbers for currency.

Here is a sample output from an execution of the program:

Enter the conversion rate: 0.17<enter>
Enter the amount to be converted (in foreign currency): 245.00<enter>

The amount in Canadian Dolars is: 41.65

*/
 
/*int main(){
    float a, b, c;
    printf("Enter the conversion rate: ");
    scanf("%f",&a);
    printf("Enter the amount to be converted (in foreign currency): ");
    scanf("%f",&b);
    c = a * b;
    printf("The amount in Canadian Dollars is: %.2f",c);
    return 0;
}*/

/********************************************************************************/

/*Q3 As you start your journey in the world of computer programming, you will need to become familiar with the way computers represent numbers in "bits" (short for binary digits). Binary numbers, also known as Base 2 number representation, will appear many times from this point on. You are to write a program that converts a base 10 integer number no larger than 15 into a Base 2 number representation.

Write a C program that asks for the user to enter an integer number no greater than 15, and outputs on separate lines, the four digits of the base 2 representation of that entered number. Below is a sample input and output sequence for the program.

Enter number to convert to base 2: 13<enter>
The four digits of that number are as follows:
Most significant digit: 1
Next digit: 1
Next digit: 0
Least significant digit: 1
*/

int main(){
    int a, b, c, d, input;
    printf("Enter number to convert to base 2: ");
    scanf("%d",&input);
    d = input % 2;
    c = (input - d)/2 % 2;
    b = (input - d - c*2)/4 % 2;
    a = (input - d - c*2 - b*4)/8 % 2;
    printf("The four digits of that number are as follows:\nMost significant digit: %d\nNext digit: %d\nNext digit: %d\nLeast significant digit: 1",a,b,c,d);
    return 0;
}

/*********************************************************************************/

/*A C program that asks the user to enter a distance (assumed to be in metres) converts this distance to yards, feet, inches and a decimal number, rounded to two decimal places, that indicates any remaining fraction of an inch. This C program has a few issues. It uses the conversion factor 1 inch = 2.54 cm. For example, if the user enters a value of 3.376, the output will be:

3 yards, 2 feet, 0 inches, 0.91 inches remainder

The prompt to the user should take the form:

Please provide a distance in metres:

written by itself on a single line.

Note: if the input leads to something like the following:

1 yards, 1 feet, 1 inches, 0.00 inches remainder
 
This is fine. You do not need to change the output to read 1 yard, 1 foot, 1 inch. Likewise, if yards, feet or inches have a value of 0, no need to remove their prints from the output.

The following program needs your expertise to fix. This is an excellent opportunity to use the debugger to find errors. Examine the values of variables at each step to know when does the program not behave as expected.*/

/*#include <stdio.h>

int main(void) {
	const double CmPerInch = 2.54;
	const double CmPerMetre = 100.00;
	const int InchesPerFoot = 12;
	const int InchesPerYard = 36;
	
	float distance;
	printf("Please provide a distance in metres: ");
	scanf("%f", &distance);
	
	double distanceInInches = distance * CmPerMetre / CmPerInch;
	
	// truncate fractional part to get # of inches
	int inches = distanceInInches;
	distanceInInches = distanceInInches - inches;
	
	int yards = inches / InchesPerYard;
	
	// how many inches are left after extracting yards
	inches = inches % InchesPerYard;
	
	int feet = inches / InchesPerFoot;
	
	// how many inches are left after extracting feet
	inches = inches % InchesPerFoot;
	
	printf("%d yards, %d feet, %d inches, %.2f inches remainder\n", yards, feet, inches, distanceInInches);
	
	return 0;
}*/
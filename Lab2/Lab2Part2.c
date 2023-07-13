/*Write a C program that calculates the body mass index (BMI) for an entered height and
weight, and categorizes it as underweight, healthy weight, overweight, or obesity, based
on the following table from the United States Center for Disease Control and Prevention
(CDC):
BMI Weight Status
Below 18.5 Underweight
18.5 – 24.9 Healthy Weight
25.0 – 29.9 Overweight 
30.0 and above Obesity
Table 1: Categories of the Body Mass Index (after rounding to the nearest tenth).
To calculate BMI based on weight in kilograms (wkg) and height in metres (hm), use this
formula:
        BMI = w/h^2
When the computed BMI is used to determine its category and printed, it is rounded to
the nearest tenth.
The user is allowed to enter body weight values in either kilograms or pounds, and to
enter height in either metres, inches, or feet. To enter weight in pounds, for example, the
user would enter 155lb. To enter weight in kilograms, the user would enter 70kg. To enter
height in inches, the user would enter 68.11in. To enter height in feet, the user would
enter 5.65ft. To enter height in metres, the user would enter 1.73mt. In other words,
each unit has a two-letter abbreviation for the user to use. A pound is equivalent to 0.4536
kilograms, a metre is equivalent to 39.37 inches, or 3.28 feet.
Here is a sample output from an execution of the program:
Enter the body weight: 150lb<enter>
Enter the height: 5.65ft<enter>
The Body Mass Index (BMI) is: 22.9
Category: Healthy Weight
Note: You may assume that all entered values are valid floating point values, within the
range allowed by the double type. You may also assume the weight unit that the user
enters is either kg or lb, and the height unit that the user enters is mt, in, or ft. All units
are entered in lower case.*/


#include <stdio.h>

int main(){
    float weight, height, BMI;
    int a;
    char status, Uweight, Uheight;
    printf("Enter the body weight: ");
    scanf("%f%c%*c", &weight, &Uweight);
    printf("Enter the height: ");
    scanf("%f%c", &height, &Uheight);

    if (Uweight == 'l')
        weight = weight * 0.4536;

    if (Uheight == 'i')
        height = height / 39.37;

    if (Uheight == 'f')
        height = height / 3.28;

    BMI = weight / (height * height);
    a = BMI / 0.1;
    BMI = (float)a / 10;

    if (BMI < 18.5)
        printf("\nThe Body Mass Index (BMI) is: %.1f\nCategory: Underweight", BMI);
    else if (18.5 <= BMI && BMI <= 24.9)
        printf("\nThe Body Mass Index (BMI) is: %.1f\nCategory: Healthy Weight", BMI);
    else if (25 <= BMI && BMI <= 29.9)
        printf("\nThe Body Mass Index (BMI) is: %.1f\nCategory: Overweight", BMI);
    else if (30 <= BMI)
        printf("\nThe Body Mass Index (BMI) is: %.1f\nCategory: Obesity", BMI);

    return 0;
}
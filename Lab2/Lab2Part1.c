/*Write a C program that takes the x-y coordinates of a point in the Cartesian plane, and
prints a message telling either an axis on which the point lies, or the quadrant in which it
is found. If the point is at (0.00, 0.00), the program should report that it is at the origin. The
floating point coordinates are entered by the user. When coordinates are printed and used
to determine the quadrant, they are rounded to the nearest hundredth. For example, 4.866
should be rounded to 4.87, and 18.953 should be rounded to 18.95, then these rounded
numbers should be used to determine the quadrant. If the input was (0.0001, 0.001), the
rounded numbers would be (0.00, 0.00), therefore the reported quadrant should be at the
origin. The following figure shows the Cartesian plane and the quadrants.

Here is a sample output from an execution of the program:
Enter the x-coordinate in floating point: 0.0<enter>
Enter the y-coordinate in floating point: -2.5<enter>
(0.00, -2.50) is on the y axis.
Here is a second example:
Enter the x-coordinate in floating point: 4.556<enter>
Enter the y-coordinate in floating point: 4.864<enter>
(4.56, 4.86) is in quadrant I.
Here is a third example:
Enter the x-coordinate in floating point: 0.0001<enter>
Enter the y-coordinate in floating point: 0.001<enter>
(0.00, 0.00) is at the origin.
Note: You can assume that the user enters valid floating point numbers within the range
allowed by the double type.*/


#include <stdio.h>

int main(){
    float X, Y;
    printf("Enter the x-coordinate in floating point: ");
    scanf("%f",&X);
    printf("Enter the y-coordinate in floating point: ");
    scanf("%f",&Y);

    if (X == 0)
    {
        if (Y == 0)
        printf("\n(%.2f, %.2f) is at the origin.", X, Y);
        else
        printf("\n(%.2f, %.2f) is on the y axis.", X, Y);
    }
    else if (Y == 0)
    printf("\n(%.2f, %.2f) is on the x axis.", X, Y);
    else if (X > 0)
    {
        if (Y > 0)
        printf("\n(%.2f, %.2f) is in quadrant I.", X, Y);
        else
        printf("\n(%.2f, %.2f) is in quadrant IV.", X, Y);
    }
    else
    {
        if (Y > 0)
        printf("\n(%.2f, %.2f) is in quadrant II.", X, Y);
        else
        printf("\n(%.2f, %.2f) is in quadrant III.", X, Y);
    }

    return 0;
}
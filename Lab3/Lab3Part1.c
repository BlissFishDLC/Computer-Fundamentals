/*In the figure below, we plot the graph of a circle with radius 4. The equation of the circle
is x
2 + y
2 = r
2
, where r is radius of the circle. Write a program that will take the radius as
input from the user and will print the corresponding circle. The circle should be printed:
• using the character *.
• in a dotted . grid square of size 2r + 1 by 2r + 1.
• in the center of the dotted grid square.
Hint: You will find x
2 + y
2 = r
2 helpful, and use the following figure to help you decide
on the coordinates of the points to be printed.
y
x2 + y2 = r2
4
r: radius = 4 
4 x
Figure 1: Circle
Here is a sample output from an execution of the program:
Example 1:
Enter the radius of the circle: 3<enter>
...o...
.ooooo.
.ooooo.
ooooooo
.ooooo.
.ooooo.
...o...
Example 2:
Enter the radius of the circle: 1<enter>
.o.
ooo
.o.
Example 3:
Enter the radius of the circle: 7<enter>
.......o.......
....ooooooo....
...ooooooooo...
..ooooooooooo..
.ooooooooooooo.
.ooooooooooooo.
.ooooooooooooo.
ooooooooooooooo
.ooooooooooooo.
.ooooooooooooo.
.ooooooooooooo.
..ooooooooooo..
...ooooooooo...
....ooooooo....
.......o.......
Example 4:
Enter the radius of the circle: 0<enter>
o*/

#include <stdio.h>

int main() {
    int r, d;
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    for (int y = 0; y <= 2*r; y++)
    {
        for (int x = 0; x <= 2*r; x++)
        {
            d = (x-r)*(x-r) + (y-r)*(y-r);
            if (d <= r*r)
                printf("o");
            else
                printf(".");
        }
        printf("\n");
    }

    return 0;
}
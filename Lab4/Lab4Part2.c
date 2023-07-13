/*Your program must repeatedly prompt the user to enter the order of the function. This
must be a value between [0, 3]. The program must then ask the user to input the coefficients
of the polynomial function. Finally, the program must plot the function’s points using the
character “ * ”, drawing a Cartesian grid between x and y [−10, 10]. If an x coordinate
generates a y coordinate that is outside the range [-10, 10], the program should not print
that point. The x-axis is drawn using a “ - ” and the y-axis is drawn using a “ | ”. If no
point or axis is to be printed three spaces are printed. If the user enters an order of −1,
the program should terminate.*/

#include <stdio.h>
#include <math.h>

int getpoints(int num,int coefs[4]);

int main(){

    int order, i;
    char plot[21][63];
    //matrix for the plot

    while(1){
        printf("Enter the order of the function: ");
        scanf("%d", &order);
        //check for -1 to stop

        if (order == -1)
            break;
        else if (order > 3 || order < 0){
            printf("The order must be between [0, 3].\n");
            continue;
        }

        int coe[4] = {0};
        i = 0;
        //reset i and coefficient array

        while(i <= order){
            printf("Enter coefficient of x^%d: ", i);
            scanf("%d", &coe[i]);
            i++;
        }
        //get input coefficients

        for (int x = 0; x < 21; x++) 
            for (int y = 0; y < 63; y++) 
                plot[x][y] =' ';
        for (int x = 1; x < 63; x+=3) 
            plot[10][x] = '-';
        for (int x = 0; x < 21; x++)
            plot[x][31] = '|';
        //giving space and x,y axis

        for(int x = -10; x < 11; x++) {
            int y = getpoints(x,coe);
            if (y > -11 && y < 11)
                plot[10-y][3*(x+10)+1] ='*';
        }
        //interchange * and space

        for (int x = 0; x < 21; x++) {
            for (int y = 0; y < 63; y++)
                printf("%c", plot[x][y]);
            printf("\n");
        }
        //print all at once
    }
    return 0;
}

//calculate the points from input coefficients
int getpoints(int num, int coe[4]) {
    int xx =0;
    for (int i = 0; i < 4; i++) 
        xx += pow(num,i) * coe[i];
    return xx;
}
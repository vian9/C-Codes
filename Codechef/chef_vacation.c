#include<stdio.h>

int main(void){
    /*
    Vacations have arrived and Chef wants to go to his home in ChefLand. There are two types of routes he can take:

Take a flight from his college to ChefArina which takes X
 minutes and then take a bus from ChefArina to ChefLand which takes Y
 minutes.
Take a direct train from his college to ChefLand which takes Z
 minutes.
Which of these two options is faster?

Input Format
The first line of the input contains a single integer T
 - the number of test cases. The test cases then follow.
The first line of the test case contains three space-separated integers X
, Y
, and Z
.
Output Format
For each test case, if Chef takes the train output TRAIN, if Chef takes the plane and the bus output PLANEBUS, if both are equal output EQUAL.

You may print each character of the string in uppercase or lowercase (for example, the strings train, tRAiN, TrAin, and TRAIN will all be treated as identical).
INPUT
3
10 12 11
3 5 15
9 4 13
OUTPUT
TRAIN
PLANEBUS
EQUAL
    */
   int n=0;
   scanf("%d",&n);
    for (int i = 0; i < n; i++)
        {
        int X,Y,Z;
        scanf("%d",&X);
        scanf("%d",&Y);
        scanf("%d",&Z);
        if(X+Y<Z){
            printf("PLANEBUS");
        }else if (X+Y==Z)
        {
              printf("EQUAL");
        } else{
            printf("TRAIN");
        }
        printf("\n");
   }
   
   
    return 0;
}
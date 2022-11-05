#include<stdio.h>

int main(){
int a[n];
int n;
printf("Enter the array size");
scanf("%d",&n);

for (int i = 0; i < n; i++)
{
    scanf("%d",&a[i]);
}
int m;
int x =0;
printf("Enter the integer to search");
scanf("%d",&m);

for (int i = 0; i < n; i++)
{
    if (a[i]==m)
    {
        printf("We found the number");
        printf("Position %d", i);
        printf("No of Comparision %d", i);
        x==a[i];
        break;
    }

}
if (x==0)       
{
    printf("Number not found");
}



return 0;
}
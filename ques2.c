#include<stdio.h>

int main(){

int n;
printf("Enter the array size");
scanf("%d",&n);
int a[n];

for (int i = 0; i < n; i++)
{
    scanf("%d",&a[i]);
}
for (int i = 0; i < n; i++)
{
    printf("%d",a[i]);
}
int m;
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        if (a[i]>a[i+1])
        {
            a[i]=m;
            a[i]=a[i+1];
            a[i+1]=m;
        }
        
    }
    
}
int avg = 0;
for (int i = 0; i < n; i++)
{
    printf("%d ", a[i]);
    avg=avg+a[i];
}

printf("%d",avg);
a[n-1]=avg;
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        if (a[i]>a[i+1])
        {
            a[i]=m;
            a[i]=a[i+1];
            a[i+1]=m;
        }
        
    }
    
}
int av=0;
for (int i = 0; i < n; i++)
{
    printf("%d ", a[i]);
    av=av+a[i];
}

printf("%d",av);
return 0;
}
#include<stdio.h>
void selectionSort(int* x,int n)
{ 
int temp;
for(int i=0;i<n-1;i++) 
{
    for(int j=i+1;j<n;j++)
    {
        if(x[i]>x[j])
        {
            temp=x[j];
            x[j]=x[i];
            x[i]=temp;
        }
    }
}
printf("\nArray after sorting with Selection Sort-");
for(int i=0;i<n;i++)
printf("%d ", x[i]);
printf("\n\n");
}

int main()
{
    int n;
    printf("\nEnter Array limit-");
    scanf("%d",&n);
    int x[n];
    printf("\nEnter the Array Values-");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("\nArray before sorting -");
for(int i=0;i<n;i++)
printf("%d ",x[i]);
selectionSort(x,n);
return 0;
}
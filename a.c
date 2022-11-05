#include<stdio.h>
void bubbleSort(int *a,int n)
{
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nArray after sorting via Bubble Sort-");
for(int i=0;i<n;i++)
printf("%d ", a[i]);
}

int main()
{
    int n;
    printf("\nEnter Array limit-");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter Array Elements-");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nArray before sorting -");
for(int i=0;i<n;i++)
printf("%d ",a[i]);
bubbleSort(a,n);
return 0;
}
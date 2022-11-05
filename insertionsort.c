#include<stdio.h>
void insertionSort(int *a,int n)
{
    for (int i=0;i<n;i++)
    {
        int temp=a[i];
        int j=i-1;
        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("\nArray after sorting via Insertion Sort-");
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
    printf("\nArray before sorting-");
for(int i=0;i<n;i++)
printf("%d ",a[i]);
insertionSort(a,n);
return 0;
}
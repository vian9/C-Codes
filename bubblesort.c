#include<stdio.h>
void bubbleSort(int *x,int n)
{
    int flag, temp;
    for (int i=0;i<n-1;i++)
    {
        flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(x[j]>x[j+1])
            {
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
                flag=1;
            }
        }
        if (flag==0)
        {
            break;
        }
        
    }
    printf("\nArray after sorting with Bubble Sort- ");
for(int i=0;i<n;i++) 
printf("%d ", x[i]);
printf("\n\n");
}

int main()
{
    int n;
    printf("\nEnter Array limit- ");
    scanf("%d",&n);
    int x[n];
    printf("\nEnter Array Values- ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("\nArray before sorting- ");
for(int i=0;i<n;i++)
printf("%d ",x[i]);
bubbleSort(x,n);
return 0;
}
#include <stdio.h>

void matrixOperation(int a[20][20],int m,int n,int b[20][20],int p,int q)
{   
	int add[20][20];
    int diff[20][20];
    int pro[20][20];
	if(m==p && n==q)
	{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			add[i][j]=a[i][j]+b[i][j];
		    diff[i][j]=a[i][j]-b[i][j];
		}
	}
	printf("The addition of the two matrix is:\n");
    	for(int i=1;i<=m;i++)
	  {
		for(int j=1;j<=n;j++)
		{
			printf("%d\t",add[i][j]);
		}
		printf("\n");
	  }
	  	printf("The subtraction of the two matrix is:\n");
    	for(int i=1;i<=m;i++)
	  {
		for(int j=1;j<=n;j++)
		{
			printf("%d\t",diff[i][j]);
		}
		printf("\n");
	  }
	}
	else
	{
		printf("The addition and subtraction of the two matrix is not possible.\n");
	}
	if(n==p)
 
	{ 
    int res=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=q;j++)
			{
				for(int k=1;k<=n;k++)
				{
					res+=a[i][k]*b[k][j];
				}
				pro[i][j]=res;
				res=0;
			}
		}
			printf("The multiplication of the two matrix is:\n");
    	for(int i=1;i<=m;i++)
	  {
		for(int j=1;j<=q;j++)
		{
			printf("%d\t",pro[i][j]);
		}
		printf("\n");
	  }
 
	}
	else
	{
		printf("The multiplication of the two matrix is not possible.");	
	}
}
 
 
int main(void) 
{
int first[20][20];
int second[20][20];
int x,y,c,d;
printf("Enter the size of the first matrix:\n");
scanf("%d%d",&x,&y);
printf("Enter the size of the second matrix:\n");
scanf("%d%d",&c,&d);
printf("Enter the elements of the first matrix:\n");
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			scanf("%d",&first[i][j]);
		}
	}
	printf("Enter the elements of the second matrix:\n");
	for(int i=1;i<=c;i++)
	{
		for(int j=1;j<=d;j++)
		{
			scanf("%d",&second[i][j]);
		}
	}
	matrixOperation(first,x,y,second,c,d);
	return 0;
}
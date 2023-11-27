#include<stdio.h>
int add(int array[50],int limit)
{
	int sum=0;
	for(int i=0;i<limit;i++)
	{
		sum=sum+array[i];
	}
	return(sum);
}
int main()
{
	int a[50];
	int i,sum=0,limit;
	printf("enter tha limit:");
	scanf("%d",&limit);
	if(limit>50)
	printf("please enter limit under 50\n");
	else
	{
		printf("enter elements:");
		for(i=0;i<limit;i++)
		{
			scanf("%d",&a[i]);
			sum=add(a,limit);
		}
		printf("sum %d: ",sum);
	}	
	
	
	return(0);
}

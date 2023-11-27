#include<stdio.h>
void sort(int arr[],int x);
void display(int arr[],int x);
void merge(int m1[],int m2[],int x,int y);
int main()
{
	int arr1[50],arr2[50],size1,size2,i;
	printf("Enter array1 size: ");
	scanf("%d",&size1);
	printf("Enter array1 elements: ");
	for(i=0;i<size1;i++)
	scanf("%d",&arr1[i]);
	printf("Enter array2 size: ");
	scanf("%d",&size2);
	printf("Enter array2 elements: ");
	for(i=0;i<size2;i++)
	scanf("%d",&arr2[i]);
	printf("\nArray1 before sorting: ");
	display(arr1,size1);
	sort(arr1,size1);
	printf("\nArray1 after sorting: ");
	display(arr1,size1);

	printf("\nArray2 before sorting: ");
	display(arr2,size2);
	sort(arr2,size2);
	printf("\nArray2 after sorting: ");
	display(arr2,size2);
	merge(arr1,arr2,size1,size2);
}
void display(int arr[],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("%d ",arr[i]);
	}
}

void sort(int arr[],int x)
{
	int i,j,swap;
	for(i=0;i<x-1;i++)
	{
		for(j=0;j<x-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=swap;
			}
		}
	}
}

void merge(int m1[],int m2[],int x,int y)
{
	int m[100],i=0,j=0,k=0;
	while(i<x && j<y)
	{
		if(m1[i]<m2[j])
		{
			m[k]=m1[i];
			i++;
			k++;
		}
		else
		{
			m[k]=m2[j];
			j++;
			k++;		
		}
	}
	while(i<x)
	{
		m[k]=m1[i];
		i++;
		k++;
	}
	while(j<y)
	{	
		m[k]=m2[j];
		j++;
		k++;	
	}
	printf("\nMerged Array: ");
	display(m,x+y);
}	


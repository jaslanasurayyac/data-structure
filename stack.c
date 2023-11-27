#include<stdio.h>
#include<stdlib.h>
int push();
void pop();
void display();
int stackarr[100],temp;
int max=5;
int top=-1,i;
void main()
{
	int choice;
	printf("IMPLEMENTATION OF STACK USING ARRAY");
	while(1)
	{
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter your choice(1/2/3/4)");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nEnter elements to push");
				scanf("%d",&temp);
				push(temp);
			        break;			  		 
			case 2:pop();
			       break;
			case 3:display();
			       break;
			case 4:exit(1);
			       break;
			default:printf("\nInvalid input");
		}
	}
}

int push()
{
	if(top<max)
	stackarr[++top]=temp;
	else
	printf("Stack is full");
}

void pop()
{
	if(top<0)
	printf("Stack is empty");
	else
	{
		printf("The poped element is: %d\n ",stackarr[top]);
		top--;
	}
}

void display()
{
	if(top==-1)
	printf("\nStack is empty");
	else
	{
		printf("Elements are:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stackarr[i]);
		}
	}
}

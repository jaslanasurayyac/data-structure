#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queuearr[MAX];
void insert();
void delete();
void display();
int temp,i;
int front=-1,rear=-1;
int main()
{
	int choice;
	printf("IMPLEMENTATION OF QUEUE USING ARRAY");
	while(1)
	{
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter your choice(1/2/3/4)");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nEnter elements to insert");
				scanf("%d",&temp);
				insert(temp);
			        break;			  		 
			case 2:delete();	
			       break;
			case 3:display();
			       break;
			case 4:exit(1);
			       break;
			default:printf("\nInvalid input");
				break;
		}
	}
}
void insert()
{
	if(rear==MAX-1)
	{
		printf("\nOverflow");
		return;
	}
	if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear++;
		
	}
	queuearr[rear]=temp;
	printf("value inserted");
}
void delete()
{
	int item;
	if(front==-1 || front>rear)
	{
		printf("No element to delete");
		return;
	}
	else
	{
		item=queuearr[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=front+1;
		}
		
		printf("deleted item is %d",item);
	}
}
void display()
{
	int i;
	if(rear==-1)
	printf("\nEmpty queue");
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",queuearr[i]);
		}
	}
}

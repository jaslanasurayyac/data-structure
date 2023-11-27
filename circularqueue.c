#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int queue[MAX];
int front=-1,rear=-1;
void enqueue(int element)
{
	if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=element;
	}
	else if((rear+1)%MAX==front)
	{
		printf("Queue is overflow");
	}
	else
	{
		rear=(rear+1)%MAX;
		queue[rear]=element;
	}
}
void dequeue()
{
	if((front==-1)&&(rear==-1))
	{
	printf("\nQueue is underflow");
	}
	else if(front==rear)
	{
		printf("\nDequed element is %d",queue[front]);
		front=-1;
                rear=-1;
	}
	else
	{
		printf("The dequed element is %d",queue[front]);
		front=(front+1)%MAX;
	}
}

void display()
{
	int i=front;
	if(front==-1 && rear==-1)
	{
		printf("\nQueue is empty");
	}
	else
	{
		printf("\nElements in a queue are:");
		while(i!=rear)
		{
			printf("%d ",queue[i]);
			i=(i+1)%MAX;
		}
		printf("%d ",queue[i]);
		
	}
}

int main()
{
	int choice,x;
	printf("IMPLEMENTATION OF CIRCULAR QUEUE USING ARRAY");
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
				scanf("%d",&x);
				enqueue(x);
			        break;			  		 
			case 2:dequeue();	
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

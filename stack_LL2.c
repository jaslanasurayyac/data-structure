#include<stdio.h>
#include<stdlib.h>
# define max 3
int s=0;
struct node
	{
		int data;
		struct node*link;
	};

struct node *Top=NULL;

void push(int item)
{
		
		struct node *new;
		new=(struct node*)malloc(sizeof(struct node));
		new->data=item;	


		if(Top==NULL)
		{

		   Top=new;
		   new->link=NULL;
		  
			
		
		}
		else
	    	{	
		
		    new->link=Top;
		    Top=new;
		    
			

		}
		printf("Element inserted succesfully\n");
	
}

void pop()
{
	if (Top==NULL)
	{
		printf("stack underflow\n");	
	}	
	else
	{
		printf("Element deleted succesfully:  %d\n",Top->data);		
		struct node *temp=Top;
		Top=Top->link;
		free(temp);
	
			
        }
	
	
}

void disp()
{	if(Top==NULL)
	{
		printf("\n ---list is empty--- \n");	
	}
	else{
            struct node *temp=Top;
            printf("\nentered items are:\n");
            while(temp!=NULL)
            {
                    printf("%d  ",temp->data);
                    temp=temp->link;	
            }
            printf("  \n  ");	
	}
}

void srch(int key)
{	int count=0;
	
	
	struct node *temp1=Top;
	       	
        while((temp1->data!=key) && (temp1->link!=NULL))
        {
            
            temp1=temp1->link;	
		    count++;
        }	
        
         if((temp1->link==NULL) && (temp1->data!=key))
        {
            printf("\nkey not found\n");
        }
	else
	   {
		printf("\nkey fount at position %d\n",count+1);		
	   }

	
}


int main()
{ 	
    int z,k,c;	
	printf("------------------STACK USING LINKED LIST OPERATIONS------------------\n");
	while(1)   
    {  
        
        printf("\n1.PUSH\n2.POP\n3.Display Elements\n4.Search position of Element\n5.Exit");  
        printf("\nSelect the options\n");         
        scanf("%d",&c);  
        switch(c)  
        {  
            case 1: 	
			if(s >= max)
			{
				printf("stack overflow\n");	
			} 
		    else{   s++;
			    printf("\n---Enter the Data---\n");
		            scanf("%d",&z);
		            push(z);
			    
		         }
		    break;
            case 2:  
                    pop();
		    s--;
                    break;
            case 3: 
                    disp();        
                    break;  
            case 4: printf("\n---enter the key---\n");
                    scanf("%d",&k);  
                    srch(k);          
                    break;  
                    
	    case 5: printf("\n...Exiting point...\n");
                    exit(0);  
                    break;
			 
            default:  
                    printf("\nwrong input..\n");  
        }  
    }  
		
	return 0;
}

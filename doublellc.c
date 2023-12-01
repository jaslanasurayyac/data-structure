#include<stdio.h>
#include<stdlib.h>

struct node
	{
		struct node*rearlink;
        int data;
        struct node*frontlink;
	};

struct node *header=NULL;

void insfrnt(int item)
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;	
    new->rearlink=NULL;
	
	if(header==NULL)
	{
        header=new;
        new->frontlink=NULL;
	    printf("\nElement Succesfully inserted at position 1 \n");
	}
	else
	{   
        header->rearlink=new;
        new->frontlink=header;    
        header=new;

	    printf("\nElement Succesfully inserted at position 1 \n");
	}	
}

void insend(int item)
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;	
    new->frontlink=NULL;
	int count=0;

	if(header==NULL)
	{

	header=new;
    new->rearlink=NULL;
   
	printf("\nElement Succesfully inserted at position 1 \n");

	}
	else
	{	 
        struct node *temp=header;
        while(temp->frontlink!=NULL)
        {

            temp=temp->frontlink;
            count++;
        }

	temp->frontlink=new;
    new->rearlink=temp;

	printf("\nElement Succesfully inserted at position %d \n",count+2);
	    
	}	
}

void inspos(int item,int key)
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	struct node *temp=header;
	int count=0;	

	while((temp->data!=key) && (temp->frontlink!=NULL))
	{
		temp=temp->frontlink;
		count++;	
	}	
	
    if((temp->frontlink==NULL) && (temp->data==key))
    {
       	new->frontlink=NULL;
        new->rearlink=temp;
		temp->frontlink=new;

		printf("\nElement Succesfully inserted at position %d \n",count+2);
    }

	else
   	 {	
        
	new->frontlink = temp->frontlink;

        temp->frontlink = new;
        
        new->rearlink = temp;
		
        temp = new->frontlink;
        
        temp->rearlink = new;
		printf("\nElement Succesfully inserted at position %d \n",count+2);
	
       	 }	
}

void delfrnt()
{
    
    if (header==NULL)
    {
        printf("\nlist is empty\n");
    }
   else if(header->frontlink==NULL)//for one element only
    {
	    printf("\nElement deleted Succesfully: %d \n",header->data);
        free(header);
        header=NULL;
    }
    else
    {
        struct node *temp=header;
	    printf("\nElement deleted Succesfully: %d \n",temp->data);
        header=temp->frontlink;
        header->rearlink=NULL;
        free(temp);
    }
}

void delend()
{
    if (header==NULL)
    {
        printf("\nlist is empty\n");
    }
    else if(header->frontlink==NULL)
    {
	    printf("\nElement deleted Succesfully: %d \n",header->data);
        free(header);
        header=NULL;
    }
    else
    {
        struct node *temp1=header;
        struct node *temp2=header;
         while(temp1->frontlink!=NULL)
        {
            temp2=temp1;
            temp1=temp1->frontlink;
            
        }
        printf("\nElement deleted Succesfully: %d \n",temp1->data);
        temp1->rearlink=NULL;
        temp2->frontlink=NULL;
        free(temp1);
    }
}

void delpos(int key)
{
	if (header==NULL)
    {
        printf("\nlist is empty\n");
    }
    
    else
    {
            struct node *temp1=header,*temp2=header;
            while((temp1!=NULL) && (temp1->data!=key))
            {
                temp2 = temp1;
                temp1 = temp1->frontlink;
            }

            if(temp1 == NULL)
            {
                printf("\nKey not found\n");
            }
            else
            {
                
                if(temp2->frontlink == NULL)//for 1 and only elemrnt
                {
                    printf("\nElement deleted Succesfully: %d \n",temp2->data);
                    free(temp2);
                    header = NULL;
                
                }
                else
                {
                    printf("\nElement deleted Succesfully: %d \n",temp1->data);
                    if(temp1 == header)//for first element
                    {
                        
                        header = temp1->frontlink;
                        header->rearlink=NULL;
                    }
                    else
                    {
                        temp2->frontlink = temp1->frontlink;
                        temp2 = temp1->frontlink;

                        if(temp2 != NULL) //since dll has rear link 
                        {
                            temp2->rearlink = temp1->rearlink;
                        }
                        /*else//(for last elemnt t2 will be Null which has no rear) to move last pointer to last element
                        {
                            last = temp1->rearlink;
                        }*/
                      
                       
                    }			
                    free(temp1);
                }
	        }
 }      
}

void disp()
{	if(header == NULL)
	{
		printf("\n ---list is empty--- \n");	
	}
	else{
            struct node *temp = header;
            printf("\nentered items are:\n");
            while(temp != NULL)
            {
                    printf("  %d  ",temp->data);
                    temp = temp->frontlink;	
            }
            printf("  \n  ");	
	}
}



void srch(int key)
{	int count=0;
	
	if (header == NULL)
		    {
			    printf("\nkey not found\n");
		    }
    else
    {
	struct node *temp1 = header;
	       	
        while((temp1 != NULL) && (temp1->data!=key))
        {
            
            temp1 = temp1->frontlink;	
		    count++;
        }	
        
        if((temp1 == NULL))
        {
            printf("\nkey not found\n");
        }
	    else
	   {
		    printf("\nkey fount at position %d\n",count+1);		
	   }
    }

}

int main()
{ 	int z,k,c;	
	printf("------------------LINKED LIST OPERATIONS------------------\n");
	while(1)   
    {  
        
        printf("\n1.Insert at front\n2.Insert at end\n3.Insert after position\n4.Delete at front\n5.Delete at end\n6.Delete node at any position\n7.Display Elements\n8.Search position of Element\n9.Exit");  
        printf("\nSelect the options\n");         
        scanf("%d",&c); 	 
        switch(c)  
        {  
            case 1:  
                    printf("\nenter the data to insert at front \n");
                    scanf("%d",&z);
                    insfrnt(z);
                    break;
            case 2:  
                    printf("\nenter the data to insert at end \n");
                    scanf("%d",&z);
                    insend(z);
                    break;
            case 3: 
                    if (header==NULL)
                    {
                        printf("----------List is Empty----------\n");
                        printf("\n----------Please Insert The First Element---------- \n");
                        scanf("%d",&z);
                        insfrnt(z);
                    }
                    else
                    {
                        disp();
                        printf("\n---select the position---\n");
                        scanf("%d",&k);
                        printf("\nenter the data to insert after the position \n");
                        scanf("%d",&z);
                        inspos(z,k);
                    }
                    break;
            case 4:  
                    delfrnt();       
                    break;  
            case 5:  
                    delend();        
                    break;  
            case 6:
                    if (header==NULL)
                    {
                        printf("\nlist is empty\n");
                    }
                else{
                        disp();
                        printf("\n---select the key---\n");
                        scanf("%d",&k);  
                        delpos(k);
                     }          
                    break;  

            case 7: disp();        
                    break;  

                    
	        case 8: 
                    
                    printf("\n---enter the key---\n");
                    scanf("%d",&k);  
                    srch(k);
                    
                    break; 

            case 9: printf("\nExit..\n");
                    exit(0);  
                    break;
			 
            default:printf("\nwrong input..\n");  
        }  
    }  
		
	return 0;

}

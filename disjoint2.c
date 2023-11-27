#include<stdio.h>
int parent[7],rank[7];
int k,z;

void makeset(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }

}

int findset(int n)
{
    if (parent[n]==n)
    {
        return n;
    }
    else
    {
         return parent[n]=findset(parent[n]);
    }
}

void un(int x,int y)
{
    int root1 = findset(x);
    int root2 = findset(y);
    if (root1!=root2)
    {    
        if(rank[root1]>rank[root2])
        {
                parent[root2]=root1;
               
              
        }
        else
	{
             parent[root1]=root2;
             
             
        }
        if(rank[root1]==rank[root2])
        { 
		 rank[root2]++;
	}


    }

}

void disp(int n)
{
	printf("\n");
    	int i;
    	printf("\n index array : ");
     	for(i=0;i<n;i++)
    	{
        	printf("%d ",i);
       
    	}
    	printf("\n parent array: ");
    	for(i=0;i<n;i++)
    	{
        printf("%d ",parent[i]);
       
    	}
    	printf("\n rank   array: ");
     	for(i=0;i<n;i++)
    	{
        	printf("%d ",rank[i]);

    	}
}


int main()
{ 	
	int c;
   	printf("enter the limit(max 7)\n");
    	scanf("%d",&c);
    	makeset(c);
    	disp(c);
    	un(0,1);
    	printf("\n");
	printf("\n\n\nAFTER UNION(0,1):\n");printf("\n");
     	disp(c);
    	un(1,2);
    	un(3,4);
    	un(5,6);
   	 printf("\n\n\nAFTER UNION(5,6),union(1,2),union(3,4):\n");
     	disp(c);
    	un(4,5);
    	printf("\n\n\nAFTER UNION(4,5):\n");
    	disp(c);
    	un(2,6);
   	printf("\n\n\nAFTER UNION(2,6):\n");
    	disp(c);
    
    
    
	return 0;
}

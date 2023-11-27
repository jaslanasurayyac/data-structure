#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
          char alphabets[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
          char set1[26],set2[26];
          int bitset1[26],bitset2[26],result[26];
          int b_union[26];
          int b_intersection[26];
          int comp1[26],comp2[26],setdiffer[26];
 
 int display(int arr[26])
{
          int i;
          for(i=0;i<26;i++)
          {
                    printf("%d ",arr[i]);
          }

}
         
int bitvector1(char set[26],int size)
{
         int i,j,n;
         
         for(i=0;i<26;i++)
         {
                    bitset1[i]=0;
         
         }
         for(i=0;i<size;i++)
         {
                    for(j=0;j<26;j++)
                    {
                              if(set[i]==alphabets[j])
                              {
                                        bitset1[j]=1;
                              
                              }
                    
                    }

         
         }
   
          


}
int bitvector2(char set[26],int size)
{
         int i,j,n;
         
         for(i=0;i<26;i++)
         {
                    bitset2[i]=0;
         
         }
         for(i=0;i<size;i++)
         {
                    for(j=0;j<26;j++)
                    {
                              if(set[i]==alphabets[j])
                              {
                                        bitset2[j]=1;
                              
                              }
                    
                    }

         
         }
   
         


}


void setunion(){
                    int i;
                    for(i=0;i<26;i++)
                    {
                              b_union[i]=0;
                    
                    }
                    for(i=0;i<26;i++)
                    {
                             b_union[i]=bitset1[i]|bitset2[i];
                             
                             
                    }
                   
                    
}
void intersection(int bitset1[26],int  bitset2[26])
{
       int i;
       for(i=0;i<26;i++)
    {
            b_intersection[i]=0;
       }
        for(i=0;i<26;i++)
          {
                    b_intersection[i]=bitset1[i] &&bitset2[i];
          
          }
          
}
int complement(int bs[26],int comp1[26])
{
	int i;
	for(i=0;i<26;i++)
	{
                     if(bs[i]==1)
                                {
                                          comp1[i]=0;
                                 } 
          else
           {
                comp1[i]=1;
           }
          }
	

}
int setdiff(int bitset1[26],int comp2[26])
{
	int i;
	for(i=0;i<26;i++)
	{
			
		setdiffer[i]=0;

	}

	for(i=0;i<26;i++)
	{		
		setdiffer[i]=bitset1[i]&comp2[i];
	}	

}

int getele()
{
          int m,n,i;
	printf("enter the size for set 1: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter elements");
		scanf("%s",&set1[i]);
	}
	for(i=0;i<26;i++)
	{
	          set1[i]=toupper(set1[i]);
	}
	bitvector1(set1,n);
	display(bitset1);
	printf("\nenter the size for set 2: ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("enter elements");
		scanf("%s",&set2[i]);
	}
	for(i=0;i<26;i++)
	{
	          set2[i]=toupper(set2[i]);
	}
	bitvector2(set2,m);
	
	display(bitset2);
}

int set(int arr1[],char alp[26])
{         
          int i;
          printf("{");
          for(i=0;i<26;i++)
          {
                    if(arr1[i]==1)
                    {
                              printf("%c",alp[i]);
                    }
                   
          }
          printf("}");
          printf("\n");

}
int main(){
                    getele();
                     int c;
                           printf("\n------------------SET OPERATIONS USING BIT VECTOR------------------\n");
	while(1)   
	{
            printf("\n1.UNION\n2.INTERSECTION\n3.COMPLEMENT OF SET 1\n4.COMPLEMENT OF SET 2\n5.SET DIFFERENCE\n6.GET ELEMENTSBOTHSET        \n7.Exit");  
     printf("\nSelect the options\n");         
          scanf("%d",&c); 	 
        switch(c)  
        {  
            case 1: 
					 printf("\nUNION OPERATION\n");
					setunion();
					printf("Bit representation 1-");
					printf("\n",display(bitset1));
					printf("Bit representation 1-");
			          	printf("\n",display(bitset2));
			          	printf("Union of 2 sets are--");
					printf("\n",display( b_union));
					printf("\n",set(b_union,alphabets));
                    break;

            case 2:  
					printf("\nINTERSECTION OPERATION\n");
					intersection(bitset1,bitset2); 
					printf("Bit representation 1-");
					printf("\n ",display(bitset1));
					printf("Bit representation 2-");
			          	printf("\n",display(bitset2));
			          	printf("Intersection of  2 sets are-");
					printf("\n",display( b_intersection));  
					printf("\n",set(b_intersection,alphabets));
                    break;

            case 3: 
                    printf("\nCOMPLEMENT OPERATION OF SET 1\n");
		            complement(bitset1,comp1);    
		            printf("Bit representation 1-");  
		            printf("\n",display(bitset1));
		            printf("Bit representation 2-");
	          	printf("\n",display(bitset2));
	          	printf("Complement of set1-");
	          	printf("\n",display( comp1));    
	          	printf("\n",set(comp1,alphabets));
		            
		            
		            
                    break;

            case 4: 
                    printf("\nCOMPLEMENT OPERATION OF SET 2\n");
                    complement(bitset2,comp2);
                    printf("Bit representation 1-");
                    printf("\n",display(bitset1));
                    printf("Bit representation 2-");
	          	printf("\n",display(bitset2));
	          	printf("Complement of set2-");
                    printf("\n",display( comp2));
                      	printf("\n",set(comp2,alphabets));
                    break;  
            
            case 5:
                    printf("\nSET DIFFERENCE OPERATION OF SET 1\n");
                         complement(bitset2,comp2);
                    setdiff(bitset1,comp2);
                    printf("Bit representation 1-");
                      printf("\n",display(bitset1));
                      printf("Bit representation 2-");
	          printf("\n",display(bitset2));
	          printf("Difference-");
                   printf("\n",display(setdiffer)) ;
                   printf("\n ",set(setdiffer,alphabets));
                           break;

	        case 6: getele();
	    
                    break;

            case 7: printf("\nExiting.....\n");
                    exit(0);  
                    break;
			 
            default:printf("\nwrong input..\n");  
          
  
            }
            }
            }

#include<stdio.h>

struct nodes
{
	struct nodes *next;
	int data;
};
struct nodes *start=NULL;
struct nodes *create(struct nodes *start)
{
	struct nodes *newnode,*ptr;
	int num;
	printf("Enter the -1 to end\n");
	printf("Enter the data\n");
	scanf("%d",&num);
	while(num!=-1)
	{
		newnode =(struct nodes*)malloc(sizeof(struct nodes));
		newnode->data=num;
	    if(start==NULL)
	    {
	      
	      newnode->next=NULL;
	      start=newnode;
	      
	    }
	  else
	  {
	      ptr=start;
		  while(ptr->next!=NULL)
		  {
		  	ptr=ptr->next;
		  }
		  	ptr->next =newnode;
		  	newnode->next=NULL;
		  	  	
	  }	
	  printf("Enter the data\n");
	    scanf("%d",&num);
	}
	return start;
}
struct nodes *display(struct nodes *start)
{
	struct nodes *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d - ",ptr->data);
		ptr=ptr->next;
	}
	return start;
}
struct nodes *reverse(struct nodes *start)
{
	struct nodes* ptr,*ptr1,*ptr2;
	ptr=start;
	if(ptr!=NULL)
	{
		ptr1=ptr;//ptr1=previous nodes
		ptr=ptr->next;
		ptr2=ptr;//ptr2=current nodes
		ptr1->next=NULL;
	}
	
	while(ptr!=NULL)
	{
	
		ptr=ptr->next;
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr;
	}
	
	
	start=ptr1;
	return start;
	
}
int main()
{
	int option;
	do{
		printf("\n\nMAIN MENU\n\n");
		printf("\n 1:Create A list\n");
		printf("\n 2:Display A list\n");
		printf("\n 3:Reverse A list\n");
		printf("\n 4:EXIT\n");
		
		printf("\nEnter the Option\n");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1 : start=create(start);
			         break;
			case 2 : start=display(start); 
			         break;
		    case 3 : start=reverse(start);
	     	          break;
			case 4	: exit(0);	  			         
		}
		
	}while(1);
	return 0;
}

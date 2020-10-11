#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int count=0;
struct node
{
	char name[20];
	int roll_no;
	struct node *next;
}*start=NULL;
void createnode()
{
	if(count==0)
	{
		count++;
		start=(struct node*)malloc(sizeof(struct node));
		start->roll_no=0;
		strcat(start->name," ");
		start->next=(struct node*)malloc(sizeof(struct node));
		cout<<"\n Enter name of student...";
		fflush(stdin);
		gets(start->next->name);
		cout<<"\n Enter Roll no....";
		cin>>start->next->roll_no;
		start->next->next=start;
		start->roll_no=count;
	}
	else
	{
		count++;
		struct node *ptr,*temp=start;
		ptr=(struct node*)malloc(sizeof(struct node));
		cout<<"\n Enter name of student...";
		fflush(stdin);
		gets(ptr->name);
		cout<<"\n Enter Roll no....";
		cin>>ptr->roll_no;
		start->roll_no=count;
		while(temp->next!=start)
			temp=temp->next;
		temp->next=ptr;
		ptr->next=start;
	}
}
void display()
{
	if(start->next==start ||start==NULL)
	{
		cout<<" \n No records found.......!! \n";
	}
	else 
	{
		struct node *temp;
		temp=start;
		int n=temp->roll_no;
		temp=temp->next;
		cout<<"\n These are the details of "<<n<<"  students  \n";
		do
		{
			
			cout<<"\n Name : "<<temp->name;
			cout<<"\n Roll no. "<<temp->roll_no<<endl<<endl;
			temp=temp->next;
			
		}while(temp!=start);
	}
}
void deletenode()
{
	if(start==NULL)
	{
		cout<<" \n No records found.......!! \n" ;
	}
	else 
	{
	int num,y=0;
	cout<<"\n Enter roll no...\n";
	cin>>num;
	struct node *temp;
	temp=start;
	while(temp->next!=NULL)
	{
		if(temp->next->roll_no==num)
		
		{
		struct node *ptr;
		ptr=temp->next;
		temp->next=temp->next->next;
		free(ptr);
		y=1;
		cout<<"\n node deleted successfully\n";
		count--;
		break;
		}
		temp=temp->next;
	}
	if(y==0)
	{
		cout<<"\n Node not found\n";
	}
}
}
void checklimit()
{
	int total=2;
	while(true)
	{
		if(count==0)
	{
		count++;
		start=(struct node*)malloc(sizeof(struct node));
		start->roll_no=0;
		strcat(start->name," ");
		start->next=(struct node*)malloc(sizeof(struct node));
		strcat(start->next->name,"abc");
		start->next->roll_no=rand();
		start->next->next=start;
		start->roll_no=count;
	}
	else
	{
		count++;
		struct node *ptr,*temp=start;
		ptr=(struct node*)malloc(sizeof(struct node));
		if(ptr==NULL)
		{
			cout<<"\n no of nodes created are "<<start->roll_no;
			break;
		}
		strcat(ptr->name,"abc");
		ptr->roll_no=rand();
		start->roll_no=count;
		while(temp->next!=start)
			temp=temp->next;
		temp->next=ptr;
		ptr->next=start;
		cout<<total<<endl;
		total++;
	}
	}
	
}

int main()
{
	int a;
	while(true){
	
	cout<<" Enter your choice\n  1.Add a record\n  2.Display records\n  3.End execution\n  4.Delete record\n  5.Check limit\n ";
	cin>>a;
	switch(a)
	{
		case 1:
			createnode();
			break;
		case 2:
			display();
			break;
		case 3:
			exit(1);
			break;
		case 4:
			deletenode();
			break;
		case 5:
			checklimit();
			break;
		default:
			cout<<" Enter correct Choice \n";
			break;
	}
}
	return 0;
}

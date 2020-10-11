#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int count=0;
int counter=0;
struct node{
	struct node *prev;
	long int num;
	char name[20];
	char gender[10];
	char fathername[20];
	char mothername[20];
	char dob[10];
	struct node *next;
}*lp=NULL,*rp=NULL,*lp1=NULL,*rp1=NULL;


int x=1;
void gettingdata(struct node *temp)
{
	cout<<"\n enter name \n";
	fflush(stdin);
	gets(temp->name);
	cout<<"\n enter gender \n";
	fflush(stdin);
	gets(temp->gender);
	cout<<"\n enter father name \n";
	fflush(stdin);
	gets(temp->fathername);
	cout<<"\n enter mother name \n";
	fflush(stdin);
	gets(temp->mothername);
	cout<<"\n enter date of birth \n";
	fflush(stdin);
	gets(temp->dob);
	
	
	
	struct node *pnr,*pnr1;
	pnr=lp;
	for(int i=1;i<count;i++)
	{
		if((strcmp(pnr->name,temp->name))==0)
		{
			if(lp1==NULL)
			{
				lp1=(struct node*)malloc(sizeof(struct node));
				lp1->num=temp->num;
				strcat(lp1->name,temp->name);
				strcat(lp1->fathername,temp->fathername);
				strcat(lp1->mothername,temp->mothername);
				strcat(lp1->gender,temp->gender);
				strcat(lp1->dob,temp->dob);
				rp1=lp1;
				lp1->next=NULL;
				rp1->next=NULL;
				break;
			}
			else
			{
				pnr1=lp1;
				while(pnr1->next!=NULL)
					pnr1=pnr1->next;
				pnr1->next=(struct node*)malloc(sizeof(struct node));
				pnr1->next->num=temp->num;
				strcat(pnr1->next->name,temp->name);
				strcat(pnr1->next->fathername,temp->fathername);
				strcat(pnr1->next->mothername,temp->mothername);
				strcat(pnr1->next->dob,temp->dob);
				strcat(pnr1->next->gender,temp->gender);
				pnr1->next->prev=pnr1;
				pnr1->next->next=NULL;
				rp1=pnr1->next;
				break;
				
			}
		}
		pnr=pnr->next;
	}
	
	
}
void createnode()
{
int a;
if(count==0){
	
	
	lp=(struct node*)malloc(sizeof(struct node));
	cout<<" enter aadhar no.  \n ";
	cin>>a;
	lp->num=a;
	gettingdata(lp);
	lp->prev=NULL;
	lp->next=NULL;
	rp=lp;
	count++;
}
else{
	count++;
	struct node *temp,*temp1,*temp2;
		temp=lp;
		cout<<"enter aadhar no. "<<endl;
		cin>>a;
		int cunt=0;
		while(temp->num < a && temp->next!=NULL)
		{
			temp2=temp;
			temp=temp->next;
			
		}
		if(temp==lp && temp->next==NULL)
		{
			if(temp->num < a)
			{
				
			temp->next=(struct node*)malloc(sizeof(struct node));
			temp->next->num=a;
			gettingdata(temp->next);
			temp->next->next=NULL;
			temp->next->prev=lp;
			rp=temp->next;
			}
			else
			{
			temp1=(struct node*)malloc(sizeof(struct node));
			temp1->num=a;
			gettingdata(temp1);
			lp->prev=temp1;
			temp1->next=lp;
			temp1->prev=NULL;
			lp=temp1;
			}
		}
		else if(temp==lp)
		{
			
			temp1=(struct node*)malloc(sizeof(struct node));
			temp1->num=a;
			gettingdata(temp1);
			lp->prev=temp1;
			temp1->next=lp;
			temp1->prev=NULL;
			lp=temp1;
			
		}
		else if(temp->next==NULL)
		{
			if(temp->num<a){
			
			temp->next=(struct node*)malloc(sizeof(struct node));
			temp->next->num=a;
			gettingdata(temp->next);
			temp->next->next=NULL;
			temp->next->prev=temp;
			rp=temp->next;
			}
			else
			{
				temp1=temp2->next;
				temp2->next=(struct node*)malloc(sizeof(struct node));
				temp2->next->num=a;
				gettingdata(temp2->next);
				temp2->next->next=temp1;
				temp2->next->prev=temp2;
				temp2->next->next->prev=temp2->next;
			}
		}
		else
		{
			temp1=temp2->next;
			temp2->next=(struct node*)malloc(sizeof(struct node));
			temp2->next->num=a;
			gettingdata(temp2->next);
			temp2->next->next=temp1;
			temp2->next->prev=temp2;
			temp2->next->next->prev=temp2->next;
		}
}
}
void deletenode()
{
	if(lp==NULL)
	{
		cout<<" Not Records found...";
	 } 
	 else
	 {
	 	struct node *temp,*ptr,*ptr1;
	temp=lp;
	int num,y=0;
	cout<<"\n Enter aadhar no of person...\n";
	cin>>num;
	for(int i=1;i<=count;i++)
	{
		
		if(temp->num==num)
		{
			
			if(temp ==lp && temp ==rp)
			{
				
				ptr=lp;
				ptr1=rp;
				lp=rp=NULL;
				free(ptr);
				free(ptr1);
				cout<<"\n node deleted sucessfully";
				y++;
				count--;
				break;
			}
			else if(temp==lp)
			{
				
				ptr=lp;
				lp=lp->next;
				free(ptr);
				cout<<"\n node deleted sucessfully";
				y++;
				count--;
				break;
			}
			else if(temp==rp)
	        {
	        	ptr=rp;
	        	rp=rp->prev;
	        	rp->next=NULL;
	        	free(ptr);
	        	cout<<"\n node deleted sucessfully";
	        	y++;
	        	count--;
	        	break;
			}
			else
			{
				ptr=ptr1->next;
				ptr1->next=ptr1->next->next;
				ptr1->next->prev=ptr1;
				free(ptr);
				cout<<"\n node deleted sucessfully";
				y++;
				count--;
				break;
			}
			
		}
		 	ptr1=temp;
			temp=temp->next;		
	 }
	 if(y==0)
	 {
	 	cout<<"\n Not  Found.......!!!!!!!!!!!\n";
	  }
	 }
}
void display(struct node *dispo)
{
	if(dispo==NULL)
	{
		cout<<" Not Records found...";
	 } 
	 else
	 {
	cout<<"\n\nDETAILS:-\n\n";
	do
	{	
		cout<<"Aadhar no.  "<<dispo->num<<endl;
		cout<<"Name "<<dispo->name<<endl;
		cout<<"Gender "<<dispo->gender<<endl;
		cout<<"Father Name "<<dispo->fathername<<endl;
		cout<<"Mother Name "<<dispo->mothername<<endl;
		cout<<"Date of Birth  "<<dispo->dob<<endl;
		dispo=dispo->next;
		
	}while(dispo!=NULL);
}
}
int main()
{	int a;
	while(true){

	cout<<"\n Enter your choice\n  1.Add a new person in record\n  2.Display all records\n  3.Delete a record\n  4.Exit program\n  5.Check Duplicate List";//5.Modify a record\n  6.Search a record\n  ";
	cin>>a;
	switch(a)
	{
	case 1:
		createnode();
		break;
	case 2:
		display(lp);
		break;
	case 3:
		deletenode();
		break;
	case 4:
		exit(2);
		break;
//	case 5:
//		modifynode();
//		break;
//	case 6:
//		searchnode();
//		break;
	case 5:
		display(lp1);
		break;
	default:
		cout<<"\n enter correct choice\n";
		break;
	}
		}
	
	
	
	return 0;
}

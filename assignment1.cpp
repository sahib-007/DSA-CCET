#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int count=0;
long int arr[30];
char m[30],n[30];
struct adress{
	char houseno[10];
	char street[10];
	char city[10];
	char state[10];
	char country[10];
	
};
struct node{
	char emp_id[20];
	char name[30];
	char father_name[30];
	char mother_name[30];
	char rank[30];
	char workplace[30];
	char date_join[15];
	struct adress ad;
	struct node *next;
	
}*start=NULL;

bool checkalpha(char a[30])
{	
	int x=0;
	for(int i=0;i<strlen(a);i++){
		if(isalpha(a[i])||a[i]==' ')
		{
			
		}
		else
		{
			x++;
		}
		
	}	
	if(x==0)
		return true;
	else
		return false;
}
bool checkalpha1(char a[30])
{	
	int x=0;
	for(int i=0;i<strlen(a);i++){
		if(isalpha(a[i])||a[i]==' '||a[i]=='.')
		{
			
		}
		else
		{
			x++;
		}
		
	}	
	if(x==0)
		return true;
	else
		return false;
}
char* getting_space_separated_string()
{	
	
	while(true){

	gets(n);
	if(checkalpha(n))
	{
		return n;
		break;
	}
	else
			 {
			 	cout<<"\n Kindly note that only alphabetic value is allowed  \n retry entering the value\n";
			 	continue;
			 }
	
	}	
}
char* getting_space_separated_string1()
{	
	
	while(true){

	
	gets(m);
	if(checkalpha1(m))
	{
		return m;
		break;
	}
	else
			 {
			 	cout<<"\n Kindly note that only alphabetic value and dot symbol is allowed  \n retry entering the value\n";
			 	continue;
			 }
	
	}	
}
bool checknumeric(char str[20])
{
	int x=0;
	for(int i=0;i<strlen(str);i++){
		if(isdigit(str[i]))
		{
			
		}
		else
		{
			x++;
		}
		
	}	
	if(x==0)
		return true;
	else
		return false;
}
bool checkdj(char dj[20])
{
	int x=0;
	for(int i=0;i<strlen(dj);i++)
	{
		if(isdigit(dj[i]) || dj[i]=='/')
		{
		}
		else
			x++;	
	}
	if(x==0)
		return true;
	else
		return false;
}
void createnode()
{
	char rank[20],wp[20],dj[20];
	if(count==0){	
  start=(struct node*)malloc(sizeof(struct node));
  if(start == NULL)
  {
  	cout<<"\n memory cannot be allocated\n";
  	
	  }
	  else
	  {
	  	
	  	
	  	cout<<"\n Enter data for node 1\n";
	  	cout<<"\n Enter Employee ID:(Unique id of Seven numbers) \n";
	  	while(true){
	  		cin>>start->emp_id;
		 	if(checknumeric(start->emp_id) && strlen(start->emp_id)==7)
		 	{
			 break;	
			 }
			 else
			 {
			 	cout<<"\n Kindly note that only numeric value is allowed for employee id and id cannot be less than 7 numbers\n retry entering the value\n";
			 	
			 }
	  	 }
	  	 
	  	cout<<"\n Enter Name of Employee \n";
	  	fflush(stdin);
	  	strcat(start->name,getting_space_separated_string());
	  	cout<<"\n Enter Father's Name of Employee \n";
	  	fflush(stdin);
	  	strcat(start->father_name,getting_space_separated_string());
	  	cout<<"\n Enter Mother's Name of Employee \n";
	  	fflush(stdin);
	  	strcat(start->mother_name,getting_space_separated_string());
	  	cout<<"\n Enter Rank of Employee \n";
	  	fflush(stdin);
	  	strcat(start->rank,getting_space_separated_string1());
	  	cout<<"\n Enter Workplace of Employee\n";
	  	fflush(stdin);
	  	strcat(start->workplace,getting_space_separated_string());
	  	cout<<"\n Enter Date of Joining(format allowed is 02/08/2004)\n";
	  	
	  	while(true){
	  			cin>>dj;
	  		
	  	if(checkdj(dj)){
		  strcat(start->date_join,dj);
		  break;
		  }
		else{
			cout<<"\n enter required format\n";
			continue;
		}	  
	  	
	  	}
	  	cout<<"\n Enter the adress of employee\n";
	  	cout<<"House no. :";
	  	fflush(stdin);
	  	gets(start->ad.houseno);
	  	cout<<"\nStreet :";
	  	fflush(stdin);
	  	gets(start->ad.street);
	  	cout<<"\nCity :";
	  	fflush(stdin);
	  	gets(start->ad.city);
	  	cout<<"\n State :";
	  	fflush(stdin);
	  	gets(start->ad.state);
	  	cout<<"\n Country :";
	  	fflush(stdin);
	  	gets(start->ad.country);
	  	
	  	start->next=NULL;
	  	count++;
}}
else
{
	struct node *ptr,*temp;
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	
	temp=(struct node*)malloc(sizeof(struct node));
		cout<<"\n Enter data for node "<<count<<endl;
	  	cout<<"\n Enter Employee ID:(Unique id of Seven numbers) \n";
	  	while(true){
	  		cin>>temp->emp_id;
		 	if(checknumeric(temp->emp_id) && strlen(temp->emp_id)==7)
		 	{
			 break;	
			 }
			 else
			 {
			 	cout<<"\n Kindly note that only numeric value is allowed for employee id and id cannot be less than 7 numbers\n retry entering the value\n";
			 	
			 }
	  	 }
	  	 
	  	cout<<"\n Enter Name of Employee (Surname is required..)\n";
	  	fflush(stdin);
	  	strcat(temp->name,getting_space_separated_string());
	  	cout<<"\n Enter Father's Name of Employee \n";
	  	fflush(stdin);
	  	strcat(temp->father_name,getting_space_separated_string());
	  	cout<<"\n Enter Mother's Name of Employee \n";
	  	fflush(stdin);
	  	strcat(temp->mother_name,getting_space_separated_string());
	  	cout<<"\n Enter Rank of Employee \n";
	  	fflush(stdin);
	  	strcat(temp->rank,getting_space_separated_string1());
	  	cout<<"\n Enter Workplace of Employee\n";
	  	fflush(stdin);
	  	strcat(temp->workplace,getting_space_separated_string());
	  	cout<<"\n Enter Date of Joining(format allowed is 02/08/2004)\n";
	  	
	  	while(true){
	  			cin>>dj;
	  		
	  	if(checkdj(dj)){
	  		fflush(stdin);
		  strcat(temp->date_join,dj);
		  break;
		  }
		else{
			cout<<"\n enter required format\n";
			continue;
		}	  
	  	
	  	}
	  	cout<<"\n Enter the adress of employee\n";
	  	cout<<"House no. :";
	  	fflush(stdin);
	  	gets(temp->ad.houseno);
	  	cout<<"\nStreet :";
	  	fflush(stdin);
	  	gets(temp->ad.street);
	  	cout<<"\nCity :";
	  	fflush(stdin);
	  	gets(temp->ad.city);
	  	cout<<"\n State :";
	  	fflush(stdin);
	  	gets(temp->ad.state);
	  	cout<<"\n Country :";
	  	fflush(stdin);
	  	gets(temp->ad.country);
	  	ptr->next=temp;
	  	temp->next=NULL;
	  	count++;
}

}

void display()
{
	if(start==NULL)
	{
		cout<<"\n No records found\n";
	}
	else{
	int no=1;
	struct node *temp;
	temp=start;
	do{
	
	
	
	cout<<"\n These are the details of Employee no "<<no<<"\n";
	
	cout<<"Employee_id: "<<temp->emp_id<<endl;
	cout<<"Employee name: "<<temp->name<<endl;
	cout<<"Employee Father name: "<<temp->father_name<<endl;
	cout<<"Employee Mother name: "<<temp->mother_name<<endl;
	cout<<"Employee rank: "<<temp->rank<<endl;
	cout<<"Employee workplace: "<<temp->workplace<<endl;
	cout<<"Date of Joining: "<<temp->date_join<<endl;
	cout<<"Adress : House no. :"<<temp->ad.houseno<<", Street :"<<temp->ad.street<<","<<temp->ad.city<<","<<temp->ad.state<<","<<temp->ad.country<<endl<<endl;
	temp=temp->next;
	no++;
}while(temp!=NULL);
}
}

void reportgeneration()
{
	char inr[30];
	int a,flag=0;
	cout<<"\n SELECT THE CATEGORY \n  1.City name \n  2.State name \n  3.Country name\n  ";
	while(true)
	{
		if(flag>0)
			break;
		cin>>a;
	switch(a)
	{
		case 1:
			cout<<"\n Enter City name \n  ";
			fflush(stdin);
			gets(inr);
				if(start==NULL)
	{
		cout<<"\n LIST is empty\n";
	}
	else{
	cout<<"\n These are the details of Employee belonging to city "<<inr<<"\n";
	struct node *temp;
	temp=start;
	do{
	
	if(strcmp(temp->ad.city,inr)==0)	
	{
	
	
	
	cout<<"Employee_id: "<<temp->emp_id<<endl;
	cout<<"Employee name: "<<temp->name<<endl;
	cout<<"Employee Father name: "<<temp->father_name<<endl;
	cout<<"Employee Mother name: "<<temp->mother_name<<endl;
	cout<<"Employee rank: "<<temp->rank<<endl;
	cout<<"Employee workplace: "<<temp->workplace<<endl;
	cout<<"Date of Joining: "<<temp->date_join<<endl;
	cout<<"Adress : House no. :"<<temp->ad.houseno<<", Street :"<<temp->ad.street<<","<<temp->ad.city<<","<<temp->ad.state<<","<<temp->ad.country<<endl<<endl;
	temp=temp->next;
	flag++;
}
}while(temp!=NULL);
if(flag==0)
	cout<<"\n NO records found";
}
break;
	
	case 2:
		cout<<"\n Enter state name \n  ";
			fflush(stdin);
			gets(inr);
				if(start==NULL)
	{
		cout<<"\n LIST is empty\n";
	}
	else{
	cout<<"\n These are the details of Employee belonging to state "<<inr<<"\n";
	struct node *temp;
	temp=start;
	do{
	
	if(strcmp(temp->ad.state,inr)==0)	
	{
	
	
	
	cout<<"Employee_id: "<<temp->emp_id<<endl;
	cout<<"Employee name: "<<temp->name<<endl;
	cout<<"Employee Father name: "<<temp->father_name<<endl;
	cout<<"Employee Mother name: "<<temp->mother_name<<endl;
	cout<<"Employee rank: "<<temp->rank<<endl;
	cout<<"Employee workplace: "<<temp->workplace<<endl;
	cout<<"Date of Joining: "<<temp->date_join<<endl;
	cout<<"Adress : House no. :"<<temp->ad.houseno<<", Street :"<<temp->ad.street<<","<<temp->ad.city<<","<<temp->ad.state<<","<<temp->ad.country<<endl<<endl;
	temp=temp->next;
	flag++;
}
}while(temp!=NULL);
if(flag==0)
	cout<<"\n NO records found";
}
break;
		case 3:
			cout<<"\n Enter Country name \n  ";
			fflush(stdin);
			gets(inr);
				if(start==NULL)
	{
		cout<<"\n LIST is empty\n";
	}
	else{
	cout<<"\n These are the details of Employee belonging to country "<<inr<<"\n";
	struct node *temp;
	temp=start;
	do{
	
	if(strcmp(temp->ad.country,inr)==0)	
	{
	
	
	
	cout<<"Employee_id: "<<temp->emp_id<<endl;
	cout<<"Employee name: "<<temp->name<<endl;
	cout<<"Employee Father name: "<<temp->father_name<<endl;
	cout<<"Employee Mother name: "<<temp->mother_name<<endl;
	cout<<"Employee rank: "<<temp->rank<<endl;
	cout<<"Employee workplace: "<<temp->workplace<<endl;
	cout<<"Date of Joining: "<<temp->date_join<<endl;
	cout<<"Adress : House no. :"<<temp->ad.houseno<<", Street :"<<temp->ad.street<<","<<temp->ad.city<<","<<temp->ad.state<<","<<temp->ad.country<<endl<<endl;
	temp=temp->next;
	flag++;
}
}while(temp!=NULL);
if(flag==0)
	cout<<"\n NO records found";
}
break;
		default:
			cout<<"\n Enter valid choice ";
			break;
	}
	}
	
	
	
}
void modifynode()
{
	if(start==NULL)
	{
		cout<<"\n No record found\n";
	}
	else{
	int nodeno;
	char dj[20];
	cout<<"\n Enter Node no which you want to modify \n";
	while(true)
	{
		
		cin>>nodeno;
		if(nodeno <= count)
			break;
		else
			{
			
			cout<<"\n You have entered a wrong  no.Retry entering the valid one";
			continue;
			}
	}
	struct node *temp;
	temp=start;	
	for(int i=1;i<nodeno;i++)
		temp=temp->next;	
	cout<<"\n Enter new data for node "<<nodeno<<endl;
	  	cout<<"\n Enter Employee ID:(Unique id of Seven numbers) \n";
	  	while(true){
	  		cin>>temp->emp_id;
		 	if(checknumeric(temp->emp_id) && strlen(temp->emp_id)==7)
		 	{
			 break;	
			 }
			 else
			 {
			 	cout<<"\n Kindly note that only numeric value is allowed for employee id and id cannot be less than 7 numbers\n retry entering the value\n";
			 	
			 }
	  	 }
	  	 
	  	cout<<"\n Enter Name of Employee (Surname is required..)\n";
	  	fflush(stdin);
	  	strcpy(temp->name,getting_space_separated_string());
	  	cout<<"\n Enter Father's Name of Employee \n";
	  	fflush(stdin);
	  	strcpy(temp->father_name,getting_space_separated_string());
	  	cout<<"\n Enter Mother's Name of Employee \n";
	  	fflush(stdin);
	  	strcpy(temp->mother_name,getting_space_separated_string());
	  	cout<<"\n Enter Rank of Employee \n";
	  	fflush(stdin);
	  	strcpy(temp->rank,getting_space_separated_string1());
	  	cout<<"\n Enter Workplace of Employee\n";
	  	fflush(stdin);
	  	strcpy(temp->workplace,getting_space_separated_string());
	  	cout<<"\n Enter Date of Joining(format allowed is 02/08/2004)\n";
	  	
	  	while(true){
	  			cin>>dj;
	  		
	  	if(checkdj(dj)){
	  		fflush(stdin);
		  strcpy(temp->date_join,dj);
		  break;
		  }
		else{
			cout<<"\n enter required format\n";
			continue;
		}	  
	  	
	  	}
	  	cout<<"\n Enter the adress of employee\n";
	  	cout<<"House no. :";
	  	fflush(stdin);
	  	gets(temp->ad.houseno);
	  	cout<<"\nStreet :";
	  	fflush(stdin);
	  	gets(temp->ad.street);
	  	cout<<"\nCity :";
	  	fflush(stdin);
	  	gets(temp->ad.city);
	  	cout<<"\n State :";
	  	fflush(stdin);
	  	gets(temp->ad.state);
	  	cout<<"\n Country :";
	  	fflush(stdin);
	  	gets(temp->ad.country);
	  }
}
void deletenode(){
	
	if(start==NULL)
	{
		cout<<"\n No record found\n";
	}
	else{
	
	int x;
	struct node *temp,*temp1;
	cout<<"\n Enter the Employee no which you want to delete \n";
	
	
	
	
		while(true){
				cin>>x;
			if(x==1)
			{
				struct node *ptr;
				ptr=start;
				start==NULL;
				free(ptr);
				cout<<"\n Record deleted successfully\n";
				count--;
				break;
			}
			else if(x==count)
			{
				int c=count;
				c--;
				temp=start;
				for(int i=1;i<c;i++)
					temp=temp->next;
				struct node *ptr;
				ptr=temp->next;
				temp->next=NULL;
				free(ptr);
				cout<<"\n Record deleted successfully\n";
				count--;
				break;
				
			}
			else if(x>count)
			{
				cout<<"\n Kindly enter valid Employee no\n";
				continue;
			}
			else
			{
				temp=start;
				for(int i=1;i<x;i++)
				{
					temp1=temp;
					temp=temp->next;
				}
				struct node *ptr;
				ptr=temp1->next;
				temp1->next=temp->next;
				free(ptr);
				count--;
				cout<<"\n Record deleted successfully\n";
				break;
			}
	
	}
}
}
void searchnode()
{
	if(start==NULL)
	{
		cout<<"\n No record found\n";
	}
	else{
	int x;
	cout<<"\n Enter the employee no you want to search.. ";
	while(true){
		cin>>x;
		if(x<=count)
		{
			break;
		}
		else{
			cout<<"\n Wrong employee no entered.Kindly enter right one..";
			continue;
		}
	}
	struct node *temp;
	temp=start;
	for(int i=1;i<x;i++)
		temp=temp->next;
	cout<<"\n These are the details of Employee no "<<x<<"\n";
	
	cout<<"Employee_id: "<<temp->emp_id<<endl;
	cout<<"Employee name: "<<temp->name<<endl;
	cout<<"Employee Father name: "<<temp->father_name<<endl;
	cout<<"Employee Mother name: "<<temp->mother_name<<endl;
	cout<<"Employee rank: "<<temp->rank<<endl;
	cout<<"Employee workplace: "<<temp->workplace<<endl;
	cout<<"Date of Joining: "<<temp->date_join<<endl;
	cout<<"Adress : House no. :"<<temp->ad.houseno<<", Street :"<<temp->ad.street<<","<<temp->ad.city<<","<<temp->ad.state<<","<<temp->ad.country<<endl<<endl;
	
}
}
int main()
{
	int a;
	while(true){

	cout<<"\n Enter your choice\n  1.Add a new person in record\n  2.Display all records\n  3.Delete a record\n  4.Exit program\n  5.Modify a record\n  6.Search a record\n  7.Generate report\n  ";
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
		deletenode();
		break;
	case 4:
		exit(2);
		break;
	case 5:
		modifynode();
		break;
	case 6:
		searchnode();
		break;
	case 7:
		reportgeneration();
		break;
	default:
		cout<<"\n enter correct choice\n";
		break;
	}
		}
	return 0;
}





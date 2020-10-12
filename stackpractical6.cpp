#include<iostream>
using namespace std;
int count=0,top=-1,top1=-1,temp;
int arr[10],arr1[10];
push()
{
	if(count>10)
	{
		cout<<"\n Stack is Full\n";
	}
	else
	{
		cout<<"\n Enter element\n  ";
		top++;
		cin>>arr[top];
		count++;
	}
}
pop()
{
	if(count==0)
	{
		cout<<"\n Stack is already empty\n ";
		
	}
	else
	{
		count--;
		top--;
	}
}
peek()
{
	int m;
	cout<<"\n enter the location of element\n  ";
	cin>>m;
	int i=top;
	if(m>0 && m<=count)
	{
		while(i>=m)
		{
			temp=arr[top];
			top--;
			i--;
			top1++;
			arr1[top1]=temp;
		}
		temp=arr[top];
		cout<<"\n  Element at "<<m<<"th location is "<<temp<<endl;
		i=-1;
		while(top1>i)
		{
			temp=arr1[top1];
			top1--;
			top++;
			arr[top]=temp;
				}		
	}
	else{
		cout<<"\n  Wrong location entered \n";
	}
}
update()
{
	int m;
	cout<<"\n enter the location of element\n  ";
	cin>>m;
	int i=top;
	if(m>0 && m<=count)
	{
		while(i>=m)
		{
			temp=arr[top];
			top--;
			i--;
			top1++;
			arr1[top1]=temp;
		}
		cout<<"\n  Enter the new value\n  ";
		cin>>temp;
		arr[top]=temp;
		
		i=-1;
		while(top1>i)
		{
			temp=arr1[top1];
			top1--;
			top++;
			arr[top]=temp;
				}		
				cout<<"\n Updated sucessfully\n  ";
	}
	else{
		cout<<"\n  Wrong location entered \n";
	}
}
int main()
{
	int a;
	
	while(true)
	{
	cout<<" Enter your choice\n  1.Push an element\n  2.Pop an element\n  3.Peek operation\n  4.Update an element\n  5.Exit\n   ";
	cin>>a;
		switch(a)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				update();
				break;
			case 5:
				exit(22);
				break;
			default:
				cout<<"\n Enter Valid Choice\n   ";
				break;
		}
	}
}

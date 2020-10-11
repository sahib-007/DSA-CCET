#include<iostream>
#include<malloc.h>

using namespace std;

int total=0;
int *a;
void addelement(int n);
void display(int n);
int deleteelement(int n);
int update(int n);
int min_max(int n);
int main()
{

    int ch;
    char choice;
    int n;
    int i=0;
    cout<<"\n Enter size: ";
    cin>>n;
    a=(int *)malloc(sizeof(int) * n);
    do
    {
        if(i>n-1)
        {
            cout<<"\n Overloading";
            break;
        }
        else{
        cout<<"\n Enter element at position "<<(i+1)<<": ";
        cin>>a[i];
         total++;
        cout<<"\n Do you want to add more elements?: ";
        cin>>choice;
        if(choice=='y')
        {
            i++;

        }
        }
    }while(choice=='y');
    do{
    cout<<"\n 1-Insert";
    cout<<"\n 2-Display";
    cout<<"\n 3-Delete";
    cout<<"\n 4-Update";
    cout<<"\n 5-To calculate minimum or maximum";
    cout<<"\n Enter choice :";
    cin>>ch;
    switch(ch)
    {
        case 1: addelement(n);
                break;
        case 2: display(total);
                break;
        case 3: deleteelement(n);
                break;
        case 4: update(n);
                break;
        case 5: min_max(n);
                break;
        default: cout<<"\n Invalid input";
                break;
    }
    cout<<"\n Do you want to perform more tasks?: ";
    cin>>choice;
    }while(choice=='y');
}

void addelement(int n)
{
    int num;
    cout<<"\n Enter the position: ";
    cin>>num;
    if(num<=0 || num>n)
    {
        cout<<"\n Invalid input";
    }
    else if(num>0 && num<total)
    {
        for(int i=total+1;i>num-1;i--)
        {
            a[i]=a[i-1];
        }
        cout<<"\n Enter value: ";
        cin>>a[num-1];
        total++;
    }
    else
    {

        cout<<"\n Enter value: ";
        cin>>a[total];
        total++;
    }
}

void display(int n)
{
    for(int i=0;i<total;i++)
    {
        cout<<"\n"<<a[i];
    }
}

int deleteelement(int n)
{
    int p;
    cout<<"\n Enter position which you want to delete: ";
    cin>>p;
    if(p<1 || p>n)
    {
        cout<<"\n Invalid Input";
    }
    else
    {
        for(int i=(p-1);i<n;i++)
        {
            a[i]=a[i+1];
        }
        total--;
    }
}

int update(int n)
{
    int p;
    cout<<"\n Enter position of element you want to update: ";
    cin>>p;
    p++;
    if(p<1 || p>n)
    {
        cout<<"\n Invalid input";
    }
    else
    {
        cout<<"\n Enter new value: ";
        cin>>a[p];
        cout<<"\n Updated";
    }
}

int min_max(int n)
{
    int ch;
    int temp;
    cout<<"\n Press 1 for minimum";
    cout<<"\n Press 2 for maximum";
    cout<<"\n Enter choice: ";
    cin>>ch;
    if(ch==1)
    {
       temp=a[0];
       for(int i=1;i<=total;i++)
       {
          if(a[i]<temp)
          {
              temp=a[i];
          }
       }
       cout<<"\n The smallest element is: "<<temp;;
    }
    else if(ch==2)
    {
       temp=a[0];
       for(int i=1;i<=total;i++)
       {
          if(a[i]>temp)
          {
              temp=a[i];
          }
       }
       cout<<"\n The largest element is: "<<temp;
    }
    else
    {
        cout<<"\n Invalid Input";
    }
}

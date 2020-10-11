#include<stdio.h>
#include<conio.h>
 #define size 5



//prototyping
void insert();
void delete();
void display();
int rear =-1;
int front=-1;
int queue[MAX]; //for max number of elements//also queue is an array
int main()



int main()   //main user interface block
int option;
{
   printf("press [1] for inerting element in queue");
   printf("press [2] for deleting element in queue");
   printf("press [3] for displaying element in queue");
   printf("press [4] for exit and return to main menu");
   //to input choice from the user using switch case

   printf("Enter your choice : ");
scanf("%d", &option);
switch(option)
{
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
exit(1);
default:
printf("sorry Wrong choice enter numbers between 1-4 \n");
}




    
    return 0;
}

void is_Empty()
{
 if(rear=n)
 printf("overflow\n")
 
return 1;                    // or directly return (head==tail)
}

void isFull()
{

if (rear=0)
printf("queue is empty\n");
return 1;

}



void insertion()
{
    int item;
    if (rear==MAX-1)
    printf("overflow\n");
    else
    {
        if (front==-1)
        front = 0;
        printf("insert element \n");
        scanf("%d", &item);
        rear=rear+1;
        queue[rear]=item;
    
    }
    
}

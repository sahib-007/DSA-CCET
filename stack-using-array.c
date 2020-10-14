#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int top = -1;
int arr[MAX];

void display()
{
    printf("\n-------------\n");
    for (int i = 0; i <= top; i++)
    {
        printf(" %6d\n", arr[i]);
    }
    printf("-------------\n\n");
}

int is_full()
{
    if (top == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_empty()
{
    if (top == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void push()
{
    int data;
    if (is_full())
    {
        printf("\nStack is full! \n");
    }

    else if (!is_full())
    {
        top = top + 1;
        printf("\nEnter data you want to insert\n");
        scanf("%d", &data);
        getchar();
        arr[top] = data;
    }
}

void pop()
{
    if (is_empty())
    {
        printf("\nStack is empty\n");
    }

    else if (!is_empty())
    {
        printf("\nThe popped element is -->  %d \n", arr[top]);
        top = top - 1;
    }
}

void peek()
{
    if (is_empty())
    {
        printf("\nStack is empty! \n");
    }

    else if (!is_empty())
    {
        printf("\nTop most element of stack is %d\n", arr[top]);
    }
}

void peep()
{
    if (is_empty())
    {
        printf("\nStack is empty! \n");
    }

    else if (!is_empty())
    {
        int a;
        printf("\nEnter index of which data you want to see\n");
        scanf("%d", &a);
        getchar();

        if (a < sizeof(arr) / sizeof(int))
        {
            printf("\nValue at index %d is %d\n", a, arr[a]);
        }

        else
        {
            printf("Underflow!\n");
        }
    }
}

int main()
{
    int x;
    do
    {
        printf("\nMAIN MENU\n\n");
        printf("1. Display Stack\n");
        printf("2. Check if stack is empty\n");
        printf("3. Check if stack is full\n");
        printf("4. Push an element in stack\n");
        printf("5. Pop an element from stack\n");
        printf("6. Peek topmost element in stack\n");
        printf("7. Peep an element of any specific location in stack\n");
        printf("8. EXIT\n\n");
        scanf("%d", &x);
        getchar();
        switch (x)
        {
        case 1:
            display();
            break;
        case 2:
            if (is_empty())
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Stack is Not Empty\n");
            }
            break;

        case 3:
            if (is_full())
            {
                printf("Stack is Full\n");
            }
            else
            {
                printf("Stack is Not Full\n");
            }
            break;

        case 4:

            push();
            break;
        case 5:
            pop();
            break;
        case 6:
            peek();
            break;
        case 7:
            peep();
            break;
        }
    }while(x!=8);
}

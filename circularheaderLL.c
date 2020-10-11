/*
Dated: 31/08/2020
Write a program  for simple linked list to create a circular header linked list.
The attributes of nodes are as follows
1.Name(only alphabets)
2.Roll No,(Only integers)
Write the following methods
1.Insert record in the list
2.Delete the record in the list
3.display Count of Number of nodes
*/
#include<stdio.h>
#include<stdlib.h>

struct circular_header_linkedlist
{
    char name[30];
    unsigned int roll_no;
    struct circular_header_linkedlist* link;
};

struct header_node
{
    unsigned int count;
    struct circular_header_linkedlist* link;
};

typedef struct header_node header;
typedef struct circular_header_linkedlist node;

header* start;

void insert_chnode();
void delete_chnode();
void display_count();

int main()
{
    start = (header*)malloc(sizeof(header));
    start->count=0;
    start->link=NULL;

    unsigned int option=0;
    while(1)
    {
        system("cls");
        printf("=============================================\n");
        printf("                  MAIN MENU\n");
        printf("=============================================\n");
        printf("[1]Insert Node\n");
        printf("[2]Delete Node\n");
        printf("[3] display count \n");
        printf("[4]Exit\n");
        scanf("%u",&option);
        switch(option)
        {
        case 1:
            insert_chnode();
            break;
        case 2:
            delete_chnode();
            break;
        case 3:
            display_count();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
        }
        system("pause");
    }
    return 0;
}

void insert_chnode()
{
    node* ptr =  (node*)malloc(sizeof(node));
    ptr->link=NULL;
    if(ptr==NULL)
    {
        printf("Error creating node\n");
        return;
    }
    printf("===================================\n");
    printf("          INSERT NODE\n");
    printf("===================================\n");
    printf("Enter the name [max limit 30 characters]\n");
    fflush(stdin);
    scanf("%[^\n]",ptr->name);
    printf("Enter the roll Number\n");
    fflush(stdin);
    scanf("%u",&ptr->roll_no);
    if(start->link == NULL)
    {
        start->link = ptr;
        ptr->link=ptr;
    }
    else
    {
        node* temp = start->link;
        while(temp->link != start->link)
        {
            temp = temp->link;
        }
        ptr->link = start->link;
        start->link = ptr;
        temp->link = start->link;
    }
    start->count += 1;
}

void display_cnode(node* ptr)
{
    printf("Name    : %s\n",ptr->name);
    printf("Roll No : %u\n",ptr->roll_no);
}

void delete_chnode()
{
    if(start->link == NULL)
    {
        printf("Nothing to delete!\n");
        return;
    }
    if( start->link == start->link->link)
    {
        display_cnode(start->link);
        free(start->link);
        start->link = NULL;
        start->count = 0;
        printf("The node is delete successfully!\n");
    }
    else
    {
        node* temp = start->link;
        while(temp->link != start->link)
        {
            temp=temp->link;
        }
        display_cnode(start->link);
        temp->link = start->link->link;
        free(start->link);
        printf("The node is delete successfully!\n");
        start->link = temp->link;
        start->count -= 1;
    }
}

    void display_count()
    {
        printf("There are %u nodes in the memory\n",start->count);
    }

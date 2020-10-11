#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

struct date
{
    unsigned short int day;
    unsigned short int month;
    unsigned short int year;
};

struct doubly_linked_list
{
    unsigned int aadhar_no;
    char name[20];
    char gender;
    char fathers_name[20];
    char mothers_name[20];
    struct date dob;
    struct doubly_linked_list* next;
    struct doubly_linked_list* prev;
};

typedef struct doubly_linked_list dnode;
dnode* start=NULL,*end=NULL;

void details_dnode(dnode*);
void insert_dnode();
void delete_dnode();
void generate_report();
void update_dnode();
void search_dnode();


int main()
{
    unsigned int choice = 0;
    while(1)
    {
        system("cls");
        printf("=============================================\n");
        printf("                   MAIN MENU\n");
        printf("=============================================\n");
        printf("[1]Insert a record\n");
        printf("[2]Delete a record\n");
        printf("[3]Update a record\n");
        printf("[4]Search a record\n");
        printf("[5]Generate Report\n");
        printf("[6]Exit\n");
        scanf("%u",&choice);
        switch(choice)
        {
        case 1:
            insert_dnode();
            break;
        case 2:
            delete_dnode();
            break;
        case 3:
            update_dnode();
            break;
        case 4:
            search_dnode();
            break;
        case 5:
            generate_report();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice !\n");
        }
        system("pause");
    }
    return 0;
}

void details_dnode(dnode* ptr)
{
    printf("============================================\n");
    printf("                   DETAILS\n");
    printf("============================================\n");
    if(ptr==NULL)
    {
        printf("Nothing to show details!");
        return;
    }
    printf("Aadhar Number :%u\n",ptr->aadhar_no);
    printf("Name          :%-20s\n",ptr->name);
    printf("Gender        :%c\n",ptr->gender);
    printf("Fathers name  :%-20s\n",ptr->fathers_name);
    printf("Mothers name  :%-20s\n",ptr->mothers_name);
    printf("Date of Birth :%2hu/%2hu/%4hu\n",ptr->dob.day,ptr->dob.month,ptr->dob.year);
}

void insert_dnode()
{
    printf("============================================\n");
    printf("                 ENTER DETAILS\n");
    printf("============================================\n");
    dnode* ptr = (dnode*)malloc(sizeof(dnode));
    ptr->next=NULL;
    ptr->prev=NULL;
    printf("Enter the Aadhar Number\n");
    fflush(stdin);
    scanf("%u",&ptr->aadhar_no);
    printf("Enter the Name\n");
    fflush(stdin);
    scanf("%[^\n]",ptr->name);
    printf("Enter the Gender M for Male/F for Female/O for Other\n");
    fflush(stdin);
    scanf("%c",&ptr->gender);
    printf("Enter the Fathers Name\n");
    fflush(stdin);
    scanf("%[^\n]",ptr->fathers_name);
    printf("Enter the Mothers Name\n");
    fflush(stdin);
    scanf("%[^\n]",ptr->mothers_name);
    printf("Enter Date of Birth dd mm yyyy\n");
    fflush(stdin);
    scanf("%hu %hu %hu",&ptr->dob.day,&ptr->dob.month,&ptr->dob.year);
    if(start==NULL)
    {
        start = ptr;
        end = ptr;
    }
    else if(start->aadhar_no == ptr->aadhar_no || end->aadhar_no == ptr->aadhar_no)
    {
        printf("Duplicate Aadhar Number couldn't Insert the record!\n");
        free(ptr);
        return;
    }
    else if(ptr->aadhar_no<start->aadhar_no)
    {
        ptr->next = start;
        start->prev = ptr;
        start = ptr;
    }
    else if(ptr->aadhar_no>end->aadhar_no)
    {
        end->next = ptr;
        ptr->prev = end;
        end = ptr;
    }
    else
    {
        dnode* temp_ptr = start->next;
        while(temp_ptr->aadhar_no < ptr->aadhar_no)
        {
            temp_ptr = temp_ptr->next;
        }
        if(temp_ptr->aadhar_no == ptr->aadhar_no)
        {
            printf("Duplicate Aadhar Number couldn't Insert the record!\n");
            free(ptr);
            return;
        }
        temp_ptr->prev->next = ptr;
        ptr->prev = temp_ptr->prev;
        temp_ptr->prev = ptr;
        ptr->next = temp_ptr;
    }
}

void delete_dnode()
{
    printf("============================================\n");
    printf("                 DELETE RECORD\n");
    printf("============================================\n");
    if(start==NULL)
    {
        printf("Nothing to Delete!\n");
        return;
    }
    unsigned int delete_aadhar_number=0;
    printf("Enter the Aadhar number\n");
    fflush(stdin);
    scanf("%u",&delete_aadhar_number);
    if(start->aadhar_no == delete_aadhar_number)
    {
        char choice='n';
        details_dnode(start);
        printf("Do you want to delete the record Y/N\n");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice == 'y' || choice == 'Y')
        {
            if(start == end)
            {
                free(start);
                start=NULL;
                end=NULL;
            }
            else
            {
                start = start->next;
                free(start->prev);
                start->prev=NULL;
            }
            printf("Record deleted successfully!\n");
        }
        return;
    }
    else if(end->aadhar_no == delete_aadhar_number)
    {
        char choice='n';
        details_dnode(end);
        printf("Do you want to delete the record Y/N\n");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice == 'y' || choice == 'Y')
        {
            end =  end->prev;
            free(end->next);
            end->next=NULL;
            printf("Record deleted successfully!\n");
        }
        return;
    }
    else
    {
        dnode* temp_ptr = start->next;
        int flag = 0;
        while(temp_ptr!=NULL)
        {
            if(temp_ptr->aadhar_no == delete_aadhar_number)
            {
                flag=1;
                break;
            }
            temp_ptr = temp_ptr->next;
        }
        if(flag==1)
        {
            char choice='n';
            details_dnode(temp_ptr);
            printf("Do you want to delete the record Y/N\n");
            fflush(stdin);
            scanf("%c",&choice);
            if(choice == 'y' || choice == 'Y')
            {
                temp_ptr->prev->next = temp_ptr->next;
                temp_ptr->next->prev = temp_ptr->prev;
                free(temp_ptr);
                printf("Record deleted successfully!\n");
            }
            return;
        }
        else
        {
            printf("No record found to delete!\n");
        }
    }
}

void update_dnode()
{
    printf("============================================\n");
    printf("                 UPDATE RECORD\n");
    printf("============================================\n");
    if(start==NULL)
    {
        printf("Nothing to Update!\n");
        return;
    }
    unsigned int update_aadhar_no=0;
    dnode* temp_ptr = NULL;
    printf("Enter the Aadhar number\n");
    fflush(stdin);
    scanf("%u",&update_aadhar_no);
    if(start->aadhar_no == update_aadhar_no)
    {
        temp_ptr = start;
    }
    else if(end->aadhar_no == update_aadhar_no)
    {
        temp_ptr = end;
    }
    else
    {
        temp_ptr = start->next;
        int flag=0;
        while(temp_ptr != NULL)
        {
            if(temp_ptr->aadhar_no==update_aadhar_no)
            {
                flag=1;
                break;
            }
            temp_ptr = temp_ptr->next;
        }
        if(flag==0)
        {
            printf("No Record Found to Update!\n");
            return;
        }
    }
    details_dnode(temp_ptr);
    int option = 0;
    while(1)
    {
        option = 0;
        printf("[1]Update Name\n");
        printf("[2]Update Gender\n");
        printf("[3]Update Fathers Name\n");
        printf("[4]Update Mothers Name\n");
        printf("[5]Update Date of Birth\n");
        printf("[6]Exit\n");
        fflush(stdin);
        scanf("%u",&option);
        switch(option)
        {
        case 1:
        {
            printf("Enter the new Name\n");
            fflush(stdin);
            scanf("%[^\n]",temp_ptr->name);
            printf("The Name updated successfully!\n");
        }
        break;
        case 2:
        {
            printf("Enter the new Gender M for Male/F for Female/O for Other\n");
            fflush(stdin);
            scanf("%c",&temp_ptr->gender);
            printf("The Gender updated successfully!\n");
        }
        break;
        case 3:
        {
            printf("Enter the new Fathers Name\n");
            fflush(stdin);
            scanf("%[^\n]",temp_ptr->fathers_name);
            printf("The Fathers Name updated successfully!\n");
        }
        break;
        case 4:
        {
            printf("Enter the new Mothers Name\n");
            fflush(stdin);
            scanf("%[^\n]",temp_ptr->mothers_name);
            printf("The Mothers Name updated successfully!\n");
        }
        break;
        case 5:
        {
            printf("Enter new Date of Birth dd mm yyyy\n");
            fflush(stdin);
            scanf("%hu %hu %hu",&temp_ptr->dob.day,&temp_ptr->dob.month,&temp_ptr->dob.year);
            printf("The Date of Birth updated successfully!\n");
        }
        break;
        case 6:
        {
            return;
        }
        break;
        default:
            printf("Invalid Choice!");
        }
    }
}


void search_dnode()
{
    printf("============================================\n");
    printf("                 SEARCH RECORD\n");
    printf("============================================\n");
    if(start==NULL)
    {
        printf("Nothing to Search!\n");
        return;
    }
    int option=0;
    printf("[1]Search by Aadhar Number\n");
    printf("[2]Search by Name\n");
    printf("[3]Search by Fathers Name\n");
    printf("[4]Search by Mothers Name\n");
    printf("[5]Search by Date of Birth\n");
    printf("[6]Exit\n");
    fflush(stdin);
    scanf("%d",&option);
    switch(option)
    {
    case 1:
    {
        unsigned int search_aadhar_number=0;
        printf("Enter the aadhar number\n");
        fflush(stdin);
        scanf("%u",&search_aadhar_number);
        if(start->aadhar_no==search_aadhar_number)
        {
            details_dnode(start);
        }
        else if(end->aadhar_no==search_aadhar_number)
        {
            details_dnode(end);
        }
        else
        {
            dnode* temp_ptr = start->next;
            int flag=0;
            while(temp_ptr!=NULL)
            {
                if(temp_ptr->aadhar_no==search_aadhar_number)
                {
                    details_dnode(temp_ptr);
                    flag=1;
                    break;
                }
                temp_ptr = temp_ptr->next;
            }
            if(flag==0)
            {
                printf("No record found!");
            }
        }
    }
    break;
    case 2:
    {
        char search_name[20];
        printf("Enter the Name\n");
        fflush(stdin);
        scanf("%[^\n]",search_name);
        dnode* temp_ptr = start;
        int flag=0;
        while(temp_ptr!=NULL)
        {
            if(strcmp(temp_ptr->name,search_name)==0)
            {
                details_dnode(temp_ptr);
                flag=1;
            }
            temp_ptr = temp_ptr->next;
        }
        if(flag==0)
        {
            printf("No records found!\n");
        }
    }
    break;
    case 3:
    {
        char search_fathers_name[20];
        printf("Enter the fathers name\n");
        fflush(stdin);
        scanf("%[^\n]",search_fathers_name);
        dnode* temp_ptr = start;
        int flag=0;
        while(temp_ptr!=NULL)
        {
            if(strcmp(temp_ptr->name,search_fathers_name)==0)
            {
                details_dnode(temp_ptr);
                flag=1;
            }
            temp_ptr = temp_ptr->next;
        }
        if(flag==0)
        {
            printf("No records found!\n");
        }
    }
    break;
    case 4:
    {
        char search_mothers_name[20];
        printf("Enter the mothers name\n");
        fflush(stdin);
        scanf("%[^\n]",search_mothers_name);
        dnode* temp_ptr = start;
        int flag=0;
        while(temp_ptr!=NULL)
        {
            if(strcmp(temp_ptr->name,search_mothers_name)==0)
            {
                details_dnode(temp_ptr);
                flag=1;
            }
            temp_ptr = temp_ptr->next;
        }
        if(flag==0)
        {
            printf("No records found!\n");
        }
    }
    break;
    case 5:
    {
        struct date search_dob;
        printf("Enter the date of birth dd mm yyyy\n");
        fflush(stdin);
        scanf("%hu %hu %hu",&search_dob.day,&search_dob.month,&search_dob.year);
        dnode* temp_ptr = start;
        int flag=0;
        while(temp_ptr!=NULL)
        {
            if(search_dob.day == temp_ptr->dob.day && search_dob.month == temp_ptr->dob.month && search_dob.year== temp_ptr->dob.year)
            {
                details_dnode(temp_ptr);
                flag=1;
            }
            temp_ptr = temp_ptr->next;
        }
        if(flag==0)
        {
            printf("No records found!\n");
        }
    }
    break;
    case 6:
        return;
        break;
    default:
        printf("Invalid Choice!\n");
    }
}

void generate_report()
{
    printf("============================================\n");
    printf("                 GENERATE REPORT\n");
    printf("============================================\n");
    if(start==NULL)
    {
        printf("Nothing to generate report\n");
        return;
    }
    int option=0;
    printf("[1]List by Aadhar Number\n");
    printf("[2]List by Name\n");
    printf("[3]List by Date of Birth\n");
    printf("[4]List by Gender\n");
    printf("[5]Exit\n");
    fflush(stdin);
    scanf("%d",&option);
    switch(option)
    {
    case 1:
    {
        unsigned int report_aadhar_number=0;
        printf("Enter the aadhar number\n");
        fflush(stdin);
        scanf("%u",&report_aadhar_number);
        if(start->aadhar_no==report_aadhar_number)
        {
            details_dnode(start);
        }
        else if(end->aadhar_no==report_aadhar_number)
        {
            details_dnode(end);
        }
        else
        {
            int flag=0;
            dnode* temp_ptr = start->next;
            while(temp_ptr!=NULL)
            {
                if(temp_ptr->aadhar_no==report_aadhar_number)
                {
                    details_dnode(temp_ptr);
                    flag=1;
                    break;
                }
                temp_ptr = temp_ptr->next;
            }
            if(flag==0)
            {
                printf("No record found to generate report!\n");
            }
        }
    }
    break;
    case 2:
    {
        char report_name[20];
        printf("Enter the name\n");
        fflush(stdin);
        scanf("%[^\n]",report_name);
        dnode* temp_start=NULL,*temp_ptr=start;
        while(temp_ptr!=NULL)
        {
            if(strcmp(temp_ptr->name,report_name)==0)
            {
                dnode* ptr = (dnode*)malloc(sizeof(dnode));
                if(temp_start==NULL)
                {
                    *ptr = *temp_ptr;
                    temp_start = ptr;
                    temp_start->next=NULL;
                    temp_start->prev=NULL;
                }
                else
                {
                    *ptr = *temp_ptr;
                    ptr->prev = NULL;
                    ptr->next = temp_start;
                    temp_start->prev = ptr;
                    temp_start = ptr;
                }
            }
            temp_ptr = temp_ptr->next;
        }
        printf("----------------------------------------------------------------------------\n");
        printf("Aadhar Number Name                 Gender Date of Birth\n");
        printf("----------------------------------------------------------------------------\n");
        dnode* ttemp_ptr = temp_start;
        while(ttemp_ptr!=NULL)
        {
            printf("%-12u  %-20s %c      %-2hu/%-2hu/%-4hu\n",ttemp_ptr->aadhar_no,ttemp_ptr->name,ttemp_ptr->gender,ttemp_ptr->dob.day,ttemp_ptr->dob.month,ttemp_ptr->dob.year);
            ttemp_ptr =  ttemp_ptr->next;
        }
    }
    break;
    case 3:
    {
        struct date report_dob;
        printf("Enter the date of birth dd mm yyyy\n");
        fflush(stdin);
        scanf("%hu %hu %hu",&report_dob.day,&report_dob.month,&report_dob.year);
        dnode* temp_start=NULL,*temp_ptr=start;
        while(temp_ptr!=NULL)
        {
            if(report_dob.day == temp_ptr->dob.day && report_dob.month == temp_ptr->dob.month && report_dob.year == temp_ptr->dob.year)
            {
                dnode* ptr = (dnode*)malloc(sizeof(dnode));
                if(temp_start==NULL)
                {
                    *ptr = *temp_ptr;
                    temp_start = ptr;
                    temp_start->next=NULL;
                    temp_start->prev=NULL;
                }
                else
                {
                    *ptr = *temp_ptr;
                    ptr->prev = NULL;
                    ptr->next = temp_start;
                    temp_start->prev = ptr;
                    temp_start = ptr;
                }
            }
            temp_ptr = temp_ptr->next;
        }
        printf("--------------------------------------------------------------------------\n");
        printf("Aadhar Number Name                 Gender Date of Birth\n");
        printf("--------------------------------------------------------------------------\n");
        dnode* ttemp_ptr = temp_start;
        while(ttemp_ptr!=NULL)
        {
            printf("%-12u  %-20s %c      %-2hu/%-2hu/%-4hu\n",ttemp_ptr->aadhar_no,ttemp_ptr->name,ttemp_ptr->gender,ttemp_ptr->dob.day,ttemp_ptr->dob.month,ttemp_ptr->dob.year);
            ttemp_ptr =  ttemp_ptr->next;
        }
    }
    break;
    case 4:
    {
        char report_gender;
        printf("Enter the gender M for Male/F for Female/O for Other\n");
        fflush(stdin);
        scanf("%c",&report_gender);
        dnode* temp_start=NULL,*temp_ptr=start;
        while(temp_ptr!=NULL)
        {
            if(temp_ptr->gender == report_gender)
            {
                dnode* ptr = (dnode*)malloc(sizeof(dnode));
                if(temp_start==NULL)
                {
                    *ptr = *temp_ptr;
                    temp_start = ptr;
                    temp_start->next=NULL;
                    temp_start->prev=NULL;
                }
                else
                {
                    *ptr = *temp_ptr;
                    ptr->prev = NULL;
                    ptr->next = temp_start;
                    temp_start->prev = ptr;
                    temp_start = ptr;
                }
            }
            temp_ptr = temp_ptr->next;
        }
        printf("--------------------------------------------------------------------------\n");
        printf("Aadhar Number Name                 Gender Date of Birth\n");
        printf("--------------------------------------------------------------------------\n");
        dnode* ttemp_ptr = temp_start;
        while(ttemp_ptr!=NULL)
        {
            printf("%-12u  %-20s %c      %-2hu/%-2hu/%-4hu\n",ttemp_ptr->aadhar_no,ttemp_ptr->name,ttemp_ptr->gender,ttemp_ptr->dob.day,ttemp_ptr->dob.month,ttemp_ptr->dob.year);
            ttemp_ptr =  ttemp_ptr->next;
        }
    }
    break;
    case 5:
        return;
        break;
    default:
        printf("Invalid choice!\n");
    }
}

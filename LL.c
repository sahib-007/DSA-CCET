/*
Date OF ASSIGNMENT 04/08/2020
DATE OF SUBMISSION 07/09/2020
Problem 1: Write a program which should manage record
of your class. The attributes of a record are as follows-
1. Roll No ( As a primary key)
2. Students Name
3. Father’s Name
4. Mother’s Name
5. Class
6. Semester
7. Branch
8. Address
a. Home/House No
b. Street Name
c. City
d. State
e. Country
The program must contain the following
methods/functions
(i) Input/ add a record in the data list/data base/Data
Array/Record Array
(ii) Delete a record from the data list/data base/Data
Array/Record Array
(iii) Search a Record from the data list/data base/Data
Array/Record Array
(iv) Display the records of all the students belong to
particular city/State/Country
(v) Generate report as per requirements

List of methods
1. User Interface
2. Input/Add a Record to data list
3. Delete a record from data list
4. Search based on
(i) City Name
(ii) State Name
(iii) Country Name
5. Generate Report as per the requirements
*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

struct address
{
    unsigned int house_no;
    char street[30];
    char city[24];
    char state[25];
    char country[25];
};

struct record
{
    unsigned int roll_no;
    char student_name[25];
    char fathers_name[25];
    char mothers_name[25];
    char class[15];
    unsigned int semester;
    char branch[25];
    struct address student_address;
};

struct record records[100];
const int size = 100;
int count=-1;

void details_record(struct record*);
void insert_record();
void delete_record();
void search_record();
void display_record();
void generate_report();

int main()
{
    int option=0;
    while(1)
    {
        system("cls");
        printf("=======================================================\n");
        printf("                       MAIN MENU                       \n");
        printf("=======================================================\n");
        printf("press [1] for Add Record\n");
        printf("press [2] for Delete Record\n");
        printf("press [3] for Search Record\n");
        printf("press [4] for Display Record\n");
        printf("press [5] for Generate Report\n");
        printf("press [6] for Exit\n");
        printf("::");
        fflush(stdin);
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            insert_record();
            break;
        case 2:
            delete_record();
            break;
        case 3:
            search_record();
            break;
        case 4:
            display_record();
            break;
        case 5:
           generate_report();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("sorry Invalid Option!\n");
        }
        system("pause");
    }
    return 0;
}

void details_record(struct record* r_record)
{
    printf("================================================\n");
    printf("                   STUDENT DETAILS              \n");
    printf("================================================\n");
    printf("Student Roll No. :%u\n",r_record->roll_no);
    printf("Student Name     :%20s\n",r_record->student_name);
    printf("Fathers Name     :%20s\n",r_record->mothers_name);
    printf("Mothers Name     :%20s\n",r_record->fathers_name);
    printf("Class            :%s\n",r_record->class);
    printf("Semester         :%u\n",r_record->semester);
    printf("Branch           :%s\n",r_record->branch);
    printf("Address          :\n");
    printf("House No.        :%u\n",r_record->student_address.house_no);
    printf("Street Name      :%s\n",r_record->student_address.street);
    printf("City             :%s\n",r_record->student_address.city);
    printf("State            :%s\n",r_record->student_address.state);
    printf("Country          :%s\n",r_record->student_address.country);
}

void insert_record()
{
    if(count == size-1)
    {
        printf("ERROR: Creating New Record!\n");
        return;
    }
    count += 1;
    printf("================================================\n");
    printf("                PLEASE  ENTER STUDENT DETAILS   \n");
    printf("================================================\n");
    printf("Enter the student roll no. [Digits]\n");
    fflush(stdin);
    scanf("%u",&records[count].roll_no);
    printf("Enter the student name\n");
    fflush(stdin);
    scanf("%20[^\n]",records[count].student_name);
    printf("Enter the student fathers name\n");
    fflush(stdin);
    scanf("%20[^\n]",records[count].fathers_name);
    printf("Enter the student mothers name\n");
    fflush(stdin);
    scanf("%20[^\n]",records[count].mothers_name);
    printf("Enter the class\n");
    fflush(stdin);
    scanf("%10[^\n]",records[count].class);
    printf("Enter the semester [digit]\n");
    fflush(stdin);
    scanf("%u",&records[count].semester);
    printf("Enter the branch\n");
    fflush(stdin);
    scanf("%20[^\n]",records[count].branch);
    printf("Enter the address : \n");
    printf("Enter the house number\n");
    fflush(stdin);
    scanf("%u",&records[count].student_address.house_no);
    printf("Enter the street name\n");
    fflush(stdin);
    scanf("%30[^\n]",records[count].student_address.street);
    printf("Enter the city name\n");
    fflush(stdin);
    scanf("%20[^\n]",records[count].student_address.city);
    printf("Enter the state name\n");
    fflush(stdin);
    scanf("%20[^\n]",records[count].student_address.state);
    printf("Enter the country name\n");
    fflush(stdin);
    scanf("%20[^\n]",records[count].student_address.country);
}

void delete_record()
{
    printf("================================================\n");
    printf("                    DELETE RECORD               \n");
    printf("================================================\n");
    if(count==-1)
    {
        printf("sorry Nothing to delete!\n");
        return;
    }
    unsigned int delete_rollno=0;
    printf("Enter the student roll number\n");
    fflush(stdin);
    scanf("%u",&delete_rollno);
    int flag=-1;
    for(int i=0; i<=count; i++)
    {
        if(records[i].roll_no==delete_rollno)
        {
            details_record(&records[i]);
            flag=i;
            break;
        }

    }
    if(flag==-1)
    {
        printf("No Record Found!\n");
    }
    else
    {
        char choice='n';
        printf("Do you want to delete the record Y/N?\n");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice == 'Y' || choice == 'y')
        {
            if(count == flag)
            {
                count -= 1;
            }
        }
        else
        {
            for(int i=flag; i<count; i++)
            {
                records[i] = records[i+1];
            }
            count -= 1;
        }
    }
}


void search_record()
{
    printf("================================================\n");
    printf("                    SEARCH RECORD               \n");
    printf("================================================\n");
    if(count==-1)
    {
        printf("Nothing to search!\n");
        return;
    }
    unsigned int search_rollno=0;
    printf("Enter the roll number\n");
    fflush(stdin);
    scanf("%u",&search_rollno);
    int flag=0;
    for(int i=0;i<=count;i++)
    {
        if(search_rollno == records[i].roll_no)
        {
            details_record(&records[i]);
            flag +=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("sorry No record found!\n");
    }
}

void display_record()
{
    printf("================================================\n");
    printf("                    DISPLAY RECORD              \n");
    printf("================================================\n");
    if(count == -1)
    {
        printf("Nothing to display!\n");
        return;
    }
    unsigned int option=0;
    printf("press [1] for Display All Record\n");
    printf("press [2] for Display by City\n");
    printf("press [3] for Display by State\n");
    printf("press [4] for Display by country\n");
    printf("press [5] for Exit\n");
    fflush(stdin);
    scanf("%u",&option);
    switch(option)
    {
    case 1:
    {
        for(int i=0; i<=count; i++)
        {
            details_record(&records[i]);
        }
    }
    break;
    case 2:
    {
        char display_city[20];
        printf("please Enter the city name\n");
        fflush(stdin);
        scanf("%[^\n]",display_city);
        for(int i=0; i<=count; i++)
        {
            if(strcmp(records[i].student_address.city,display_city)==0)
            {
                details_record(&records[i]);
            }
        }
    }
    break;
    case 3:
    {
        char display_state[20];
        printf("Enter the state name\n");
        fflush(stdin);
        scanf("%[^\n]",display_state);
        for(int i=0; i<=count; i++)
        {
            if(strcmp(records[i].student_address.state,display_state)==0)
            {
                details_record(&records[i]);
            }
        }
    }
    break;
    case 4:
    {
        char display_country[20];
        printf("Enter the country name\n");
        fflush(stdin);
        scanf("%[^\n]",display_country);
        for(int i=0; i<=count; i++)
        {
            if(strcmp(records[i].student_address.country,display_country)==0)
            {
                details_record(&records[i]);
            }
        }
    }
    break;
    case 5:
        return;
        break;
    default:
        printf("sorry Invalid choice!\n");
    }
}

void generate_report()
{
    printf("================================================\n");
    printf("                  GENERATE RECORD\n");
    printf("================================================\n");
    if(count==-1)
    {
        printf("Nothing to generate report!\n");
        return;
    }
    printf("[1]List by Roll No\n");
    printf("[2]List by Class\n");
    printf("[3]List by Semester\n");
    printf("[4]List by Branch\n");
    printf("[5]List by City\n");
    printf("[6]List by State\n");
    printf("[7]List by Country\n");
    printf("[8]Exit\n");
    int option=0;
    fflush(stdin);
    scanf("%d",&option);
    switch(option)
    {
    case 1:
    {
        unsigned int report_rollno=0;
        printf("Enter the roll number\n");
        fflush(stdin);
        scanf("%u",&report_rollno);
        for(int i=0; i<=count; i++)
        {
            if(report_rollno==records[i].roll_no)
            {
                details_record(&records[i]);
                break;
            }
        }
    }
    break;
    case 2:
    {
        char report_class[10];
        printf("Enter the class\n");
        fflush(stdin);
        scanf("%[^\n]",report_class);
        printf("-----------------------------------------------------------\n");
        printf("Roll No Name                 Class      Semester Branch\n");
        printf("-----------------------------------------------------------\n");
        for(int i=0; i<=count; i++)
        {
            if(strcmp(report_class,records[i].class)==0)
            {
                printf("%.5u   %-20s %-10s %-6u   %-20s",records[i].roll_no,records[i].student_name,records[i].class,records[i].semester,records[i].branch);
            }
        }
    }
    break;
    case 3:
    {
        unsigned int report_semester;
        printf("Enter the semester\n");
        fflush(stdin);
        scanf("%u",&report_semester);
        printf("-----------------------------------------------------------\n");
        printf("Roll No Name                 Class      Semester Branch\n");
        printf("-----------------------------------------------------------\n");
        for(int i=0; i<=count; i++)
        {
            if(report_semester==records[i].semester)
            {
                printf("%.5u   %-20s %-10s %-6u   %-20s",records[i].roll_no,records[i].student_name,records[i].class,records[i].semester,records[i].branch);
            }
        }
    }
    break;
    case 4:
    {
        char report_branch[20];
        printf("Enter the branch\n");
        fflush(stdin);
        scanf("%[^\n]",report_branch);
        printf("-----------------------------------------------------------\n");
        printf("Roll No Name                 Class      Semester Branch\n");
        printf("-----------------------------------------------------------\n");
        for(int i=0; i<=count; i++)
        {
            if(strcmp(report_branch,records[i].branch)==0)
            {
                printf("%.5u   %-20s %-10s %-6u   %-20s",records[i].roll_no,records[i].student_name,records[i].class,records[i].semester,records[i].branch);
            }
        }
    }
    break;
    case 5:
    {
        char report_city[20];
        printf("Enter the city\n");
        fflush(stdin);
        scanf("%[^\n]",report_city);
        printf("-----------------------------------------------------------\n");
        printf("Roll No Name                 Class      Semester Branch\n");
        printf("-----------------------------------------------------------\n");
        for(int i=0; i<=count; i++)
        {
            if(strcmp(report_city,records[i].student_address.city)==0)
            {
                printf("%.5u   %-20s %-10s %-6u   %-20s",records[i].roll_no,records[i].student_name,records[i].class,records[i].semester,records[i].branch);
            }

        }
    }
    break;
    case 6:
    {
        char report_state[20];
        printf("Enter the state\n");
        fflush(stdin);
        scanf("%[^\n]",report_state);
        printf("-----------------------------------------------------------\n");
        printf("Roll No Name                 Class      Semester Branch\n");
        printf("-----------------------------------------------------------\n");
        for(int i=0; i<=count; i++)
        {
            if(strcmp(report_state,records[i].student_address.state)==0)
            {
                printf("%.5u   %-20s %-10s %-6u   %-20s",records[i].roll_no,records[i].student_name,records[i].class,records[i].semester,records[i].branch);
            }

        }
    }
    break;
    case 7:
    {
        char report_country[20];
        printf("Enter the country\n");
        fflush(stdin);
        scanf("%[^\n]",report_country);
        printf("-----------------------------------------------------------\n");
        printf("Roll No Name                 Class      Semester Branch\n");
        printf("-----------------------------------------------------------\n");
        for(int i=0; i<=count; i++)
        {
            if(strcmp(report_country,records[i].student_address.country)==0)
            {
                printf("%.5u   %-20s %-10s %-6u   %-20s",records[i].roll_no,records[i].student_name,records[i].class,records[i].semester,records[i].branch);
            }

        }
    }
    break;
    case 8:
        return;
    break;
    default:
        printf("Invalid option!\n");
    }
}

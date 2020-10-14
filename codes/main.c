#include<stdio.h>
#include<math.h>
#include<time.h>
//#include<sys/utsname.h>

int arr[20],count;
char t;

int main()
{
    int n,i,j;
    void nqueen(int row,int n);
    printf("Enter the side length of board\n");
    scanf("%d",&n);
    clock_t t;
    t=clock();
    nqueen(1,n);
    t=clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n\nNumber of solutions is : %d",count);
    printf("\nThe program took %f seconds to execute \n\n", time_taken);
    printf("System configuration is:\n");
    printf("Processor: \t\tIntel(R) Core(TM) i5-4210U CPU @ 1.70GHz 2.40GHz\n");
    printf("Installed memory(RAM):\t8GB(7.89GB usable)\n");
    printf("System type: \t\t64-bit Operating System, x64-based processor\n");
    return 0;
}
//function to check for proper positioning of queen
void nqueen(int row,int n)
{
    int solution=0,column;
    for(column=1;column<=n;column++)
    {
        if(place(row,column))
        {
            arr[row]=column; //no conflicts so place queen
            if(row==n) //dead end
                show(n); //printing the arr configuration
            else //try queen with next position
                nqueen(row+1,n);
        }
    }
}
//function for printing the solution
void show(int n)
{
    int i,j;
    printf("\n\nSolution %d:",++count);
    for(i=1;i<=n;i++)
    {
       printf("\n\n");
        for(j=1;j<=n;j++) //for nxn arr
        {
            if(arr[i]==j)
            {
                printf("\tQ"); //queen at i,j position
            }
            else
                printf("\tx"); //empty slot
        }
    }
}
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
    int i;
    for(i=1;i<=row-1;i++)
    {
    //checking column and digonal conflicts
        if(arr[i]==column)
            return 0;
        else
            if(abs(arr[i]-column)==abs(i-row))
                return 0;
    }
    return 1; //no conflicts
}

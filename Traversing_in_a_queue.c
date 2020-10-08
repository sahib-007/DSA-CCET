#include <stdio.h>

void traverse(int queue[],int front,int rear)
{
int i;
if (front == rear) {
printf("\nQueue is Empty\n");
return;
}
for (int i = 0; i < rear; i++)
{
    printf(" %d  ",queue[i]);
}
return; }

int main()
{
    int queue[]={3,45,62,12,34};
    int front=0;
    int rear =sizeof(queue) / sizeof(queue[0]);
    traverse(queue,front,rear);
    return 0;
}

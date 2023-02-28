#include<stdio.h>
#include<stdlib.h>
# define MAX 4
int queue[MAX];
int f=0;
int r=0;

int isempty()
{
    if (r==f)
    return 1;
    else
    return 0;
}

int isfull()
{
    if (((r+1)%MAX)==f)
    return 1;
    else
    return 0;
}

void enqueue(int a)
{

    if(isfull()==1)
    {
        printf("\nOverflow...");
    }

    else
    {
        r=(r+1)%MAX;
        queue[r]=a;
        printf("\nPushed successfully...");
    }
}

void dequeue()
{
    if(isempty()==1)
    printf("\nUnderflow...");

    else
    {
        f=(f+1)%MAX;
        printf("\nDeleted Successfully...");
    }
}

void traversal()
{
    for (int i = f+1; i <MAX; i++)
        printf("\n%d", queue[i]);
}

void main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    traversal();
    dequeue();
    dequeue();
    enqueue(5);
    enqueue(10);
    enqueue(20);
    traversal();
}


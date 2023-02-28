#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
void enqueue(struct queue *ptr, int a)
{
    if (ptr->f == (ptr->r+1)%ptr->size)
        printf("\nQueue overflow\n");
    else
    {
        ptr->r=(ptr->r+1)%(ptr->size);
        ptr->arr[ptr->r] = a;
        printf("\nvalue pushed successfully\n");
    }
}
void dequeue(struct queue *ptr)
{
    int val;
    if (ptr->r == ptr->f)
        printf("\nQueue underflow\n");
    else
    {
        val = ptr->arr[ptr->f+1];
       ptr->f= (ptr->f+1)%(ptr->size);
        printf("\n%d popped successfully...\n", val);
    }
}
void display(struct queue *ptr)
{
    for (int i = ptr->f; i < ptr->size; i++)
        printf("\n%d\n", ptr->arr[i]);
}

void main()
{
    int i = 0, a;
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 5;
    q->r = 0;
    q->f = 0;
    q->arr = (int *)malloc(sizeof(int));
    while (i < 4)
    {
        printf("\nEnter the value to be pushed...\n");
        scanf("%d", &a);
        enqueue(q, a);
        i++;
    }
    display(q);
    dequeue(q);
   dequeue(q); 
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 6);
    enqueue(q, 6);
    display(q);
}
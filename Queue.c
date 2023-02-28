#include <stdio.h>
#include <stdlib.h>
struct queue  // structure to define queue
{
    int size;  // size 
    int f;  //front
    int r;  // rear point
    int *arr;  //array
};

// Enqueue Function

void enqueue(struct queue *ptr, int a)
{
    if (ptr->r == ptr->size - 1)       // Queue full condition
        printf("\nQueue overflow\n");
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = a;                        // value adding
        printf("\nvalue pushed successfully\n");
    }
}

// Dequeue function

void dequeue(struct queue *ptr)
{
    int val;
    if (ptr->r == ptr->f)       // Queue empty condition
        printf("\nQueue underflow\n");
    else
    {
        val = ptr->arr[ptr->f + 1];    // Delete the value
        ptr->f++;
        printf("\n popped successfully...");
    }
}

// dislay function

void display(struct queue *ptr)
{
    for (int i = ptr->f + 1; i < ptr->size; i++)
        printf("\n%d\n", ptr->arr[i]);
}

void main()
{
    int i = 0, a,b;
    struct queue *q = (struct queue *)malloc(sizeof(struct queue)); 
    printf("Enter the size of queue:");
    scanf("%d",&b);  // taking size of queue from user
    q->size = b;
    q->r = q->f = -1;
    q->arr = (int *)malloc(sizeof(int));
    while (i < b)
    {
        printf("\nEnter the value to be pushed...\n");
        scanf("%d", &a);
        enqueue(q, a);   // enqueue function call
        i++;
    }
    printf("\nBefore dequeing...\n");
    display(q);
    dequeue(q); // dequeue function call
    dequeue(q);
    printf("\nafter dequeue...\n");
    display(q);
}
#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
}; struct node *head=NULL; struct node *tail=NULL;

void enqueue(int val)
{
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    new->next=head;

    if (head==NULL && tail==NULL)
    {
        head=new;
        tail=new;
    }  

    else
    {
        tail->next=new;
        tail=new;
    }  
}

void dequeue()
{
    struct node *ptr = head;
    head=ptr->next;
    tail->next=head;
    free(ptr);
}

void display()
{
    struct node *p = head;
    do
    {
        printf("Element is: %d\n", p->data);
        p = p->next;
    } while (p != head);
}

void main()
{
    enqueue(10);
    enqueue(11);
    enqueue(21);
    enqueue(31);
    display();
    dequeue();
    dequeue();
    display();
    enqueue(20);
    enqueue(22);
    display();
}
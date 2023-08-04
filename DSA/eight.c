// implement queues

#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *array;
};

void create(struct Queue* q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->array=(int *)malloc(q->size*sizeof(int ));
}

void isempty(struct Queue* q)
{
    if(q->front==q->rear)
    printf("The stack is empty");
}

void isfull(struct Queue* q)
{
    if(q->rear==q->size-1)
    printf("The stack is full");
}

void enqueue(struct Queue* q,int data)
{
    q->rear++;
    q->array[q->rear]=data;
}

int dequeue(struct Queue* q)
{
    int x;
    
    q->front++;
    x=q->array[q->front];

    return x;
}

void Display(struct Queue q)
{
    int i;
    
    for(i=q.front+1 ;i<=q.rear ; i++)
    printf(" %d ",q.array[i]);
    
}

int main()
{
    struct Queue q;
    
    create(&q,4);
    
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    
    Display(q);
    
    return 0;
}
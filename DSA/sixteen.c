// doubly linked list 

#include <stdio.h>
#include <stdlib.h>


struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
}*first=NULL;


void create(int arr[],int n)
{
    struct Node *t,*last;
    
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->prev=first->next=NULL;
    last=first;
    
    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
    
}


void Insert(struct Node* p,int pos,int x)
{
    struct Node* t;

    if(pos==0)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        
        first->prev=t;
        first=t;
    }
    
    else
    {
        for(int i=0;i<pos;i++)
        p=p->next;
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        
        t->prev=p;
        t->next=p->next;
        
        if(p->next)
        p->next->prev=t;
        p->next=t;
        
        
    }
}


int Delete(struct Node* p,int index)
{
    struct Node* q;
    int x=0;
    
    if(index==1)
    {
        first=first->next;
        
        if(first)
        first->prev=NULL;
        
        x=p->data;
        free(p);
        
    }
    
    else
    {
        for(int i=0;i<index-1;i++)
        p=p->next;
        p->prev->next=p->prev;
        
        if(p->next)
        p->next->prev=p->prev;
        
        x=p->data;
        free(p);
    }
}

void Display(struct Node* p)
{
    while(p)
    {
        printf(" %d ",p->data);
        p=p->next;
    }
    
    printf("\n");
}


int length(struct Node* p)
{
    int len=0;
    
    while(p)
    {
        len++;
        p=p->next;
    }
    
    return len;
}


int main()
{
    int arr[]={10,20,30,40,50};
    create(arr,5);
    
    Display(first);
}
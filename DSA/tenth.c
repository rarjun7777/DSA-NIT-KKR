// implement single linked list 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* create(int data)
{
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;
    
    return new_node;
}

struct Node* Insertathead(struct Node* head,int data)
{
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=head;
    
    head=new_node;
    
    return head;
}

void Insert(struct Node* p,int pos,int x)
{
    struct Node* head;
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    
    if(pos==0)
    {
        t->next=head;
        head=t;
    }
    
    else
    {
        for(int i=0;i<pos- 1;i++)
            
        p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

struct Node *RSearch(struct Node *p, int key)
{

    if(p==NULL)
    return NULL;
    if(key==p->data)
    return p;

    return RSearch(p->next,key);

}

int isSorted(struct Node *p)
{
    int x = -65536;

    while (p != NULL)
    {
        if (p->data < x)
        return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

int Delete(struct Node *p, int index)
{
    struct Node* head;
    struct Node *q = NULL;
    int i;

    if (index == 1)
    {
        q = head;
        head = head->next;
        free(q);
    }
    
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
    }
}

void Display(struct Node* n)
{
    while(n!=NULL)
    {
        printf(" %d ",n->data);
        n=n->next;
    }
}

int main()
{
    struct Node* head=create(10);
    
    struct Node* second=create(20);
    head->next=second;
    
    struct Node* third=create(30);
    second->next=third;

    
    Display(head);
}
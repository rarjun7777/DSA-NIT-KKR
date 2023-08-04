// reverse a single linked list 


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


struct Node* insertathead(struct Node* head,int data)
{
    struct Node* new_node;
    
    new_node=(struct Node*)malloc(sizeof(struct Node));
    
    
    new_node->data=data;
    new_node->next=head;
    
    head=new_node;
    
    return head;
    
}

void Insert(struct Node *p,int index,int x)
{

 struct Node* head;    
 struct Node *t;
 int i;

 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=x;

 if(index == 0)
 {
 t->next=head;
 head=t;
 }
 
 else
 {
     
 for(i=0;i<index-1;i++)
 p=p->next;
 t->next=p->next;
 p->next=t;

 }


}


struct Node* Reverse(struct Node* head)
{
    struct Node *current,*prev,*next;
    current=head;
    prev=NULL;
    
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    
    return head;
}


void printlinkedlist(struct Node* n)
{
    while(n!=NULL)
    {
        printf(" %d ",n->data);
        n=n->next;
    }
    printf("\n");
}


int main()
{
    struct Node* head=create(10);
     
    struct Node* two=create(11);
    head->next=two;
    struct Node* three=create(12);
    two->next=three;
    struct Node* four=create(13);
    three->next=four;
    
    printlinkedlist(head);
    
    head=Reverse(head);
    
    printlinkedlist(head);


    return 0;
    
}
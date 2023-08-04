// palindrome using stack

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack* create()
{
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->top=-1;
    stack->capacity=100;
    stack->array=(int *)malloc(sizeof(int ));
}

void isempty(int top)
{
    if(top==-1)
    {
        printf("The stack is empty");
    }
}

void isfull(int top)
{
    if(top==99)
    {
        printf("The stack is full");
    }
}

void push(struct Stack* stack,char val)
{
    stack->top++;
    stack->array[stack->top]=val;
}

char pop(struct Stack* stack)
{
    return stack->array[stack->top--];
    return '$';
}

int main()
{
    struct Stack* a=create();
    char name[100]="mom";
    char arjun[100];
    
    int k=strlen(name);
    
    for(int i=0;i<k;i++)
    {
        push(a,name[i]);
    }
    
    for(int i=0;i<k;i++)
    {
        arjun[i]=pop(a);
    }
    
    int result=strcmp(arjun,name);
    
    if(result==0)
    {
        printf("It is a palindrome");
    }
    
    else
    {
        printf("The string is not a palindrome");
    }
}
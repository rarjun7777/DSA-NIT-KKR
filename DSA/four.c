// valid parenthesis

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char push(struct Stack* stack,char val)
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
    
    char name[100]="(())";
    
    int k=strlen(name);
    
    for(int i=0;i<k;i++)
    {
        if(name[i]=='(')
        {
            push(a,name[i]);
        }
        
        else if(name[i]==')')
        {
            if(a->top==-1)
            {
            printf("It is invalid");
            return ;
            }
            
            pop(a);
        }
    }
    
    
    if(a->top==-1)
    {
        printf("It is valid");
    }
    
    else
    {
        printf("It is invalid");
    }
    
    return 0;

}
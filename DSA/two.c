// postfix evaluation

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack* create(unsigned capacity)
{
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->top=-1;
    stack->capacity=capacity;
    stack->array=(int *)malloc(stack->capacity*sizeof(int ));
    
    return stack;
}

void isempty(int top)
{
    if(top==-1)
    printf("The stack is empty");
}

void push(struct Stack* stack,char op)
{
    stack->top++;
    stack->array[stack->top]=op;
}

char pop(struct Stack* stack)
{
    return stack->array[stack->top--];
    return '$';
}


int postfixeval(char exp[])
{
    struct Stack* stack=create(strlen(exp));
    
    for(int i=0;exp[i];i++)
    {
        if(isdigit(exp[i]))
        push(stack,exp[i]-'0');
        
        
        else
        {
            int val1=pop(stack);
            int val2=pop(stack);
            
            switch(exp[i])
            {
                case '+':
                push(stack,val2+val1);
                break;
                case '-':
                push(stack,val2-val1);
                break;
                case '*':
                push(stack,val2*val1);
                break;
                case '/':
                push(stack,val2/val1);
                break;
            }
        }
    }
    
    return pop(stack);
}

int main()
{
    char exp[] = "231*+9-";
    printf("%d", postfixeval(exp));
    return 0;
}


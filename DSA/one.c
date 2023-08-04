// implementation of stacks

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *create()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = 100;
    stack->array = (int *)malloc(sizeof(int));
}

void ismepty(int top)
{
    if (top == -1)
    {
        printf("The stack is empty\n");
    }
}

void isfull(int top)
{
    if (top == 99)
    {
        printf("The stack is full\n");
    }
}

void push(struct Stack *stack, int data)
{
    stack->top++;
    stack->array[stack->top] = data;
}

void pop(struct Stack *stack)
{
    stack->top--;
    for (int i = 0; i <= stack->top; i++)
    {
        printf(" %d  ", stack->array[i]);
    }
}

int main()
{
    struct Stack *a = create();

    push(a, 10);
    push(a, 20);
    push(a, 30);

    return 0;
}
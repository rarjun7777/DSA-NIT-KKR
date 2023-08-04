// stack using linkedlist

#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
} *top = NULL;

void main()
{
   int choice, value;

   while (1)
   {

      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
         printf("Enter the value to be insert: ");
         scanf("%d", &value);
         push(value);
         break;
      case 2:
         pop();
         break;
      case 3:
         display();
         break;
      case 4:
         exit(0);
      default:
         printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}

void push(int value)
{
   struct Node *newNode;
   newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = value;

   newNode->next = top;
   top = newNode;
}

void pop()
{
   struct Node *temp = top;
   printf("\nDeleted element: %d", temp->data);
   top = temp->next;
   free(temp);
}

void display()
{

   struct Node *temp = top;
   while (temp->next != NULL)
   {
      printf("%d--->", temp->data);
      temp = temp->next;
   }
   printf("%d--->NULL", temp->data);
}
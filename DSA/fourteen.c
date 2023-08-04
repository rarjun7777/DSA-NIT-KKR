// queue using linkedlist

#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
} *front = NULL, *rear = NULL; 

void main()
{
   int choice, value;

   scanf("%d", &choice);
   switch (choice)
   {
   case 1:
      printf("Enter the value to be insert: ");
      scanf("%d", &value);
      insert(value);
      break;
   case 2:
      delete ();
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

void insert(int value)
{
   struct Node *newNode;
   newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode->next = NULL;
   
   if (front == NULL)
   front = rear = newNode;

   else
   {
      rear->next = newNode;
      rear = newNode;
   }
}

void delete ()
{
   struct Node *temp = front;
   front = front->next;
   free(temp);
}

void display()
{

   struct Node *temp = front;
   while (temp->next != NULL)
   {
      printf("%d--->", temp->data);
      temp = temp->next;
   }

   printf("%d--->NULL\n", temp->data);
}


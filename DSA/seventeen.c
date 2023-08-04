// C program for different tree traversals

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create(int data)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->left = NULL;
    t->right = NULL;

    return t;
}

void preorder(struct Node *p)
{
    if (p == NULL)
        return;

    else
    {

        printf(" %d ", p->data);

        preorder(p->left);

        preorder(p->right);
    }
}

void inorder(struct Node *p)
{
    if (p == NULL)
        return;

    else
    {

        inorder(p->left);

        printf(" %d ", p->data);

        inorder(p->right);
    }
}

void postorder(struct Node *p)
{
    if (p == NULL)
        return;

    else
    {

        postorder(p->right);

        postorder(p->left);

        printf(" %d ", p->data);
    }
}

int main()
{
    struct Node *new_node = create(1);

    new_node->left = create(2);
    new_node->right = create(3);

    new_node->left->left = create(4);
    new_node->left->right = create(5);

    preorder(new_node);
    printf("\n");

    inorder(new_node);
    printf("\n");

    postorder(new_node);
    printf("\n");

    return 0;
}
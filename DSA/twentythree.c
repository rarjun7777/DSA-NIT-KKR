// (b)find inorder-predecessor and inorder-successor for any node in a BST

// code has some errors  refer it again 


#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int key;
	struct Node *left, *right;
};

struct Node* newNode(int item)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void findPreSuc(struct Node* root,struct Node* pre, struct Node* suc, int key)
{

	if (root == NULL) return ;

	if (root->key == key)
	{
		
		if (root->left != NULL)
		{
			struct Node* tmp = root->left;
			while (tmp->right)
			tmp = tmp->right;
			pre = tmp ;
		}

	
		if (root->right != NULL)
		{
			struct Node* tmp = root->right ;
			while (tmp->left)
			tmp = tmp->left ;
			suc = tmp ;
		}
		
		return ;
		
	}

	
	if (root->key > key)
	{
		suc = root ;
		findPreSuc(root->left, pre, suc, key) ;
	}
	
	else 
	{
		pre = root ;
		findPreSuc(root->right, pre, suc, key) ;
	}
	
}


struct Node *insert(struct Node *node, int key)
{

    if (node == NULL)
    return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}


int main()
{
	int key = 65; //Key to be searched in BST

/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	struct Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);


	struct Node* pre = NULL;
	struct Node* suc = NULL;

	findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	printf("%d",pre->key );
	else
	printf("No Predecessor\n");

	if (suc != NULL)
	printf("%d",suc->key);
	else
    printf("No Successor\n");
    
	return 0;
}

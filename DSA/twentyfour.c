// find the height, number of levels, number of leave nodes, number of internal nodes and total number of nodes in the given BST.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* create(int item)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}


unsigned int leafcount(struct Node* node)
{
    if(node==NULL)
    return 0;
    
    else if(node->left==NULL && node->right==NULL)
    return 1;
    
    else 
    return leafcount(node->left)+leafcount(node->right);
}

int countnonleaf(struct Node* root)
{
    
    if (  root==NULL ||  (root->left==NULL && root->right==NULL) )
    return 0;
    
    else
    return 1+countnonleaf(root->left)+countnonleaf(root->right);
    
}

int maxdepth(struct Node* node)
{
    if(node==NULL)
    return 0;
    
    else
    {
        int ldepth=maxdepth(node->left);
        int rdepth=maxdepth(node->right);
        
        if(ldepth > rdepth)
        return ldepth+1;
        
        else
        return rdepth+1;
    }
}

int main()
{
    struct Node *new_node = create(1);

    new_node->left = create(2);
    new_node->right = create(3);

    new_node->left->left = create(4);
    new_node->left->right = create(5);
    
    int leaf,nonleaf,height;
    
    leaf=leafcount(new_node);
    nonleaf=countnonleaf(new_node);
    height=maxdepth(new_node);
    
    
    
    printf("%d %d %d\n",leaf,nonleaf,height);
    printf("total nodes are %d\n",leaf+nonleaf);
    printf("No of levels and height are same %d\n",height);
    
    return 0;
    
}





#include "avltree.h"

AvlTree* initialize(AvlTree* a)
{
    a->root = NULL;
}

bool empty(AvlTree* a)
{
    if(a->root == NULL)
        return true;
    else
        return false;
}

int height(Node* n)
{
    if(n == NULL)
        return -1;
    else
        return n->height;
}

int rebalance(Node* n)
{
    if(n == NULL)
        return -1;
    else
        return height(n->left) - height(n->right);
}

Node* rightRotate(Node* n)
{
    Node* aux = n->left;
    n->left = aux->right;
    aux->right = n;

    n->height = max(height(n->left), height(n->right)) +1;

    aux->height = max(height(aux->left), height(n->height)) +1;

    return aux;
}

Node* leftRotate(Node* n)
{
    Node* aux = n->right;
    n->right = aux->left;
    aux->left = n;

    aux->height = max(height(n->left), height(n->right)) +1;

    n->height = max(height(aux->right), height(n->height)) +1;

    return aux;
}

Node* insert(Node* n, int value)
{
    if(n == NULL)
    {
        n = malloc(sizeof(Node));
        n->data = value;
        n->height = 0;
        n->left = NULL;
        n->right = NULL;
    }
    else
    {
        if(value < n->data)
            insert(n->left, value);
        else if(value > n->data)
            insert(n->right, value);
        else
            return n;
    }

    n->height = max(height(n->left), height(n->right)) +1;

    int balance = rebalance(n);
    
    // Left Left Case
    if(balance > 1 && value < n->left->data)
		return rightRotate(n);

	// Right Right Case
	if(balance < -1 && value > n->right->data)
		return leftRotate(n);

	//Left Right Case
	if(balance > 1 && value > n->left->data)
	{
		n->left = leftRotate(n->left);
		return rightRotate(n);
	}

	// Right Left Case
	if(balance < -1 && value < n->right->data)
	{
		n->right = rightRotate(n->right);
		return leftRotate(n);
	}

    return n;
}

Node* remove(Node* n, int value)
{
    if(n == NULL)
        return n;
    
    if(value < n->data)
        n->left = remove(n->left, value);
    else if(value > n->data)
        n->right = remove(n->right, value);
    else
    {
        if(n->right == NULL && n->left == NULL)
        {
            free(n);
            n = NULL;
        }
        else if(n->left != NULL && n->right == NULL)
        {
            Node* aux = n->left;
            n = n->left;
            free(aux);
        }
        else if(n->left == NULL && n->right != NULL)
        {
            Node* aux = n->right;
            n = n->right;
            free(aux);
        }
    }
    if(n == NULL)
        return n;

    n->height = 1 + max(height(n->left), height(n->right));

    int balance = rebalance(n);
    
    // Left Left Case
    if(balance > 1 && value < n->left->data)
		return rightRotate(n);

	// Right Right Case
	if(balance < -1 && value > n->right->data)
		return leftRotate(n);

	//Left Right Case
	if(balance > 1 && value > n->left->data)
	{
		n->left = leftRotate(n->left);
		return rightRotate(n);
	}

	// Right Left Case
	if(balance < -1 && value < n->right->data)
	{
		n->right = rightRotate(n->right);
		return leftRotate(n);
	}

    return n;
}
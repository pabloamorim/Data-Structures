#include "binary_tree.h"

struct binaryTree
{
    int value;
    struct binaryTree *left;
    struct binaryTree *right;
};

BinaryTree* create_empty_binary_tree()
{
    return NULL;
}

int is_empty(BinaryTree *bt)
{
    return bt==NULL;
}

BinaryTree* create_binary_tree(int value, BinaryTree *left, BinaryTree *right)
{
    BinaryTree *bt = (BinaryTree*)malloc(sizeof(BinaryTree));
    bt->value = value;
    bt->left = left;
    bt->right = right;
    return bt;
}

void print_in_order(BinaryTree *bt)
{
    if (!is_empty(bt))
    {
        print_in_order(bt->left);
        printf("%d ", bt->value);
        print_in_order(bt->right);
    }
}

void print_pre_order(BinaryTree *bt)
{
    if (!is_empty(bt))
    {
        printf("%d ", bt->value);
        print_pre_order(bt->left);
        print_pre_order(bt->right);
    }
}

void print_post_order(BinaryTree *bt)
{
    if (!is_empty(bt))
    {
        print_pre_order(bt->left);
        print_pre_order(bt->right);
        printf("%d ", bt->value);
    }
}

BinaryTree* search(BinaryTree *bt, int value)
{
	if ((bt == NULL) || (bt->value == value))
	{
		return bt;
	} 
	else if (bt->value > value)
	{
		return search(bt->left, value);
	}
	else
	{
		return search(bt->right, value);
	}
}

BinaryTree* add(BinaryTree *bt, int value)
{
	if (bt == NULL)
	{
		bt = create_binary_tree(value, NULL, NULL);
	} 
	else if (bt->value > value)
	{
		bt->left = add(bt->left, value);
	}
	else
	{
		bt->right = add(bt->right, value);
	}
	return bt;
}
//ADICIONAR NÓ, MAS USANDO PONTEIRO DUPLO
/*
void add(BinaryTree **bt, int value)
{
	if (*bt == NULL)
	{
		*bt = create_binary_tree(value, NULL, NULL);
	}
	else if ((*bt)->value > value)
	{
		add(&(*bt)->left, value);
	}
	else
	{
		add(&(*bt)->right, value);
	}
}
*/
int main()
{
    BinaryTree *bt =  create_binary_tree(6, create_binary_tree(4, NULL, NULL), create_binary_tree(9, create_binary_tree(1, NULL, NULL), create_binary_tree(2, NULL, NULL)));
    puts("***ARVORE IN ORDER***");
    print_in_order(bt);
    puts("\n");
    puts("***ARVORE IN PRE ORDER***");
    print_pre_order(bt);
    puts("\n");
    puts("***ARVORE IN POST ORDER***");
    print_post_order(bt);
    puts("\n");

    return 0;
}
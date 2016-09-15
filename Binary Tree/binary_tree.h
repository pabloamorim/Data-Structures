#include <stdio.h>
#include <stdlib.h>

typedef struct binaryTree BinaryTree;

BinaryTree* create_empty_binary_tree();

BinaryTree* create_binary_tree( int value, BinaryTree *left, BinaryTree *right);

int is_empty(BinaryTree *bt);

void print_in_order(BinaryTree *bt);

void print_pre_order(BinaryTree *bt);

void print_post_order(BinaryTree *bt);

BinaryTree* search(BinaryTree *bt, int value);

BinaryTree* add(BinaryTree *bt, int value);

//void add(BinaryTree **bt, int value);

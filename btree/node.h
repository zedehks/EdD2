#ifndef NODE_H
#define NODE_H
#include <stdio.h>
#include <stdlib.h>

#define NODE_CAPACITY 4
#define KEY_CAPACITY NODE_CAPACITY-1

typedef struct node node;

struct node
{
	int keys[3];

	node* child1;
	node* child2;
	node* child3;
	node* child4;
	
	int n_keys;
	int n_children;
};

node* node_init();
int add(int value, node** root);
void print_tree(node** root);

#endif /* NODE_H */
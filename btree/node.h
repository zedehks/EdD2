#ifndef NODE_H
#define NODE_H
#include <stdio.h>
#include <stdlib.h>

#define NODE_CAPACITY 5
#define KEY_CAPACITY NODE_CAPACITY-1

typedef struct node node;

struct node
{
	int keys[KEY_CAPACITY];

	node* nodes[NODE_CAPACITY];

	int n_keys;
	int n_children;
};

node* node_init();
int add(int value, node** root);
int split(int value, node** root);
void print_tree(int level, node** root);
void order_keys(node** root);
#endif /* NODE_H */

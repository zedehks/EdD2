#include "node.h"

node* node_init()
{
	node* n = malloc(sizeof(node));
	for(int i = 0;i<KEY_CAPACITY;i++)
		n->keys[i] = -1;

	for(int i = 0;i<NODE_CAPACITY;i++)
		n->nodes[i] = NULL;
	/*n->child1 = NULL;
	n->child2 = NULL;
	n->child3 = NULL;
	n->child4 = NULL;*/
	
	n->n_keys = 0;
	n->n_children = 0;
}

int add(int value, node** root)
{
	if((*root)->n_keys == KEY_CAPACITY)
	{
		printf("it be full\n");
		return -1;
	}
	else
	{
		(*root)->keys[(*root)->n_keys] = value;
		(*root)->n_keys++;
		printf("Added %d to tree.\n", value);
		return 0;
	}
}

void order_keys(node** root)
{
	node* tmp = (*root);
	int i[3];

	int max = tmp->keys[0];
	int exit = 0;
	while(exit ==0)
	{
		
	}
}
void print_tree(node** root)
{
	int depth = 0;
	node* temp = NULL;
	temp = node_init();

	printf("Root level: ");
	for(int i = 0;i < KEY_CAPACITY;i++)
	{
		printf("%d ",(*root)->keys[i]);
	}
	printf("\n");
	for(int i = 0; i < (*root)->n_children; i++)
	{
		//do stuff
	}
	free(temp);
}


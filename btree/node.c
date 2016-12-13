#include "node.h"

node* node_init()
{
	node* n = malloc(sizeof(node));
	for(int i = 0;i<3;i++)
		n->keys[i] = -1;

	n->child1 = NULL;
	n->child2 = NULL;
	n->child3 = NULL;
	n->child4 = NULL;
	
	n->n_keys = 0;
	n->n_children = 0;
}

int add(int value, node** root)
{
	if((*root)->n_keys == 3)
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
	/*switch( (*root)->n_keys)
	{
		case 0:
			(*root)->keys[0] = value;
			(*root)->n_keys++;
			break;
		case 1:
			(*root)->key2 = value;
			(*root)->n_keys++;
			break;
		case 2:
			(*root)->key3 = value;
			(*root)->n_keys++;
			break;
		case 3:
			printf("it be full\n");
			break;
	}*/

}

void order_keys(node** root)
{
	node* tmp = (*root);
	int max = tmp->keys[0];
	int i = 1;
	//if(tmp[i] =
}
void print_tree(node** root)
{
	int depth = 0;
	node* temp = NULL;
	temp = node_init();

	printf("Root level: %d, %d, %d.\n",(*root)->keys[0],(*root)->keys[1],(*root)->keys[2]);
	for(int i = 0; i < (*root)->n_children; i++)
	{
		//do stuff
	}
	free(temp);
}


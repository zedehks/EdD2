#include "node.h"

node* node_init()
{
	node* n = malloc(sizeof(node));
	for(int i = 0;i<KEY_CAPACITY;i++)
		n->keys[i] = -1;

	for(int i = 0;i<NODE_CAPACITY;i++)
		n->nodes[i] = NULL;
	n->n_keys = 0;
	n->n_children = 0;
}

int add(int value, node** root)
{
	if((*root)->n_keys == KEY_CAPACITY)
	{
		printf("it be full\n");
		//split(value,root);
		return -1;
	}
	else
	{
		(*root)->keys[(*root)->n_keys] = value;
		(*root)->n_keys++;
		printf("Added %d to tree.\n", value);
		order_keys(root);
		return 0;
	}
}

void order_keys(node** root)
{
	int tmp = -1;

	int fail_counter = 0;
	int exit = 0;
	while(fail_counter< (KEY_CAPACITY) && exit ==0 )
	{
		exit = 1;
		for(int i = 0;i<KEY_CAPACITY;i++)
		{
			if(i<KEY_CAPACITY-1)
			{
				if((*root)->keys[i] > (*root)->keys[i+1] || (*root)->keys[i] == -1) 
				{
					exit = 0;
					tmp = (*root)->keys[i+1];
					(*root)->keys[i+1] = (*root)->keys[i];
					(*root)->keys[i] = tmp;
					tmp = -1;
				}
			}
		}
		fail_counter++;
	}
}

void print_tree(int level, node** root)
{
	node* temp = (*root);
	if(temp != NULL)
	{
		if(level == 0)
			printf("Root level: ");
		else
			printf("Level %d, %d nodes: ", level, temp->n_children); 	
		for(int i = 0;i < KEY_CAPACITY;i++)
		{
			printf("%d ",temp->keys[i]);
		}
		printf("\n");
		temp = temp->nodes[0];
		print_tree(++level,&temp);
		temp = temp->nodes[1];
		print_tree(++level,&temp);
		/*for(int i = 0; i < NODE_CAPACITY; i++)
		{
			if(temp->nodes[i] != NULL)
			{
				temp = temp->nodes[i];
				print_tree(++level,&temp);
			}
		}*/
	}	
}

int split(int value, node** root)
{
	int median = (*root)->keys[2];//for some reason, KEY_CAPACITY/2 dont work welp 
	if((*root)->n_children == 0)
	{
		(*root)->nodes[/*(*root)->n_children*/0] = node_init();
		(*root)->nodes[1] = node_init();
		(*root)->n_children+=2;

		(*root)->nodes[0]->keys[0]=value;
		(*root)->nodes[1]->keys[0]=value+1;
		/*for(int i = 0;i< (*root)->n_keys; i++)
		{
			if((*root)->keys[i] < (*root)->keys[median])
			{
				(*root)->nodes[(*root)->n_children-2]->keys[i] = (*root)->keys[1];
				(*root)->keys[i] = -1 ;
			}
			else 
				(*root)->nodes[(*root)->n_children-1]->keys[i] = (*root)->keys[1];
		}*/
	}
	/*else
	{
		(*root)->nodes[(*root)->n_children+1] = node_init();
		(*root)->n_children++;
	}*/

}

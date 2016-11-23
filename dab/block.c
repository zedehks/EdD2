#include "block.h"

block_t* init_block_t(block_t** previous)
{
	block_t_header* h = init_block_header(previous);
	block_t* b = malloc(sizeof(block_t));
	b->header = h;
	for(int i =0;i<BLOCK_CAPACITY;i++)
		b->tables[i] = NULL;
	if((previous) != NULL) //printf("benis");
		(*previous)->header->next = b;
	return b;
}
block_t_header* init_block_header(block_t** previous)
{
	block_t_header* h = malloc(sizeof(block_t_header));
	h->next = NULL;
	h->previous = (&previous);
	h->amount_tables = 0;
	return h;
}

int block_add_table(block_t** b, char* name)
{
	if((*b)->header->amount_tables == BLOCK_CAPACITY)
	{
		printf("\nBlock Full.\n");
		return -1;
	}
	for(int i=0;i<BLOCK_CAPACITY;i++)
	{
		if((*b)->tables[i] == NULL)
		{
			init_table(&((*b)->tables[i]),0,name);
			(*b)->header->amount_tables++;
			break;
		}
	}
return 0;	
}

void free_block(block_t** b)
{
	
	block_t* tmp = (*b);
	
	while(tmp != NULL)
	{
		block_t* tmp2 = tmp;
		tmp = tmp->header->next;
		free(tmp2->header);
		free(tmp2);
	}
}

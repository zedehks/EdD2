#include "block.h"

block_t* init_block_t(block_t** previous, int c)
{
	block_t_header* h = init_block_header(previous, c);
	block_t* b = malloc(sizeof(block_t));
	b->header = h;
	b->tb = NULL;
	return b;
}
block_t_header* init_block_header(block_t** previous, int c)
{
	block_t_header* h = malloc(sizeof(block_t_header));
	h->next = NULL;
	h->previous = (&previous);
	h->capacity = c;
	return h;
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

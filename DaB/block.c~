#include "block.h"

int init_block(char type,int number, Block* b)
{
	b = (Block*) malloc(sizeof(Block));
	if(!b)
		return 0;
	b->n_block = number;
	b->type = type;
	
	//TODO, must calculate type size first
	switch(type)
	{
		case 't':
		b->capacity = 3;//can fit 3 tables per block
		break;
		case 'f':
		default:
		b->capacity = 0;

	}
	b->block_content = 0;
	b->next = 0;
	return 1;
}
int append_block(Block* first, Block* second)
{
	first->next = second;
	if(!(first->next))
		return 0;
	return 1;
}

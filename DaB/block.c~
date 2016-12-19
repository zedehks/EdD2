#include "block.h"

int init_block(char type,int number, Block** b)
{
	(*b) = (Block*) malloc(sizeof(Block));
	if(!(*b))
		return 0;
	(*b)->n_block = number;
	(*b)->type = type;
	
	//TODO, must calculate type size first
	switch(type)
	{
		case 't':
		for(int i = 0;i<4;i++)
			(*b)->tables[i] = 0;
		break;
		/*case 'f':
		default:
		//(*b)->content = NULL;*/

	}
	(*b)->next = 0;// Remember! not included in binary file!
	return 1;
}
int append_block(Block** first, Block** second)
{
	(*first)->next = (*second);
	if(!((*first)->next))
		return 0;
	return 1;
}

void free_block(Block** b)
{
	//free((*b)->content);
	free((*b)->next);
	free (*b);
}

#include "table.h"

int init_table(char name[9], Table** t,int block)
{
	*t = /*(Table*)*/ malloc(sizeof(Table));
	if(!(*t))
		return 0;
	strcpy((*t)->name,name);
	(*t)->first_field_block = block;
	return 1;
}

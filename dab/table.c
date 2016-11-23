#include "table.h"

int init_table(table** t, int c)
{
	(*t) = malloc(sizeof(table));	
	(*t)->capacity = c;
	(*t)->next = NULL;
	if(!(*t) == NULL)
		return RETURN_OK;
	return RETURN_ERROR;
}

int append_table(table** original,int c)
{
	table* t = NULL;
	if(init_table(&t,c) == RETURN ERROR) 
		return RETURN_ERROR;
	table* tmp = (*original);
	while(tmp->next != NULL)


}


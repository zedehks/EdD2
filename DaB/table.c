#include "table.h"

int init_table(char name[8], Table* t)
{
	t = (Table*) malloc(sizeof(Table));
	strcpy(t->name,name);
}

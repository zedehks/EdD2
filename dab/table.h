#include <stdio.h>
#include <stdlib.h>
#define RETURN_OK 1
#define RETURN_ERROR -1

typedef struct table table;
struct table
{
	table* next;
	int first_field_block;
	int first_registry_block;
	int capacity;	
};

int init_table(table** t, int c);

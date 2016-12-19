#ifndef TABLE_H
#define TABLE_H
#include <stdio.h>
#include <stdlib.h>

#define B_CAPACITY 3// 3 tables at most per block

typedef struct table Table;

struct table
{
	char name[9]; //9 bytes
	int first_field_block;//4 bytes
};

int init_table(char name[9], Table* t); 
#endif /* TABLE_H  */

#ifndef BLOCK_H
#define BLOCK_H
#include <stdio.h>
#include <stdlib.h>
#include "table.h"
#define BLOCK_SIZE 64//bytes per physical block
typedef struct block_header Block;

struct block_header
{
	int n_block;//4 bytes
	char type;//1 byte
	Block* next;//8 bytes, but not included in actual binary file!
	union
	{
		Table* tables[4]; //52 bytes (4 tables, 13 bytes each);
		Field* fields[3]; //51 bytes (3 fields, 17 bytes each);
	};
};//total 56-57 bytes (when writing, write several zeroes to fill space up to 64 bytes)

int init_block(char type, int number,  Block** b);
int append_block(Block** first, Block** next);
void free_block(Block** b);
#endif /* BLOCK_H */

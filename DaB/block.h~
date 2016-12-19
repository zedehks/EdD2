#ifndef BLOCK_H
#define BLOCK_H
#include <stdio.h>
#include <stdlib.h>
#include "table.h"
#define BLOCK_SIZE 64//bytes per physical block
#define HEADER_SIZE 23 //same (defined for rememberance purposes :^)
#define B_CONTENT_SIZE 41//void* cannot exceed this size
typedef struct block_header Block;

struct block_header
{
	int n_block;//4 bytes
	char type;//1 byte
	unsigned short capacity; // must be calculated per type (table block uses such size, field block another, etc;
	Block* next;//8 bytes
	//void* block_content;//8 bytes
	union
	{
		Table* tables[3];
	};
};

/*typedef struct 
{
	Table* table1; 
	Table* table2; 
	Table* table3; 
}block_table;
*/
int init_block(char type, int number,  Block** b);
int append_block(Block** first, Block** next);
void free_block(Block** b);
#endif /* BLOCK_H */

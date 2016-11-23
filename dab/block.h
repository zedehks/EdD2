#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK_CAPACITY 4

typedef struct block_t block_t;
typedef struct block_t_header block_t_header;
struct block_t
{
	block_t_header* header;
	table* tb;
};
struct block_t_header
{
	block_t* next;
	block_t* previous;
	int capacity;
};

void init_block_t(block_t** previous, int c);
void init_block_header(block_t** previous, int c);

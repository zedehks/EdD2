#ifndef BLOCK_H
#define BLOCK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
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

block_t* init_block_t(block_t** previous, int c);
block_t_header* init_block_header(block_t** previous, int c);
void free_block(block_t** b);
#endif /* BLOCK_H */


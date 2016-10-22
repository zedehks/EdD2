// adapted from Emil Hernvall's implementation: https://gist.github.com/EmilHernvall/953968
// he says it's available using the MIT license, but I only know about the GPL so i dunno 


#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int v_init(vector* v, int capacity)
{
	v->data = malloc(capacity * sizeof(void*));
	if(!v->data) return -1;

	v->capacity = capacity;
	v->size = 0;

	return 1; //we did it, leddit!
}

void v_free(vector* v)
{
	free(v->data);
}

void v_push(vector* v, void* element)
{
	if (v->capacity == v->size)
	{
		v->capacity *=2;
		v->data = realloc(v->data, sizeof(void*) * v->size); 
	}
	v->data[v->size++] = element;
}

void v_delete(vector* v, int index)
{
	// TODO
}


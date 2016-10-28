// adapted from Emil Hernvall's implementation: https://gist.github.com/EmilHernvall/953968
// he says it's available using the MIT license, but I only know about the GPL so i dunno 


#ifndef VECTOR_H	
#define VECTOR_H

typedef struct dynamic_array_struct
{
  void** data;
  int* capacity; /*capacity*/
  int* size; /*current # of crap inside vector*/
}vector;

int v_init(vector* v, int capacity);
void v_free(vector* v);
void v_push(vector* v, void* element);
void v_delete(vector* v, int index);

#endif

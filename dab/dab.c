#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include  "table.h"
#include "command.h"

int main()
{
	/*table* t = NULL;
	int i = init_table(&t,69);

	if(i == RETURN_OK) //printf("lol\n");
		printf("\n%d capacity\n",t->capacity);
	free(t);*/

	int exit=0;

	printf("\n~~DAB: The DatABase~~\n");
	print_help();
	while(exit == 0)
	{
		exit = get_command(); 
	}
}

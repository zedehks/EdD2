//+1 punto extra
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "vector.h"


typedef struct 
{
	vector options;
}menu_t;

typedef struct
{
	char* name;
	int id;
	int order;
	menu_t* submenu;
}option_t;

int get_menu(char* json, menu_t* menu); 
vector read_file(FILE* menu, int c);
vector parse_array(FILE* menu, int c);

void print_menu(menu_t m);

int main()
{
	menu_t menu;
	int result = get_menu("menu.json", &menu);
	if(result == -1)
		printf("\n\nError reading json menu file\n\n");

	int input;
	bool can_exit = false;
	
}

int get_menu(char* json, menu_t* menu)
{
	FILE* m;
	m = fopen(json,"r");
	if(!m)
		return -1;//NULL;

	int c;
	menu.options -> read_file(m,i);
	

	
	fclose(m);
}

// I've gotta get a crapton of recursive mileage outta this sheisse lol
vector read_file(FILE* menu, int c)
{
	while( (c=getc(menu)) != EOF)
	{
		switch(c)
		{
			case '[':
				//parse_array(menu, c);
				break;
			case '{':
				//parse_option(menu, options, c);
				break;
		}
		
	}
}


vector parse_array(FILE* menu, int c)
{
	vector array;
	if(v_init(array, 2) != 1)
	{
		printf("\n\nSomething went wrong with the vector!\n\n");
		return;
	}

	


}

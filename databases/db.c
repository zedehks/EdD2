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

menu_t get_menu(char* json); 
vector parse_array(FILE* menu, int c);
void parse_option(FILE* menu, vector* options, int c);
void print_menu(menu_t m);

int main()
{
	//menu_t menu_options = get_menu("menu.json");

	int input;
	bool can_exit = false;
	
}

menu_t get_menu(char* json)
{
	int c;
	FILE* menu;
	menu = fopen(json,"r");
	if(!menu)
		return ;//NULL;

	while( (c=getc(menu)) != EOF)
	{
		switch(c)
		{
			case '[':
				parse_array(menu, c);
				break;
			case '{':
				parse_option(menu, options, c);
				break;
		}
		
	}
	

	
	}
	fclose(menu);
}

vector parse_array(FILE* menu, int c)
{
	vector options;
	v_init(options, 4);


	while( (c=getc(menu)) != EOF)
	{
		switch(c)
		{
			case '[':
				parse_array(menu);
				break;
			case '{':
				parse_option(menu, options);
				break;
		}
		
	}
}

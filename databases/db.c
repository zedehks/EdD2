//+1 punto extra
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define BUFFER_SIZE 255

typedef struct menu_t menu_t; 
typedef struct option_t option_t;
struct menu_t
{
	option_t* options;
	       	//options;
};

struct option_t
{
	char* name;
	int id;
	int order;
	//vector* submenu;
	
};

int get_menu(char* json, menu_t* menu); 
menu_t* read_file(char* buffer, int buff_pointer, int f_size, int c);
//vector parse_array(FILE* menu, int c);

void print_menu(menu_t m);

int main()
{
	menu_t* menu;
	int result = get_menu("menu2.json", menu);
	if(result == -1)
		printf("\n\nError reading json menu file\n\n");

	int input;
	bool can_exit = false;
}

int get_menu(char* json, menu_t* menu)
{
	// open file & check if everything 大丈夫
	FILE* m;
	m = fopen(json,"r");
	if(!m)
		return -1;//NULL;
	//get file size, and copy all of it to a char array
	fseek(m,0,SEEK_END);
	long f_size = ftell(m);
	fseek(m,0,SEEK_SET);

	char buffer[f_size];	
	fread(buffer,f_size,1,m);	
	fclose(m);

	//let's actually try to parse some 糞
	bool read_word = false;	
	//v_init(&(menu->options),32);	


	int c=0; // counter for menu options
	for(int i=0;i<f_size;i++)
	{
		if(buffer[i] == ';')	c++;	
	}
	printf("%d \n",c);


	menu = read_file(buffer,0,f_size,c);
}

// I've gotta get a crapton of recursive mileage outta this sheisse lol
menu_t* read_file(char* buffer, int buff_pointer, int f_size, int c)
{


	menu_t menu;
	option_t options[c];
	//menu.options = options;	
	int option_counter = 0;

	for(int i=buff_pointer;i < f_size;i++) 
	{
		switch(buffer[i])
		{
			case '[':
				//this is where the submenus would be read
				break;

			case '{':
				options[option_counter]			
				break;
		}
		
	}
}

/*vector parse_array(FILE* menu, int c)
{
	vector array;
	if(v_init(array, 2) != 1)
	{
		printf("\n\nSomething went wrong with the vector!\n\n");
		return;
	}

	


}*/

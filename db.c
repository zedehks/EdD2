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
int move_pointer(int pointer, char* buffer, char delimiter);
char* grab_field(int pointer, char* buffer, char delimiter);
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


	menu = read_file(buffer,0,f_size,c);
}

// I've gotta get a crapton of recursive mileage outta this sheisse lol
menu_t* read_file(char* buffer, int buff_pointer, int f_size, int c)
{


	menu_t menu;
	option_t options[c];
	int option_counter = 0;
	//printf("%s",string_copy);
	//menu.options = options;
	
	for(int i=buff_pointer;i < f_size;i++) 
	{
		//printf("%c\n",buffer[i]);
		switch(buffer[i])
		{
			case '[':
				//this is where the submenus would be read
				break;

			case '{':
				while(buffer[i] != '}' /*&& i < buff_pointer*/)
				{
					i++;
					//printf("%c\n",buffer[i]);
					switch(buffer[i])
					{
						case 'n':
							i = move_pointer(i,buffer,'"');
							//i = move_pointer(i,buffer,'"');
							//i+=8;
							i+=3;
							//printf("%c %c %c\n\n\n",buffer[i],buffer[i+1],buffer[i+2]);
							options[option_counter++].name =grab_field(i,buffer,',');
							//i = move_pointer(i,buffer,'"');
							i = move_pointer(i,buffer,'"');
							printf("\nlets hope this werks: \n\"%s\"\n%c\n\n",options[option_counter-1].name,buffer[i]);
							break;
						case 'i':
							//printf("Nombre\n\n");
							break;
						case 'o':
							//printf("order\n\n");
							break;
						case 's':
							//printf("Submenu\n\n");
							break;
						case '}':
							//return
							break;
					}
				}
				//options[option_counter];			
				break;
		}
		
	}
}
int move_pointer(int pointer, char* buffer, char delimiter)
{
	pointer++;
	while(buffer[pointer] != delimiter)

	{
		pointer++;
	}	
	return pointer;
}

char* grab_field(int pointer, char* buffer, char delimiter)
{
	char token[1024];
	int i = 0;
	while(buffer[i+pointer] != delimiter && (i+pointer <1024))
	{
		token[i] = buffer[i+pointer];
		printf("current char: %c\n",buffer[i+pointer]);
		i++;
	}
	return token;
}



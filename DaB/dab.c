#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "block.h"

char* get_tagline();
int interpret_input(char* input);
int parse_command(char command[32], char* comparison);
void print_h();
int add_table(char* name);
int extract_int(char* command);
void clear();

int write_tape();

struct metadata
{
	char blocks[62];
	short next_metablock;
}Metadata;
FILE* f;
char* tape = 0;

int main()
{
	srand(time(NULL));
	// Initialize Block list header
	Block *header;
	long length;
	// File I/O
	f = fopen("database.dab","rb+");
	if(!f)
	{
		// File not found! let's make it!
		f = fopen("database.dab","wb+");
		Metadata.next_metablock = -1;
		for(int i = 0;i<62;i++)
			Metadata.blocks[i] = 0;
		Metadata.next_metablock = -1;
		if(write_tape())
			printf("\nCreated Database file\n");
	}
	else	
		printf("\nDatabase found\n");
	fseek (f, 0, SEEK_END); //
	length = ftell (f);     // get the length of the file
	fseek (f, 64, SEEK_SET); // go to location of first block in file
	tape = malloc (length);
	fread(tape,1,length,f);

	// Initial greeting preparations & printing
	char* tagline = get_tagline();
	printf("\n~~DaB: The DataBase~~\n%s\n",tagline);
	int exit = 0;
	char input[32];
	print_h();

	//main loop
	while(exit == 0)
	{
		//clear input 
		for(int i = 0;i<32;i++)  
			input[i] = '\0';
		//print prompt
		printf("\n$ ");
		//yank input and add null byte at end
		fgets(input,32,stdin);
		int len = strlen(input);
		if(len > 0 && input[len-1] == '\n') 
		       	input[len-1] = '\0';
		exit = interpret_input(input);
	}

	free(tape);
	fclose(f);
	return 0;
}

int write_tape()
{
	fwrite(Metadata.blocks,1,62,f);
	fwrite(&(Metadata.next_metablock),sizeof(short),1,f);
	//TODO: write blocks here
}
int first_empty_block()
{
	for(int i = 0; i<62;i++)
	{
		if(Metadata.blocks[i] != 'o')//o for 'occupied'
			return i;
	}	
	return -1;//TODO: make it so it continues with next metablock
}

int interpret_input(char* input)
{
	//command parsing tree (sorry for all the if/elses) :(	
	if(parse_command(input,"h") == 1) 
		print_h();  
	else if(parse_command(input,"c") == 1) 
		clear();
	else if(parse_command(input,"quit") == 1) 
		printf("\nNO ESCAPE\n");
	else if(parse_command(input,"q") == 1) 
		return -1;
	else if(parse_command(input,"a") == 1) 
	{
		add_table(input);
	}
	else if(parse_command(input,"l") == 1) 
		//print_tree(0,&root);
		printf("Right back at ya.\n");
	
	//temporary! remove later!
	else if(parse_command(input,"o") == 1) 
		//order_keys(&root);
		printf("Right back at ya.\n");
	
	//just for fun
	else if(parse_command(input,"?") == 1) 
		printf("Right back at ya.\n");
	else if(parse_command(input,"¿") == 1) 
		printf("You have to go back.\n");
	else if(parse_command(input,"cyka") == 1) 
		printf("Ah, I see you're a good friend of president Trump.\n");
	else if(parse_command(input,"fug") == 1) 
		printf(":D\n");
	else if(parse_command(input,"blyat") == 1) 
		printf("The CIA would like to have a word with you.\n");
	else if(parse_command(input,"日本語") == 1) 
		printf("お前の母は馬の顔有る。\n");
	else
		printf("?");
	return 0;
}
int parse_command(char command[32], char* comparison)
{
	if(command[0] == ' ') return 0;
	for(int i = 0;i<32;i++)
	{
		if(comparison[i] == '\0' || command[i]==' ') 
			break;
		if(command[i] != comparison[i]) 
		       	return 0;
	}
	return 1;
}

int add_table(char* name)
{
	//we gotta grab the name from the command first
	char* tmp;
	tmp = strtok(name," ");
	tmp = strtok(NULL," ");
	if(tmp == NULL) 
	{
		printf("\nPlease enter an eight-character name.\n");
		return 0;
	}
	//if(strlen(tmp > 8)) I'll look into why this aint needed later lol
	{
		char tmp2[7+1];//max name pointer size, plus the null char
		for(int i =0;i<=7;i++)
		{
			tmp2[i] = tmp[i];
		}
		tmp2[8] = '\0';
		strcpy(tmp,tmp2);
	}
	//if(block_add_table(b,tmp) == 0)
		printf("\nCreated a new table \"%s\".\n",tmp);
		return 1;
}
void print_h()
{
	printf("\nCommands:\na [int]\t Add [int] to tree.");
	printf("\nr [int]\t Remove [int] to tree.");
	printf("\n\tNote: [int] in previous commands must be positive.\n");
	printf("\nl\t Print out tree.");
	printf("\nc\t Clear your troubles away.");
	printf("\nh\t This thing is just spitting ?'s at me HELP.");
	printf("\nq\t End it all.\n");
}

int extract_int(char* command)
{
	char *tmp;
	tmp = strtok(command," ");
	tmp = strtok(NULL," ");
	if(tmp == NULL)
	{
		printf("? Missing/incorrect parameter\n");
		return -1;
	}

	return atoi(tmp);
}

char* get_tagline()
{
	char* tagline;
	switch(rand()%10) 
	{
		case 0:
		tagline = "\"You getting tired of debugging yet?\"";
		break;
		case 1:
		tagline = "\"Is it really just a \'dance\'?\"";
		break;
		case 2:
		tagline = "\"You kids and your memes are incomprehensible these days.\"";
		break;
		case 3:
		tagline = "\"I sometimes wish we could go back to those days,\nwhere pointers were just that scary C thing Java ain't got no need of.\"";
		break;
		case 4:
		tagline = "\"Gesundheit. Oh wait, you weren't sneezing?\"";
		break;
		case 5:
		tagline = "\"You know, you should probably be writing actual code right about now.\"";
		break;
		case 6:
		tagline = "\"100% Russian proof. Looking at you, Clinton.\"";
		break;
		case 7:
		tagline = "\"日本語は話しません。でも、楽しい、ね？\"";
		break;
		case 8:
		tagline = "\"Can confirm, rubber ducky debugging is incredibly useful.\nNothing beats anime figure debugging, though.\"";
		break;
		case 9:
		tagline = "\"Don't worry, this tagline is actually about the program itself, I swear!\"";
		break;
	}
	return tagline;
}
void clear()
{
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	system("clear");
    	#endif
	#if defined(_WIN32) || defined(_WIN64)
	system("cls");
	#endif
}//Solution by nbro, stolen from https://stackoverflow.com/questions/2347770/how-do-you-clear-console-screen-in-c


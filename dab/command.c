#include "command.h"

int get_command()
{
	char input[32];
	for(int i = 0;i<32;i++)
		input[i] = NULL;


	printf("\nReady.\n");
	fgets(input,32,stdin);
	int len = strlen(input);
	if (len > 0 && input[len-1] == '\n')
		  input[len-1] = '\0';

	if(parse_command(input,"help") == TRUE)
		print_help();
	else if(parse_command(input,"exit") == TRUE)
		return	CODE_EXIT;
	else if(parse_command(input,"add") == TRUE)
		add_table(input);
	else
		printf("?\n");
	return 0;
}

void add_table(char* name)
{
	//we gotta grab the name from the command first
	char* tmp;
	tmp = strtok(name," ");
	tmp = strtok(NULL," ");
	if(tmp == NULL) 
	{
		printf("\nPlease insert an eight-character name.\n");
		return;
	}
	//if(strlen(tmp > 8)) I'll look into why this aint needed later lol
	{	
		char tmp2[8+1];//max name size, plus the null char
		for(int i =0;i<=8;i++)
		{
			tmp2[i] = tmp[i];
		}
		tmp2[8] = '\0';
		strcpy(tmp,tmp2);
	}
	printf("\nCreated a new table \"%s\".\n",tmp);
}

int parse_command(char command[32],char* comparison)
{
	//char buffer = command[0];
	

	for(int i = 0;i<32;i++)
	{
		if(comparison[i] == '\0' || command[i] == ' ') break;
		if(command[i] != comparison[i])
		{
			return FALSE;
		}
		//else
		//	printf("%c, %c ok\n",command[i],comparison[i]);
	}
	
	return TRUE;
}

void print_help()
{
	printf("\n\nUsage: [COMMAND] (PARAMETER)\n");
	printf("Note the space between the command and the parameter (if any).");
	//printf("\nArguments choose the data structure:");
	printf("\n\nadd [NAME]\tAdd a table with the given name (maximum length 8)\n");
	printf("\nlist\tList all available tables\n");
	printf("\nhelp\tPrint this help page\n");
	printf("\nexit\tThis does something iunno what\n\n\n");

}


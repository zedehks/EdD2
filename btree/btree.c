#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

int parse_command(char command[32], char* comparison);
void print_h();
int extract_int(char* command);

int main()
{
	node* root = NULL; 
	//printf("Initializing root...\n");
	root = node_init();
//	if(root != NULL) { printf("success lol\n");}
	
	int exit = 0;
	char input[32];
	print_h();
	while(exit == 0)
	{
		for(int i = 0;i<32;i++)  
			input[i] = '\0';
		printf("\nBTREE $ ");
		fgets(input,32,stdin);
		int len = strlen(input);
		if(len > 0 && input[len-1] == '\n') 
		       	input[len-1] = '\0';
		
		if(parse_command(input,"h") == 1) 
		       	print_h();  
		else if(parse_command(input,"q") == 1) 
			exit =1;  
		else if(parse_command(input,"a") == 1) 
		{
			int result = extract_int(input);
			if(result != -1)
				add(result,&root);
		}
		else if(parse_command(input,"l") == 1) 
			print_tree(&root);
		else
			printf("?");
	}

	free(root);
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

void print_h()
{
	printf("\n~~BTREES~~\n");
	printf("Commands:\na [int]\t Add [int] to tree.");
	printf("\nr [int]\t Remove [int] to tree.");
	printf("\n\tNote: [int] in previous commands must be positive.\n");
	printf("\nl\t Print out tree.");
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

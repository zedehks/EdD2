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
		else if(parse_command(input,"quit") == 1) 
			printf("?");
		else if(parse_command(input,"q") == 1) 
			exit =1;  
		else if(parse_command(input,"a") == 1) 
		{
			int value = extract_int(input);
			int result = 0;
			if(value != -1)
				result = add(value,&root);
			if(result == -1)
				split(value,&root);
			order_keys(&root);
		}
		else if(parse_command(input,"l") == 1) 
			print_tree(0,&root);
		
		//temporary! remove later!
		else if(parse_command(input,"o") == 1) 
			order_keys(&root);
		
		//just for fun
		else if(parse_command(input,"?") == 1) 
			printf("Right back at ya.\n");
		else if(parse_command(input,"¿") == 1) 
			printf("You have to go back.\n");
		else if(parse_command(input,"cyka") == 1) 
			printf("Ah, I see you're a good friend of president Trump.\n");
		else if(parse_command(input,"blyat") == 1) 
			printf("The CIA would like to have a word with you.\n");
		else if(parse_command(input,"日本語") == 1) 
			printf("お前の母は馬の顔有る。\n");
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

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void ar_print(int* num_array, char* col_array);
void reset(int* num_array, char* col_array);
//void add(int* num_array, char* col_array);
void add(int* num_array, char* col_array);
void del(int* num_array, char* col_array);

int r = 0;
int b = 0;

int main()
{
	int main_array[10];
	char col_array[10];
	
	reset(main_array,col_array);
//	ar_print(main_array,col_array);

	bool can_exit = false;
	char* input;

	while(!can_exit)
	{
		printf("\nReady.\n");
		scanf("%s",input);

		if(!strcmp("exit",input))
			can_exit = true;

		else if(!strcmp("ls",input))
			ar_print(main_array,col_array);

		else if(!strcmp("reset",input))
			reset(main_array,col_array);

		else if(!strcmp("add",input))
			add(main_array,col_array);

		else if(!strcmp("del",input))
			del(main_array,col_array);

		else if(!strcmp("help",input))
			printf("\n\nexit\tI Wonder...?\nls\tPrint Status\nadd\tAdd Balls wherever you want, ご主人様\ndel\tRemove Balls\nreset\tBack to Square One\nhelp\thurr durr\n\n");

		else
			printf("?SYNTAX ERROR\n\n");
	}
	
}

void del(int* num_array, char* col_array)
{
	int index;
	printf("\n\nIndex (0/9): ");
	scanf("%d",&index);
	

	if(col_array[index] =='b') 
	{		
		if(b > 0)
			b-=num_array[index];
	}
	else if(col_array[index]=='r')
	{
		if(r > 0)
			r-=num_array[index];
	}

	num_array[index] = 0;
	col_array[index]= 'N';
}
void del_silent(int* num_array, char* col_array, int index)
{

	if(col_array[index] =='b') 
	{		
		if(b > 0)
			b-=num_array[index];
	}
	else if(col_array[index]=='r')
	{
		if(r > 0)
			r-=num_array[index];
	}

	num_array[index] = 0;
	col_array[index]= 'N';
}


void add(int* num_array, char* col_array)
{
	int index;
	while(true)
	{
		printf("\n\nIndex (0/9): ");
		scanf("%d",&index);
		
		if(index > 9 || index < 0)
			printf("\nDo you like segfaulting that much?");
		else
			break;
	}

	if(num_array[index] != 0)
		del_silent(num_array,col_array,index);

	
	char color;
	while(true)
	{
		/* of course, stolen from Stack Overflow (scanf sucks)*/
		/* clears scanf buffer so instructions (hopefully) aren't fugged */
		int c;
		while ( (c = getchar()) != '\n' && c != EOF ) { }
		/*---*/

		printf("\nColor (r/b): ");
		scanf("%c",&color);

		if(color == 'r' || color == 'b')
			break;
		else
			printf("\nMake it 'r' or 'b' pls.");

	}

	int amount;
	while(true)
	{
		printf("\nAmount: "); 
		scanf("%d",&amount);

		if(amount < 1)
			printf("\nSure, try adding zero or negative balls; I'll wait.");
		else
			break;
	}

	switch(color)
	{
		case 'b':
			b+=amount;
			break;
		case 'r':
			r+=amount;
			break;
	}



	num_array[index] = amount;
	col_array[index] = color;

}



void reset(int* num_array, char* col_array)
{
	for(int i=0;i<10;i++)
	{
		num_array[i] = 0; 
		col_array[i] = 'N';
	}
	r = 0;
	b = 0;
}

void ar_print(int* num_array, char* col_array)
{
	printf("\n@\t#\tcolor\n\n");

	int r_pointer = 0;
	int b_pointer = 0;
	int reds[10];
	int blues[10];

	for(int i = 0;i<10;i++)
	{
		reds[i]=-1;
		blues[i]=-1;
		int number = num_array[i];
		int color = col_array[i];
		printf("%d\t%d\t%c\n",i,number,color);
		if(color == 'b')
			blues[b_pointer++] = i;

		else if(color == 'r')
			reds[r_pointer++] = i;

	}
	printf("\n@Reds: ");
	for(int i = 0;i<10;i++)
	{
		int num=reds[i];
		if(num !=-1)
			printf("%d ", num);
	}

	printf("\n@Blues: ");
	for(int i = 0;i<10;i++)
	{
		int num=blues[i];
		if(num !=-1)
			printf("%d ", num);
	}
	printf("\n\n#Reds: %d\n#Blues: %d\n#Total: %d\n\n",r,b,(r+b));
}

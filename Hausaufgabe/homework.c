#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct person person;
struct person
{
	char* given_name;
	char* surname;
	int age;
	person* next;
};

person* gen_person();
void print_p(person* p);
void print_h();

int list_size(person* p);
const char* print_fs(person* p);
char* print_ld(person* p);
char* print_cd(person* p);
char* print_dir(person* p);

person* fixed_size(char* buffer);
person* ln_delim(char* buffer);
person* char_delim(char* buffer);
person* dir_ls(char* buffer);



char* names[10] = {"Goku","Vegeta","Krilin","Gohan","Saitama","Dio","Naruto","Sonic","Guts","Rintarou"};
char* surnames[10] = {"Sayan","Okabe","Pérez","the Hedgehog","Chasilema","Chávez","Yamamoto","Goebbels","Simpson","Mussolini"};
int main (int argc, char *argv[])
{
	srand(time(NULL));
	if(argc < 2)
	{
		printf("\nERROR: Insufficient parameters(<1)\n");
		print_h();
		return -1;
	}
	else if(argc > 2)
	{

		printf("\nERROR: Excess parameters (>1)\n");
		print_h();
		return -1;
	}
	else
	{
		//there's a correct number of arguments, let's go!
		if(!strcmp("-h",argv[1]))
			print_h();
		else 
		{
			//gen a list of people 
			person* hito = gen_person();
			hito->next = gen_person();
			hito->next->next = gen_person();
			//hito->next->next->next = gen_person();

			person* ningen = NULL;

			if(!strcmp("-l",argv[1]))
			{
			}
			else if(!strcmp("-f",argv[1]))
			{
				print_p(hito);
				char* buffer = print_fs(hito);
				printf("\nString containing list: %s\n",buffer);
				ningen = fixed_size(buffer);
				print_p(ningen);

			}
			else
			{
				printf("\nERROR: Unknown parameter.\n");
				print_h();
				return -1;
			}

			while(hito!=NULL)
			{
				person *tmp = hito;
				hito = hito->next;
				free(tmp);
			}	
			free(hito);
			while(ningen!=NULL)
			{
				person *tmp = ningen;
				ningen = ningen->next;
				free(tmp);
			}	
			free(ningen);

		}
	
	}
}
const char* print_fs(person* p)
{
	char name[20]; 
	char surname[20]; 
	int age = 0;
	char age_s[6];
	int ls = 44* (list_size(p));
	printf("\n%d\n",ls);
	char buffer[ls];

	int i=0;
	while(i<ls)	
	{
		buffer[i] = 0;
		i++;
	}
	while(p!=NULL)
	{
		memcpy(&name,p->given_name,20);
		memcpy(&surname,p->surname,20);
		age = p->age;
		sprintf(age_s,"%d",age);
		strcat(buffer,name);
		int c = 20-strlen(name);
		for(int i = 0; i < c; i++)
		{
			strcat(buffer,"-");
		}
		strcat(buffer,surname);
		c = 20-strlen(surname);
		for(int i = 0; i < c; i++)
		{
			strcat(buffer,"-");
		}

		strcat(buffer,age_s);
		c = 4-strlen(age_s);
		for(int i = 0; i < c; i++)
		{
			strcat(buffer,"-");
		}
		p = p->next;
	}
	return buffer;
}
person* fixed_size(char* buffer)
{
	person* p = (person*)malloc(sizeof(person));
	char name[20];
	for(int i = 0;i<20;i++)	name[i] = 0;
	char surname[20];
	for(int i = 0;i<20;i++)	surname[i] = 0;
	int pointer =0;
	
	printf("\n%s\n",buffer);
	strncpy(&name,buffer,20);
	//name[20] = '\0';
	strncpy(&surname,buffer+20,20);
	//name[39] = '\0';
	strtok(&name,"-");
	//strtok(&surname,"-");
	p->given_name = name;
	p->surname = surname;
	return p;
}



/** 
 * 	BEGIN RANDOM UTILS 
 * 	(these should really be in another .c
 * 	but lol i's lazy
 **/



int list_size(person* p)
{
	int counter = 0;
	while(p != NULL)
	{
		counter++;
		p = p->next;
	}
	printf("\n%d\n",counter);
	return counter;
}



//Generate a random person struct with random attributes
person* gen_person()
{
	person* p = (person*)malloc(sizeof(person));
	p->given_name = names[rand()%10]; 
	p->surname = surnames[rand()%10]; 
	p->age = rand()%123;	
	p->next = NULL;
	return p;
}
//print the persons crap
void print_p(person* p)
{
	while( p!=NULL)	
	{
		printf("\nName: %s %s\nAge: %d",p->given_name,p->surname,p->age);
		p = p->next;
	}
	printf("\n##END OF LIST##\n");
}
//print the helpening help of help halp pls
void print_h()
{
	
	printf("\nUsage: clone [OPTION]\n");
	printf("Clone a list of various different data structures to another one, passing through a char*.");
	printf("\nArguments choose the data structure:");
	printf("\n\n-f\tFixed Size\n-l\tLength Indicator\n-c\tDelimiting Char\n-d\tDirction List");
	printf("\n-h\tPrint this help page\n\n");
}

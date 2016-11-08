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
char* print_fs(person* p);
char* length_delim(person* p);
char* char_delim(person* p);
char* dir_list(person* p);

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
			hito->next->next->next = gen_person();

			if(!strcmp("-l",argv[1]))
			{
			}
			else if(!strcmp("-f",argv[1]))
			{
				print_p(hito);
				char* buffer = print_fs(hito);
				printf("\nString containing list: %s\n",buffer);

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
		}
	
	}
}
char* print_fs(person* p)
{
	char name[20]; 
	char surname[20]; 
	int age = 0;
	char age_s[6];
	int ls = 44* list_size(p);
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
		strcat(buffer,surname);
		strcat(buffer,age_s);
		p = p->next;
	}
	return buffer;
}


int list_size(person* p)
{
	int counter = 1;
	while(p != NULL)
	{
		counter++;
		p = p->next;
	}
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
		printf("Name: %s %s\nAge: %d\n",p->given_name,p->surname,p->age);
		p = p->next;
	}
	printf("##END OF LIST##\n");
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

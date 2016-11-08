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
void printp(person* p);
void printh();

char* fixed_size(person* p);
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
		printh();
	}
	else if(argc > 2)
	{

		printf("\nERROR: Excess parameters (>1)\n");
		printh();
	}
	else
	{

		if(!strcmp("-h",argv[1]))
			printh();
		else 
		{

			person* hito = gen_person();
			if(!strcmp("-f",argv[1]))
			{
				char* buffer = fixed_size(hito);
			}
			printp(hito);
			free(hito);
		}
	
	}
}
char* fixed_size(person* p)
{

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
void printp(person* p)
{
	printf("\nName: %s %s\nAge: %d\n\n",p->given_name,p->surname,p->age);
}
//print the helpening help of help halp pls
void printh()
{
	
	printf("\nUsage: clone [OPTION]\n");
	printf("Clone a list of various different data structures to another one, passing through a char*.");
	printf("\nArguments choose the data structure:");
	printf("\n\n-f\tFixed Size\n-l\tLength Indicator\n-c\tDelimiting Char\n-d\tDirction List");
	printf("\n-h\tPrint this help page\n\n");
}

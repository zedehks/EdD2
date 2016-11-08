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

person gen_person();
void printp(person p);

char* names[10] = {"Goku","Vegeta","Krilin","Gohan","Saitama","Dio","Naruto","Sonic","Guts","Rintarou"};
char* surnames[10] = {"Sayan","Okabe","Pérez","the Hedgehog","Chasilema","Chávez","Yamamoto","Goebbels","Simpson","Mussolini"};
int main (int argc, char *argv[])
{
	srand(time(NULL));
		if(argc < 2 || !strcmp("-h",argv[2]))
		{
			printf("\nUsage: clone [OPTION]\n");
			printf("Clone a list of various different data structures to another one, passing through a char*.");
			printf("\nArguments choose the data structure:");
			printf("\n\n-f\tFixed Size\n-l\tLength Indicator\n-c\tDelimiting Char\n-d\tDirction List");
			printf("\n-h\tPrint this help page\n\n");
		}
	person hito= gen_person();
	&(hito.next) = gen_person();
	//hito->next->next = gen_person();
	
	//person* temp = hito;
	//while(temp->next != NULL)
	{
		printp(hito);
		//temp = temp->next;
	}

}

person gen_person()
{
	person p;
	p.given_name = names[rand()%10]; 
	p.surname = surnames[rand()%10]; 
	p.age = rand()%123;	
	p.next = NULL;
	return p;
}

void printp(person p)
{
	printf("\nName: %s %s\nAge: %d\n\n",p.given_name,p.surname,p.age);
}

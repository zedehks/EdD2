#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printstring(char* c)
{
	printf("\n%s\n",c);
}
char* getstring()
{
	return "benis";
}
int main()
{
	char* s = getstring();
	printstring(s);
}

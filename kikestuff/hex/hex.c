#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* foo=fopen("foo","r+");
	if(foo==NULL)
		printf("\nSOMETHINGS NOT RIGHT WITH THE FOO\nPANIC HALP\n\n");

	int buffer[5]={0,0,0,0,0};
	int benis = 0;

	fread(&benis,1,1,foo);
	fclose(foo);
	/*for(int i=0;i<5;i++)
		printf("\n%c\n",buffer[i]);*/
	printf("%d",benis);
}	

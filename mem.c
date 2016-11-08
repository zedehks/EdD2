#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	int a;
	int b;
	char* c;
}meme;

int main()
{
	meme dank;
	dank.a = 5318008;
	dank.b = 1488;
	dank.c = "He did nothing wrong";
	

	printf("\ndank meme: %d\t%d\t%s",dank.a,dank.b,dank.c);

	int size = (sizeof(dank));
	printf("\nsize of dank meme: %d\n",size);

	char* memory;
       	memcpy(memory,&(dank),size);
	printf("dank meme is now stored in char* memory as: %s\n",memory);

	meme stale;
	memcpy(&stale,memory,size); 

	printf("copied memory to stale meme\nstale meme: %d\t%d\t%s\n",stale.a,stale.b,stale.c);
	////printf("
}

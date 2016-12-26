#include <stdio.h>
#include <string.h>

int wordcount(char *string, int size );

int main(void)
{
	char str[100];
	int wordcountfinal;
	printf("Word Counter!\n");
	printf("=============\n");
	printf("Text to be analyzed : ");
	fgets(str, 100, stdin);
	wordcountfinal = wordcount(str, 100);
	printf("Word Count          : %d\n", wordcountfinal + 1);
	
return 0;
}


int wordcount(char *string, int size)
{

int i;
int count;
count = 0;

for ( i = 0; i < size; i++)
{
	if ( string[i] == ' ') { 
		count=count + 1;
	} else {
		count=count + 0;
	}
}

return count;
}

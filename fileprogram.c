#include <stdio.h>
#include <ctype.h>

void clear(void){
	char c = 0;
	while(getchar() != '\n');
	c = getchar();
}

int main(void){
	char inputfileName[31] ="";
	char outputfileName[31]="";
	char response;
	char c = 0;
	FILE *input = NULL;
	FILE *output = NULL;
	printf("CHANGE CASE\n");
	printf("============\n");
	printf("Enter U for upper, L for lower : ");
	scanf(" %c", &response);
	clear();
	printf("Enter a input file name: ");
	scanf(" %30[^\n]", inputfileName);
	clear();
	printf("Enter the output file name: ");
	scanf(" %30[^\n]", outputfileName);
	input = fopen(inputfileName, "r");
	output = fopen(outputfileName, "w");
	while(c != EOF){
	c = fgetc(input);
	if (c != EOF){
		if(response == 'U'){
		c = toupper(c); //convert c to uppercase version
		}else {
		 c = tolower(c);
		
		}
		fputc(c,output);
	}
}
	
fclose(input);
fclose(output);
return 0;
}

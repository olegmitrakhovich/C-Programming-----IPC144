#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void clear(void);
int main(void)
{
	int total,dicethrow,sumofdice,dice1,dice2,test;
	char after;
	printf("Game of Dice\n");
	printf("============\n");
	do{
	printf("Enter total sought : ");
	test=scanf("%d%c", &total, &after);
	if (test == 0){
		printf("** Invalid Input! Try Again! **\n");
		clear();
	} else if (after != '\n'){
		printf("** Invalid Input! Try Again! **\n");
		clear();
	} else
		printf("** Invalid Input! Try Again! **\n");
	}while (total >= 13 || 1 >= total);
	dicethrow = 0;
	srand(time(NULL));
	do{
	dicethrow++;
	dice1=rand();
	dice1=dice1 % 6 + 1;
	dice2=rand();
	dice2=dice2 % 6 + 1;
	printf("Result of throw %d : %d + %d\n", dicethrow, dice1,dice2); 
	sumofdice=dice1+dice2;
	}while (sumofdice != total);
	printf("You got your total in %d throws!\n", dicethrow);
return 0;
}

void clear(void)
{
	while (getchar() != '\n')
		;
}


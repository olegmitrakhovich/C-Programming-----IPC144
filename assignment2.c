#include <stdio.h>
#include <stdlib.h>
int getinteger(int min, int max);
void getdailydata(float *dailyhigh2, float *dailylow2, char *conditions2);
float average(float dailyhigh2, float dailylow2);
int display(int numdays2);
float symboltodraw (char conditions2, float dailyavg2);
char draw(char symboltodraw2, int amounttodraw);
void displayresult(int numdays2, float averageofdays2);
void clear(void);

int main(void)
{
	int numdays;
	int i;
	float sum = 0;
	float dailyhigh;
	float dailylow;
	char conditions;
	float dailyavg = 0;
	printf("weather Analyzer 2.0\n");
	printf("====================\n");
	printf("how many days of data?\n");
	numdays = getinteger(1,14);
	for(i = 0; i < numdays; i++){
		getdailydata(&dailyhigh, &dailylow, &conditions);
		//printf("dailiyhigh %f\n", dailyhigh);
		dailyavg = average(dailyhigh, dailylow);
		printf("Today's average temperature is: %.2f\n", dailyavg);
		sum += dailyavg;
		draw(symboltodraw(conditions, dailyavg), 20);
	}
	displayresult(numdays, (sum/numdays));
return 0;
}


int getinteger(int min, int max)
{
	int test, total;
	char after;
	do{
	printf("Enter an integer between 1 and 14: ");
	test=scanf("%d%c", &total, &after);
	if (test == 0){
		printf("ERROR! Try again!\n");
		clear();
	}else if (after != '\n'){
		printf("ERROR! Try again!\n");
		clear();
	}else
		printf("ERROR! Try again!\n");
	}while (total >= 15 || 0 >= total);
return total;
}


void getdailydata(float *dailyhigh2, float *dailylow2, char *conditions2)
{
	int rc, keeptrying;
	keeptrying = 1;
	float dailyhighnumber, dailylownumber;
	char conditions;
	char camo1;
	char camo2;
	do {
		printf("Enter today's high, low, and condition (c=cloudy, s=sunny, p=precipitation) separated by commas:");
		rc = scanf(" %f %c %f %c %c", &dailyhighnumber, &camo1, &dailylownumber, &camo2, &conditions);
		if (rc == 0) {
			printf("ERROR! Try again!\n");
			clear();
		}else if (camo1 != ',') {
			printf("ERROR! Try again!\n");
			clear();
		}else if (camo2 != ',') {
			printf("ERROR! Try again!\n");
			clear();
		}else if (dailyhighnumber < dailylownumber) {
			printf("ERROR! Try again!\n");
		}else
			keeptrying = 0;
	} while (keeptrying == 1);  
	//scanf(" %c", &conditions);
	printf("dailyhigh=%f\n", dailyhighnumber);
	printf("dailylow=%f\n", dailylownumber);
	printf("conditions=%c\n", conditions);
}

float average(float dailyhigh2, float dailylow2)
{
	printf("TEST3!\n");
}

int display(int numdays2)
{
	printf("TEST4!\n");
}

float symboltodraw(char conditions2, float dailyavg2)
{
	printf("TEST5!\n");
}

char draw(char symboltodraw2, int amounttodraw)
{
	printf("TEST6!\n");
}

void displayresult(int numdays2, float averageofdays2)
{
	printf("TEST7!\n");
}

void clear(void)
{
	while (getchar() != '\n')
		;
}

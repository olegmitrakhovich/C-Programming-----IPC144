#include <stdio.h>
#include <stdlib.h>

int getinteger(int min, int max);
void getdailydata(float *dailyhigh2, float *dailylow2, char *conditions2);
float average(float dailyhigh2, float dailylow2);
float symboltodraw (char conditions2, float dailyavg2);
char draw(char symboltodraw2, int amounttodraw);
void displayresult(int numdays2, float averageofdays2);
void clear(void);

//Function copied from the IPC144 website
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
		//getinput from the user
		getdailydata(&dailyhigh, &dailylow, &conditions);
		//printf("dailyhigh = %f dailylow = %f conditions=%c\n", dailyhigh, dailylow, conditions);
		dailyavg = average(dailyhigh, dailylow);
		printf("Today's average temperature is: %.2f\n", dailyavg);
		sum += dailyavg;
		draw(symboltodraw(conditions, dailyavg), 20);
	}
	displayresult(numdays, (sum/numdays));
return 0;
}

/*
Asks the user to enter a number between 1 and 14, results in an error, 
if the user enters a higher number then 14 or any other character that 
is not a number. Doesn't allow decimal points. Clears the buffer everytime there is an error.
*/
int getinteger(int min, int max)
{
	int test, total, nothing;
	char after;
	do{
	printf("Enter an integer between 1 and 14: ");
	test=scanf("%d%c", &total, &after);
	if (test == 0){
		printf("ERROR! Try again!\n");
		clear();
	//}else if (after != '\n'){
	//	printf("ERROR! Try again!\n");
	//	clear();
	}else if (total > 14 || 0 >= total){
		printf("ERROR! Try again!\n");
	}else
		nothing = 1;
	}while (total >= 15 || 1 > total);
return total;
}

/*
Requests the user to enter his/her data separated by commas. I split the input into separate number integers, so if the user wishes to enter '13.5', the function
actually registers the input as int dailyhighnumber = '13' decimalpoint1 = '.' and int after1 = 5. The function runs through a validation cycle to see if all those characters have been inserted, this is also to make sure 
that user is only able to enter a floating point numbers. The function then converts the ' 5 ' into a floating point number by dividing it by 10.00, which in turn will give you 0.5. The function then adds the 0.5 to the dailyhigh 
number. Function also makes sure that incase of the negative number input, the calculation of adding the decimal integers is done properly, and it will subtract from the negative number instead of adding, the get the correct 
final answer. Function also compares the two inputs, and returns an error if the dailyhighnumber is lower then dailylownumber. Function will return an error if the users puts in "13.-5". Function will return an Error if any other 
characters other then c, s or p are entered.
*/ 
void getdailydata(float *dailyhigh2, float *dailylow2, char *conditions2)
{
	int rc, keeptrying, testint, testint3, endloop, dailyhighnumber, dailylownumber, after1, after2;
	keeptrying = 1;
	float dailyhighnumberf, dailylownumberf,testint2, testint4, firsttest1, firsttest2,after1f,after2f;
	dailyhighnumberf = 0;
	dailylownumberf = 0;
	char conditions;
	char commas1;
	char commas2;
	char decimalpoint1;
	char decimalpoint2;
do {
	if (dailyhighnumberf < dailylownumberf){
		printf("ERROR! Try again!\n");
		//clear();
	}
	do {
		printf("Enter today's high, low, and condition (c=cloudy, s=sunny, p=precipitation) separated by commas:");
		rc = scanf("%d %c %1d %c %d %c %1d %c %c", &dailyhighnumber, &decimalpoint1, &after1, &commas1, &dailylownumber, &decimalpoint2, &after2, &commas2, &conditions);
		if (rc == 0) {
			printf("ERROR! Try again!\n");
			clear();
		}else if (dailyhighnumber = '\n'){
			printf("ERROR! Try again!\n");
			clear();
		}else if (commas1 != ',') {
			printf("ERROR! Try again!\n");
			clear();
		}else if (commas2 != ',') {
			printf("ERROR! Try again!\n");
			clear();
		}else if (decimalpoint1 != '.') {
			printf("ERROR! Try again!\n");
			clear();
		}else if (decimalpoint2 != '.') {
			printf("ERROR! Try again!\n");
			clear();
		}else if (conditions != 'c' && conditions != 's' && conditions != 'p') {
			printf("ERROR! Try again!\n");
			clear();
		}else if (after1 < 0) {
			printf("ERROR! Try again!\n");
			clear();
		}else if (after2 < 0) {
			printf("ERROR! Try again!\n");
			clear();
		}else if (dailyhighnumber < dailylownumber) {
			printf("ERROR! Try again!\n");
		}else
			keeptrying = 0;
	} while (keeptrying == 1);  
	
//putting the inputs together into one floating point number. Incase of a negative input for daily tempreature, will subtract.
	after1f = after1;
	after1f = after1f / 10.0;
	if (dailyhighnumber <= 0.0){
		dailyhighnumberf = dailyhighnumber;
		dailyhighnumberf = dailyhighnumberf - after1f - after1f;
		//dailyhighnumberf = dailyhighnumberf - 1.00;
	}else
		dailyhighnumberf = dailyhighnumber;
		dailyhighnumberf = dailyhighnumberf + after1f;
	
	after2f = after2; 
	after2f = after2f / 10.0;
	
	if (dailylownumber <= 0.0) {
		dailylownumberf = dailylownumber;
		dailylownumberf = dailylownumberf - after2f - after2f;
		//dailylownumberf = dailylownumberf - 1.00;
	}else
		dailylownumberf = dailylownumber;
		dailylownumberf = dailylownumberf + after2f;

} while (dailyhighnumberf < dailylownumberf);		

	*dailyhigh2 = dailyhighnumberf;
	*dailylow2 = dailylownumberf;
	*conditions2 = conditions;
}

//calculates and prints the average temperature for two days.
float average(float dailyhigh2, float dailylow2)
{
	float avgtwodays;
	avgtwodays = dailyhigh2 + dailylow2;
	avgtwodays = avgtwodays / 2.00;

return avgtwodays;
}

//this function figures out which symbol is needed to be used depending on the condition letter and the average daily temperature.
float symboltodraw(char conditions2, float dailyavg2)
{
	char symbol;
	if (conditions2 == 's') {
		symbol = '@';
	}else if (conditions2 == 'c'){
		symbol = '~';
	}else if ((conditions2 == 'p') && (dailyavg2 <= 0)){
		symbol = '*';
	}else if ((conditions2 == 'p') && (dailyavg2 > 0)){
		symbol = ';';
}
return symbol;
}

// prints the symbol 20 times, all on one line.
char draw(char symboltodraw2, int amounttodraw)
{
	int i;
	i = 0;
	do{
		printf("%c", symboltodraw2);
		i++;
	}while (i < amounttodraw);
	printf("\n");
}

//displays a different sentence depending on the number of days.
void displayresult(int numdays2, float averageofdays2)
{
	if (numdays2 == 1){
		printf("Your one day average is %.2f", averageofdays2);
	}else if (numdays2 == 2){
		printf ("Your two day average is %.2f", averageofdays2);
	}else if (numdays2 == 3){
		printf ("Your three day average is %.2f", averageofdays2);
	}else if (numdays2 == 4){
		printf ("Your four day averahe is %.2f", averageofdays2);
	}else if (numdays2 == 5){
		printf ("Your five day average is %.2f", averageofdays2);
	}else if (numdays2 == 6){
		printf ("Your six day average is %.2f", averageofdays2);
	}else if (numdays2 == 7){
		printf ("Your seven day average is %.2f", averageofdays2);
	}else if (numdays2 == 8){
		printf ("Your eight day average is %.2f", averageofdays2);
	}else if (numdays2 == 9){
		printf ("Your nine day average is %.2f", averageofdays2);
	}else
		printf ("Your %d day average is %.2f", numdays2, averageofdays2);
printf("\n");
}

void clear(void)
{
	while (getchar() != '\n')
		;
}

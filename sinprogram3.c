#include <stdio.h>


int main(void){
	int number1, number2,number3, number4, number5, number6, 
	number7, number8, checkdigit, weightedsum, weightedsum8, 
	weightedsum6, weightedsum4, weightedsum2, enter;
	do
	{
	printf("********************SIN VALIDATOR********************\n");
	printf("Please enter your 9 digit Social Insurance Number:");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d\n", &number1, &number2, 
	&number3, &number4, &number5, &number6, &number7, &number8, 
	&checkdigit);
	printf("Your SIN#: %d %d %d %d %d %d %d %d %d\n", number1, 
	number2, number3, number4, number5, number6, number7, number8, 
	checkdigit);
} while (number1 > 0);
	do
	{
	int sum8 = 0;
	weightedsum8 = number8*2;
	while (weightedsum8 != 0) {
		sum8 += weightedsum8 % 10;
		weightedsum8 /=10;
}
	int sum6 = 0;
	weightedsum6 = number6*2;
	while (weightedsum6 != 0) {
		sum6 += weightedsum6 % 10;
		weightedsum6 /=10;
} 
	int sum4 = 0;
	weightedsum4 = number4*2;
	while (weightedsum4 != 0) {
		sum4 += weightedsum4 % 10;
		weightedsum4 /=10;
}
	int sum2 = 0;
	weightedsum2 = number2*2;
	while (weightedsum2 != 0) {
		sum2+= weightedsum2 % 10;
		weightedsum2 /=10;
} 
	int sumsum = sum8 + sum6 + sum4 + sum2;
	int alternativesum = number1 + number3 + number5 + number7;
	int total = alternativesum + sumsum;
	int totalcheck;
	totalcheck = total % 10;
	totalcheck = totalcheck + checkdigit;
	if (totalcheck == 10){
		printf ("Your SIN#: number is correct\n");
	} else {
		printf ("Your SIN#: number is incorrect\n");
}

} while (number1 > 0);
	 return 0;
}

		




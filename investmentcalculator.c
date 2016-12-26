#include <stdio.h>

float calculation(float priamount, float rate, float period)
{
	float result1, result2, result0;
	
	result0 = 1 + rate;
	result1 = priamount * result0; 
	result2 = result1 * period;
	
	return 0;	
}

int main(void)
{
	float priamount, rate, period, result2;
	printf("Please Enter your principal amount:");
	scanf("%f\n", &priamount);
	getchar();
	printf("Please Enter your annual rate:");
	scanf("%f\n", &rate);
	getchar();
	printf("Please Enter your number of years:");
	scanf("%f\n", &period);
	getchar();
	printf("The future value is:%f\n", &result2);
return 0;
} 
	
	


#include <stdio.h>

float calculation(float priamount, float rate, float period)
{
	float n, result1, result2, result0; 
	result0 = 1 + rate; 						//declaring result0 as rate plus one.
	n = 0;              						// n is a loop counter declared as zero.
	result1 = 1;        						//declared result1 as one, to ensure that during the multiplication process the first value multipled is not 0.
	while (n < period){ 						//loop keeps multiplying untill the value of n is higher then period.	
	result1 = result1 * result0; 					//mutiplying rate plus one and storing the result in result1.
	n = n + 1;							//adding one to n each time the cycle of the loop is complete.
	}
	result2 = result1 * priamount;  				//mutiplying the end value of result1 by principalamount and storing it in result2.
	return result2;	
}

int main(void)
{
	float priamount, rate, period, answer;
	printf("Please Enter your principal amount:");
	scanf("%f\n", &priamount);
	getchar();
	printf("Please Enter your annual rate:");
	scanf("%f\n", &rate);
	getchar();
	printf("Please Enter your number of years:");
	scanf("%f\n", &period);
	getchar();
	printf("Investment Calculator\n");
	printf("======================\n");
	printf("Principal    : %.0f \n", priamount);
	printf("Annual Rate  : %.2f \n", rate);
	printf("No of Years  : %.0f \n", period);
	answer = calculation(priamount, rate, period);
	printf("The future value is %.2f\n", answer);
return 0;
} 
	
	


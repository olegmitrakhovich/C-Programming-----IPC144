#include <stdio.h>

int main(void)
{
	int days, a;
	a = 1;
	float todayhigh, todaylow, todayavg, weekavg, count,count1,count2,count3,count4,count5,count6,count7;
	count=0;
	char condition;
	printf("Weather Analyzer\n");
	printf("================\n");
	do{										// first loop, makes sure the user entered a valid integer for days, input must be above 0 and not equal to 0
	printf("please enter a positive number of days:");
	scanf(" %d",&days);
	printf("\n");
	} while (0 >= days);
	do{										// Second loop, user gets promoted to enter data. The loop repeats itself depending on amount of days was entered above
	printf("\n");
	printf("\n");
	printf("Enter todays's high:");
	scanf ("%f", &todayhigh);
	printf("\n");
	printf("Enter today's low:");
	scanf ("%f", &todaylow);
	printf("\n");
	printf("Enter today's conditions s: sunny, c: cloudy, p: precipitation:");
	scanf (" %c", &condition);
	printf("\n");
	todayavg = 0;
	todayavg = todayhigh+todaylow;
	todayavg = todayavg / 2;
	printf("Today's Average temperature is: %.2f\n", todayavg);	
	printf("\n");
	{
	if (condition == 's') {
		printf("%.*s", 20, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"); // another programmer can control the amouunt of characters displayed by changing the number from 20 to whatever is needed.
	}else if (condition == 'c') {
		printf("%.*s", 20, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	}else if ((condition == 'p') && (todayavg <= 0)) {
		printf("%.*s", 20, "************************************************************");
	}else if ((condition = 'p') && (todayavg > 0))
		printf("%.*s", 20, ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;");
	}
	a=a+1;
	count++;
	if (count == 1){									// third loop, data from "todayavg" get stored and redistributed between diffrent "count" variables
		count1 = todayavg;
	}else if (count == 2){
		count2 = todayavg;
	}else if (count == 3){
		count3 = todayavg;
	}else if (count == 4){
		count4 = todayavg;
	}else if (count == 5){
		count5 = todayavg;
	}else if (count == 6){
		count6 = todayavg;
	}else if (count == 7){
		count7 = todayavg;
	}
	} while (days >= a);
	weekavg=count1+count2+count3+count4+count5+count6+count7;				// stored "count" data from each iteration of the second loop gets added up, and divided by days	
	weekavg=weekavg/days;
	printf("\n");
	printf("\n");
	printf("Average for all %d days is: %.2f degrees\n", days, weekavg);
	printf("\n");
	return 0;
}


	
	


	

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*V 1.1:
Changes:

1) declared i outside of loop, you don't need -std=c99 to compile anymore
2) added a check for existence of historicaldata.csv
*/

/*an instance of this struct holds the weather data for a single day*/

struct DailyData{
    int day;
    int month;
    int year;
    float high;
    float low;
    float precipitation;
    char condition;
};

/*an instance of this struct holds summary information for the weather
for a given month*/

struct MonthlyStatistic{
    float minTemperature;
    float maxTemperature;
    float averageTemperature;
    float totalPrecipitation;
};

int readDailyData(FILE* fp, struct DailyData allData[]);
int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz,  struct DailyData yearData[]);
void sortYearData(struct DailyData yearData[], int sz);
void getStats(int month, const struct DailyData yearData[],int sz, struct MonthlyStatistic* monthStats);
void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly);
void graphLine(int month, const struct MonthlyStatistic* monthly);
void printVerbose(const struct DailyData yearData[],int sz);
char symbolToDraw(char condition, float avgTemp);
float average(float first, float second);
void draw( char c, int num );
float getmintemp(int month, const struct DailyData yearData[], int x);
float getmonthavg(int month, const struct DailyData yearData[], int sz);
float gettotalprecip(int month, const struct DailyData yearData[], int sz);

int main(void){
    FILE* fp = fopen("historicaldata.csv","r");
    if(!fp){
        printf("you need to put historicaldata.csv into this directory\n");
        exit(0);
    }
    struct DailyData  allData[3000];
    struct DailyData yearData[366];
    int numTotalRecords;

    numTotalRecords = readDailyData(fp, allData);
    int year;
    int reportType;
    int i;
    struct MonthlyStatistic monthly[12];
    printf("Please enter the year for the report: ");
    scanf("%d",&year);
    printf("Please enter the type of report you wish to generate:\n");
    printf("1) summary\n");
    printf("2) detailed\n");
    scanf("%d",&reportType);
    int numDays = getRelevantRecords(year,allData,numTotalRecords,yearData);
    sortYearData(yearData,numDays);

    for(i=0;i < 12 ;i++){
        getStats(i+1,yearData,numDays,&monthly[i]);
    }

    printf("Weather summary for %d\n",year);
    printf("|   Month   | High  |  Low  |  Avg  | Precip  |\n");
    printf("|-----------|-------|-------|-------|---------|\n");
    for(i=0;i<12;i++){
        printMonthlyStatistic(i+1,&monthly[i]);
    }
    printf("\n\n");
    printf("Precipitation Graph\n\n");
    for (i=0;i<12;i++){
        graphLine(i+1,&monthly[i]);
    }
    if(reportType == 2){
        printf("\n\n");
        printf("Detailed report:\n");
        printVerbose(yearData,numDays);
    }
    return 0;
}


int readDailyData(FILE* fp, struct DailyData allData[]){
    int i=0;
    while(fscanf(fp,"%d,%d,%d,%f,%f,%f,%c\n",
        &allData[i].year,&allData[i].month,&allData[i].day,
        &allData[i].high,&allData[i].low,&allData[i].precipitation,
        &allData[i].condition) == 7){
        i++;
    }
    return i;
}

int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz,  struct DailyData yearData[]){
	int i, x, q, z, j;
	float c;
	x = 0;
	q = 0;
	z = 0;
	j = 0;
	char con;
	//printf("%d\n", yearWanted);
		for(i=0; i < 3000; i++){ 
		if (allData[i].year == yearWanted){
			c = allData[i].year;
			yearData[x].year = c;
			c = allData[i].month; 
			yearData[x].month = c;
			c = allData[i].day; 
			yearData[x].day = c;
			c = allData[i].high;
			yearData[x].high = c;
			c = allData[i].low;
			yearData[x].low = c;
			c = allData[i].precipitation;
			yearData[x].precipitation = c;
			con = allData[i].condition;
			yearData[x].condition = con;
			x = x + 1;		
		}else
			//printf("nothing!");
			q = q + 1; 
		}
		sz = x;
		
		//do{
		//printf("#%d %d, %d, %d, %.2f, %.2f, %.2f, %c\n",j , yearData[z].year, yearData[z].month, yearData[z].day,yearData[z].high,yearData[z].low,yearData[z].precipitation,yearData[z].condition);
		//z++;
		//j++;
		//}while (z < sz);	
	       // put your code here
}

void sortYearData(struct DailyData yearData[], int sz){
    	
int i, j, a, n, x, z;
a = 0;
n = 0; 

float h, l, p;

char con;

for (i = 0; i < sz; i++)
{
	for (j = i + 1; j < sz; j++)
	{
			if (yearData[i].month > yearData[j].month) 
			{
			a = yearData[i].month;
			yearData[i].month = yearData[j].month;
			yearData[j].month = a;
			z = yearData[i].day;
			yearData[i].day = yearData[j].day;
			yearData[j].day = z;
			h = yearData[i].high;  
			yearData[i].high = yearData[j].high;
			yearData[j].high = h;
			l = yearData[i].low;
			//printf("DEBUG %.2f\n", yearData[i].low);
                        yearData[i].low = yearData[j].low;
                        yearData[j].low = l;
			p = yearData[i].precipitation;
                        yearData[i].precipitation = yearData[j].precipitation;
                        yearData[j].precipitation = p;
			con = yearData[i].condition;
                        yearData[i].condition = yearData[j].condition;
                        yearData[j].condition = con;

		}
	}
}

a = 0; 
n = 0; 
x = 0;
j = 0;

for (i = 0; i < sz; ++i)
{
        for (j = i + 1; j < sz; ++j)
        {
                        if ((yearData[i].day > yearData[j].day) && (yearData[i].month == yearData[j].month))
                        {
                        a = yearData[i].month;
                        yearData[i].month = yearData[j].month;
                        yearData[j].month = a;
                        z = yearData[i].day;
                        yearData[i].day = yearData[j].day;
                        yearData[j].day = z;
                        h = yearData[i].high;
                        yearData[i].high = yearData[j].high;
                        yearData[j].high = h;
                        l = yearData[i].low;
                        yearData[i].low = yearData[j].low;
                        yearData[j].low = l;
                        p = yearData[i].precipitation;
                        yearData[i].precipitation = yearData[j].precipitation;
                        yearData[j].precipitation = p;
                        con = yearData[i].condition;
                        yearData[i].condition = yearData[j].condition;
                        yearData[j].condition = con;

                }
        }
} 


	//printf("number of days %d\n", sz);
	//do{
	//printf("sorted data %d %d %d %.2f %.2f %.2f %c\n", yearData[x].year, yearData[x].month, yearData[x].day, yearData[x].high, yearData[x].low, yearData[x].precipitation, yearData[x].condition);
	//x++;
	//}while (x < sz );
}

void getStats(int month, const struct DailyData yearData[], int sz, struct MonthlyStatistic* monthly){
	float highestmonth, lowestmonth, avgtemp1, avgtemp2, totalavg, totalprecip;
	int i, x, z, count;
	count = sz;
	highestmonth = 0;
	lowestmonth = 0;
	//printf("int sz %d\n", sz);

		
do{ 
	if (yearData[i].high > highestmonth)
	{
	highestmonth = yearData[i].high;
	}
	i++;
}while (yearData[i].month == month);		  
	monthly->maxTemperature = highestmonth; 	

	lowestmonth = getmintemp(month, yearData, i);
	monthly->minTemperature = lowestmonth;
	avgtemp1 = getmonthavg(month, yearData, sz);
	monthly->averageTemperature = avgtemp1;
	totalprecip = gettotalprecip(month, yearData,sz);
	monthly->totalPrecipitation = totalprecip;
}

float gettotalprecip(int month, const struct DailyData yearData[], int sz){
	int z;
	float total;
	total = 0;
	for(z = 0; z < sz; z++){
        if (yearData[z].month == month)
        {
                total = total + yearData[z].precipitation;
        }
}
return total;
}

float getmonthavg(int month, const struct DailyData yearData[], int sz){
	int z , i;
	z = 0;
	i = 0;
	float avgtemp1, avgtemp2;
	avgtemp1 = 0;
	avgtemp2 = 0;
for(z = 0; z < sz; z++){
	avgtemp2 = avgtemp2 + avgtemp1;
	avgtemp1 = 0;
	if (yearData[z].month == month)
	{
        	avgtemp1 = avgtemp1 + yearData[z].high;
        	avgtemp1 = avgtemp1 + yearData[z].low;
        	avgtemp1 = avgtemp1 / 2;
		i++;
	}
}
avgtemp2 = avgtemp2 / i;
return avgtemp2;
}
  

float getmintemp(int month, const struct DailyData yearData[], int x){
	float lowestmonth;
	lowestmonth = 100;
	int i;
	i = x - 1;
do{
        if (yearData[i].low < lowestmonth)
        {
        lowestmonth = yearData[i].low;
        }
        i--;
}while (yearData[i].month == yearData[x - 1].month);
	return lowestmonth;
 	
}

void printMonthlyStatistic(int month,const struct MonthlyStatistic* monthly){
	int i;
	char month1[10] = "January";
	char month2[10] = "February";
	char month3[10] = "March";
	char month4[10] = "April";
	char month5[10] = "May";
	char month6[10] = "June";
	char month7[10] = "July";
	char month8[10] = "August";
	char month9[10] = "September";
	char month10[10] = "October";
	char month11[10] = "November";
	char month12[10] = "December";


	if (month == 1){
	printf("|%11s|%7.1f|%7.1f|%7.1f|%9.1f|\n", month1, monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature,  monthly->totalPrecipitation);
	}else if (month == 2){
	printf("|%11s|%7.1f|%7.1f|%7.1f|%9.1f|\n", month2, monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature,  monthly->totalPrecipitation);
	}else if (month == 3){
        printf("|%11s|%7.1f|%7.1f|%7.1f|%9.1f|\n", month3, monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature,  monthly->totalPrecipitation);
        }else if (month == 4){
        printf("|%11s|%7.1f|%7.1f|%7.1f|%9.1f|\n", month4, monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature,  monthly->totalPrecipitation);
        }else if (month == 5){
        printf("|%11s|%7.1f|%7.1f|%7.1f|%9.1f|\n", month5, monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature,  monthly->totalPrecipitation);
        }else if (month == 6){
        printf("|%11s|%7.1f|%7.1f|%7.1f|%9.1f|\n", month6, monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature,  monthly->totalPrecipitation);
        }else if (month == 7){
        printf("|%11s|%7.1f|%7.1f|%7.1f|%9.1f|\n", month7, monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature,  monthly->totalPrecipitation);
        }else if (month == 8){
        printf("|%11s|%7.1f|%7.1f|%7.1f|%9.1f|\n", month8, monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature,  monthly->totalPrecipitation);
        }else if (month == 9){
        printf("|%11s|%7.1f|%7.1f|%7.1f|%9.1f|\n", month9, monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature,  monthly->totalPrecipitation);
        }else if (month == 10){
        printf("|%11s|%7.1f|%7.1f|%7.1f|%9.1f|\n", month10, monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature,  monthly->totalPrecipitation);
        }else if (month == 11){
        printf("|%11s|%7.1f|%7.1f|%7.1f|%9.1f|\n", month11, monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature,  monthly->totalPrecipitation);
        }else if (month == 12){
        printf("|%11s|%7.1f|%7.1f|%7.1f|%9.1f|\n", month12, monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature,  monthly->totalPrecipitation);
        }


    //put your code here
}

void graphLine(int month,const struct MonthlyStatistic* monthly){

	float i, b;
	int c , x;
	i = 0;
	b = 0;
	c = 0;
	i = monthly->totalPrecipitation;
	c = i;
	x = i / 10;
	c = c % 10;
	if (c > 5){
		c = x + 1;
	}else{
		c = x;
}
	
	if (month == 1){
		printf("   January|");
		do{
		printf("*");
		c--;
		}while (c > 0);
	printf("\n");
}    

 	if (month == 2){
                printf("  February|");
                do{
                printf("*");
                c--;
                }while (c > 0);
	printf("\n");
}
	 if (month == 3){
                printf("     March|");
                do{
                printf("*");
                c--;
                }while (c > 0);
        printf("\n");
}

	 if (month == 4){
                printf("     April|");
                do{
                printf("*");
                c--;
                }while (c > 0);
        printf("\n");
}

 	if (month == 5){
                printf("       May|");
                do{
                printf("*");
                c--;
                }while (c > 0);
        printf("\n");
}

	 if (month == 6){
                printf("      June|");
                do{
                printf("*");
                c--;
                }while (c > 0);
        printf("\n");
}
	 if (month == 7){
                printf("      July|");
                do{
                printf("*");
                c--;
                }while (c > 0);
        printf("\n");
}
	 if (month == 8){
                printf("    August|");
                do{
                printf("*");
                c--;
                }while (c > 0);
        printf("\n");
}
 	if (month == 9){
                printf(" September|");
                do{
                printf("*");
                c--;
                }while (c > 0);
        printf("\n");
}
	 if (month == 10){
                printf("   October|");
                do{
                printf("*");
                c--;
                }while (c > 0);
        printf("\n");
}
	 if (month == 11){
                printf("  November|");
                do{
                printf("*");
                c--;
                }while (c > 0);
        printf("\n");
}
	 if (month == 12){
                printf("  December|");
                do{
                printf("*");
                c--;
                }while (c > 0);
        printf("\n");
}

 
}

void printVerbose(const struct DailyData yearData[],int sz){
	int i = 0;
	float avg;
	char symbol;
	do{
	if (yearData[i].month == 1){
		printf("  January  %2d %2d :", yearData[i].day, yearData[i].year); 
		avg = average(yearData[i].high, yearData[i].low);
		printf(" %6.1f ", avg);
		symbol = symbolToDraw(yearData[i].condition, avg);
		draw(symbol, 20);
	}else if (yearData[i].month == 2){
		printf(" February  %2d %2d :", yearData[i].day, yearData[i].year);
                avg = average(yearData[i].high, yearData[i].low);
                printf(" %6.1f ", avg);
                symbol = symbolToDraw(yearData[i].condition, avg);
                draw(symbol, 20);
	}else if (yearData[i].month == 3){
                printf("    March  %2d %2d :", yearData[i].day, yearData[i].year);
                avg = average(yearData[i].high, yearData[i].low);
                printf(" %6.1f ", avg);
                symbol = symbolToDraw(yearData[i].condition, avg);
                draw(symbol, 20);
  	}else if (yearData[i].month == 4){
                printf("    April  %2d %2d :", yearData[i].day, yearData[i].year);
                avg = average(yearData[i].high, yearData[i].low);
                printf(" %6.1f ", avg);
                symbol = symbolToDraw(yearData[i].condition, avg);
                draw(symbol, 20);
	}else if (yearData[i].month == 5){
                printf("      May  %2d %2d :", yearData[i].day, yearData[i].year);
                avg = average(yearData[i].high, yearData[i].low);
                printf(" %6.1f ", avg);
                symbol = symbolToDraw(yearData[i].condition, avg);
                draw(symbol, 20);
	}else if (yearData[i].month == 6){
                printf("     June  %2d %2d :", yearData[i].day, yearData[i].year);
                avg = average(yearData[i].high, yearData[i].low);
                printf(" %6.1f ", avg);
                symbol = symbolToDraw(yearData[i].condition, avg);
                draw(symbol, 20);
	}else if (yearData[i].month == 7){
                printf("     July  %2d %2d :", yearData[i].day, yearData[i].year);
                avg = average(yearData[i].high, yearData[i].low);
                printf(" %6.1f ", avg);
                symbol = symbolToDraw(yearData[i].condition, avg);
                draw(symbol, 20);
	}else if (yearData[i].month == 8){
                printf("   August  %2d %2d :", yearData[i].day, yearData[i].year);
                avg = average(yearData[i].high, yearData[i].low);
                printf(" %6.1f ", avg);
                symbol = symbolToDraw(yearData[i].condition, avg);
                draw(symbol, 20);
	}else if (yearData[i].month == 9){
                printf("September  %2d %2d :", yearData[i].day, yearData[i].year);
                avg = average(yearData[i].high, yearData[i].low);
                printf(" %6.1f ", avg);
                symbol = symbolToDraw(yearData[i].condition, avg);
                draw(symbol, 20);
	}else if (yearData[i].month == 10){
                printf("  October  %2d %2d :", yearData[i].day, yearData[i].year);
                avg = average(yearData[i].high, yearData[i].low);
                printf(" %6.1f ", avg);
                symbol = symbolToDraw(yearData[i].condition, avg);
                draw(symbol, 20);
	}else if (yearData[i].month == 11){
                printf(" November  %2d %2d :", yearData[i].day, yearData[i].year);
                avg = average(yearData[i].high, yearData[i].low);
                printf(" %6.1f ", avg);
                symbol = symbolToDraw(yearData[i].condition, avg);
                draw(symbol, 20);
	}else if (yearData[i].month == 12){
                printf(" December  %2d %2d :", yearData[i].day, yearData[i].year);
                avg = average(yearData[i].high, yearData[i].low);
                printf(" %6.1f ", avg);
                symbol = symbolToDraw(yearData[i].condition, avg);
                draw(symbol, 20);

	}    
	i++;
	}while (i < sz);
	//put your code here
}

char symbolToDraw(char condition, float avgTemp){
    	char symbol;
	if (condition == 's') {
		symbol = '@';
	}else if (condition == 'c'){
		symbol = '~';
	}else if ((condition == 'p') && (avgTemp <= 0)){
		symbol = '*';
	}else if ((condition == 'p') && (avgTemp > 0)){
		symbol = ';';
}
return symbol;
}

float average(float first, float second){
    	
	float avgtwodays;
	avgtwodays = first + second;
	avgtwodays = avgtwodays / 2.00;

	return avgtwodays;
}

void draw( char c, int num ){
	int i;
	i = 0;
	do{
	printf("%c", c);
	i++;
	}while (i < num);
	printf("\n");
}

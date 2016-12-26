#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "header.h"

using namespace std;


int main() {
	int number1 = 0, number2 = 0, number3 = 0, number4 = 0, number5 = 0, number6 = 0,
		number7 = 0, number8 = 0, checkdigit = 0;
	int* sinptr;
	do
	{
		cout << "********************SIN VALIDATOR********************" << endl;
		cout << "Please enter your 9 digit Social Insurance Number:" << endl;
			scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d\n", &number1, &number2,
				&number3, &number4, &number5, &number6, &number7, &number8,
				&checkdigit);
			getchar();
		cout << "Your SIN#: " << number1 << number2 << number3 << number4 << number5 << number6 << number7 << number8 << checkdigit;
		if (validation(number1, number2, number3, number4, number5, number6, number7, number8, checkdigit)) {
			cout << " Your sin number is correct" << endl;
		}
		else {
			cout << " Your sin number is incorrect" << endl;
		}
		

	} while (number1 > 0);

	int answer = 0;
	int i = 0;
	int x = 0;
	cout << "**************Welcome to SIN GENERATOR****************" << endl;
	cout << "How many SIN Numbers would you like to generate?" << endl;
	cin.ignore(1000, '\n');
	cin >> answer;
	int* ptr1;
	int* ptr2;
	int* ptr3;
	int* ptr4;
	int* ptr5;
	int* ptr6;
	int* ptr7;
	int* ptr8;
	int* ptr9;
	ptr1 = new int[answer];
	ptr2 = new int[answer];
	ptr3 = new int[answer];
	ptr4 = new int[answer];
	ptr5 = new int[answer];
	ptr6 = new int[answer];
	ptr7 = new int[answer];
	ptr8 = new int[answer];
	ptr9 = new int[answer];
	int z = 0;
	do {
		srand(time(NULL));
		ptr1[z] = number1 = rand() % 8 + 1;
		ptr2[z] = number2 = rand() % 8 + 1;
		ptr3[z] = number3 = rand() % 8 + 1;
		ptr4[z] = number4 = rand() % 8 + 1;
		ptr5[z] = number5 = rand() % 8 + 1;
		ptr6[z] = number6 = rand() % 8 + 1;
		ptr7[z] = number7 = rand() % 8 + 1;
		ptr8[z] = number8 = rand() % 8 + 1;
		ptr9[z] = checkdigit = rand() % 8 + 1; 
	
		if ((validation(number1, number2, number3, number4, number5, number6, number7, number8, checkdigit)) && (ptr1[z-1] != number1) && (ptr2[z-1] != number2) && (ptr3[z-1] != number3) && (ptr4[z - 1] != number4) && (ptr5[z - 1] != number5) && (ptr6[z - 1] != number6) && (ptr7[z - 1] != number7) && (ptr8[z - 1] != number8) && (ptr9[z - 1] != checkdigit)) {
			i++;
			cout << number1 << number2 << number3 << "-" << number4 << number5 << number6 << "-" << number7 << number8 << checkdigit << endl;
			z++;
		}
		//x++;
		//cout << x << endl;
		//cout << number1 << number2 << number3 << "-" << number4 << number5 << number6 << "-" << number7 << number8 << checkdigit << endl;
	} while (i < answer);

	return 0;
}

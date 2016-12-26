#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

using namespace std;

bool validation(int number1, int number2, int number3, int number4, int number5, int number6, int number7, int number8, int checkdigit) {
	int weightedsum = 0, weightedsum8 = 0, weightedsum6 = 0, weightedsum4 = 0, weightedsum2 = 0, enter = 0;
	int sum8 = 0;
	weightedsum8 = number8 * 2;
	while (weightedsum8 != 0) {
		sum8 += weightedsum8 % 10;
		weightedsum8 /= 10;
	}
	int sum6 = 0;
	weightedsum6 = number6 * 2;
	while (weightedsum6 != 0) {
		sum6 += weightedsum6 % 10;
		weightedsum6 /= 10;
	}
	int sum4 = 0;
	weightedsum4 = number4 * 2;
	while (weightedsum4 != 0) {
		sum4 += weightedsum4 % 10;
		weightedsum4 /= 10;
	}
	int sum2 = 0;
	weightedsum2 = number2 * 2;
	while (weightedsum2 != 0) {
		sum2 += weightedsum2 % 10;
		weightedsum2 /= 10;
	}
	int sumsum = sum8 + sum6 + sum4 + sum2;
	int alternativesum = number1 + number3 + number5 + number7;
	int total = alternativesum + sumsum;
	int totalcheck;
	totalcheck = total % 10;
	totalcheck = totalcheck + checkdigit;
	if (totalcheck == 10) {
		//cout << "Your SIN#: number is correct" << endl;
		return true;
	}
	else {
		//cout << "Your SIN#: number is incorrect" << endl;
		return false;
	}

}


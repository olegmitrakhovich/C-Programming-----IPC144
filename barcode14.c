#include <stdio.h>

void display (long long int a[], float b[], int c[], int n);
void clear(void);
int validintfunction(long long int barcodeint[], int x);
int validintfunction2(float priceint[], int x);
int validintfunction3(int quantityint[], int x);

//I'm using varibables test1,2,3 intialized as zero...as my varibables that will tell the "do while" loops to keep asking for barcode, quantity or price. For do while to stop running test must be equal to 2 or higher.
//Varibale is set at 100, that means that only 100 items can be entered, but a programmer can change that if they need to.
//Char After variable is used to test the quantity input is in fact an integer and not a charcacter or a decimal point, it makes sure they are no decimal points entered for quantity. 
int main(void)
{
	int i;
	int n = 100;
	int test;
	test = 0;
	int test2;
	test2 = 0;
	int test3;
	test3 = 0;
	long long int barcode[n]; 
	int quantity[n];
	float price[n], totalvalueofitems[n];
	char after;
	printf("Grocery Store Inventory\n");
	printf("=======================\n");
	for (i = 0; i <= n; n--){
		do{
			printf("Barcode  : ");
			scanf("%lld", &barcode[n]);
			test = validintfunction(barcode, n);
			test = test;
		}while (1 >= test );
		if (barcode[n] == 0){
			display(barcode, price, quantity, n+1);
		}else{
			do{
				printf("Price    : ");
				scanf("%f", &price[n]);
				test2 = validintfunction2(price, n);
				test2 = test2;
			}while (1 >= test2);
			do{
				printf("Quantity : ");
				scanf("%d%c", &quantity[n], &after);
				test3 = validintfunction3(quantity, n);
				test3 = test3;
				if (after != '\n'){
				test3 = 1;
				clear();
				}else
				test3 = 2;
			}while (1 >= test3);
		test = 0;
		test2 = 0;
		test3 = 0;	
		}
	}

return 0;
}

//checks if quanity is a valid number or equal to 0, I left this function in case a programer wants to change whether the user can or cant enter 0 as quantity.
int validintfunction3(int quantityint[], int x)
{
	int result;
	result = 0;
	int i;
	if (0 == quantityint[x]){
		result = 2;
	}else{
		result = 2;
}
return result;
}	

//checks if price is higher then 0, by comparing the input to zero and returns a varible result.
int validintfunction2(float priceint[], int x)
{
	int result;
	result = 0;
	int i;
	if (0 >= priceint[x]){
		result = 1;
	}else{
		result = 2;
}
return result;
}

//checks if the barcode has 10 digits, by setting a range for the number. If barcode is not within range the function will return as false.
int validintfunction(long long int barcodeint[], int x)
{
	int result;
	result = 0;
	int i;
	//for( i = 0; i <= x; x--){
	if (barcodeint[x] >= 9999999999){
		result = 1;
	}else if (barcodeint[x] == 0){
		result = 2;
	}else if (1000000000 >= barcodeint[x]){
		result = 1;
	}else{
		result = 2;
}
	result = result;	
return result;
}
		
	  	
//display function gets excuted when the users presses 0 as his input for barcode.
//stores the barcode integer as a long integer, also store the iteration of the loop as X,
// and we use that iteration to sort all other varible information.
void display(long long int a[], float b[], int c[], int x)
{
	int z;
	z = 100;
	int h;
	h = 100;
	float value[z];
	float sumofallgoods;
	sumofallgoods = 0;
	printf("        Goods in Stock\n");
	printf("        ==============\n");
	printf("Barcode    Price      Quantity    Value\n");
	printf("-----------------------------------------\n");
	do{
		value[z]= b[z] * c[z];
		printf("%lli  %.2f          %d      %.2f\n", a[z], b[z], c[z], value[z]);
		z--; 
	}while (z >= x);
	
	z=z+1;
	
	do{
		sumofallgoods=sumofallgoods+value[h];
		h--;
	}while (h >= z);
	printf("                                 --------\n");
	printf("Total Value of goods in stock     %.2f\n", sumofallgoods);	
}

//Clears the buffer after the input for quaintity is something that is not an integer
void clear(void)
{
	while (getchar() != '\n')
		;
}




	



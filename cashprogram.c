
#include <stdio.h>
int main(void)
{
	int itemsp, looniess;
	float itemsprice,hst, totalprice, cash, change,cents,purchaseprice;
	printf("How many items did you purchase today? Type Y when done\n");
	scanf("%d\n", &itemsp);
	getchar();
	printf("Items Purchased.......%d\n", itemsp);
	getchar();
	printf("What was the price of each unit? Type Y when done\n");
	scanf("%f\n", &itemsprice);
	getchar();
	printf("Each Item Price.......%.02f\n", itemsprice);
	purchaseprice = itemsp*itemsprice;
	printf("Total price...........%.02f\n", purchaseprice);
	hst = purchaseprice/7.69;
	printf("HST (13%).............%.02f\n", hst);
	totalprice=hst+purchaseprice;
	printf("Total Price...........%.02f\n", totalprice);
	printf("Insert money below:\n");
	scanf("%f\n", &cash);
	change = cash - totalprice;
	printf("Change................%.02f\n", change);
	looniess = change;
	printf("Loonies...............%d\n", looniess);
	cents = change - looniess;
	printf("Cents.................%.02f\n", cents);
	printf(".................................................**Final Bill**\n");
	printf(".................................................Number of Items: %d\n", itemsp);
	printf(".................................................Unit Price: %.02f\n", itemsprice);
	printf(".................................................Purchase Price: %.02f\n", purchaseprice);
	printf(".................................................HST (13%): %.02f\n", hst);
	printf(".................................................Total Price: %.02f\n", totalprice);
	printf(".................................................Cash Tendered: %.02f\n", cash);
	printf(".................................................Change loonies: %d\n", looniess);
	printf(".................................................Change cents: %.02f\n", cents);
	printf(".................................................Total Change: %.02f\n", change);
	getchar();
	return 0;
}

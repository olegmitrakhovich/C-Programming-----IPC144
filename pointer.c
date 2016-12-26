#include <stdio.h>

int main(void)
{
	int x;

	printf("enter x : ");
	scanf("%d", &x);
	printf("value stored in x :%d\n", x);
	printf("address of x 	  :%x\n", &x);

	return 0;
}

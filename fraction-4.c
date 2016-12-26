#include <stdio.h>

struct Fraction
{
        int num;
        int den;
};


void simplify(struct Fraction*);
void enter(struct Fraction*);
void display(const struct Fraction*);

int main(void)
{
	struct Fraction f;
	
	printf("Fraction Simplifier\n");
	printf("===================\n");
	enter(&f);	 
	simplify(&f);
	display(&f);
}

void enter(struct Fraction* f)
{
	printf("Numerator  :");
	scanf(" %d", &f->num);
	printf("Denominator:");
	scanf (" %d", &f->den);
}

void simplify(struct Fraction* x)
{ 
	int divider,top2,bottom2;
        divider = 101;
        top2=1;
        bottom2=1;
        while(top2 != 0 || bottom2 != 0){
        	divider=divider-1;
        	top2=x->num % divider;
        	bottom2=x->den % divider;
        }
        x->num = x->num / divider;
        x->den = x->den / divider;		
}

void display(const struct Fraction* x)
{
	printf("\n");
	printf("%d / %d\n", x->num, x->den);
} 

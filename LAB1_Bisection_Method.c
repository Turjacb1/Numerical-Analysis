#include<stdio.h>
#define EPSILON 0.01


double func(double x)
{
	return x*x*x-2*x-5;
}


void bisection(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		printf("You have not assumed right a and b\n");
		return;
	}

	double c = a;
	while ((b-a) >= EPSILON)
	{
		
		c = (a+b)/2;

		
		if (func(c) == 0.0)
			break;

		
		else if (func(c)*func(a) < 0)
			b = c;
		else
			a = c;
	}

printf("The value of root is :%lf ",c );
}




int main()
{
	double a =2, b = 3;
	bisection(a, b);
	return 0;
}





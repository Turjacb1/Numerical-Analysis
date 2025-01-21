// #include<stdio.h>
// #define EPSILON 0.01



// // An example function whose solution is determined using
// // Bisection Method. The function is x^3 - x^2 + 2
// double func(double x)
// {
// 	return x*x-7;
// }



// void bisection(double a, double b)
// {
// 	if (func(a) * func(b) >= 0)
// 	{
// 		printf("You have not assumed right a and b\n");
// 		return;
// 	}




// 	double c = a;
// 	while ((b-a) >= EPSILON)
// 	{
// 		// Find middle point
// 		c = (a+b)/2;

// 		// Check if middle point is root
// 		if (func(c) == 0.0)
// 			break;

// 		// Decide the side to repeat the steps
// 		else if (func(c)*func(a) < 0)
// 			b = c;
// 		else
// 			a = c;
// 	}

// printf("The value of root is :%lf ",c );
// }



// // Driver program to test above function
// int main()
// {
// 	// Initial values assumed
// 	double a =1, b = 0;
// 	bisection(a, b);
// 	return 0;
// }



#include<stdio.h>
#define epslion 0.01

double func(double x)
{
	return x*x-7;
}

void bijection(double a,double b)
{
	if(func(a)*func(b)>=0)
	{
		printf("you have not assumed");
		return;
	}

	double c=a;
	while((b-a)>=epslion)
	{
		c=a+b/2;
		if(func(c)==0.0)
		break;

		else if(func(c)*func(a)<0)
		b=c;
		else
		a=c;
	}
	printf("%lf",c);
}

int main()
{
	double a=1,b=0;
	bijection(a,b);
}
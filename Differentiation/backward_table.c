#include<stdio.h>



int main()
{
    int n;
    printf("Enter the number of n =");
    scanf("%d",&n);

    double x[n],y[n];

    printf("Enter the number of x =");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&x[i]);
    }




printf("Enter the number of y =");
    for(int i=0;i<n;i++)
    {
        scanf("%d",y[i]);
    }

backward(x,y,n);

}





void backward(double x[],double y[],int n)
{

    double diff[n][n];

    for(int i=1;i<n;i++)
    {
        diff[i][0]=y[i];
    }

    for(int j=1;j<n;j++)
    {
        for(int i=n-1;i>=j;i--)
        {
            diff[i][j]=diff[i][j-1]-diff[i-1][j-1];
        }
    }




    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("diff[%d] [%d]  %lf",i,j,diff[i][j]);
        }
    }






    double h=x[1]-x[0];
    double sum=0;
    int sign=1;

    for(int i=0;i<n;i++)
    {
        double term=diff[n-1][i]/x[i];
        sum+=sign*term;
        sign=-sign;
    }


    double first_deribative=sum/h;

    printf(" first deribative = %lf", first_deribative);



}
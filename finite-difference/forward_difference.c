





#include<stdio.h>
int main()
{
    int n=4;
    double x[n],y[n];

    printf("value of x" );
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&x[i]);
    }

    printf("value of y");
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&y[i]);
    }

    forward(x,y,n);
    return 0;
}



void forward(double x[],double y[],int n)
{
    double diff[n][n];

    for(int i=0;i<n;i++)
    {
        diff[i][0]=y[i];
    }

    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n-j;i++)
        {
            diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            
        printf(" diff[%d][%d]%5.2lf\n",i,j,diff[i][j]);
        }
    }
}


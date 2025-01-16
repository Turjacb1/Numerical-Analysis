








                                                                  
#include<stdio.h>                                     
int main()
{
    int n;
    
    printf("enter the total number =");
    scanf("%d",&n);

     double x[n],y[n];
    printf("enter the number of x");
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&x[i]);
    }

    printf("enter the number of y");

     for(int i=0;i<n;i++)
     {
    scanf("%lf",&y[i]);
     }

     backward(x,y,n);
     return 0;


}





void backward(double x[],double y[],int n)
{
    double diff[n][n];



for(int i=0;i<n;i++)
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
        printf("diff[%d][%d] %5.2lf",i,j,diff[i][j]);
    }
}

}
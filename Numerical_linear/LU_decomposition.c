






#include<stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    int mat[][MAX]={ {2,3,1}, {1,2,3}, {3,1,2}};
    luDecomposition(mat,3);
    return 0;
}




void  luDecomposition(int mat[][MAX],int n)
{
    int lower[n][n],upper[n][n];
    memset(lower,0,sizeof(lower));
    memset(upper,0,sizeof(upper));



for(int i=0;i<n;i++)
{
  for(int k=i;k<n;k++)
  {
    int sum=0;
    for(int j=0;j<i;j++)
 
        sum+=(lower[i][j]* upper[j][k]);

        upper[i][k]=mat[i][k]-sum;
    
  }



    for(int k=i;k<n;k++)
    {
        if(i==k)
        
            lower[i][i]=1;
  
        

        else{
            int sum=0;
            for(int j=0;j<i;j++)
            
                sum+=(lower[k][j]*upper[j][i]);

                lower[k][i]=(mat[k][i]-sum)/upper[i][i];
            
        }

    }
  }




  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
        
        printf("%6d\t",lower[i][j]);
        printf("\t");
      

      for(int j=0;j<n;j++)
      
        printf(" %6d\t",upper[i][j]);
        printf("\n");
      
  }

}


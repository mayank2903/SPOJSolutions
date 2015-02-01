#include<stdio.h>
int inv[13][200];
int main()
{
    int i,j,k,n,t;
    for(i=1;i<=12;i++)
    {
        for(j=0;j<=100;j++)
        {
            if(i==1)
            {
                if(j==1)inv[i][j]=1;
                else inv[i][j]=0;
            }
            else
            {
                inv[i][j]=0;
                for(k=0;k<i;k++)
                {
                    inv[i][j]+=inv[i-1][j-k];
                }
            }
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("%d\n",inv[n][k+1]);
    }
    return 0;
}

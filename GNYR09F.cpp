#include<bits/stdc++.h>
using namespace std;
int adj[101][101][2];
int main()
{
    int t,a,n,k;
    for(int i = 1; i <= 100; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(i == j + 1)
            {
                adj[i][j][0] = (i == 1);
                adj[i][j][1] = 1;
            }
            
            else if(j == 0)
            {
                adj[i][j][0] = adj[i-1][j][0] + adj[i-1][j][1];
                adj[i][j][1] = adj[i-1][j][0];
            }
            
            else
            {
                adj[i][j][0] = adj[i-1][j][0] + adj[i-1][j][1];
                adj[i][j][1] = adj[i-1][j][0] + adj[i-1][j-1][1];
            }
        }
    }
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&n,&k);
        
        printf("%d %d\n", a, adj[n][k][0] + adj[n][k][1]);
    }
    
    return 0;
}

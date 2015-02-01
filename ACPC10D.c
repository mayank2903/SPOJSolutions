#include<stdio.h>
typedef long long int ll;
ll cost[100001][3];
ll min(ll a, ll b)
{
    if(a<b)return a;
    return b;
}
int main()
{
    int i,rows,t=0;
    scanf("%d",&rows);
    while(rows!=0)
    {
        t++;
        for(i=0;i<rows;i++)
        {
            scanf("%lld%lld%lld",&cost[i][0],&cost[i][1],&cost[i][2]);
        }
        cost[1][0]+=cost[0][1];
        cost[0][2]+=cost[0][1];
        cost[1][1]+=min(min(cost[1][0],cost[0][1]),cost[0][2]);
        cost[1][2]+=min(min(cost[0][2],cost[0][1]),cost[1][1]);
        for(i=2;i<rows;i++)
        {
            cost[i][0]+=min(cost[i-1][0],cost[i-1][1]);
            cost[i][1]+=min(min(cost[i][0],cost[i-1][0]),min(cost[i-1][1],cost[i-1][2]));
            cost[i][2]+=min(min(cost[i][1],cost[i-1][1]),cost[i-1][2]);
        }
        printf("%d. %lld\n",t,cost[rows-1][1]);
        scanf("%d",&rows);
    }
    return 0;
}

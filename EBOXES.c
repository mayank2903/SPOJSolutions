#include<stdio.h>
int main()
{
    int tt,n,t,k,f;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d%d%d%d",&n,&k,&t,&f);
        printf("%d\n",f+(f-n)/(k-1));
    }
    return 0;
}

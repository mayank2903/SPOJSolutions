#include<stdio.h>
int main()
{
    int n,d,ans,i;
    scanf("%d%d",&n,&d);
    while(n!=0 && d!=0)
    {
        i=1;ans=1;
        while(i<=n)
        {
            ans=(ans+d)%i;
            i++;
        }
        printf("%d %d %d\n",n,d,ans+1);
        scanf("%d%d",&n,&d);
    }
    return 0;
}

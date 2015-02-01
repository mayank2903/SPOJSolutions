#include<stdio.h>
int main()
{
    int n,ans;
    scanf("%d",&n);
    while(n!=0)
    {
        ans=-1;
        while(n)
        {
            n>>=1;ans++;
        }
        printf("%d\n",ans);
        scanf("%d",&n);
    }
    return 0;
}

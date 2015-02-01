#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    long long int n;
    double ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n<=1){printf("1\n");continue;}
        ans=n*(log10(n)-M_LOG10E)+0.5*(log10(2*n)+log10(M_PI));
        ans= ceil(ans);
        printf("%lld\n",llrintl(ans));
    }
    return 0;
}

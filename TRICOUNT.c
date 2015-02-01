#include<stdio.h>
#include<math.h>
int main()
{
    int t,i;
    unsigned long long int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu",&n);
        printf("%llu\n",(n*(n+2)*((n<<1)+1))>>3);
    }
    return 0;
}

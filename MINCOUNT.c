#include<stdio.h>
int main()
{
unsigned long long int a,b;
int n;
scanf("%d",&n);
while(n--)
{
    scanf("%llu",&a);
    printf("%llu\n",a*(a+1)/6);
}
return 0;
}

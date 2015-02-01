#include<stdio.h>
int main()
{
    int n,k=0,i;
    char str[500];
    scanf("%d",&n);
    if(n==0)
    {
        printf("0\n");return 0;
    }
    while(n!=0)
    {
        if(n&1)
        {
            str[k++]='1';
            n=(n-1)/(-2);
        }
        else
        {
            str[k++]='0';
            n=n/(-2);
        }
    }
    for(i=k-1;i>=0;i--)putchar(str[i]);
    putchar('\n');
    return 0;
}

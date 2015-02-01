#include<stdio.h>
int main()
{
    int t,n,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n, &x);
        if(x==0)
        printf("Airborne wins.\n");
        else
        printf("Pagfloyd wins.\n");
    }
    return 0;
}

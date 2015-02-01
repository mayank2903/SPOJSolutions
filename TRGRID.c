#include<stdio.h>
int main()
{
    int t,r,c,rb,cb;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&r,&c);
        rb=r&1; cb=c&1;
        if((r^c)==0)
        {
            if(rb)
            printf("R\n");
            else printf("L\n");
        }
        else if(rb==0 && cb==0)//e*e
        {
            if(c>r)printf("L\n");
            else printf("U\n");
        }
        else if(rb&&cb)//o*o
        {
            if(c>r)printf("R\n");
            else printf("D\n");
        }
        else if(rb==1 && cb==0)//o*e
        {
            if(c>r)printf("R\n");
            else printf("U\n");
        }
        else if(rb==0 && cb==1)//e*o
        {
            if(c>r)printf("L\n");
            else printf("D\n");
        }
    }
    return 0;
}

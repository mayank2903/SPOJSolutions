#include<stdio.h>
int ans[1000001];
int main()
{
    int n,s,i,j,k,l,m,nn,x;
    nn=0;
    for(i=0;i<10;i++)
    for(j=0;j<10;j++)
    for(k=0;k<10;k++)
    for(l=0;l<10;l++)
    for(m=0;m<10;m++)
    for(n=0;n<10;n++)
    {
        s=i+j+k+l+m+n;
        x=nn+s;
        if(x<=1000000)
        ans[nn+s]=1;
        nn++;
    }
    for(i=1;i<1000000;i++)
    {
        if(ans[i]==0)printf("%d\n",i);
    }
    return 0;
}

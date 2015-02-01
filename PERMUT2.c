#include<stdio.h>
 
int a[100001];
 
int main()
{
    int t,n,i,f;
 
    scanf("%d",&n);
 
    while(n!=0)
    {
        for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
 
        //checking ambiguity
        for(i=1;i<=n;i++)
        {
            if(a[a[i]]!=i)
            {
                f=1;break;
            }
        }
        if(f==1)
        printf("not ambiguous\n");
 
        else
        printf("ambiguous\n");
 
        f=0;scanf("%d",&n);
    }
 
    return 0;
}

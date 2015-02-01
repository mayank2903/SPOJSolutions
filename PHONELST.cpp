#include<stdio.h>
#include<algorithm>
#include<string.h>
int comp(const void* a, const void* b)
{
    return strcmp((char*)a, (char*)b);
}
char str[100000][10];
int main()
{
    int t,i,n,f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%s",str[i]);
        }
        qsort(str,n,sizeof(char)*10,comp);
        f=0;/*
        printf("sorted:\n");
        for(i=0;i<n;i++)
        printf("%s\n",str[i]);*/
        for(i=0;i<n-1;i++)
        {
            if(strstr(str[i+1],str[i]))
            {
                f=1;break;
            }
        }
        if(f==1)
        printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

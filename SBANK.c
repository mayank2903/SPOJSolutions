#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[100000][33];
int comp(const void* a, const void* b)
{
    return strcmp((char*)a, (char*)b);
}
int main()
{
    int t,n,i,j,count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
        {
            gets(str[i]);
            //getchar();
        }
        qsort(str,n,sizeof(char)*33,comp);
        for(i=0;i<n;i++)
        {
            count=1;
            j=i+1;
            while(j<n && strcmp(str[i],str[j])==0)
            {
                count++;
                j++;
            }
            i=j-1;
            printf("%s %d\n",str[i],count);
        }
        printf("\n");
    }
    return 0;
}

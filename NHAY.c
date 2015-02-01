#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void lpsCalc(char* pat, int l, int* lps)
{
    int i,len;
    len=0;
    i=1;
    lps[0]=0;
    while(i<l)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
void kmp(char* pat, int l)
{
    int i,j,f=0;
    i=0;
    j=0;
    //creating an lps array..[LONGEST PREFIX SUFFIX]
    int* lps=(int*)malloc(sizeof(int)*l);
    lpsCalc(pat,l,lps);
    char c=getchar();
    while(c!='\n')
    {
        //printf("read %c\n",c);
        if(pat[j]==c)
        {
            j++;
            i++;
            c=getchar();
        }
        if(j==l)
        {
            f=1;
            printf("%d\n",i-j);
            j=lps[j-1];
        }
        else if(pat[j]!=c)
        {
            if(j==0)
            {
                c=getchar();
                i++;
            }
            else
            {
                j=lps[j-1];
            }
        }
    }///while loop
    if(f==0)putchar('\n');
    free(lps);
}
int main()
{
    int l;
    while(scanf("%d",&l)!=EOF)
    {
        char str[l+1];
        getchar();
        scanf("%s",str);
        getchar();
        //printf("string=%s\n",str);
        kmp(str,l);
    }
    return 0;
}

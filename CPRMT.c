#include<stdio.h>
int c1[26];
int c2[26];
char s1[1001];
char s2[1001];
int min(int a, int b)
{
    if(a<b)return a;
    return b;
}
int main()
{
    int i,j,c,alpha,l1,l2;
    while(scanf("%s",s1)!=EOF)
    {
        scanf("%s",s2);
        for(i=0;s1[i]!='\0';i++)
        {
            c1[s1[i]-'a']++;
        }
        for(i=0;s2[i]!='\0';i++)
        {
            c2[s2[i]-'a']++;
        }
        for(i=0;i<26;i++)
        {
            alpha=i+'a';
            c=min(c1[i],c2[i]);
            for(j=0;j<c;j++)putchar(alpha);
        }
        putchar('\n');
        for(i=0;i<26;i++)
        c1[i]=c2[i]=0;
    }
    return 0;
}

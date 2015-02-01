#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<iostream>
#include<set>
#include<stack>
#include<string>
#include<cstdlib>
#include<sstream>
using namespace std;
int mat[2001][2001];
char s1[2001],s2[2001];
inline int read()
{
    register int noRead=0,isneg=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked()){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    if(isneg) noRead = -noRead;
    return noRead;
}
inline void fastWrite(int a)
{
    char snum[6];
    register int i=0,t=10,tt=48;
    do
    {
        snum[i++]=a%t+tt;
        a=a/t;
    }
    while (a);
    i=i-1;
    while (i>=0)
        putchar_unlocked(snum[i--]);
    putchar_unlocked('\n');
}
int main()
{
    int t,i,j,x,y,z,l1,l2;
    t=read();
    getchar();
    while(t--)
    {
        scanf("%s",s1);
        getchar();
        scanf("%s",s2);
        getchar();
        //printf("s1=%s s2=%s\n",s1,s2);
        l1=strlen(s1);
        l2=strlen(s2);
        for(i=0;i<=l1;i++)
        {
            for(j=0;j<=l2;j++)
            {
                if(i==0)
                mat[i][j]=j;
                else if(j==0)
                mat[i][j]=i;
                else
                {
                    x=mat[i-1][j-1] + (s1[i-1]!=s2[j-1]);//replace operation..
                    y=mat[i-1][j]+1;//delete operation..
                    z=mat[i][j-1]+1;//insert operation..
                    mat[i][j]=min(x,min(y,z));
                }
            }
        }
        fastWrite(mat[l1][l2]);//c50-B
    }
	return 0;
}

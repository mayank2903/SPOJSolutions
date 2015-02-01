#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<cstring>
using namespace std;
char str[6110];
char rev[6110];
int a[6110][6110];
int lcs(int m, int n)
{
	int i,j;
	
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
			a[i][j]=0;
			else if(str[i-1]==rev[j-1])
			a[i][j]=1+a[i-1][j-1];
			else a[i][j]=max(a[i-1][j],a[i][j-1]);
		}
	}
	return a[m][n];
}
int main()
{
	int t,m1,m2,l,i,j;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		scanf("%s",str);
//		printf("string=%s\n",str);
		l=strlen(str);
		for(i=0;i<l;i++)rev[i]=str[l-1-i];
		rev[l]='\0';
	//	printf("rev=%s\n",rev);
		printf("%d\n",l-lcs(l,l));
	}
	return 0;
}

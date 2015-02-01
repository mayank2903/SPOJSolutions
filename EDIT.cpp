#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<ctype.h>
using namespace std;
char str[100000];
int main()
{
	int l,caseone,casetwo,i;
	while(scanf("%s",str)!=EOF){
	l=strlen(str);
	caseone=casetwo=0;
	for(i=0;i<l;i++)
	{
		//first is uppercase..
		caseone+=(i&1 && isupper(str[i])) + (!(i&1) && islower(str[i]));
		//first is lowercase:
		casetwo+=(i&1 && islower(str[i])) + (!(i&1) && isupper(str[i]));
	}
	printf("%d\n",min(caseone,casetwo));
	}
	return 0;
}

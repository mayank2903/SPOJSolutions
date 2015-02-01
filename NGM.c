#include<stdio.h>
#include<string.h>
int main()
{
	char str[50];
	int l;
	scanf("%s",str);
	l=strlen(str);
	if(str[l-1]=='0')printf("2\n");
	else {printf("1\n%c\n",str[l-1]);}
	return 0;
}

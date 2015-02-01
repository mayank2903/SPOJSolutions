#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#define plus 0
#define minus 1
typedef long long int ll;
using namespace std;
int main()
{
	ll t,a,b,c,d,start,start2,f,i,sign,pos,cind;
	char str[100];
	scanf("%lld",&t);
	getchar();
	while(t--)
	{
		gets(str);
		//finding "a"
		if(!isdigit(str[0]))
			a=1;
		else
		{
			a=0;
			for(i=0;isdigit(str[i]);i++)
			{
				a=a*10+str[i]-'0';
			}
		}
		///finding "b"
		pos=strstr(str,"x*x")-str;
		//either "b" is zero..
		if(strstr(str+pos+3,"x")==NULL)
		{
			b=0;cind=pos+3;
		}
		//or "b" is not zero..
		else
		{
			b=0;
			if(str[pos]=='-')sign=minus;
			else sign=plus;
			for(i=pos+4;isdigit(str[i]);i++)
			{
				b=b*10+str[i]-'0';
			}
			cind=i;
			if(sign==minus)
				b=-b;
		}
		//finding "c"
		sign=plus;c=0;
		for(i=cind;str[i]!='=';i++)
		{
			if(str[i]=='-')sign=minus;
			else if(isdigit(str[i]))
				c=c*10+str[i]-'0';
		}
		if(sign==minus)c=-c;
		d=b*b-4*a*c;
		if(d==0)
			printf("Equal roots.\n");
		else if(d<0)
			printf("Imaginary roots.\n");
		else printf("Distinct real roots.\n");
	}
	return 0;
}

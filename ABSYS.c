#include<stdio.h>
#include<string.h>
int main()
{
	int t,plus,equalsign,machula,l,a,b,i;
	char str[500];
	scanf("%d",&t);
	while(t--)
	{
		a=b=0;
		//for(i=0;i<500;i++)str[i]='\0';
		gets(str);
		if(strlen(str)==0){t++;continue;}
	//	printf("%s\n",str);
		l=strlen(str);
		//printf("%u %u\n",strstr(str,"+"),str);
		plus=strstr(str,"+")-str;
		machula=strstr(str,"m")-str;
		equalsign=strstr(str,"=")-str;
		//plus=strstr(str,"+")-str;
		//if machula is the first number..
		if(machula<equalsign && machula<plus)
		{
		//	printf("machula is first\n");
			for(i=plus+1;i<equalsign;i++)
			{
				if(!isdigit(str[i]))continue;
				a=(a<<3)+(a<<1)+str[i]-'0';
			}
			for(i=equalsign+1;i<l;i++)
			{
				if(!isdigit(str[i]))continue;
				b=(b<<3)+(b<<1)+str[i]-'0';
			}
			printf("%d + %d = %d\n",b-a,a,b);
		}
		//if machula is the middle number..
		else if(machula>plus && machula<equalsign)
		{
			//printf("machula is middle\n");
			for(i=0;i<plus;i++)
			{
				if(!isdigit(str[i]))continue;
				a=(a<<3)+(a<<1)+str[i]-'0';
			}
			for(i=equalsign+1;i<l;i++)
			{
				if(!isdigit(str[i]))continue;
				b=(b<<3)+(b<<1)+str[i]-'0';
			}
			printf("%d + %d = %d\n",a,b-a,b);
		}
		//if machula is the last number..
		else
		{
			//printf("machula is last\n");
			for(i=0;i<plus;i++)
			{
				if(!isdigit(str[i]))continue;
				a=(a<<3)+(a<<1)+str[i]-'0';
			}
			for(i=plus+1;i<equalsign;i++)
			{
				if(!isdigit(str[i]))continue;
				b=(b<<3)+(b<<1)+str[i]-'0';
			}
			printf("%d + %d = %d\n",a,b,a+b);
		}
	}
	return 0;
}

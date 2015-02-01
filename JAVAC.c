#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	char str[1001],newstr[5000];
	int k,java,cpp,i,f,l;
	while(scanf("%s",str)!=EOF)
	{
		java=cpp=k=f=0;
		//first letter is always small
		if(!isalpha(str[0]) || isupper(str[0]))
		{
			printf("Error!\n");
			continue;
		}
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]>='A' && str[i]<='Z')
			{
				java=1;
				if(cpp==1){printf("Error!\n");f=1;break;}
			}
			else if(str[i]=='_')
			{
				cpp=1;
				if(str[i-1]=='_'){printf("Error!\n");f=1;break;}
				if(java==1){printf("Error!\n");f=1;break;}
			}
		}
		if(!f && str[i-1]=='_'){printf("Error!\n");continue;}
		if(f)continue;
		if(!java && !cpp)
		{
			printf("%s\n",str);
			continue;
		}
		else if(java)
		{
			for(i=0;str[i]!='\0';i++)
			{
				if(isupper(str[i]))
				{
					newstr[k++]='_';
					newstr[k++]=tolower(str[i]);
				}
				else newstr[k++]=str[i];
			}newstr[k]='\0';
			printf("%s\n",newstr);
		}
		else//cpp
		{
			for(i=0;str[i]!='\0';i++)
			{
				if(str[i]=='_')
				{
					newstr[k++]=toupper(str[i+1]);
					i++;
				}
				else newstr[k++]=str[i];
			}newstr[k]='\0';
			printf("%s\n",newstr);
		}
	}
	return 0;
}

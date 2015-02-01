#include<stdio.h>
#include<iostream>
#include<map>
#include<utility>
#include<string.h>
#define gtc getchar()
inline int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
using namespace std;
int main()
{
	int n,l,num,homo,hetero,i;
	char str[50];
	map<int, int> nos;
	n=read_int();
	//getchar();
	homo=hetero=0;
	int count=0;
	while(n--)
	{
		scanf("%s",str);
		//printf("str=%s\n",str);
		//extracting number:
		num=read_int();
		//printf("num=%d\n",num);
		//printf("l=%d\n",l);
/*
		num=0;int minus=0;
		for(i=7;str[i]!='\0';i++)
		{
			//printf("%c",str[i]);
			if(str[i]=='-'){minus=1;continue;}
			else num=(num<<3)+(num<<1)+(str[i]-'0');
			//printf("%d\n",num);
		}
		if(minus)num=-num;
		//printf("\n\nnum=%d\n",num);
*/
		if(str[0]=='i')//insert operation
		{
			//check if element already exists..
			if(nos.find(num)==nos.end())//element doesnt exist..
			{
			//	printf("%d not found..inserting..\n",num);
				hetero++;
				nos[num]=1;
			}
			else//element exists..
				{
					nos[num]++;
					if(nos[num]==2)
					homo++;
				}
			count++;
		/*	if(count<=1)printf("neither\n");
			else if(hetero && homo)
				printf("both\n");
			else if(hetero)printf("hetero\n");
			else printf("homo\n");
*/ if ( homo >= 1 && hetero >= 2 ) {
            printf( "both\n" );
        }
        else if ( homo >= 1 ) {
            printf( "homo\n" );
        }
        else if ( hetero >= 2 ) {
            printf( "hetero\n" );
        }
        else {
            printf( "neither\n" );
        }
			//printf("count=%d\n",count);
		}
		else
		{
			//check again if the element exists..
			map<int, int>::iterator ii=nos.find(num);
			if(ii!=nos.end())
			{
				nos[num]--;
				count--;
				//printf("freq of %d now=%d\n",num,nos[num]);
				if(nos[num]==1)homo--;
				if(nos[num]==0)
				{
					hetero--;
					//printf("deleting from list..\n");
					nos.erase(ii);
				}
			}
/*
			if(count<=1)printf("neither\n");
			else if(hetero && homo)
				printf("both\n");
			else if(hetero)printf("hetero\n");
			else printf("homo\n");
*/
 if ( homo >= 1 && hetero >= 2 ) {
            printf( "both\n" );
        }
        else if ( homo >= 1 ) {
            printf( "homo\n" );
        }
        else if ( hetero >= 2 ) {
            printf( "hetero\n" );
        }
        else {
            printf( "neither\n" );
        }
		}
/*
		//now go through the map to check for homo or hetero
		if(count<=1)
		{
		//	printf("list<=1\n");
			//printf("count=%d\n",count);
			printf("neither\n");
		}
		else
		{
			homo=hetero=0;
			//printf("\nlist:\n");
			int first=(*nos.begin()).first;
			map<int, int>::iterator end=nos.end();
			for(map<int, int>::iterator ii=nos.begin();ii!=end;ii++)
			{
				//cout<<(*ii).first<<": "<<(*ii).second<<endl;
				if((*ii).second>=2)homo=1;
				if((*ii).first!=first)hetero=1;
				if(homo && hetero)break;
			}
			if(hetero==1 && homo==1)
				printf("both\n");
			else if(hetero==1)
				printf("hetero\n");
			else printf("homo\n");
*/
	}
	return 0;
}

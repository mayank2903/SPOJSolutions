#include<stdio.h>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n,i,f,reqd,found;
	int a[10000];
	stack<int> s;
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		reqd=1;i=0;
		while(i<n)
		{
			//check if any one of a[i] or TOS match 'reqd'
			found=0;
			if(a[i]==reqd)
			{
				i++;
				reqd++;
				found=1;
			}
			else if(!s.empty() && s.top()==reqd)
			{
				found=1;
				s.pop();
				reqd++;
			}
			//if they don't
			if(found==0)
			{
				s.push(a[i]);
				i++;
			}
		}
		f=0;
		while(!s.empty())
		{
			if(s.top()!=reqd)
			{
				f=1;break;
			}
			s.pop();reqd++;
		}
		while(!s.empty())s.pop();
		if(f)printf("no\n");
		else printf("yes\n");
		scanf("%d",&n);
	}
	return 0;
}

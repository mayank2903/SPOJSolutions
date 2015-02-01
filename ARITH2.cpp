#include<stdio.h>
#include<queue>
#include<algorithm>
#include<ctype.h>
using namespace std;
typedef long long int ll;
ll operate(ll a, ll b, char op)
{
	if(op=='+')return a+b;
	if(op=='-')return a-b;
	if(op=='/')return a/b;
	if(op=='*')return a*b;
}
int main()
{
	int t;char c,op;
	ll num,n1,n2,ans;
	scanf("%d",&t);
	while(t--)
	{
		num=0;ans=0;n1=0;n2=0;
		queue<int> nums;
		queue<int> ops;
		getchar();
		while((c=getchar())!='=')
		{
			if(isdigit(c))
			{
				//putchar(c);//printf("is digit\n");
				num=num*10+c-'0';
			}
			else if(c=='+' || c=='-' || c=='/' || c=='*')//operator..
			{
				//printf("num=%d\n",num);
				//printf("found operator %c\n",c);
				nums.push(num);
				num=0;
				ops.push(c);
			}
		}
		nums.push(num);
		//putchar('\n');
		if(ops.empty())
		{
			//printf("%d\n",nums.front());
			continue;
		}
		else
		{
			n1=nums.front();
			//printf("popped %d\n",n1);
			nums.pop();
			n2=nums.front();
			nums.pop();
			//printf("popped %d\n",n2);
			op=ops.front();
			ops.pop();
			//printf("popped %c\n",op);
			ans=operate(n1,n2,op);
			while(!ops.empty())
			{
				op=ops.front();//printf("popped %c\n",op);
				ops.pop();
				n1=nums.front();//printf("popped %d\n",n1);
				nums.pop();
				ans=operate(ans,n1,op);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

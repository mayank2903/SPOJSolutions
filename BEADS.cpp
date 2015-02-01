#include <bits/stdc++.h>
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define mp make_pair
#define pb push_back
#define gtc getchar()
typedef long long ll;
using namespace std;
int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
}
string str,strtr,x,minstr;
int main()
{
	int t,l,pos;
	char mini;
	s(t);
	
	while(t--)
	{
		cin>>str;
	
		strtr=str+str;
		l=str.size();
		
		//finding lowest ascii character..
		rep(i,l)
		{
			if(str.at(i)<mini)
			mini=str.at(i);
		}
		
		//min ascii is stored in "mini"..
		//storing all psitions of mini..
		minstr="";pos=-1;
		rep(i,l)
		{
			x=strtr.substr(i,l-1);
			if(x<minstr || minstr.compare("")==0)
			{
				minstr=x;
				pos=i;
			}
		}
		cout<<pos+1<<endl;
	}
	
	return 0;
}

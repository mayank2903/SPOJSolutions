#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;
stack<char> s;
char str[2001];
int main()
{
    int i,ans,open,t;
    char c;
    t=0;
    while(1)
    {
        ans=0;open=0;t++;
        scanf("%s",str);
        if(str[0]=='-')break;
        for(i=0;str[i]!='\0';i++)
        {
            //opening brace
            if(str[i]=='{')
            s.push(str[i]);
            //closing brace
            else
            {
                if(s.empty())
                {
                    //push opening brace
                    s.push('{');
                    ans++;
                }
                else s.pop();
            }
        }
        ans+=s.size()>>1;
        while(s.empty()==false)
        s.pop();
        printf("%d. %d\n",t,ans);
    }
    return 0;
}

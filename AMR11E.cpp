#include<bits/stdc++.h>
using namespace std;
int numFact(int x)
{
    int tmp=x,cnt=0;
    for(int i=2;i*i<=x;i++)
    {
        if(tmp%i==0)
        {
            while(tmp%i==0)tmp/=i;
            cnt++;
        }
    }
    return cnt+(tmp!=1);
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int tot=0;
        int i=30;
        while(tot!=n)
        {
            if(numFact(i)>=3)
                tot++;
            i++;
        }
        cout<<i-1<<endl;
    }
    return 0;
}

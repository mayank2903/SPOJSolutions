#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        int i=0,j=str.size()-1;
        int f=0;
        for(;i<=j;i++,j--)
        {
            if(str.at(i)!=str.at(j))
            {
                f=1;break;
            }
        }
        if(f)
            puts("NO");
        else puts("YES");
    }
    return 0;
}

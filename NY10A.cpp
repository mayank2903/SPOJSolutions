#include<stdio.h>
#include<map>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
map<string, int> m;
int main()
{
    int t,tno,i;
    string arr[]={ "TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT","HHH"};
    string str;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&tno);
        getchar();
        cin>>str;
       // cout<<"str="<<str<<endl;
        for(i=0;i<8;i++)
        m[arr[i]]=0;
        for(i=0;i<38;i++)
        {
            m[str.substr(i,3)]++;
        }
        printf("%d ",tno);
        for(i=0;i<8;i++)
        {
            printf("%d ",m[arr[i]]);
        }putchar('\n');
    }
    return 0;
}

#include<vector>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;
int main()
{
    	list<int> L;
        for(int i = 2;i<=33850;++i) L.push_back(i);
        int sz = 0, ans[3000];
        list<int> :: iterator it,it2;
        while(!L.empty() && sz<3000){
        ans[sz] = L.front();
        ++sz;
        int k = L.front(),i = 0;
        for(it = L.begin();it!=L.end();it = it2,++i){
        it2 = it; ++it2;
        if(i%k==0) L.erase(it);
            }
        }
    int n;
    cin>>n;
    while(n!=0)
    {
        printf("%d\n",ans[n-1]);
        cin>>n;
    }
    return 0;
}

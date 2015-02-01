#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int cnt[20001];
int main()
{
    int n,m;
    string str;
    
    scanf("%d%d",&n,&m);
    
    while(n!=0)
    {
        mp.clear();
        for(int i = 0; i < n; i++)
        {
            cin>>str;
            mp[str]++;
            cnt[i + 1]=0;
        }
        
        for(map<string, int>::iterator mm = mp.begin(); mm != mp.end(); mm++)
            cnt[mm->second]++;
        
        for(int i = 1; i <= n; i++)
            printf("%d\n",cnt[i]);
            
        scanf("%d%d",&n,&m);
    }
    return 0;
}

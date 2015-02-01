#include<bits/stdc++.h>
using namespace std;
pair<int, int> val[100001];
int main()
{
    int t, events, a, b;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&events);
        
        for(int i = 0; i < events; i++)
        {   
            scanf("%d%d", &a, &b);
            val[i] = make_pair(b,a);
        }
            
        sort(val, val + events);
        
        int prev = -1, ans=0;
        for(int i = 0; i < events; i++)
        {
            if(val[i].second >= prev)
            {
                ans++;
                prev = val[i].first;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}

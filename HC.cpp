#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, x;
    char str[5];
    
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&n);
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%s",str);
            if(str[0] == 'l')
                ans^=1;
        }
        
        puts(ans? "lxh": "hhb");
    }
    
    return 0;
}

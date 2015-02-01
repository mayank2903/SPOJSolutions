#include<bits/stdc++.h>
using namespace std;
int  main()
{
    long long t, n, x, row;
    string odd[] = {"W L", "A L", "A R", "M R", "W R"};
    string even[] = {"W R", "M R", "A R", "A L", "W L"};
    
    scanf("%lld",&t);
    
    while(t--)
    {
        scanf("%lld",&n);
        
        if(n == 1)
        {
            puts("poor conductor");
            continue;
        }
        
        row = (n - 2) / 5 + 1;
        x = 5*(row-1) + 2;
        
        printf("%lld ", row);
        
        if(row&1)
            puts(odd[n-x].c_str());
        
        else
            puts(even[n-x].c_str());
    }
    
    return 0;
}

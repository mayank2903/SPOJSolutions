#include<bits/stdc++.h>
using namespace std;
char a[501], b[501];
int main()
{
    scanf("%s %s", a, b);
    
    while(a[0] != '*')
    {
        int cnt = 0;
        for(int i = 0; a[i]; i++)
        {
            if(a[i] != b[i])
            {
                cnt++;
                int j = i + 1;
                while(a[j] != b[j])
                    j++;
                    
                i = j - 1;
            }
        }
        
        printf("%d\n",cnt);
        scanf("%s %s", a, b);
    }
    
    return 0;
}

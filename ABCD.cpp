#include<bits/stdc++.h>
using namespace std;
bool colors[4];
string str;
char ans[100001];
pair<char, char> findUnmarked()
{
    pair<char, char> ret;
    bool flag = false;
    for(int i = 0; i < 4; i++)
    {
        if(colors[i] == false)
        {
            if(flag)
            {
                ret.second = i + 'A';
                return ret;
            }
            
            else
            {
                ret.first = i + 'A';
                flag = true;
            }
        }
    }
}
int main()
{
    int n,pos=0;
    scanf("%d",&n);
    
    cin>>str;
    for(int i = 0; i < str.size(); i += 2)
    {
        for(int i = 0; i < 4; i++)colors[i] = false;
        
        colors[str[i] - 'A'] = true;
        colors[str[i + 1] - 'A'] = true;
        
        pair<char, char> rem = findUnmarked();
        if(i == 0)
        {
            if(rem.first == str[i])
                swap(rem.first, rem.second);
            
            putchar(rem.first);
            putchar(rem.second);
            
            ans[pos++] = rem.first;
            ans[pos++] = rem.second;
        }
        
        else
        {
            if(rem.first == str[i] || rem.first == ans[pos-1])
                swap(rem.first, rem.second);
                
            putchar(rem.first);
            putchar(rem.second);
            
            ans[pos++] = rem.first;
            ans[pos++] = rem.second;
        }
    }
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string str[100];
int marked[100][100];
int h,w;
bool isValid(int x, int y, int key)
{
    return x>=0 && x<h && y>=0 && y<w && marked[x][y]!=key;
}
int dfs(int x, int y, int key)
{
    //cout<<"dfs("<<x<<", "<<y<<")"<<endl;
    int ans=1,temp=0;
    marked[x][y]=key;
    //top left..
    if(isValid(x-1,y-1, key) && str[x-1][y-1]==str[x][y]+1)
        temp = max(temp, dfs(x-1,y-1, key));
    //top..
    if(isValid(x-1,y,key) && str[x-1][y]==str[x][y]+1)
        temp = max(temp, dfs(x-1,y,key));
    //top right..
    if(isValid(x-1,y+1,key) && str[x-1][y+1]==str[x][y]+1)
        temp = max(temp, dfs(x-1,y+1,key));
    //left..
    if(isValid(x,y-1,key) && str[x][y-1]==str[x][y]+1)
        temp = max(temp, dfs(x,y-1,key));
    //right..
    if(isValid(x,y+1,key) && str[x][y+1]==str[x][y]+1)
        temp = max(temp, dfs(x,y+1,key));
    //bottom left..
    if(isValid(x+1,y-1,key) && str[x+1][y-1]==str[x][y]+1)
        temp = max(temp, dfs(x+1,y-1,key));
    //bottom..
    if(isValid(x+1,y,key) && str[x+1][y]==str[x][y]+1)
        temp = max(temp, dfs(x+1,y,key));
    //bottom right..
    if(isValid(x+1,y+1,key) && str[x+1][y+1]==str[x][y]+1)
        temp = max(temp, dfs(x+1,y+1,key));
    return ans+temp;
}
int main()
{
    int t=0;
    while(true)
    {
        t++;
        cin>>h>>w;
        if(h==0 && w==0)
            break;
        for(int i=0;i<h;i++)
        {
            cin>>str[i];
            for(int j=0;j<w;j++)
                marked[i][j]=0;
        }
        int ans=0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(str[i][j]=='A')
                //cout<<"doing dfs("<<i<<", "<<j<<")"<<endl;
                ans=max(ans,dfs(i,j, i*w + j + 1));
            }
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}

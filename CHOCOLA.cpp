#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int x[1001];
int y[1001];
int main()
{
    int t,n,m,xcut,ycut;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(int i=0;i<m-1;i++)
        {
            cin>>x[i];
        }
        for(int i=0;i<n-1;i++)
        {
            cin>>y[i];
        }
        ycut=xcut=0;
        sort(y,y+n-1);
        sort(x,x+m-1);
        int xi=m-2,yi=n-2;
        int cost=0;
        while(xi>=0 || yi>=0)
        {
            if(xi<0)
            {
                cost+=y[yi--]*(xcut+1);
            }
            else if(yi<0)
            {
                cost+=x[xi--]*(ycut+1);
            }
            else if(x[xi]>=y[yi])
            {
                xcut++;
                cost+=x[xi]*(ycut+1);
                xi--;
            }
            else
            {
                ycut++;
                cost+=y[yi]*(xcut+1);
                yi--;
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}

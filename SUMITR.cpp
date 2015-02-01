#include<iostream>
#define for(a,b,c) for(int a=b;a<=c;a++)
using namespace std;long a[101][101],r;main(){cin>>r;for(t,1,r){long l,m=0;cin>>l;for(i,1,l)for(j,1,i){cin>>a[i][j];(a[i][j]=max(a[i-1][j-1],a[i-1][j])+a[i][j])>m?m=a[i][j]:m;}cout<<m<<endl;}}

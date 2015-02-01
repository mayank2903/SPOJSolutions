#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
typedef long l;
using namespace std;
const double pi = acos(-1.0);
map<int,int>m;
void f()
{
      int arr[]={4,9,16,25,36,49,64,81,100,121,144,169,180,196,225,252,256,289,300,324, 361,396,400,441,450,468,484,529,576,588,612,625,676,684,700,720,729,784,828,841,882,900,961,980,1008,1024,1044,1089,1100,0};
     int i=0;
     while(arr[i]!=0)
     {
       m[arr[i]]=1;
       i++;
     }
}
int main()
{
     f();
     int t;
     scanf("%d",&t);
     while(t--)
     {
               int n,k;
               scanf("%d%d",&n,&k);
               int j,p=0;
               int sum=0;
               int raj[102];
               for(int i=0;i<n;i++)
               {
                       scanf("%d",&j);
                       if(m[j])
                       {
                               raj[p++]=j;
                               sum+=j;
                       }
               }
               int ans[sum+10];
               for(int i=0;i<sum+10;i++)
               {
                       ans[i]=0;
               }
               ans[0]=1;
              
               for(int i=0;i<p;i++)
               {
                       for(int h=sum;h>=raj[i];h--)
                       {
                               ans[h]|=ans[h-raj[i]];
                       }
               }
               if(k>sum)
                        printf("No\n");
               else if(ans[k])
                        printf("Yes\n");
               else
                        printf("No\n");
     }
    
     return 0;
}

#include<stdio.h>
#include<algorithm>
using namespace std;
int bsearch(int* a, int size, int key)
{
    int min,max,mid,count,index;
    min=0;
    max=size-1;
    while(min<=max)
    {
        mid=(min+max)/2;
        if(a[mid]==key)
        {
            index=mid;
            count=0;
            while(index<size && a[index]==key)
            {
                count++;index++;
            }
            index=mid-1;
            while(index>=0 && a[index]==key)
            {
                count++;
                index--;
            }
            return count;
        }
        else if(a[mid]>key)
        {
            max=mid-1;
        }
        else min=mid+1;
    }
    return 0;
}
int s1[4000*4000];
int s2[4000*4000];
int main()
{
    int n,i,j,k,ans;
    scanf("%d",&n);
    int a[n],b[n],c[n],d[n];
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            s1[k]=a[i]+b[j];
            s2[k++]=c[i]+d[j];
        }
    }
    sort(s1,s1+k);
    sort(s2,s2+k);
    ans=0;
    for(i=0;i<k;i++)
    {
        ans+=bsearch(s2,k,-s1[i]);
    }
    printf("%d\n",ans);
    return 0;
}

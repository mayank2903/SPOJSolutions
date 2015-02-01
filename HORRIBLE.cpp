#include<stdio.h>
#include<iostream>
#define ll long long
using namespace std;
struct node
{
    ll toadd;
    ll sum;
};
typedef struct node node;
node segtree[300001];
void update(ll index, ll i, ll j, ll l, ll r, ll val)
{
    if(i==l && j==r)
    {
        segtree[index].toadd+=val;
        segtree[index].sum+=(j-i+1)*val;
        return;
    }
    ll mid=(i+j)>>1;
    if(r<=mid)
    {
        update(index*2, i, mid, l, r, val);
    }
    else if(l>mid)
    {
        update(index*2+1, mid+1, j, l, r, val);
    }
    else
    {
        update(index*2, i, mid, l, mid, val);
        update(index*2+1, mid+1, j, mid+1, r, val);
    }
    segtree[index].sum+=(min(r,j)-max(i,l)+1)*val;
}
ll query(ll index, ll i, ll j, ll l, ll r, long long toadd)
{
    if(i==l && j==r)
    {
        return segtree[index].sum+(j-i+1)*toadd;
    }
    ll mid=(i+j)>>1;
    if(r<=mid)
    {
        return query(index*2, i, mid, l, r, toadd+segtree[index].toadd);
    }
    else if(l>mid)
    {
        return query(index*2+1, mid+1, j, l, r, toadd+segtree[index].toadd);
    }
    else return query(index<<1, i, mid, l, mid, toadd+segtree[index].toadd)
        + query(index*2+1, mid+1, j, mid+1, r, toadd+segtree[index].toadd);
}
int main()
{
    ll t,ch,p,q,c,n;
    long long v;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        for(ll i=0;i<=300000; i++)
        {
            segtree[i].sum=segtree[i].toadd=0;
        }
        for(ll i=0;i<c;i++)
        {
            cin>>ch>>p>>q;
            if(ch==0)
            {
                cin>>v;
                update(1, 1, n, p, q, v);
            }
            else
            {
                cout<<query(1,1,n,p,q,0)<<endl;
            }
        }
    }
    return 0;
}

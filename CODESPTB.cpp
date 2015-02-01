#include<bits/stdc++.h>
#define left index*2
#define right index*2+1
using namespace std;
long long tree[2100010], a[100001];
vector<int> ele;
void init(int index, int l, int r)
{
    if(l == r)
    {
        tree[index] = 0;
        return;
    }
    
    int mid = (l + r) >> 1;
    
    init(left, l, mid);
    init(right, mid + 1, r);
    
    tree[index] = 0;
}
void update(int index, int l, int r, int point, int val)
{
    if(l == r && l == point)
    {
        tree[index] += val;
        return;
    }
    
    if(point >= l && point <= r)
        tree[index] += val;
        
    int mid = (l + r) >> 1;
    
    if(point <= mid)
        update(left, l, mid, point, val);
        
    else
        update(right, mid + 1, r, point, val);
}
long long findsum(int index, int l, int r, int tl, int tr)
{
    if(l > r)
        return 0;
        
    if(tl == l && tr == r)
        return tree[index];
        
    int mid = (tl + tr) >> 1;
    
    if(r <= mid)
        return findsum(left, l, r, tl, mid);
        
    else if(l > mid)
        return findsum(right, l, r, mid + 1, tr);
    
    else
        return findsum(left, l, mid, tl, mid) + findsum(right, mid + 1, r, mid + 1, tr);
}
int main()
{
    int t, n;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&n);
        
        ele.clear();
        init(1, 0, 1000000);
        
        for(int i = 0; i < n; i++)
            scanf("%lld",&a[i]);
            
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += findsum(1, a[i] + 1, 1000000, 0, 1000000);
            update(1, 0, 1000000, a[i], 1);
        }
        
        printf("%lld\n", ans);
    }
}

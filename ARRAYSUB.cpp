#include<stdio.h>
#include<algorithm>
#include<limits.h>
#define LEFT index*2
#define RIGHT index*2+1
using namespace std;
struct node
{
    int l;
    int r;
    int max;
};
typedef struct node node;
node tree[2000010];
int a[1000009];
inline int max(int a, int b)
{
    if(b>=a)return b;
    else return a;
}
node buildtree(node* tree, int l, int r, int index)
{
    if(l==r)
    {
        tree[index].l=tree[index].r=l;
        tree[index].max=a[l];
        return tree[index];
    }
    int mid=l+(r-l)/2;
    tree[LEFT]=buildtree(tree,l,mid,LEFT);
    tree[RIGHT]=buildtree(tree,mid+1,r,RIGHT);
    tree[index].l=l;tree[index].r=r;
    tree[index].max=max(tree[LEFT].max,tree[RIGHT].max);
    return tree[index];
}
int query(int l, int r, int index)
{
    //totally fitting..
    if(tree[index].l>=l && tree[index].r<=r)
    return tree[index].max;
    //totally disjoint..
    else if(tree[index].l>r || tree[index].r<l)
    return INT_MIN;
    else
    {
        int m1=query(l,r,LEFT);
        int m2=query(l,r,RIGHT);
        return max(m1,m2);
    }
}
int main()
{
    int n,k,i,l,r;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",a+i);
    }
    buildtree(tree,1,n,1);
    scanf("%d",&k);
    for(l=1;l<=n;l++)
    {
        r=l+k-1;
        if(r>n)break;
        printf("%d ",query(l,r,1));
    }
    printf("\n");
    return 0;
}

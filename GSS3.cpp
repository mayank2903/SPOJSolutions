#include<stdio.h>
#include<algorithm>
#define LEFT index*2
#define RIGHT index*2+1
typedef long long int ll;
using namespace std;
struct node
{
    int l;
    int r;
    ll sum;
    ll maxL;
    ll maxR;
    ll max;
};
typedef struct node node;
node tree[200000];
ll a[100001];
int indices[50001];
node buildtree(node* tree, int l, int r, int index)
{
    //printf("building from %d to %d...tree index=%d\n",l,r,index);
    if(l==r)
    {
        tree[index].l=tree[index].r=l;
        tree[index].max=tree[index].maxL=tree[index].maxR=tree[index].sum=a[l];
        indices[l]=index;
      //  printf("tree[%d] contains a[%d]=%lld\n",index,l,a[l]);
        return tree[index];
    }
    int mid=l+(r-l)/2;
    tree[LEFT]=buildtree(tree,l, mid, LEFT);
    tree[RIGHT]=buildtree(tree,mid+1,r,RIGHT);
    tree[index].l=l;
    tree[index].r=r;
    tree[index].sum=tree[LEFT].sum+tree[RIGHT].sum;
    tree[index].maxL=max(tree[LEFT].maxL,tree[LEFT].sum+tree[RIGHT].maxL);
    tree[index].maxR=max(tree[RIGHT].maxR,tree[RIGHT].sum+tree[LEFT].maxR);
    tree[index].max=max(tree[LEFT].max,max(tree[RIGHT].max,tree[LEFT].maxR+tree[RIGHT].maxL));
    return tree[index];
}
void update(ll i)
{
    int start=indices[i];
    //printf("updating at index %d of tree..\n",start);
    tree[start].max=tree[start].maxL=tree[start].maxR=tree[start].sum=a[i];
    int index=start>>1;
    while(index)
    {
        tree[index].sum=tree[LEFT].sum+tree[RIGHT].sum;
        tree[index].maxL=max(tree[LEFT].maxL,tree[LEFT].sum+tree[RIGHT].maxL);
        tree[index].maxR=max(tree[RIGHT].maxR,tree[RIGHT].sum+tree[LEFT].maxR);
        tree[index].max=max(tree[LEFT].max,max(tree[RIGHT].max,tree[LEFT].maxR+tree[RIGHT].maxL));
        //printf("sum[%d, %d]=%lld\n",tree[index].l,tree[index].r,tree[index].sum);
        index>>=1;
    }
    return;
}
node query(int l, int r, int index)
{
    if(tree[index].l>=l && tree[index].r<=r)
    return tree[index];
    int mid=tree[index].l+(tree[index].r-tree[index].l)/2;
    if(r<=mid)
    return query(l,r,LEFT);
    else if(l>mid)
    return query(l,r,RIGHT);
    else
    {
        node q1=query(l,mid,LEFT);
        node q2=query(mid+1,r,RIGHT);
        node q3;
        q3.sum=q1.sum+q2.sum;
        q3.l=l;q3.r=r;
        q3.maxL=max(q1.maxL,q1.sum+q2.maxL);
        q3.maxR=max(q2.maxR,q2.sum+q1.maxR);
        q3.max=max(q1.max,max(q2.max,q1.maxR+q2.maxL));
        return q3;
    }
}
int main()
{
    node ans;
    int n,i,m,ch;
    ll l,r;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    buildtree(tree,1,n,1);
    //printf("indices array:\n");
    //for(i=1;i<=4;i++)printf("%d ",indices[i]);
    //printf("\n");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%lld%lld",&ch,&l,&r);
        if(ch==0)
        {
      //      printf("update value=%lld\n",r);
            a[l]=r;
            update(l);
        }
        else
        {
            ans=query(l,r,1);
            printf("%lld\n",ans.max);
        }
    }
    return 0;
}

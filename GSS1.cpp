#define LEFT 2*index+1
#define RIGHT 2*index+2
#include<stdio.h>
#include<algorithm>
#define gtc getchar_unlocked()
using namespace std;
inline long int lread_int()
{
    register long int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
inline int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
struct node
{
    int l;
    int r;
    long int max;
    long int sum;
    long int maxL;
    long int maxR;
};
typedef struct node node;
node buildtree(node* tree, long int* a, int l, int r, int index)
{
    if(l==r)
    {
        //printf("max[%d, %d]=%d\n",l,r,a[l]);
        tree[index].l=tree[index].r=l;
        tree[index].max=tree[index].maxL=tree[index].maxR=tree[index].sum=a[l];
        return tree[index];
    }
    else
    {
        int mid=l+(r-l)/2;
        //left subtree:
        tree[LEFT]=buildtree(tree,a,l,mid,LEFT);
        tree[RIGHT]=buildtree(tree,a,mid+1,r,RIGHT);
        tree[index].l=l;
        tree[index].r=r;
        tree[index].sum=tree[LEFT].sum+tree[RIGHT].sum;
        tree[index].maxL=max(tree[LEFT].maxL,tree[LEFT].sum+tree[RIGHT].maxL);
        tree[index].maxR=max(tree[RIGHT].maxR,tree[LEFT].maxR+tree[RIGHT].sum);
        tree[index].max=max(max(tree[LEFT].max,tree[RIGHT].max),tree[LEFT].maxR+tree[RIGHT].maxL);
        //printf("max[%d, %d]=%d\n",l,r,tree[index].sum);
        return tree[index];
    }
}
node query(node* tree, int index, int l, int r)
{
    node q1,q2,q3;
    //totally fitting:
    if(tree[index].l>=l && tree[index].r<=r)
    return tree[index];
    int mid=tree[index].l + (tree[index].r-tree[index].l)/2;
    //[l,r] lies in first half:
    if(r<=mid)
    {
        return query(tree,LEFT,l,r);
    }
    //if [l,r] lies in second half:
    else if(l>mid)
    {
        return query(tree,RIGHT,l,r);
    }
    else
    {
        q1=query(tree,LEFT,l,tree[LEFT].r);
        q2=query(tree,RIGHT,tree[LEFT].r+1,r);
        q3.l=l;
        q3.r=r;
        q3.sum=q1.sum+q2.sum;
        q3.maxL=max(q1.maxL,q1.sum+q2.maxL);
        q3.maxR=max(q2.maxR,q2.sum+q1.maxR);
        q3.max=max(max(q1.max,q2.max),q1.maxR+q2.maxL);
        return q3;
    }
}
node tree[1000001];
int main()
{
    int n,m,i,x,y;
    n=read_int();
    long int a[n];
    for(i=0;i<n;i++)
    {
        a[i]=lread_int();
    }
    tree[0]=buildtree(tree,a,0,n-1,0);
    m=read_int();
    while(m--)
    {
        x=read_int();
        y=read_int();
        node q=query(tree,0,x-1,y-1);
        printf("%ld\n",q.max);
    }
    return 0;
}

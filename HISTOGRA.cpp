#include<stdio.h>
#include<algorithm>
#define LEFT 2*index+1
#define RIGHT 2*index+2
typedef long long int ll;
using namespace std;
struct node
{
	ll l;
	ll r;
	ll mindex;
};
typedef struct node node;
node tree[300001];
ll a[100001];
node buildtree(ll* a, ll l, ll r, ll index)
{
	ll mid;
	if(l==r)
	{
		tree[index].l=tree[index].r=l;
		tree[index].mindex=l;
		return tree[index];
	}
	mid=l+(r-l)/2;
	tree[index].l=l;
	tree[index].r=r;
	tree[LEFT]=buildtree(a,l,mid,LEFT);
	tree[RIGHT]=buildtree(a,mid+1,r,RIGHT);
	if(a[tree[LEFT].mindex]<=a[tree[RIGHT].mindex])
		tree[index].mindex=tree[LEFT].mindex;
	else tree[index].mindex=tree[RIGHT].mindex;
	return tree[index];
}
ll query(ll l, ll r, ll index)
{
	ll m1,m2;
	//full intersection
	if(tree[index].l>=l && tree[index].r<=r)
		return tree[index].mindex;
	else if(tree[index].l>r || tree[index].r<l)
		return -1;
	else
	{
		m1=query(l,r,LEFT);
		m2=query(l,r,RIGHT);
		if(m1==-1)return m2;
		else if(m2==-1)return m1;
		else if(a[m1]<=a[m2])return m1;
		else return m2;
	}
}
ll calc(ll l, ll r)
{
	ll m1,m2,m3;
	if(l>r)return 0;
	//printf("doing query [%lld,%lld]\n",l,r);
	//find index of min element in [l,r]..
	ll mindex=query(l,r,0);
	//printf("query returned %lld\n",mindex);
	m1=calc(l,mindex-1);
	m2=calc(mindex+1,r);
	m3=(r-l+1)*a[mindex];
	return max(max(m1,m2),m3);
}
int main()
{
	ll n,i;
	scanf("%lld",&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		//printf("Accepted\n");
		buildtree(a,0,n-1,0);
		//printf("built tree\n");
		printf("%lld\n",calc(0,n-1));
		scanf("%lld",&n);
	}
	return 0;
}

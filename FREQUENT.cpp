#include<stdio.h>
#include<algorithm>
#define left index*2
#define right left+1
#define lval tree[left]
#define rval tree[right]
#define li tree[index].l
#define ri tree[index].r
using namespace std;
struct node
{
	int l;
	int r;
	int lf;
	int rf;
	int mf;
};
typedef struct node node;
node tree[1<<18];
int a[100001];
void buildtree(int* a, int index, int l, int r)
{
	if(l==r)
	{
		tree[index].l=l;
		tree[index].r=r;
		
		tree[index].mf=tree[index].lf=tree[index].rf=1;
		return;
	}
	
	int mid=l+(r-l)/2;
	
	buildtree(a,left,l,mid);
	
	if(mid+1<=r)
	buildtree(a,right,mid+1,r);
	
	tree[index].l=l;
	tree[index].r=r;
	
	if((mid+1)>r)	//no right child exists.
	{
		//calculating lf..
		tree[index].lf=lval.lf;
		tree[index].rf=lval.rf;
		tree[index].mf=lval.mf;
	}
	
	else	//both children exist..
	{
		//lf..
		if(a[mid]==a[mid+1])
		{
			tree[index].lf=tree[left].lf+tree[right].lf*(a[mid]==a[l]);
			tree[index].rf=tree[right].rf+tree[left].rf*(a[mid]==a[r]);
		
			int temp=lval.rf+rval.lf;
			tree[index].mf=max(temp, max(lval.mf, rval.mf));
		}
		
		else
		{
			tree[index].lf=tree[left].lf;
			tree[index].rf=tree[right].rf;
			tree[index].mf=max(lval.mf, rval.mf);
		}
	}
}
int query(int index, int l, int r)
{
	if(li==l && ri==r)
	return tree[index].mf;
	
	int mid=(li+ri)>>1;
	
	if(l>mid)//	only right part exists..
	return query(right, l, r);
	
	if(r<=mid)
	return query(left, l, r);
	
	else
	{
		int temp=0;
		
		if(a[mid]==a[mid+1])
		temp=min(lval.rf, mid-l+1) + min(rval.lf, r-mid);
		
		return max(temp, max(query(left, l, mid), query(right, mid+1, r)));
	}
}
int main()
{
	int n,i,q,j;
	node res;
	
	scanf("%d",&n);
	
	while(n)
	{
		scanf("%d",&q);
		
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		buildtree(a,1,0,n-1);
		
		while(q--)
		{
			scanf("%d%d",&i,&j);
			printf("%d\n",query(1,i-1,j-1));
		}
		
		scanf("%d",&n);
	}
	
	return 0;
}

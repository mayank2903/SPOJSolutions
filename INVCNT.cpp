#include<stdio.h>
typedef long long int ll;
ll a[200001];
ll merge(ll* a, ll* aux, ll l, ll mid, ll r)
{
	ll i,j=l,k=mid+1,inv=0;
	for(i=l;i<=r;i++)
	{
		aux[i]=a[i];
	}
	for(i=l;i<=r;i++)
	{
		if(j>mid) a[i]=aux[k++];
		else if(k>r) a[i]=aux[j++];
		else if(aux[j]<=aux[k]) a[i]=aux[j++];
		else if(aux[j]>aux[k]){ inv+=mid+1-j; a[i]=aux[k++];}
	}
	return inv;
}
ll sort(ll* a, ll* aux, ll l, ll r)
{
	ll mid=l+(r-l)/2;
	if(l==r)return 0;
	ll inv=sort(a,aux,l,mid);
	inv+=sort(a,aux,mid+1,r);
	inv+=merge(a,aux,l,mid,r);
	return inv;
}
ll msort(ll* a, ll size)
{
	ll inv;
	ll l=0,r=size-1,aux[size];
	inv=sort(a,aux,l,r);
	return inv;
}
int main()
{
	ll t,n,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)scanf("%lld",&a[i]);
		printf("%lld\n",msort(a,n));
		//printf("Sorted:\n");
		//for(i=0;i<n;i++)printf("%d ",a[i]);printf("\n");
	}
	return 0;
}

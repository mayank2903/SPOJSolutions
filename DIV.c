#include<stdio.h>
int marked[1000001];
int powa[1000001];
int powb[1000001];
int countdiv[1000001];
int nottosee[1000001];//marks whether numbers are a prospective number of the required kind.
int primes[100000];
void sieve()
{
	int i,j,temp,pow,k=0;
	marked[1]=marked[0]=1;
	for(i=2;i<=1000;i++)
	{
		if(!marked[i])
		{
			primes[k++]=i;
			//printf("%d\n",i);
			for(j=i*i;j<=1000000;j+=i)
			{
				marked[j]=1;
			}
		}
	}
	i=primes[k-1]+1;
	for(;i<=1000000;i++)
	{
		if(!marked[i]){primes[k++]=i;}
	}
	//printf("%d primes\n",k);
	for(i=0;i<k;i++)
	{
		nottosee[primes[i]]=1;
		for(j=2*primes[i];j<=1000000;j+=primes[i])
		{
			if(nottosee[j])continue;
			countdiv[j]++;
			if(countdiv[j]>2)nottosee[j]=1;
			else{
			temp=j;pow=0;
			while(temp%primes[i]==0)
			{
				temp/=primes[i];pow++;
			}
			if(powa[j]==0){powa[j]=pow;}
			else {powb[j]=pow;}
			}
		}
	}
/*
	for(i=999800;i<=1000000;i++)
	{
		printf("i=%d powa=%d powb=%d countdiv=%d diva=%d divb=%d\n",i,powa[i],powb[i],countdiv[i],diva[i],divb[i]);
	}printf("---------------\n");
*/
}
int main()
{
	int count=0,i;
	sieve();
	//printf("here\n");
	//if(marked[20407]==0)printf("20407isprime\n");
	for(i=2;i<=1000000;i++)
	{
		if(nottosee[i])continue;
		if(countdiv[i]==2 && marked[1+powa[i]]==0 && marked[1+powb[i]]==0 && powa[i]!=powb[i])
		{
			count++;
			if(count%9==0)
			printf("%d\n",i);
		}
		else if(countdiv[i]==1 && countdiv[1+powa[i]]==2 && powa[1+powa[i]]==1 && powb[1+powa[i]]==1 )
		{
			count++;
		if(count%9==0)
			printf("%d\n",i);
		}
	}
	return 0;
}

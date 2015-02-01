#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	long int k,row,diff;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&k);
		row=(long int)((sqrt(1.0+8*k)-1.0)/2.0);
		//printf("row=%ld\n",row);
		diff=k-row*(row+1)/2;
		//printf("diff=%ld\n",diff);
		if(diff==0)
		{
			if(row&1)
			printf("TERM %ld IS %ld/%ld\n",k,1,row);
			else printf("TERM %ld IS %ld/%ld\n",k,row,1);
			continue;
		}
		else{
			if(row%2==0)
			printf("TERM %ld IS %ld/%ld\n",k,row+2-diff,diff);
			else printf("TERM %ld IS %ld/%ld\n",k,diff,row+2-diff);
		}
	}
	return 0;
}

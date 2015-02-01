#include<stdio.h>
int main()
{
	int t,max1,max2,nm,ng,i,x;
	scanf("%d",&t);
	while(t--)
	{
		max1=0;max2=0;
		scanf("%d%d",&ng,&nm);
		for(i=0;i<ng;i++)
		{
			scanf("%d",&x);
			if(x>max1)max1=x;
		}
		for(i=0;i<nm;i++)
		{
			scanf("%d",&x);
			if(x>max2)max2=x;
		}
		if(max1>max2)
			printf("Godzilla\n");
		else if(max2>max1)
			printf("MechaGodzilla\n");
		else printf("Godzilla\n");
	}
	return 0;
}

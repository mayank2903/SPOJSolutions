#include <stdio.h>
int main(void) {
	// your code goes here
	
	int t,x,y;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d",&x,&y);
		
		if(y==x)
		{
			if(y%2==0)
			{
				printf("%d\n",2*y);
			}
			else
			printf("%d\n",2*y-1);
		}
		
		else if(y==(x-2))
		{
			if(x%2==0)
			{
				printf("%d\n",2*x-2);
			}
			
			else
			printf("%d\n",2*y+1);
		}
		else
		printf("No Number\n");
	}
	return 0;
}

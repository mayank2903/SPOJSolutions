#include<stdio.h>
int main()
{
	int row, col,i,j,k,f,l,start,temp,step,step1;
	char str[200];int marked[200];
	scanf("%d",&col);
	getchar();
	while(col!=0)
	{
		for(i=0;i<200;i++)marked[i]=0;
		scanf("%s",str);
		l=strlen(str);
		row=l/col;
		step=2*col-1;
		start=0;step1=1;
		while(marked[start]==0 && start<l)
		{
			temp=start;
			f=0;
			while(marked[temp]==0 && temp<l)
			{
				putchar(str[temp]);
				marked[temp]=1;
				if(f==0)
				{
					temp+=step;
					f=1;
				}
				else {temp+=step1;f=0;}
			}
			step-=2;
			step1+=2;
			start++;
		}
		putchar('\n');
		scanf("%d",&col);
		getchar();
	}
	return 0;
}

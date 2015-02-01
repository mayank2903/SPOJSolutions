#include<stdio.h>
#include<string.h>
int visitx[3][3];
int visity[3][3];
char mat[3][3];
int intersect(char c)
{
	int ans=0;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(c=='X')
			ans+=(visitx[i][j]==2);
			
			else ans+=(visity[i][j]==2);
		}
	}
	return ans;
}
int wins(char c)
{
	int w=0,i,j;
	
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	visitx[i][j]=visity[i][j]=0;
	
	//row wise..
	for(i=0;i<3;i++)
	{
		if(mat[i][0]==c && mat[i][1]==c && mat[i][2]==c)
		{
			if(c=='X')
			{
				visitx[i][0]++;visitx[i][1]++;visitx[i][2]++;
			}
			
			if(c=='Y')
			{
				visity[i][0]++;visity[i][1]++;visity[i][2]++;
			}
			
			w++;
		}
	}
	
	//columnwise..
	for(i=0;i<3;i++)
	{
		if(mat[0][i]==c && mat[1][i]==c && mat[2][i]==c)
		{
			if(c=='X')
			{
				visitx[0][i]++;visitx[1][i]++;visitx[2][i]++;
			}
			
			if(c=='Y')
			{
				visity[0][i]++;visity[1][i]++;visity[2][i]++;
			}
			
			w++;
		}
	}
	
	//principal diagonal wise..
	if(mat[0][0]==c && mat[1][1]==c && mat[2][2]==c)
	{
		if(c=='X')
		{
			visitx[0][0]++;visitx[1][1]++;visitx[2][2]++;
		}
		
		if(c=='Y')
		{
			visity[0][0]++;visity[1][1]++;visity[2][2]++;
		}
		
		w++;
	}
	
	//other diagonal wise..
	if(mat[0][2]==c && mat[1][1]==c && mat[2][0]==c)
	{
		if(c=='X')
		{
			visitx[0][2]++;visitx[1][1]++;visitx[2][0]++;
		}
		
		if(c=='Y')
		{
			visity[0][2]++;visity[1][1]++;visity[2][0]++;
		}
		
		w++;
	}
	
	return w;
}
int main()
{
	int l,i,j,a,b,cx,cd,co,wx,wo;
	
	char str[10];
	
	while(scanf("%s",str))
	{
		if(str[0]=='e')
		return 0;
		
		l=9;
		
		a=b=cx=cd=co=0;
		for(i=0;i<l;i++)
		{
			mat[a][b++]=str[i];
			
			if(str[i]=='X')
			cx++;
			
			else if(str[i]=='O')
			co++;
			
			else
			cd++;
			
			if(b==3)
			{
				b=0;a++;
			}
		}
		
		//validity of counts..
		if(cx!=co && cx!=co+1)
		{
			puts("invalid");
			continue;
		}
		
		//calculating wins of X..
		wx=wins('X');
		
		//wins of O..
		wo=wins('O');
		
		//both cannot win..
		if(wx!=0 && wo!=0)
		{
			puts("invalid");
			continue;
		}
		
		//nobody won..
		if(wo==0 && wx==0)
		{
			if(cd!=0)
			puts("invalid");
			
			else puts("valid");
			
			continue;
		}
		
		//X won..
		if(wx!=0)
		{
			//CHECK COUNT..
			if(cx!=co+1)
			{
				puts("invalid");
				continue;
			}
			
			if(wx==1)
			puts("valid");
			
			else if(wx==2)
			{
				if(intersect('X')<=1)
				puts("valid");
				
				else puts("invalid");
			}
			
			else puts("invalid");
			
			continue;
		}
		
		//O won..
		if(wo!=0)
		{
			//check count..
			if(co!=cx)
			{
				puts("invalid");
				continue;
			}
			
			if(wo==1)
			puts("valid");
			
			else if(wo==2)
			{
				if(intersect('O')==1)
				puts("valid");
				
				else puts("invalid");
			}
			
			else puts("invalid");
			
			continue;
		}
	}
	
	return 0;
}

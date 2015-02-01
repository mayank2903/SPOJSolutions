#include<stdio.h>
#include<stdlib.h>
#define white 0
#define black 1
struct vertex
{
	int no;
	struct vertex* link;
};
typedef struct vertex vertex;
struct adj
{
	vertex* head;
	int marked;
};
typedef struct adj adj;
adj vertices[10001];
void add_neighbour(int a, int b)
{
	vertex* newnode=(vertex*)malloc(sizeof(vertex));
	newnode->no=b;
	newnode->link=vertices[a].head;
	vertices[a].head=newnode;
}
void dfs(int i)
{
	vertex* temp;
	vertices[i].marked=black;
	for(temp=vertices[i].head;temp!=NULL;temp=temp->link)
	{
		if(vertices[temp->no].marked==white)
			dfs(temp->no);
	}
}
int main()
{
	int n,m,i,u,v,f;
	scanf("%d%d",&n,&m);
	if(m!=(n-1)){printf("NO\n");return 0;}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		add_neighbour(u,v);
		add_neighbour(v,u);
	}
	dfs(1);f=0;
	for(i=1;i<=n;i++)
	{
		if(vertices[i].marked==white)
		{
			f=1;break;
		}
	}
	if(f==0)printf("YES\n");
	else printf("NO\n");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct vertex
{
	int vertex;
	bool marked;
	struct vertex* link;
};
typedef struct vertex vertex;
vertex vertices[10001];
int ht[10001];
int h1[10001];
int h2[10001];
int outdeg[10001];
void add_neighbour(int a, int b)
{
	vertex* newnode=(vertex*)malloc(sizeof(vertex));
	newnode->vertex=b;
	newnode->link=vertices[a].link;
	vertices[a].link=newnode;
}
int height(int a)
{
	vertex* temp;
	int x;
	if(vertices[a].link==0)return 0;
	for(temp=vertices[a].link;temp;temp=temp->link)
	{
			x=height(temp->vertex);
			if(x>h1[a])
			{
				h2[a]=h1[a];
				h1[a]=x;
			}
			else if(x>h2[a])
				h2[a]=x;
			ht[a]=max(ht[a],x+1);
	}
	return ht[a];
}
int diameter(int a)
{
	if(ht[a]==0)return 0;
	vertex* temp;int d=0;
	for(temp=vertices[a].link;temp;temp=temp->link)
	{
		d=max(d,diameter(temp->vertex));
	}
	if(outdeg[a]>=2)
	{
		return max(h1[a]+h2[a]+2,d);
	}
	else if(outdeg[a]==1)
		return max(d,h1[a]+1);
	else return d;
}
int main()
{
	int n,t,u,v;
	scanf("%d",&n);
	t=n-1;
	while(t--)
	{
		scanf("%d%d",&u,&v);
		add_neighbour(u,v);
		outdeg[u]++;
	}
	height(1);
	printf("%d\n",diameter(1));
	return 0;
}

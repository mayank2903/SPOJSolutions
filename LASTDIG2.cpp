#include<stdio.h>
#include<string.h>
#define x getchar()
typedef unsigned long long int ll;
ll r(){register ll noRead=0,isneg=0;register char p=x;for(;p<48||p>57;p=x){if(p=='-')isneg=1;}while(p>47&&p<58){noRead=(noRead<<3)+(noRead<<1)+(p-'0');p=x;}if(isneg)noRead=-noRead;return noRead;}
int pows[10][4]={{0,0,0,0},{1,1,1,1},{2,4,8,6},{3,9,7,1},{4,6,4,6},{5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1}};
main(){int t,l1,l2,c1;ll c2;char s1[2000];scanf("%d",&t);while(t--){scanf("%s",s1);c2=r();l1=strlen(s1);c1=s1[l1-1]-'0';if(c2==0){printf("1\n");continue;}c2-=1;if(c1<=1)printf("%d\n",c1);else printf("%d\n",pows[c1][c2%4]);}}

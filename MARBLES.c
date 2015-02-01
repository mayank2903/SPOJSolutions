#include<stdio.h>
 
#define gc() getchar_unlocked()
 
inline int read_int() {
  register char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
 
 
inline long long int read_lint() {
  register char c = gc();
  while(c<'0' || c>'9') c = gc();
  long long int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
 
inline void fastwrite(long long int a){
register char c;
char snum[20];
int i=0;
do{
snum[i++]=a%10+48;
a=a/10;
}while(a!=0);
i=i-1;
while(i>=0)
putchar_unlocked(snum[i--]);
putchar_unlocked('\n');
}
 
 
 
long long int C(long long int n,long long int r)
{
    if(r==0)return 1;
 
    if(n==r)return 1;
 
    if(n-r<r)r=n-r;
 
    return (n*C(n-1,r-1)/r);
}
 
int main()
{
    int t;
    long long  int n,k;
    t=read_int();
    while(t--)
    {
        n=read_lint();
        k=read_lint();
        if(n-1==0||k-1==0)
        {
            putchar_unlocked('1');
            putchar_unlocked('\n');
            continue;
        }
        fastwrite(C(n-1,k-1));
 
    }
    return 0;
}

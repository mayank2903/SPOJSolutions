#include<stdio.h>
#include<algorithm>
#include<climits>
using namespace std;
void empty(int* a)
{
    *a=0;
}
void fill(int* a, int cap)
{
    *a=cap;
}
void pour(int* from, int* to, int cap)
{
    *to=((*to)+(*from));
    if((*to)>cap)
    {
        *from=*to-cap;
        *to=cap;
    }
    else *from=0;
}
int gcd(int a, int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int solve(int acap, int bcap, int fil)
{
   // printf("solving...acap=%d bcap=%d fil=%d\n",acap,bcap,fil);
    int a,b;
    a=b=0;
    int steps=0;
    while(b!=fil && a!=fil)
    {
        if(a==0)
        {
            fill(&a, acap);
        //    printf("filling..a=%d b=%d\n",a,b);
            steps++;
        }
        else if(b==0)
        {
            pour(&a,&b,bcap);
          ///  printf("pouring..a=%d b=%d\n",a,b);
            steps++;
        }
        else if(b==bcap)
        {
            empty(&b);
           // printf("emptying..a=%d b=%d\n",a,b);
            steps++;
        }
        else
        {
            pour(&a,&b,bcap);
           // printf("pouring..a=%d b=%d\n",a,b);
            steps++;
        }
    }
    return steps;
}
int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(c>a && c>b)printf("-1\n");
        else if(c%gcd(a,b)!=0)printf("-1\n");
        else if(c==a||c==b)printf("1\n");
        else
        {
            printf("%d\n",min(solve(a,b,c),solve(b,a,c)));
        }
    }
    return 0;
}

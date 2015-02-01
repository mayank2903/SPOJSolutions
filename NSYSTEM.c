#include<stdio.h>
int calc(char* s1)
{
    int n1=0;
        //pos of 'm'
        char* mpos=strstr(s1,"m");
        if(mpos)
        {
            int mmpos=mpos-s1;
            if(mmpos!=0)
            n1+=(s1[mmpos-1]-'0')*1000;
            else n1+=1000;
        }
        char* cpos=strstr(s1,"c");
        if(cpos)
        {
            int ccpos=cpos-s1;
            if(ccpos!=0 && isdigit(s1[ccpos-1]))
            n1+=(s1[ccpos-1]-'0')*100;
            else n1+=100;
        }
        char* xpos=strstr(s1,"x");
        if(xpos)
        {
            int xxpos=xpos-s1;
            if(xxpos!=0 && isdigit(s1[xxpos-1]))
            n1+=(s1[xxpos-1]-'0')*10;
            else n1+=10;
        }
        char* ipos=strstr(s1,"i");
        if(ipos)
        {
            int iipos=ipos-s1;
            if(iipos!=0 && isdigit(s1[iipos-1]))
            n1+=s1[iipos-1]-'0';
            else n1++;
        }
        return n1;
}
void print(int n)
{
    int m=n/1000;
    if(m!=0)
    {
        if(m==1)putchar('m');
        else printf("%dm",m);
    }
    int c=(n%1000)/100;
    if(c!=0)
    {
        if(c==1)
        putchar('c');
        else printf("%dc",c);
    }
    int x=(n%100)/10;
    if(x!=0)
    {
        if(x==1)
        putchar('x');
        else printf("%dx",x);
    }
    int i=n%10;
    if(i!=0)
    {
        if(i==1)putchar('i');
        else printf("%di",i);
    }
    putchar('\n');
}
int main()
{
    int n1,n2,t;
    char s1[100],s2[100];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        scanf("%s %s",s1,s2);
        //printf("s1=%s s2=%s\n",s1,s2);
        n1=calc(s1);
        n2=calc(s2);
        //printf("n1=%d n2=%d\n",n1,n2);
        n1+=n2;
        print(n1);
    }
    return 0;
}

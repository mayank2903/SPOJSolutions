#include<stdio.h>
#include<string.h>
char increment(char a)
{
    if(a>='0' && a<='8')return a+1;
    else return '0';
}
char str[1000010];
int main()
{
    int t,i,just9,l,mid1,mid2,m1,m2,carry;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&str[1]);
        l=strlen(&str[1]);
        just9=1;
        for(i=1;i<l+1;i++)
        {
            if(str[i]!='9'){just9=0;break;}
        }
        //all 9's case:
        if(just9)
        {
            putchar('1');
            for(i=1;i<l;i++)
            {
                putchar('0');
            }
            putchar('1');
            putchar('\n');
            continue;
        }
        if(l&1)
        {
            mid1=mid2=(l>>1)+1;
            m1=m2=mid1;
        }
        else
        {
            mid1=l>>1;m1=mid1;
            mid2=mid1+1;m2=mid2;
        }
        //keep running till the opposite ends are equal.
        while(mid1>0 && str[mid1]==str[mid2])
        {
            mid1--;
            mid2++;
        }
        //if the string is a palindrome..
        if(mid1==0 || str[mid1]<str[mid2])
        {
            //increment the middle digit and forward the carry..
            str[m1]=str[m2]=increment(str[m1]);
            if(str[m1]=='0')
            {
                carry=1;
                //forward the carry now..
                while(carry==1)
                {
                    str[m1-1]=increment(str[m1-1]);
                    if(str[m1-1]=='0')carry=1;
                    else carry=0;
                    m1--;
                }
            }
        }
        if(l&1)
        {
            mid1=mid2=(l>>1)+1;
            m1=m2=mid1;
        }
        else
        {
            mid1=l>>1;m1=mid1;
            mid2=mid1+1;m2=mid2;
        }
        //copying left to right part..
        while(mid1>0)
        {
            str[mid2]=str[mid1];
            mid1--;
            mid2++;
        }
        printf("%s\n",str+1);
    }
    return 0;
}

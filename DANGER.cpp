#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    long long int nn,num;
    char str[5];
    int i,logval;
    scanf("%s",str);
    while(strstr(str,"00e0")==NULL)
    {
        num=(str[0]-'0')*10+(str[1]-'0');
        for(i=1;i<=str[3]-'0';i++)
        {
            num=(num<<3)+(num<<1);
        }
        nn=num;
        logval=(int)log2(nn);
        //printf("logval=%d\n",logval);
        nn-=1<<logval;
        nn<<=1;
        nn+=1;
        printf("%lld\n",nn);
        scanf("%s",str);
    }
    return 0;
}

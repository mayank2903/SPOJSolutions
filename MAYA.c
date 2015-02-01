#include<stdio.h>
typedef long long int ll;
int main()
{
    ll ans;
    int n,i,j,wt;
    char str[100];
    ll weights[7]={1,20,360,7200,144000,2880000,57600000,1152000000};
    //accept number of digits to follow..ive to convert these to decimal form..
    scanf("%d",&n);
    getchar();
    while(n!=0)
    {
        ans=0;wt=n-1;
        //scan the n digits..
        for(i=0;i<n;i++)
        {
            //accepting a digit..
            gets(str);
            //printf("digit=%s\n",str);
            //traversing the digit..
            //i already have a weight for the digit..i.e. 'wt'
            for(j=0;str[j]!='\0';j++)
            {
                if(str[j]=='.')
                ans+=weights[wt];
                else if(str[j]=='-')
                ans+=5*weights[wt];
            }
            wt--;
        }
        printf("%lld\n",ans);
        scanf("%d",&n);
        getchar();
    }
    return 0;
}

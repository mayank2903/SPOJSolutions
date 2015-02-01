#include<stdio.h>
#define gtc getchar_unlocked()
inline int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
int main()
{
	int t,p,x,i,rem,j,denom;
	t=read_int();
	while(t--)
	{
		p=read_int();x=read_int();
		denom=10*x-1;
		switch(denom)
		{case 9:
                for(j=0;j<p;j++)printf("1");
                printf("\n");
                break;
            case 19:
                if(p%18==0)
                {
                    rem=p/18;
                    for(j=0;j<rem;j++)printf("105263157894736842");
                    printf("\n");
                }
                else printf("Impossible\n");
                break;
            case 29:
                if(p%28==0)
                {
                    rem=p/28;
                    for(j=0;j<rem;j++)printf("1034482758620689655172413793");
                    printf("\n");
                }
                else printf("Impossible\n");
                break;
            case 39:
                if(p%6==0)
                {
                    rem=p/6;
                    for(j=0;j<rem;j++)printf("102564");
                    printf("\n");
                }
                else printf("Impossible\n");
                break;
            case 49:
                if(p%42==0)
                {
                    rem=p/42;
                    for(j=0;j<rem;j++)printf("102040816326530612244897959183673469387755");
                    printf("\n");
                }
                else if(p%6==0)
                {
                    rem=p/6;
                    for(j=0;j<rem;j++)printf("142857");
                    printf("\n");
                }
                else printf("Impossible\n");
                break;
            case 59:
                if(p%58==0)
                {
                    rem=p/58;
                    for(j=0;j<rem;j++)
                    {
                        printf("1016949152542372881355932203389830508474576271186440677966");
                    }
                    printf("\n");
                }
                else printf("Impossible\n");
                break;
            case 69:
                if(p%22==0)
                {
                    rem=p/22;
                    for(j=0;j<rem;j++)printf("1014492753623188405797");
                    printf("\n");
                }
                else printf("Impossible\n");
                break;
            case 79:
                if(p%13==0)
                {
                    rem=p/13;
                    for(j=0;j<rem;j++)printf("1012658227848");
                    printf("\n");
                }
                else printf("Impossible\n");
                break;
            case 89:
                if(p%44==0)
                {
                    rem=p/44;
                    for(j=0;j<rem;j++)printf("10112359550561797752808988764044943820224719");
                    printf("\n");
                }
                else printf("Impossible\n");
                break;
            }
        }
        return 0;
}

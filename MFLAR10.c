#include<stdio.h>
#include<ctype.h>
int main()
{
    int f;
    char c,first;
    while(1)
    {
        f=0;
        c=getchar();
        if(c=='*')break;
        first=tolower(c);
        while((c=getchar())!='\n')
        {
            if(c==' ' && tolower(getchar())!=first)
            {
                f=1;
            }
        }
        if(f==0)putchar('Y');
        else putchar('N');
        putchar('\n');
    }
    return 0;
}

#include<stdio.h>
char str[10],str1[4],str2[4],str3[4];
int main()
{
    int i,j,no_X,no_O,flag,win_X,win_O,t;
    scanf("%i",&t);
    while(t--)
    {
        no_X = no_O = flag = win_X = win_O = 0;
        scanf("%s%s%s",str1,str2,str3);
        str[0] = str1[0];
        str[1] = str1[1];
        str[2] = str1[2];
        str[3] = str2[0];
        str[4] = str2[1];
        str[5] = str2[2];
        str[6] = str3[0];
        str[7] = str3[1];
        str[8] = str3[2];
        for(i=0;    i<9;    i++)
        {
            if(str[i] == 'X')
                no_X++;
            else if(str[i] == 'O')
                no_O++;
        }
        if(str[4] != '.')
        {
            if(str[4] == 'O')
            {
                if((str[0] == 'O' && str[8] == 'O') || (str[1] == 'O' && str[7] == 'O') || (str[2] == 'O' && str[6] == 'O') || (str[3] == 'O' && str[5] == 'O'))
                    win_O = 1;
            }
            else
            {
                if((str[0] == 'X' && str[8] == 'X') || (str[1] == 'X' && str[7] == 'X') || (str[2] == 'X' && str[6] == 'X') || (str[3] == 'X' && str[5] == 'X'))
                    win_X = 1;
            }
        }
        if(str[1] != '.')
        {
            if(str[0] == 'O')
            {
                if((str[3] == 'O' && str[6] == 'O') || (str[1] == 'O' && str[2] == 'O'))
                    win_O =1;
            }
            else
            {
                if((str[3] == 'X' && str[6] == 'X') || (str[1] == 'X' && str[2] == 'X'))
                    win_X =1;
            }
        }
        if(str[8] != '.')
        {
            if(str[8] == 'O')
            {
                if((str[5] == 'O' && str[2] == 'O') || (str[7] == 'O' && str[6] == 'O'))
                    win_O = 1;
            }
            else
            {
                if((str[5] == 'X' && str[2] == 'X') || (str[7] == 'X' && str[6] == 'X'))
                    win_X = 1;
            }
        }
        if(win_X == 1 && win_O == 1)
            flag = 1;
        else
        {
            if(win_X == 1 && win_O == 0 && no_X != no_O + 1)
                flag = 1;
            else if(win_X == 0 && win_O == 1 && no_X != no_O)
                flag = 1;
            else if(no_X != no_O+1 && no_X != no_O)
            {
                flag = 1;
            }
        }
        if(flag)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}

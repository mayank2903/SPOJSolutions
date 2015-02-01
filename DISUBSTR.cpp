#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;
bool comp(const void* a, const void* b)
{
    return (strcmp((char*)a,(char*)b)<0);
}
int lcp(char* a, char* b, char* str)
{
    int lcp=0;
    while((*a)!='\0' && (*b)!='\0')
    {
        if((*a)==(*b))
        {
            lcp++;
            a++;b++;
        }
        else return lcp;
    }
    return lcp;
}
int main()
{
    int t,l,i,j,ans,len;
    char str[1001];char* suffix_array[1001];
    char* temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        //creating a suffix array of the given string..
        for(i=0;str[i]!='\0';i++)
        {
            suffix_array[i]=str+i;
        }
        len=i;
        sort(suffix_array,suffix_array+len,comp);
/*
        for(i=0;i<len;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(strcmp(suffix_array[i],suffix_array[j])>0)
                {
                    temp=suffix_array[i];
                    suffix_array[i]=suffix_array[j];
                    suffix_array[j]=temp;
                }
            }
        }
        printf("sorted suffixes:");
        for(i=0;i<len;i++)
        printf("%s\n",suffix_array[i]);*/
        //ive now created the suffix array.
        //now to find the number of distinct substrings.
        ans=(str+len)-suffix_array[0];
//        printf("initial ans=%d\n",ans);
        for(i=1;i<len;i++)
        {
            //ans+=length of this suffix-length of its lcp with prev suffix.
  //          printf("\nfor suffixes %s and %s:\n",suffix_array[i-1],suffix_array[i]);
            ans+=((str+len)-suffix_array[i])-lcp(suffix_array[i-1],suffix_array[i],str);
    //        printf("ans=%d\n",ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}

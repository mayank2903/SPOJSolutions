#include<bits/stdc++.h>
using namespace std;
int cubes[101];
int m[1000001];
int main()
{
    //producing all cubes first.
    for(int i = 2; i <= 100; i++)
    {
        cubes[i] = i*i*i;
        m[cubes[i]] = i;
    }
        
    //for each cube
    for(int i = 2; i <= 100; i++)
    {
        //find all triplets such that they sum up to cubes[i].
        for(int j = 2; j <= i; j++)
        {
            for(int k = 2; k <= 100; k++)
            {
                int sum = cubes[j] + cubes[k];
                if(cubes[i] >= sum && m[cubes[i] - sum])
                {
                    int a = j;
                    int b = k;
                    int c = m[cubes[i] - sum];
                    
                    if(a <= b && b <= c)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", i, a, b, c);
                }
            }
        }
    }
    
    return 0;
}

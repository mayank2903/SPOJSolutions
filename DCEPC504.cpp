#include<bits/stdc++.h>
using namespace std;
int findGender(int n, long long k)
{
    //cout<<"Gender ("<<n<<", "<<k<<")"<<endl;
    if(n==1)
        return 1;
    //find gender of parent..
    int parent = findGender(n-1,k/2);
    if(k%2==1)
        return 1-parent;
    return parent;
}
int main()
{
    int t,n;
    long long k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        puts(findGender(n,k-1)? "Male" : "Female");
    }
    return 0;
}

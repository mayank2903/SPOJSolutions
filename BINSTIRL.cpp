/*
 * binstirl.cpp
 *
 *  Created on: Dec 26, 2014
 *      Author: mb1994
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,A,B;
	cin>>t;
	while(t--)
	{
		cin>>A>>B;
		bool ans = ((A-B)&((B-1)>>1)) == 0;
		cout<<ans<<endl;
	}
	return 0;
}

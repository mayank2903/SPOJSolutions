/*
 * bomarble.cpp
 *
 *  Created on: Dec 27, 2014
 *      Author: mb1994
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	while(true)
	{
		scanf("%d",&t);
		if(t==0)
			return 0;
		t++;
		cout<<t*(3*t-1)/2<<endl;
	}
}

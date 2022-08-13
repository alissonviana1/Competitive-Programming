#include <bits/stdc++.h>
#define MAX 1000100

using namespace std;

int n, x,c = -1, dp[MAX];

int fib(int x)
{
	c++;
	if (x == 0) return 0;
	if (x == 1) return 1;
	
	dp[x] = fib(x-1)+fib(x-2);
	
	return dp[x];
	
}



int main()
{
	memset(dp,-1,sizeof(dp));
	
	cin>>n;
	while(n--)
	{	
		cin>>x;
		cout<<"fib("<<x<<") = "<<c<<" calls = "<<fib(x)<<"\n";
		c = -1;
	}
	
}

#include <bits/stdc++.h>
using namespace std;
int memo[1001][1001];

int n,m;
string str, str2;
int lcs(int i, int j)
{
	if(i == n || j == m) return 0;
	int &pd = memo[i][j];
	if(pd != -1) return pd;
	if(str[i] == str2[j]) return pd = 1 + lcs(i+1,j+1);
	return pd = max(lcs(i+1, j), lcs(i,j+1));
}


int main()
{
	
	cin>>str;
	cin>>str2;
	n = str.size();
	m = str2.size();
	memset(memo,-1,sizeof memo);
	printf("%d\n", (n+m)-lcs(0,0));
	
}

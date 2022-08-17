#include <bits/stdc++.h>
using namespace std;

int memo[1001][1001],n;
string aux,s,t;

int lcs(int i,int j)
{
	if(i == n || j == n) return 0;
	int &pd = memo[i][j];
	if(pd != -1) return pd;
	if(s[i] == t[j]) return pd = 1 + lcs(i+1,j+1);
	return pd = max(lcs(i+1,j), lcs(i,j+1));	
}


int main()
{
	memset(memo, -1, sizeof memo);
	cin>>aux;
	for (int i = 0; i < (int)aux.size(); i++)
	{
		if(aux[i] != 'a') s += aux[i];
	}
	n = (int)s.size();
	t = s;
	reverse(t.begin(),t.end());
	cout<<lcs(0,0)<<endl;	
}

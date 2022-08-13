#include <bits/stdc++.h>
using namespace std;
vector<int>G[350];
int vist[350];
int cont = 0;

void dfs(int u)
{
	vist[u] = 1;
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		int v = G[u][i];
		if(!vist[v]) dfs(v);
	}
}


int main()
{
	int na,nv,c1 = 0;
	string n1,aresta,n2;
	map<string,int> mp;
	scanf(" %d%d", &nv,&na);
	for (int i = 0; i < na; i++)
	{
		cin>>n1>>aresta>>n2;
		if(mp.find(n1) != mp.end() && mp.find(n2) != mp.end())
		{
			G[mp[n1]].push_back(mp[n2]);
			G[mp[n2]].push_back(mp[n1]);
		}
		else
		{
			if(mp.find(n1) == mp.end())
			{
				c1++;
				mp[n1] = c1;
			}
			if(mp.find(n2) == mp.end())
			{
				c1++;
				mp[n2] = c1;
			}
			G[mp[n1]].push_back(mp[n2]);
			G[mp[n2]].push_back(mp[n1]);
		}
	}
	
	for (int i = 1; i <= nv; i++)
	{
		if(!vist[i])
		{
			dfs(i);
			cont++;
		}
	}
	printf("%d\n", cont);
	
}

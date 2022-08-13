#include <bits/stdc++.h>
using namespace std;

vector<int>G[100100];
int visitado[100100];

int CC = 0,nv,na,a,b;

void dfs(int u)
{
	visitado[u] = 1;
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		int v = G[u][i];
		if(visitado[v] == 0)
		{
			dfs(v);
		}
	}
	
}


int main()
{
	
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	cin>>nv>>na;
	
	for (int i = 0; i < na; i++)
	{
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	
	CC = 0;
	memset(visitado,0,sizeof(visitado));
	
	for (int i = 1; i <= nv; i++)
	{
		if(visitado[i] == 0)
		{
			dfs(i);
			++CC;
		}
	}
	cout<<CC<<"\n";
	CC = 0;
	
	
}

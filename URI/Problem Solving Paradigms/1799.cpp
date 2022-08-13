#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
map<string, int> mp;
vector<int> G[5001];
int dist[5001];

int bfs(int s,int r)
{
	dist[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = 0; i < (int)G[u].size(); i++)
		{
			int v = G[u][i];
			if(dist[v] == inf)
			{
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
	return dist[r];
}

int main()
{
	int a,b;
	scanf(" %d%d",&a,&b);
	string x,y;
	int cont = 0;
	for (int i = 0; i < a; i++)
	{
		dist[i] = inf;
	}
	
	for (int i = 0; i < b; i++)
	{	
		cin>>x>>y;
		if(mp.find(x) == mp.end())
		{
			mp[x] = cont;
			cont++;
			if(mp.find(y) == mp.end())
			{
				mp[y] = cont;
				cont++;
			}
			G[mp[x]].push_back(mp[y]);
			G[mp[y]].push_back(mp[x]);
		}
		else
		{
			if(mp.find(y) == mp.end())
			{
				mp[y] = cont;
				cont++;
			}
			G[mp[x]].push_back(mp[y]);
			G[mp[y]].push_back(mp[x]);
		}
	}
	
	int res = bfs(mp["Entrada"], mp["*"]);
);
	for (int i = 0; i < a; i++)
	{
		dist[i] = inf;
	}	
	int res2 = bfs(mp["*"],mp["Saida"]);

	printf("%d\n", res+res2);
	
}

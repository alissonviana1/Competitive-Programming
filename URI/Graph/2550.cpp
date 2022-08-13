#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int pai[100100],tam[100100];
vector<int>A[100100];

int find(int u)
{
	if(pai[u] == u) return u;
	return find(pai[u]);
}

void UnionSet(int a,int b)
{
	a = find(a);
	b = find(b);
	
	if(tam[a] > tam[b])
	{
		pai[b] = a;
		tam[a] += tam[b];
	}
	else
	{
		pai[a] = b;
		tam[b] += tam[a];
	}
}

int vis[10100];

void dfs(int u)
{
	vis[u] = 1;
	for (int i = 0; i < (int)A[u].size(); i++)
	{
		int v = A[u][i];
		if(!vis[v])
			dfs(v);
	}
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	int nv,na;
	while (scanf("%d%d", &nv,&na) != -1)
	{
		int a,b,custo,total = 0;
		vector<iii>G;
		
		for (int i = 1; i <= nv; i++)
		{
			pai[i] = i;
			tam[i] = 1;
			vis[i] = 0;
			A[i].clear();
		}
		for (int i = 0; i < na; i++)
		{
			scanf("%d%d%d",&a,&b,&custo);
			G.push_back(iii(custo,ii(a,b)));
			A[a].push_back(b);
			A[b].push_back(a);
		}
		int cont = 0;
		for (int i = 1; i <= nv; i++)
		{
			if(!vis[i])
			{
				dfs(i);
				cont++;
			}
			if(cont >= 2) break;
		}
		if(cont < 2)
		{
			sort(G.begin(),G.end());
			for (int i = 0; i < (int)G.size(); i++)
			{
				if(find(G[i].second.first) != find(G[i].second.second))
				{
					UnionSet(G[i].second.first, G[i].second.second);
					total += G[i].first;
				}
			}
			printf("%d\n", total);
		}
		else
		{
			puts("impossivel");
		}
	}
}

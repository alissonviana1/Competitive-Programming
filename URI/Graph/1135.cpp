#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ull, ull> pull;
vector<ii>G[100100];
ull dist[100100][21];
int sparse[100100][21];
int h[100100];
int n;

void dfs(ull u, ull pai,ull soma)
{
	sparse[u][0] = pai;
	dist[u][0] = soma;
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		ull v = G[u][i].first;
		if(v == pai) continue;
		h[v] = h[u]+1;
		dfs(v, u, G[u][i].second);
	}
}

void calcular()
{
	for(int i = 1; i < 21; ++i)
	{
		for (int x = 0; x < n; x++)
		{
			dist[x][i] = dist[x][i-1];
			ull v = sparse[x][i-1];
			dist[x][i] += dist[v][i-1];
			sparse[x][i] = sparse[v][i-1];
		}
		
	}
}

ull lca(ull x, ull y) 
{
	ull soma = 0;
	if(h[y] > h[x])
		swap(x, y);

	int d = h[x] - h[y];
	for(int i = 0; i < 21; ++i) 
	{
		if(d&(1<<i)) 
		{
			soma += dist[x][i];
			x = sparse[x][i];
		}
	}

	if(x == y)
		return soma;
		
	for(int i = 20; i >= 0; --i) 
	{
		if(sparse[x][i] != sparse[y][i]) 
		{
			soma += (dist[x][i] + dist[y][i]);
			x = sparse[x][i];
			y = sparse[y][i];
		}
	}
	soma += (dist[x][0] + dist[y][0]);
	return soma;
}




int main()
{
	//~ freopen("in", "r", stdin);
	//~ freopen("out", "w", stdout);
	
	int a,q,x,y;
	ull peso;
	while(scanf(" %d",&n) && n)
	{
		for (int i = 0; i < n+1; i++)
		{
			G[i].clear();
			//~ dist[i][0] = 0;	
		}
		for (int i = 1; i < n; i++)
		{
			scanf(" %d%llu", &a,&peso);
			G[a].push_back(ii(i,peso));
			G[i].push_back(ii(a,peso));
		}
		dfs(0,0,0);
		calcular();
		scanf(" %d", &q);
		ull vet[100100];
		for (int i = 0; i < q; i++)
		{
			scanf(" %d%d", &x,&y);
			ull t = lca(x,y);
			vet[i] = t;
		}
		for (int i = 0; i < q; i++)
		{
			if(i == 0) printf("%llu", vet[i]);
			else printf(" %llu",vet[i]);
		}
		puts("");
		
		
	}
}

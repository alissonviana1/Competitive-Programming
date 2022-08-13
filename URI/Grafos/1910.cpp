#include <bits/stdc++.h>
#define inf 123456789
using namespace std;
bool rest[1000100];
int bfs(int s, int a)
{
	queue<int>fila;
	fila.push(s);
	vector<int> dist(1000100, inf);
	dist[s] = 0;
	while (!fila.empty())
	{
		int u = fila.front();
		fila.pop();
		if(u+1 <= 100000 && !rest[u+1] && dist[u+1] == inf)
		{
			dist[u+1] = dist[u]+ 1;
			fila.push(u+1);
		}
		if (u-1>0 && !rest[u-1] && dist[u-1]==inf)
		{
			dist[u-1] = dist[u] + 1;
			fila.push(u-1);
		}
		if (u*2 <= 100000 && !rest[u*2] && dist[u*2] == inf )
		{
			dist[u*2] = dist[u] + 1;
			fila.push(u*2);
		}
		if(u%2==0 && !rest[u/2] && dist[u/2] == inf )
		{
			dist[u/2] = dist[u] + 1;
			fila.push(u/2);
		}
		if(u*3 <= 100000 && !rest[u*3] && dist[u*3] == inf)
		{
			dist[u*3] = dist[u] + 1;
			fila.push(u*3);
		}	
		
	}
	return dist[a];
}

int main()
{
	int o,d,k,a;
	while(scanf(" %d%d%d", &o,&d,&k) && o  || d || k)
	{
		memset(rest, false, sizeof rest);
		for (int i = 0; i < k; i++)
		{
			cin>>a;
			rest[a] = true; 
		}
		int x = bfs(o,d);
		if(x == inf)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", x);
		}
		
	}
	
}

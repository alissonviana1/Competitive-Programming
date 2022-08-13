#include <bits/stdc++.h>

using namespace std;

vector<int>G[10000];
bool visitados[10000];




void DFS (int u)
{
		
	visitados[u] = 1;
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		int vizinho = G[u][i];
		if (visitados[vizinho] == 0)
		{
			DFS(vizinho);
		}
	}
}


int main()
{
	//freopen("in.txt", "r", stdin);
	int cont = 1, na,nv,primeiro,segundo;
	while (cin>>nv>>na && na!=0 && nv!=0)
	{
		for (int i = 0; i < 1000; i++)
		{
			G[i].clear();
			visitados[i] = 0;
		}
		
		
		for (int i = 0; i < na; i++)
		{
			cin>>primeiro>>segundo;
			G[primeiro].push_back(segundo);
			G[segundo].push_back(primeiro);
		}
		int c = 0;
		printf("Teste %d\n", cont);
		cont++;
		
		for (int u = 1; u <= nv; u++)
		{
			if (visitados[u] == 0)
			{
				c++;
				DFS(u);
				//c++;
			}
		}
		if (c == 1)
		{
			printf("normal\n\n");
		}
		else
		{
			printf("falha\n\n");
		}
	}	
}

#include <bits/stdc++.h>
using namespace std;

vector<int> G[10000]; 
bool visitados[10000];
int c = 0;
int total;


int DFS(int u)
{
	visitados[u] = 1;
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		int vizinho = G[u][i];
		if (visitados[vizinho] == 0)
		{
			c++;
			DFS(vizinho);
			
			
		}
		//printf("%d\n", c);
	}
	return c;
}





int main()
{
	
	//freopen("in.txt", "r", stdin);
	int n,inicio,nv,na,primeiro,segundo;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		
		cin>>inicio;
		for(int u = 0 ; u < 10000 ; ++u)
		{
			G[u].clear();
			visitados[u] = 0;
		}
		
		
		cin>>nv>>na;
		for(int j = 0; j < na; ++j)
		{
			cin>>primeiro>>segundo;
			G[primeiro].push_back(segundo);
			G[segundo].push_back(primeiro);
		}
		for(int k = 0; k < nv; ++k)
		{
			if(visitados[k] == 0)
			{
				total = DFS(k);
			}
		}
		printf("%d\n", total*2);
		total = 0;
		c = 0;
	}	
}
#include <bits/stdc++.h>

using namespace std;
vector<int> G[1001];
bool visitado[1001];
int componentes = 0,nv,na,a,b,numero;

void dfs(int u)
{
	
	visitado[u] = 1;
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		int v = G[u][i];
		if(visitado[v] == 0)
		{
			dfs(v);
			componentes++;
		}
	}
	
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	while(cin>>nv>>na && nv != EOF && na != EOF)
	{
		
		for (int i = 0; i < 1001; i++)
		{
			G[i].clear();
			visitado[i] = 0;
		}
		for (int i = 0; i < na; i++)
		{
			cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		cin>>numero;
		dfs(numero);
		cout<<componentes+1<<"\n";
		componentes = 0;
		
	}
}

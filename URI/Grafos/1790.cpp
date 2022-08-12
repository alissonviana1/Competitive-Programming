#include <bits/stdc++.h>
using namespace std;

int visitados[10100];
int c = 0;
vector<int>G[10100];
int b[10100];
int h[10100];



void dfs(int u,int D,int pai)
{
	
	visitados[u] = 1;
	h[u] = D;
	b[u] = D;
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		int v = G[u][i];
		if (visitados[v] == 0)
		{
			
			dfs(v,D+1,u);
			b[u] = min(b[u], b[v]);
			if (b[v] > h[u])
			{
				//cout<<"é ponte -> "<<u<<endl;
				c++;
			}		
		}
		else
		{
			if (v != pai)
			{
				b[u] = min(b[u], h[v]);
				
			}
			
		}
		
		
	}
}


int main()
{
	
	int nv,na,a,r;
	while(scanf(" %d%d", &nv,&na) != -1)
	{
	
		for (int i = 0; i <= 10010; i++)
		{
			visitados[i] = 0;
			G[i].clear();
			h[i] = 0;
			b[i] = 0;
		}
		//memset(b, 0,sizeof b);
		for (int i = 0; i < na; i++)
		{
			cin>>a>>r;
			G[a].push_back(r);
			G[r].push_back(a);
		}
		for (int i = 1; i <= nv ; i++)
		{
			if(visitados[i] == 0)
			{
				dfs(i,1,i);
			}
					
		}
		cout<<c<<endl;
		c = 0;
	}
	
}

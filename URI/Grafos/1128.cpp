#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi dfs_num, dfs_low, S, visited;
vector<int> G[2000];
int numSCC, dfsNumberC;
int c = 0;


void tarjan(int u)
{	

	dfs_low[u] = dfs_num[u] = dfsNumberC++;
	//cout<<dfs_low[u]<<" ";
	S.push_back(u);
	
	visited[u] = 1;
	
	for(int j = 0; j < (int)G[u].size(); j++)
	{
		int v = G[u][j];
		//cout<<"V -> "<<v<<endl;
		if(dfs_num[v] == 0)
			tarjan(v);
		if(visited[v])	
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		
	}
	if(dfs_low[u] == dfs_num[u])
	{
		++numSCC;
		//cout<<"cont -> "<<numSCC<<endl;
		while(1)
		{
			int v = S.back();
		//	cout<<" v -> "<<v<<"  ";
			S.pop_back();
			visited[v] = 0;
			//printf(" %d",v);
		
			if(u == v)
			{	
				break;
			}
			
		}
		//cout<<'\n';
		
	}
			
}
int main()
{
	int nv,na,a,b,dir;

	while (cin>>nv>>na && nv!= 0 && na!= 0)
	{	
		dfs_num.assign(20000, 0);
		dfs_low.assign(20000, 0); 
		visited.assign(20000, 0);
		numSCC = 0;
		dfsNumberC = 0;
		for(int i = 0; i < 2000; i++)
		{
			G[i].clear();
		}
		for(int i = 1; i <= na; i++)
		{
			cin>>a>>b>>dir;
			if(dir == 1)
			{
				G[a].push_back(b);	
			}
			else
			{
				G[a].push_back(b);
				G[b].push_back(a);
			}
			
		}
		for(int k = 1; k <= nv; k++)
		{
			if(dfs_num[k] == 0)
			{
				//cout<<"cont -> "<<i<<endl;
				tarjan(k);
			}
				
		}
		
		if(numSCC != 1)
		{
			cout<<"0\n";
		}
		else
		{
			cout<<"1\n";
		}
			
	}
		
}

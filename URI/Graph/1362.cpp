#include <bits/stdc++.h>
#define inf 123456789
using namespace std;


int pai[70];
vector<int>G[70];
int res[70][70];

bool bfs(int s,int t)
{
	memset(pai,-1,sizeof pai);
	queue<int> fila;
	fila.push(s);
	pai[s] = s;
	while (!fila.empty())
	{
		int u = fila.front();
		fila.pop();
		for (int i = 0; i < (int)G[u].size(); i++)
		{
			int v = G[u][i];
			if(pai[v] == -1 && res[u][v] > 0)
			{
				pai[v] = u;
				fila.push(v);
			}
		}
	}
	if(pai[t] == -1) return 0;
	return 1;
}

int MaxFlow(int s,int t)
{
	int flow = 0;
	while (bfs(s,t))
	{
		int gargalo = inf;
		int vt = t;
		while (vt != s)
		{
			gargalo = min(gargalo, res[pai[vt]][vt]);
			vt = pai[vt];
		}
		flow += gargalo;
		vt = t;
		while (vt != s)
		{
			res[pai[vt]][vt] -= gargalo;
			res[vt][pai[vt]] += gargalo;
			vt = pai[vt];
		}
	}
	return flow;
}
	
int main()
{
	int t,nv,na;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d",&nv,&na);
		
		memset(res,0,sizeof res);
		
		map<string,int> mp;
		
		mp["XXL"] = 50;
		mp["XL"] = 51;
		mp["L"] = 52;
		mp["M"] = 53;
		mp["S"] = 54;
		mp["XS"] = 55;
		
		int t = nv/6;
		
		string str1,str2;
		
		for (int i = 1; i <= na; i++)
		{
			cin>>str1>>str2;
			
			G[0].push_back(i);
			G[i].push_back(0);
			
			G[i].push_back(mp[str1]);
			G[i].push_back(mp[str2]);
			
			G[mp[str1]].push_back(i);
			G[mp[str2]].push_back(i);

			res[0][i] = 1;
			res[i][0] = 1;
			
			res[i][mp[str1]] = inf;
			res[i][mp[str2]] = inf;
		}
		
		for (int i = 50; i < 56; i++)
		{
			G[i].push_back(60);
			G[60].push_back(i);
			
			res[i][60] = t;
		}
		
		if(MaxFlow(0,60) == na)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	
}

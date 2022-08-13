#include <bits/stdc++.h>
#define inf 123456789

using namespace std;
typedef pair<int,int> ii;
typedef long unsigned lu;

lu maxglobal = 0;
vector<int>G[1001];
int D = 0;


ii dfs(int u, int v, int d)
{
	
	int prof = d;
	int resp = 1;
	if(d < D)
	{
		for (int i = 0; i < (int)G[v].size(); i++)
		{
			int w = G[v][i];
			if(w != u)
			{
				ii y = dfs(v, w,d+1);
				resp += y.first;
				prof = max(prof, y.second);
			}
		}
		
	}
	return ii(resp,prof);
}


int main()
{
	int nv, k;
	//freopen("in", "r", stdin);
	while(scanf(" %d%d", &nv,&k) != EOF)
	{
		for (int i = 0; i <= nv; i++)
		{
			G[i].clear();
		}
		int  a = 0, b = 0;
		for (int i = 0; i < nv-1; i++)
		{
			scanf(" %d%d", &a,&b);
			G[a-1].push_back(b-1);
			G[b-1].push_back(a-1);
		}
		for (int centro = 0; centro < nv-1; centro++)
		{
			lu somapar = 0;
			int maxdif = 0;
			lu somaprofmaiork = 0;
			lu spmk1 = 0;
		
			for (int i = 0; i < (int)G[centro].size(); i++)
			{
				
				int v = G[centro][i];
				D = k/2;
				ii res = dfs(centro, v, 1);
				a = res.first;
				if(res.second == D)
				{
					somaprofmaiork++;
				}
				b = a;
				if(k%2 != 0)
				{
					
					D++;
					res = dfs(centro,v,1);
					b = res.first;
					if(res.second == D)
					{
						spmk1++;
					}
				}
				maxdif = max(maxdif, b-a);
				somapar += a;
			}
			if(k%2 == 0)
			{
				
				if(somaprofmaiork >= 2)
				{
					maxglobal = max(maxglobal, somapar+maxdif+1);
				}
				
			}
			else
			{
				if(somaprofmaiork >= 2 && spmk1 >= 1)
				{
					maxglobal = max(maxglobal, somapar+maxdif+1);	
				}
			}
			
			//cout << somapar << " " << maxdif << " in " << centro << endl;
		}
		if(maxglobal == 0)
		{
			printf("Impossible revenge!\n");
		}
		else
		{
			printf("%lu\n", maxglobal);
		}
		maxglobal = 0;
		
	}
	
}

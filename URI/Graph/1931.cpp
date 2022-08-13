#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
typedef pair<int,int> ii;

typedef pair<int, ii> iii;

vector<ii> G[50010];
int dist[50010][3];

int n,m,a,b,minu;

int dj(int s,int a)
{
    priority_queue<iii, vector<iii>, greater<iii> > filaP;
    
    filaP.push(iii(0,ii(s,0)));
    
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			dist[i][j] = inf;
		}	
	}
	
    dist[s][0] = 0;
	dist[s][1] = 0;
	
    while (!filaP.empty())
    {
        iii front = filaP.top();
        filaP.pop();
        int d = front.first;
        int u = front.second.first;
        int p = front.second.second;
		
		if(d == dist[u][p])
        for (int i = 0; i < (int)G[u].size(); i++)
        {
            ii v = G[u][i];
            
			if(dist[u][p] + v.second < dist[v.first][!p])
			{
				dist[v.first][!p] = dist[u][p] + v.second;
				
				filaP.push(iii(dist[v.first][!p],ii(v.first, !p)));
			}				
        }
    }
    //~ for (int i = 1; i <= n; i++)
	//~ {
		//~ for (int j = 0; j < 2; j++)
		//~ {
			//~ cout<<dist[i][j]<<" ";
		//~ }
		//~ puts("");	
	//~ }
    return dist[a][0];
}

int main()
{
	//~ freopen("in", "r", stdin);
	
	scanf(" %d%d", &n,&m);
	for (int i = 0; i < m; i++)
	{
		scanf(" %d%d%d", &a,&b,&minu);
		G[a].push_back(ii(b,minu));
		G[b].push_back(ii(a,minu));
	}
	int t = dj(1,n);
	if(t == inf) printf("-1\n");
	else printf("%d\n", t);
}

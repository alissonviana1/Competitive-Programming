#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
long  double G[101][101];
int main()
{
	//~ freopen("in", "r", stdin);
	//~ freopen("out", "w", stdout);
	
	int n, m ,a,b,p;
	//~ while(scanf(""))
		while(cin>>n>>m && n)
		{
			memset(G,0.0,sizeof G);
			for (int i = 0; i < m; i++)
			{
				scanf(" %d%d%d", &a,&b,&p);
				G[a][b] = (p/100.0);
				G[b][a] = (p/100.0);
			}
			for (int k = 1; k <= n; k++)
			{
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++)
					{
						G[i][j] = max(G[i][j], G[i][k] * G[k][j]);
					}
				}
			}
			printf("%.6Lf percent\n", (G[1][n]*100));
			
		}
}

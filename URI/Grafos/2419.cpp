#include <bits/stdc++.h>
using namespace std;
bool visitado[1005][1005];
char matriz[1005][1005],mat[1005][1005];
int n,m;

int flag = 0;
int t = 0;
void dfs(int u, int v)
{
	bool c = false;
	visitado[u][v] = 1;
	
	if(u+1 <= n+1 && matriz[u+1][v] == '.')
	{
		c = true;
	}
	if(u-1 >= 0 && matriz[u-1][v] == '.' )
	{	
		c = true;
	}
	if(v+1 <= m+1 && matriz[u][v+1] == '.')
	{	
		c = true;
	}
	if(v-1 >= 0 && matriz[u][v-1] == '.' )
	{	
		c = true;
	}
	if(c == true && t == 0)
	{
		flag++;
		
	}
		if(u+1 <= n+1 && matriz[u+1][v] == '#' && visitado[u+1][v] == 0)
		{
			visitado[u+1][v] = 1;
			dfs(u+1, v);
		}
		else
		{
			if(u-1 >= 0 && matriz[u-1][v] == '#' && visitado[u-1][v] == 0)
			{	
				visitado[u-1][v] = 1;
				dfs(u-1, v);
			}
			else
			{
				if(v+1 <= m+1 && matriz[u][v+1] == '#' && visitado[u][v+1] == 0)
				{
					visitado[u][v+1] = 1;
					dfs(u, v+1);
				}
				else
				{
					if(v-1 >= 0 && matriz[u][v-1] == '#' && visitado[u][v-1] == 0)
					{
						visitado[u][v-1] = 1;
						dfs(u, v-1);
					}
				}
					
			}
		}
	
	
		
		
		
		
		
			
}

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin>>mat[i][j];
		}
	}
	for (int i = 0; i <= n+1; i++)
	{
		for (int j = 0; j <= m+1; j++)
		{
			if(mat[i][j] == '#')
			{
				matriz[i][j] = '#';
			}
			else
			{
				matriz[i][j] = '.';
			}
		}
	}
	for (int i = 0; i <= n+1; i++)
	{
		for (int j = 0; j <= m+1; j++)
		{
			if(matriz[i][j] == '#' && visitado[i][j] == 0)
			{
				dfs(i,j);
			}
		}
	}
	cout<<flag<<endl;
	
#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
int G[401][401];
int a,b,c,x,y,p,t;

int main()
{
	scanf(" %d%d%d", &a,&b,&c);
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= a; j++)
		{
			G[i][j] = inf;
		}
	}
	
	for (int i = 0; i < b; i++)
	{
		scanf(" %d%d", &x,&y);
		G[x][y] = 1;
		G[y][x] = 1;
	}
	
	for (int k = 1; k <= a; k++)
	{
		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= a; j++)
			{
				G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
			}
		}	
	}
	
	
	for (int i = 0; i < c; i++)
	{
		scanf(" %d%d", &p,&t);
		if(G[p][t] != inf)
		{
			printf("Lets que lets\n");
		}
		else
		{
			printf("Deu ruim\n");
		}
	}	
}

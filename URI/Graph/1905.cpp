#include <bits/stdc++.h>
using namespace std;

int mat[5][5];

int jogo(int i, int j)
{
	mat[i][j] = 1;
	if(i == 4 && j == 4)
	{
		return true;
	}
	if(i + 1 < 5 && !mat[i+1][j])
	{
		if(jogo(i+1, j)) return true;
	}
	if(i - 1 >= 0 && !mat[i-1][j])
	{
		if(jogo(i-1,j)) return true;
	}
	if(j + 1 < 5 && !mat[i][j+1])
	{
		if(jogo(i,j+1)) return true;
 	}
 	if(j - 1 >= 0 && !mat[i][j-1])
 	{
		if(jogo(i,j-1)) return true;
	}
	
	return false;
}


int main()
{
	int n;
	//~ freopen("in","r",stdin);
	scanf(" %d", &n);
	while (n--)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				scanf(" %d", &mat[i][j]);
			}
		}
		if(!mat[0][0])
			if(jogo(0,0))
				puts("COPS");
			else puts("ROBBERS");
		else puts("ROBBERS");
		
	}
}

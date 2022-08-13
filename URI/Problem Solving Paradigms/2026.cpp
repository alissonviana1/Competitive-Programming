#include <bits/stdc++.h>
using namespace std;

int pd[1000][1000];
int valor[1000], peso[1000];
int n,p;

int mochila(int item, int disp)
{
	if(item == n || disp == 0) return 0;
	
	if(pd[item][disp] != -1) return pd[item][disp];
	
	if(disp - peso[item] < 0) return pd[item][disp] = mochila(item +1, disp);
	
	return pd[item][disp] = max(mochila(item+1,disp), valor[item]+mochila(item+1, disp-peso[item]));
	
	
}

int main()
{
	
	int r,c = 0;
	cin>>r;
	for (int i = 0; i < r; i++)
	{
		memset(pd,-1,sizeof pd);
		cin>>n>>p;
		for (int i = 0; i < n; i++)
		{
			scanf(" %d %d", &valor[i], &peso[i]);
		}
		printf("Galho %d:\n", ++c);
		printf("Numero total de enfeites: %d\n\n",  mochila(0,p));
		
	}
}

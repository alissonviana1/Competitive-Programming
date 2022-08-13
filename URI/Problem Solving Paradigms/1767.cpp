#include <bits/stdc++.h>
using namespace std;
int n,q, pd[310][310];
int valor[310], peso[310];
int soma = 0,pacotes = 0;

vector<int>res;

int mochila(int item, int disp)
{

	if( disp == 0 || item == q ) return 0;
	
	if(pd[item][disp] != -1) return pd[item][disp];
	
	if(disp-peso[item] < 0) return pd[item][disp] = mochila(item + 1, disp);
	
	
	return pd[item][disp] = max(mochila(item+1,disp), valor[item]+mochila(item+1,disp-peso[item]));

}

void rec(int item, int disp)
{
    if(item == q || disp == 0) return;
    
    if (disp - peso[item] >= 0)
    {
		 if(valor[item] + mochila(item + 1, disp - peso[item]) > mochila(item+1, disp))
		 {
			 res.push_back(peso[item]);
			 rec(item+1, disp - peso[item]);
			 return;
		 }
    }
    rec(item+1, disp);
    
}

int main()
{
	int c = 0;
	//freopen("in","r",stdin);
	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
	{
		memset(pd, -1, sizeof pd);
		res.clear();
		
		scanf(" %d", &q);
		for (int j = 0; j < q; j++)
		{
			scanf(" %d%d", &valor[j], &peso[j]);
		}
		printf("%d brinquedos\n", mochila(0,50));
		rec(0,50);
		for (int j = 0; j < (int)res.size(); j++)
		{
			soma += res[j];
			c++;
		}
		pacotes = abs(c-q);
		printf("Peso: %d kg\n", soma);
		soma = 0;
		printf("sobra(m) %d pacote(s)\n\n", pacotes);
		pacotes = 0;
		c = 0;
			
	}
	
}

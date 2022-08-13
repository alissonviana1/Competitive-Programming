#include <bits/stdc++.h>
using namespace std;

int valor[10000],peso[10000];
int n,p;
int matriz[1000][1000];
int M[1000][2];

int f(int item, int disp)
{
    
    if(disp == 0 || item == n) return 0; //casos bases
    
    if(matriz[item][disp] != -1) return matriz[item][disp]; // se for -1, ou seja, nao foi visitado
    
    if(disp - peso[item] < 0) return matriz[item][disp] = f(item + 1, disp); // n pode ser menor que 0, pois nao tem negativo
    
    return matriz[item][disp] = max(f(item+1, disp), valor[item]+f(item+1, disp-peso[item]));
        
}


int main()
{
    
     while(scanf("%d %d", &n,&p) && n!=0)
    {
		memset(matriz,-1,sizeof matriz);
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin>>M[i][j];
			}
		}	
		
		for (int i = 0; i < n; i++)
		{
			valor[i] = M[i][0];
		}
		for (int i = 0; i < n; i++)
		{
			peso[i] = M[i][1];
		}
		cout<<f(0,p)<<" min."<<endl;
	} 
}

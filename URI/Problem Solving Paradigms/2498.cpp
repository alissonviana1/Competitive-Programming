#include <bits/stdc++.h>
using namespace std;

int valor[10000],peso[10000];
int n,p;
int matriz[1000][1000];
int M[10000][10000];

int f(int item, int disp)
{
    
    if(disp == 0 || item == n) return 0;
    
    if(matriz[item][disp] != -1) return matriz[item][disp];
    
    if(disp - peso[item] < 0) return matriz[item][disp] = f(item + 1, disp);
    
    return matriz[item][disp] = max(f(item+1, disp), valor[item]+f(item+1, disp-peso[item]));
        
}


int main()
{
    int c = 1;
    while(scanf("%d %d", &n,&p) && n!=0 && p!=0)
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
			peso[i] = M[i][0];
		}
		for (int i = 0; i < n; i++)
		{
			valor[i] = M[i][1];
		}
		cout<<"Caso "<<c++<<": "<<f(0,p)<<endl;
	} 
}
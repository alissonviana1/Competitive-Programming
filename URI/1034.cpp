#include <bits/stdc++.h>
using namespace std;

int valor[1000000],peso[1000000];
int n,p;
int matriz[1000000];

int f(int disp)
{   
	
    if(disp == 0) return 0;
    if(matriz[disp] != -1) return matriz[disp];
    
    
    int aux = 999999;
    
    for (int i = 0; i < n; i++)
    {
        if(disp - peso[i] >= 0)
        {
            aux = min(aux,1 + f(disp-peso[i]));
        }
    }
    
    return matriz[disp] = aux;   
   
}

int main()
{
    
    int t;
    cin>>t;
    for (int k = 0; k < t; k++)
	{
		cin>>n>>p;
		memset(matriz,-1,sizeof matriz);
		//memset(valor,1,sizeof valor);
		
		
		for (int i = 0; i < n; i++)
		{
			cin>>peso[i];
		}
		cout<<f(p)<<endl;    
	}
}

#include <bits/stdc++.h>
using namespace std;

int horas[10000],quantidade[10000];
int n,p;
int pd[10000];
int M[1000][1000];

int f(int disp)
{
    
    if(disp == 0) return 0;
    if(pd[disp] != -1) return pd[disp];
    int aux = 0;
    
    for (int i = 0; i < n; i++)
    {
        if(disp - horas[i] >= 0)
        {
            aux = max(aux,quantidade[i] + f(disp-horas[i]));
        }
    }
    
    return pd[disp] = aux;
    
   
}


int main()
{
    int c = 1;
      
   while(scanf("%d %d", &n,&p) && n!=0 && p!=0)
    {
		memset(pd,-1,sizeof pd);
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin>>M[i][j];
			}
		}	
		
		for (int i = 0; i < n; i++)
		{
			horas[i] = M[i][0];
		}
		for (int i = 0; i < n; i++)
		{
			quantidade[i] = M[i][1];
		}
		cout<<"Instancia "<<c++<<endl;
		cout<<f(p)<<endl<<endl;
	} 
}

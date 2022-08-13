#include <bits/stdc++.h>
using namespace std;

int valor[10001],peso[10001];
int n,p;
long long matriz[101][10100];

long long f(int item, int disp)
{
    
    if(disp == 0 || item == n) return 0; 
    
    if(matriz[item][disp] != -1) return matriz[item][disp]; 
    
    if(disp - peso[item] < 0) return matriz[item][disp] = f(item + 1, disp);
    
    return matriz[item][disp] = max(f(item+1, disp), valor[item]+f(item+1, disp-peso[item]));
   	 
}


int main()
{
    //freopen("in","r",stdin);
    while(cin>>n>>p && n!=EOF)
    {
		memset(matriz,-1,sizeof matriz);
		for (int i = 0; i < n; i++)
		{
			cin>>valor[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin>>peso[i];
		}
		cout<<f(0,p)<<endl;  
	} 
}


#include <bits/stdc++.h>
using namespace std;

long long n,k;
long long pd[110][100000];
long long V[110];

long long f(long long item, long long cont)
{
	if(cont == k) return 1;
	if(item == n) return 0;
	
	if(pd[item][cont] != -1) return pd[item][cont];
	
	long long aux = 0;
	for (int i = item+1; i < n; i++)
	{
		if(V[i] > V[item])
		{
			aux += f(i, cont + 1);
		}
	}
	return pd[item][cont] = aux;
}


int main()
{
	
    
    while(cin>>n>>k && n!= 0 && k!= 0)
    {
		long long res = 0;
		memset(pd,-1,sizeof pd);
		for (int i = 0; i < n; i++)
		{
			cin>>V[i];
		}
		for (int i = 0; i < n; i++)
		{
			res += f(i,1);
		}
		
		cout<<res<<endl;
		
	}  
}

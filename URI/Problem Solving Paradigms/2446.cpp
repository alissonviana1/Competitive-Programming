#include <bits/stdc++.h>
using namespace std;

int n,valor,vetor[100000];
int pd[10000][10000];

int troco(int item, int soma)
{
	if(soma == valor) return 1;
	
	if(item == n) return 0;
	
	if(pd[item][soma] != -1) return pd[item][soma];
	
	if(soma + vetor[item] <= valor)
	{
		return pd[item][soma] = troco(item+1,soma+vetor[item]) || troco(item+1,soma);
	}
	return pd[item][soma] = troco(item+1, soma);
}

int main()
{
	memset(pd,-1,sizeof pd);
	cin>>valor>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>vetor[i];
	}
	int t = troco(0,0);
	if(t == 1)
	{
		cout<<"S\n";
	}
	else
	{
		cout<<"N\n";
	}	
}

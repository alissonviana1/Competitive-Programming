#include <bits/stdc++.h>
using namespace std;

int n,valor,vetor[11000];


int troco(long long item, long long soma)
{
    if(soma == valor) return 1;
    
    if(item == n) return 0;
        
    if(soma + vetor[item] <= valor)
    {
        return troco(item+1, soma+vetor[item]) || troco(item+1,soma);
    }
    return troco(item + 1, soma);
        
    
    
}

int main()
{
	while(cin>>valor>>n && valor!=0 && n!=0)
	{
		
		
		for (int i = 0; i < n; i++)
		{
			cin>>vetor[i];
		}
		int t = troco(0,0);
		if(t == 1)
		{
			cout<<"sim\n";
		}
		else
		{
			cout<<"nao\n";
		}
	}    
}

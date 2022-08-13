#include <bits/stdc++.h>
using namespace std;

int main()
{

	cin.tie(NULL);
	cout.sync_with_stdio(false);
	int n,valor,vetor[100100];
	string fun;
	cin>>n;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		cin>>fun;
		int t = fun.size();
		if(t >= 4)
		{
			
			cin>>valor;
			vetor[k] = valor;
			k++;
		}
		else
		{
			if(fun == "MIN")
			{
				if(k == 0)
				{
					cout<<"EMPTY\n";
				}
				else
				{
					int m = 1234567899;
					for (int y = 0; y < k; y++)
					{
						//vet[y] = vetor[y];
						m = min(m,vetor[y]);
					}
					cout<<m<<'\n';
				}		
			}
			else
			{
				
					if(k == 0)
					{
						cout<<"EMPTY\n";
					}
					else
					{
						k--;
					}
				
			}
		}
	}
	
}

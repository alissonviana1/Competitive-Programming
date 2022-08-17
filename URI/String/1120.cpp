#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	string nome,novo;
	char a;
	while(cin>>a>>nome && a != '0' && nome != "0")
	{
		int t = nome.size();
		int k =0;
		for (int i = 0; i < t; i++)
		{
			if(nome[i] != a)
			{
				novo += nome[i];
				k++;
				
			}
		}
		int posi = -1;
		if(k == 0)
		{
			cout<<"0\n";
		}
		else
		{
			for (int i = 0; i < k; i++)
			{
				if(novo[i] != '0')
				{
					
					posi = i;
					break;
				}	
			}
			if(posi == -1)
			{
				cout<<"0\n";
			}
			else
			{
				for (int i = posi; i < k; i++)
				{
					cout<<novo[i];
				}
				cout<<'\n';
			}
			
		}
		novo = "";
		
		
		
		
	}
	
}

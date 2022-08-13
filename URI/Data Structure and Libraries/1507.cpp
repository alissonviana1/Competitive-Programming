#include <bits/stdc++.h>

using namespace std;

int main()
{
	char nome[100000], nome2[100000],novo[100000];
	int n,m,c = 0;
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		c = 0;
		cin>>nome;
		int t = strlen(nome);
		
		
		cin>>m;
		
		
		for (int j = 0; j < m; j++)
		{
			
			for (int k = 0; k < t; k++)
			{
				novo[k] = nome[k];
			}
			
			cin>>nome2;
			int r = strlen(nome2);
			c = 0;
			for (int k = 0; k < r; k++)
			{
				for (int e = 0; e < t; e++)
				{
					if(nome2[k] == novo[e])
					{
						c++;
						novo[e] = '0';
						break;
					}
					else
					{
						novo[e] = '0';
					}
				}
			}
			
			
			if(c == r)
			{
				cout<<"Yes\n";
			}
			else
			{
				cout<<"No\n";
			}
			c = 0;
		}
	}
}

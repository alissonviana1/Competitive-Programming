#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	char nome[59];
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		scanf(" %[^\n]", nome);
		int t = strlen(nome);
		if(nome[0]!=' ')
		{
			cout<<nome[0];
		}
		for (int j = 1; j < t; j++)
		{
			if(nome[j-1]== ' ' && nome[j]!= ' ')
			{
				cout<<nome[j];
			}
		}
		cout<<endl;
		
	}
	
	
}

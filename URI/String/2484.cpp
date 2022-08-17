#include <bits/stdc++.h>
using namespace std;

int main()
{
	int c = 0;
	char nome[1000];
	while(cin>>nome && (int)nome != EOF)
	{
		int t = strlen(nome);
		int aux = t;
		for(int i = 0; i < aux; i++)
		{
			for(int k = 0; k < t; k++)
			{
				cout<<nome[k];
				if(k<t-1)
				{
					cout<<" ";
				}
			}
			cout<<endl;
			c++;
			if(c < aux)
			{
				for(int j = 0; j < c; j++)
				{
					cout<<" ";
				}
			}
			t--;
		}
		cout<<endl;
		c = 0;	
	}
}
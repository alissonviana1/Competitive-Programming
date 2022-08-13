#include <bits/stdc++.h>
using namespace std;

int main()
{
	 //~ freopen("in", "r", stdin);
	 //~ freopen("outi", "w", stdout);
	int n,k,p;
	char quero[101],br[101];
	string japones,brasil;
	string resp;
	map<string,string> mapa;
	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
	{
		mapa.clear();
		scanf(" %d%d", &k,&p);
		for (int j = 0; j < k; j++)
		{
			cin>>japones;
			scanf(" %[^\n]",br);
			
			
			mapa[japones] = br;
			
		}
		for (int j = 0; j < p; j++)
		{
			scanf(" %[^\n]\n", quero);
			int t = strlen(quero)+1;
			quero[t-1] = '.';
			int c = 0;
			for (int y = 0; y < t; y++)
			{
				
				if(quero[y] != ' ' && quero[y] != '.' )
				{
					resp += quero[y];
				}
				else
				{
					c++;
					if(c > 1) printf(" ");
					if(mapa.find(resp) != mapa.end())
					{
						cout<<mapa[resp];
					}
					else
					{
						cout<<resp;
					}
					resp = "";
				}
				
			}
			cout<<endl;
		}
		cout<<endl;
		
	}
		
}

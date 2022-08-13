#include <bits/stdc++.h> 

using namespace std;

int main()
{
	set<string> set1;
	set<string>::iterator it;
	char texto[100000],tex[100000];
	string novo;
	cin.tie(NULL);
	cout.sync_with_stdio(false);
    while(scanf(" %[^\n]", texto) != EOF)
    {
		int t = strlen(texto) + 1;
		for (int i = 0; i < t; i++)
		{
			tex[i] = tolower(texto[i]);
			tex[t-1] = '.';
		}
		for (int i = 0; i < t; i++)
		{
			if(tex[i] >= 'a' && tex[i] <= 'z')
			{
				novo += tex[i];
			}
			else
			{
				set1.insert(novo);
				novo = "";
			}			
		}		
	}
	set1.erase("");
	for (it = set1.begin(); it != set1.end(); ++it)
	{
		cout << *it<<'\n';	
	}
}

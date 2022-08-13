#include <bits/stdc++.h>
using namespace std;

int main()
{
	//~ freopen("in", "r",stdin);
	//~ freopen("out", "w",stdout);
	
	int n;
	map<string, vector<int> > mv;
	string str,res,plv;
	getline(cin,str);
	str += ' ';
	for (int i = 0; i < (int)str.size(); i++)
	{
		if(str[i] != ' ')
		{
			plv += str[i];
		}
		else
		{
			mv[plv].push_back(abs(i - (int)plv.size()));
			plv = "";
		}
	}
	
	scanf("%d", &n);
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cin>>res;
		
		if(mv.find(res) != mv.end())
		{
			sort(mv[res].begin(),mv[res].end());
			for (int j = 0; j < (int)mv[res].size(); j++)
			{
				if(j == (int)mv[res].size() -1) printf("%d\n", mv[res][j]);
				else
				{
					printf("%d ", mv[res][j]);
				}
			}
			
		}
		else
		{
			puts("-1");
		}
	}
	
	
}

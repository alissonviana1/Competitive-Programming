#include <bits/stdc++.h>
using namespace std;

int m,memo[1001][1001],p[1001], v[1001];
vector<int>vec;
int ks(int item, int disp)
{
	if(item == m || disp == 0) return 0;
	int &pd = memo[item][disp];
	if(pd != -1) return pd;
	if(p[item] > disp) return pd = ks(item+1, disp);
	return pd = max(v[item] + ks(item +1, disp - p[item]), ks(item+1, disp)); 
}

void rec(int item, int disp)
{
	if(item == m || disp == 0) return;
	int pd = memo[item][disp];
	if(pd == ks(item+1, disp)) return rec(item+1, disp);
	vec.push_back(v[item]);
	rec(item+1, disp-p[item]);
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int w;
	int c = 0;
	while(scanf("%d%d", &w,&m) , (w || m))
	{
		memset(memo,-1,sizeof memo);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &p[i], &v[i]);
		}
		ks(0,w);
		rec(0,w);
		int soma = 0;
		for (int i = 0; i < (int)vec.size(); i++)
		{
			soma += vec[i];
		}
		vec.clear();
		printf("Teste %d\n", ++c);
		printf("%d\n\n", soma);
	}
		
	
}

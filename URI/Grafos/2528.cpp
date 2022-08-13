#include <bits/stdc++.h>
#define inf 123456789
using namespace std;
typedef pair<int,int> ii;

vector<int> G[1010];


int bfs(int s, int a, int e)
{
    queue<int>fila;
    fila.push(s);
    vector<int>dis(1010,inf);
    dis[s] = 0;
    while(!fila.empty())
    {
        int u = fila.front();
        fila.pop();
        for (int i = 0; i < (int)G[u].size(); i++)
        {
            int v = G[u][i];
            if(dis[v] == inf && v != e)
            {
                dis[v] = dis[u] + 1;
                fila.push(v);
            }
        }   
    }
    return dis[a];
}


int main()
{
	int nv,na,a,b,c,r,e;
	while (scanf("%d%d", &nv,&na) != -1)
	{
		for (int i = 0; i < 1010; i++)
		{
			G[i].clear();
		}
		
		for (int i = 0; i < na; i++)
		{
			scanf("%d%d", &a,&b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		scanf("%d%d%d", &c,&r,&e);
		cout<<bfs(c,r,e)<<endl;
	}
	
}

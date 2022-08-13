#include <bits/stdc++.h>
#define inf 123456789
using namespace std;

typedef pair<int,int> ii; 
vector<ii> G[100010];
int nv,na,aqui,minu,c;

int dj(int s,int a)
{
	priority_queue<ii, vector<ii>, greater<ii> > filaP;
	filaP.push(ii(0,s));
	vector<int>dist(100000,inf);
	dist[s] = 0;
	
	while (!filaP.empty())
	{
		ii front = filaP.top();
		filaP.pop();
		int d = front.first;
		int u = front.second;
		
		if(d > dist[u]) continue;
		
		for (int i = 0; i < (int)G[u].size(); i++)
		{
			ii v = G[u][i];
			if(dist[u] + v.second < dist[v.first])
			{
				dist[v.first] = dist[u] + v.second;
				filaP.push(ii(dist[v.first], v.first));
			}
		}
	}
	return dist[a];
}



int main()
{
	//freopen("in","r",stdin);
	int a,b,k;
	while(scanf(" %d%d%d%d", &nv,&na,&c,&k) && nv != 0 && na != 0 && c!=0 && k!=0)
	{
		for (int i = 0; i < 100000; i++)
		{
			G[i].clear();
		}
		
		
		for (int j = 0; j < na; j++)
		{
			cin>>a>>b>>minu;
			if(a < c && b < c)
			{
				if( min(a,b)+1 != max(a,b)) continue;
				G[min(a,b)].push_back(ii( max(a,b),minu));		
			}
			else
			{
				if(a < c)
				{
					G[b].push_back(ii(a,minu));
				}
				else
				{
					if(b < c)
					{
						G[a].push_back(ii(b,minu));
					}
					else
					{
						G[a].push_back(ii(b,minu));
						G[b].push_back(ii(a,minu));
					}
				}
			}	
		}
		int t = dj(k,c-1);
		cout<<t<<endl;
	
	}
}

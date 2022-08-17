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
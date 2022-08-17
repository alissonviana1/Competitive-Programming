int bfs(int s, int a)
{
	queue<int>fila;
	fila.push(s);
	vector<int> dist(1000100, inf);
	dist[s] = 0;
	while (!fila.empty())
	{
		int u = fila.front();
		fila.pop();
		if(u+1 <= 100000 && !rest[u+1] && dist[u+1] == inf)
		{
			dist[u+1] = dist[u]+ 1;
			fila.push(u+1);
		}
		if (u-1>0 && !rest[u-1] && dist[u-1]==inf)
		{
			dist[u-1] = dist[u] + 1;
			fila.push(u-1);
		}
		if (u*2 <= 100000 && !rest[u*2] && dist[u*2] == inf )
		{
			dist[u*2] = dist[u] + 1;
			fila.push(u*2);
		}
		if(u%2==0 && !rest[u/2] && dist[u/2] == inf )
		{
			dist[u/2] = dist[u] + 1;
			fila.push(u/2);
		}
		if(u*3 <= 100000 && !rest[u*3] && dist[u*3] == inf)
		{
			dist[u*3] = dist[u] + 1;
			fila.push(u*3);
		}	
		
	}
	return dist[a];
}
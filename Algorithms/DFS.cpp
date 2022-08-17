int DFS(int u)
{
	visitados[u] = 1;
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		int vizinho = G[u][i];
		if (visitados[vizinho] == 0)
		{
			c++;
			DFS(vizinho);
			
			
		}
	}
	return c;
}

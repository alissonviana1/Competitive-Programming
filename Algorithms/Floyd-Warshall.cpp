for (int k = 1; k <= n; k++)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			G[i][j] = max(G[i][j], G[i][k] * G[k][j]);
		}
	}
}
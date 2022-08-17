int lcs(int i,int j)
{
	if(i == n || j == n) return 0;
	int &pd = memo[i][j];
	if(pd != -1) return pd;
	if(s[i] == t[j]) return pd = 1 + lcs(i+1,j+1);
	return pd = max(lcs(i+1,j), lcs(i,j+1));
}
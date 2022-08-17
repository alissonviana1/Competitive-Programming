vector<int> BIT;

int rsq(int j)
{
	int sum = 0;
	for(; j; j -= (j & -j) )
		sum += BIT[j];
	return sum;
}

void update(int i, int v)
{
	for(; i < (int)BIT.size(); i += (i & -i) )
		BIT[i] += v;
}
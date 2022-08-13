#include <bits/stdc++.h>
using namespace std;

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

int main()
{
	int n,k;
	cin>>n;
	int vet[n+1];
	BIT.assign(n+1,0);
	
	for (int i = 1; i <= n; i++)
	{
		cin>>vet[i];
		update(i,vet[i]);
	}
	char c;
	while (cin>>c>>k && !cin.eof())
	{
		if(c == 'a') update(k, -vet[k]);
		else cout<<rsq(k-1)<<endl;
	}
	
	
}

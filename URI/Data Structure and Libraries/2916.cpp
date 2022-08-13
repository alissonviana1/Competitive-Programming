#include <bits/stdc++.h>
using namespace std;
int vetor[1000000];
int main()
{
	
	int n,m;
	long long soma = 0;
	cin.tie(NULL);
	cout.sync_with_stdio(false);
	
	while(cin>>n>>m && n!=EOF)
	{
		memset(vetor,0,sizeof(vetor));
		for (int i = 0; i < n; i++)
		{
			cin>>vetor[i];
		}
		sort(vetor, vetor + n,greater<int>());
		for (int i = 0; i < m; i++)
		{
			soma += vetor[i];
		}
		cout<<soma%1000000007<<'\n';
		soma = 0;
	}
	
	
}

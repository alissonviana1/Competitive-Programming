#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>vetor;
	long long int n,m;
	cin>>n;
	while(n--)
	{
		cin>>m;
		vetor.resize(m);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &vetor[j]);
		}
		sort(vetor.begin(), vetor.end());
		for (int j = 0; j < m-1; j++)
		{
			cout<<vetor[j]<<" ";
		}
		cout<<vetor[m-1]<<endl;
		
		
	}
	
}

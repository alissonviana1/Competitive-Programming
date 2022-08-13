#include<bits/stdc++.h>

using namespace std;
int h = 0;
map<char,int> mapa;
map<char,int>::iterator it;
int main()
{
	int aux = 0;
	int vetor2[10000];
	char vetor[10000];
	char string[10009];
	while (scanf(" %[^\n]", string) != -1)
	{
		if(aux++ > 0)
		{
			cout<<"\n";
		}
		int t = strlen(string);
		for (int i = 0; i < t; i++)
		{
			mapa[string[i]]++;	
		}
		int i = 0,k = 0;
		for (it = mapa.begin(); it != mapa.end(); ++it)
		{
			vetor[i] = it->first;
			vetor2[i] = it->second;
			k++;
			i++;	
		}
		int temp = 0,aux = 0;
		for (int i = 0; i < k-1; i++)
		{
			for (int j = i+1; j < k; j++)
			{
				if(vetor2[j] <= vetor2[i])
				{
					aux = vetor2[i];
					vetor2[i] = vetor2[j];
					vetor2[j] = aux;
					
					temp = vetor[i];
					vetor[i] = vetor[j];
					vetor[j] = temp;
				}
			}
		}
		for (int i = 0; i < k; i++)
		{
			printf("%d %d\n",vetor[i],vetor2[i]);
			
		}
		mapa.clear();
	}
	
}

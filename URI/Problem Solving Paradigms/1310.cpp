#include <iostream>
#include <vector>
using namespace std;

int vetor[10010];


int main()
{
	int n,custo,num;
	while(scanf(" %d %d", &n, &custo) != -1)
	{
		for (int i = 0; i < n; i++)
		{
			cin>>num;
			vetor[i] = num-custo;
		}
		
		int max_atual = 0, max_total = -1;
	
		for(int i = 0; i < n; i++)
		{
			max_atual = max_atual + vetor[i];
			
			if(max_atual < 0)
			{
				max_atual = 0;
			}
			if(max_atual > max_total)
			{
				max_total = max_atual;
			}
		}
		
		printf("%d\n", max_total);
	}

}

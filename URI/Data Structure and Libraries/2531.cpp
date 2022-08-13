#include <bits/stdc++.h>
using namespace std;
#define inf 123456789
typedef pair<int,int> ii;

int n;
int a[100001];
ii segtree[100001*4];


ii build(int p, int l, int r)
{
	
	if(l == r) return segtree[p] = ii(a[l],a[l]);//return ii(segtree[p].first = a[l],segtree[p].second = a[l]); 
	
	int meio = (l+r)/2;
	
	ii esquerda = build( 2*p, l, meio );
	
	ii direita = build( 2*p+1, meio+1, r );
	
	
	
	segtree[p].first = max(esquerda.first,direita.first);
	segtree[p].second = min(esquerda.second,direita.second);
	return ii(segtree[p].first,segtree[p].second);
		
}


ii query(int p, int l,int r, int i, int j)
{
	
	if ( r < i || l > j) return ii(-inf,inf);
	
	if ( i <=  l && r <= j) return segtree[p];
	
	int meio = ( l + r ) / 2;
	
	ii esquerda = query( p*2, l, meio, i, j );
	
	ii direita = query( p*2+1, meio+1, r,i,j );
	
	
	
	return ii(max(esquerda.first, direita.first), min(esquerda.second, direita.second));
}

ii update(int p,int l, int r, int i, int v)
{
	if ( r < i || l > i) return segtree[p];
	
	if( r == l )
	{
		segtree[p].first = v;
		segtree[p].second = v;
		return segtree[p];
	}
	
	int meio = ( l + r ) / 2;
	
	ii esquerda = update(p*2, l, meio, i, v);
	
	ii direita = update(p*2+1, meio + 1, r, i, v); 
	
	segtree[p].first = max(esquerda.first,direita.first);
	segtree[p].second = min(esquerda.second,direita.second);
	return segtree[p];
	
}

int main()
{
	int q,w,e,num;
	
	
	//freopen("in","r",stdin);
	while (scanf(" %d", &n) != -1)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf(" %d", &a[i]);
		}
		scanf(" %d", &q);
		build(1,1,n);
	
		for (int i = 0; i < q; i++)
		{
			scanf(" %d%d%d", &num, &w,&e);
			if (num == 1)
			{
				update(1,1,n,w,e);
			
			}
			else
			{
				ii maior = query(1,1,n,w,e);
				int soma = maior.first;
				int soma2 = maior.second;
				int total = abs(soma-soma2);
				printf("%d\n", total);
				
			}			
		}	
	}
}



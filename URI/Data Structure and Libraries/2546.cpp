#include <bits/stdc++.h>
using namespace std;
#define inf 123456789
typedef pair<long long,long long> ii;
typedef long long ll;

ll n;
ii segtree[1000000*4];
long long  a[1000000],lz[1000000*4] ; 

ii M (ii p1, ii p2)
{
	
	if (p1.first == p2.first)
	{
		if (p1.second < p2.second)
		{
			return p1;
		}
		else
		{
			return p2;
		}
		
	}
	else
	{
		if(p1.first > p2.first)
		{
			return p1;
		}
		else
		{
			return p2;
		}	
	}
}


ii build(int p, int l, int r)
{
	lz[p] = 0;
	
	if(l == r) return segtree[p] = ii(a[l],l);
	
	int meio = (l+r)/2;
	
	ii esquerda = build( 2*p, l, meio );
	
	ii direita = build( 2*p+1, meio+1, r );
	
	
	return segtree[p] = M(esquerda,direita);
		
}


ii query(int p, int l,int r, int i, int j)
{
	
	if ( r < i || l > j) return ii(-inf,7896757);
	
	if (lz[p] != 0)
	{
		segtree[p].first += lz[p];
		if (l!=r)
		{
			lz[2*p] += lz[p];
			lz[2*p+1] += lz[p];
		}
		lz[p] = 0;
	}
	
	
	if ( i <=  l && r <= j) return segtree[p];
	
	int meio = ( l + r ) / 2;
	
	ii esquerda = query( p*2, l, meio, i, j );
	
	ii direita = query( p*2+1, meio+1, r,i,j );

	return M(esquerda, direita);
}

ii update(int p,int l, int r, int i,int j, int v)
{
	
	if (lz[p] != 0)
	{
		segtree[p].first += lz[p];
		if (l!=r)
		{
			lz[2*p] += lz[p];
			lz[2*p+1] += lz[p];
		}
		lz[p] = 0;
	}
	
	
	
	if ( r < i || l > j) return segtree[p];
	if ( i <= l && r <= j )
	{
		segtree[p].first += v;
		
		if (l!=r)
		{
			lz[2*p] += v;
			lz[2*p+1] += v;
		}
		return segtree[p];
	}
	
	int meio = ( l + r ) / 2;
	
	ii esquerda = update(p*2, l, meio, i,j, v);
	
	ii direita = update(p*2+1, meio + 1, r, i,j, v); 
	
	segtree[p] = M(esquerda,direita);

	return segtree[p];
	
}
int main()
{
	ll q,w,e,v;
	char num;
		while(scanf(" %lld%lld", &n,&q) != -1)
		{
			for (int i = 1; i <= n; i++)
			{
				scanf(" %lld", &a[i]);
			}
				
			build(1,1,n);
			for (int i = 1; i <= q; i++)
			{
				scanf(" %c", &num);
				if (num == 'A')
				{
					scanf(" %lld%lld%lld", &w,&e,&v);
					update(1,1,n,w,e,v);
				}
				else
				{	if(num == 'C')
					{
						scanf(" %lld%lld", &w,&e);
						printf("%lld\n",query(1,1,n,w,e).second);
					}
				}						
			}		
		}	
	

}

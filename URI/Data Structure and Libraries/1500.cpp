#include <bits/stdc++.h>
#define max_n 100001
using namespace std;
typedef long long ll;

ll a[max_n];
ll st[4*max_n];
ll lz[4*max_n];


ll build(ll p,ll i,ll j)
{
	lz[p] = 0;
	if(i == j) return st[p] = a[i];
	ll p1 = build(2*p,i,(i+j)/2);
	ll p2 = build(2*p+1,((i+j)/2) + 1, j);
	
	return st[p] = p1+p2;	
}

ll query(ll p, ll i, ll j, ll k,ll l)
{
	
	if(l < i || j < k) return 0;
	if(lz[p] != 0)
	{
		st[p] += lz[p] * (j-i + 1);
		if(i != j)
		{
			lz[2*p] += lz[p];
			lz[2*p+1] += lz[p];
		}
		lz[p] = 0;
	}
	if(k <= i && j <= l) return st[p];
	
	ll p1 = query(2*p,i,(i+j)/2, k,l);
	ll p2 = query(2*p+1,((i+j)/2) + 1, j, k,l);
	
	return p1+p2;
	
}

ll update(ll p, ll i, ll j, ll k, ll l, ll val)
{
	if(lz[p] != 0)
	{
		st[p] += lz[p] * (j-i+1);
		if(i != j)
		{
			lz[2*p] += lz[p];
			lz[2*p+1] += lz[p];
		}
		lz[p] = 0;
	}
	if(l < i || j < k) return st[p];
	if(k <= i && j <= l)
	{
		st[p] += val * (j-i +1);
		if(i != j)
		{
			lz[2*p] += val;
			lz[2*p+1] += val;
		}
		return st[p];
	}
	ll p1 = update(2*p,i,(i+j)/2, k,l,val);
	ll p2 = update(2*p+1,((i+j)/2)+1,j,k,l,val);
	
	return st[p] = p1+p2;
}

int main()
{
	ll n;
	scanf("%lld", &n);
	while (n--)
	{
		ll r,t,q,k,l,val;
		scanf("%lld%lld", &r,&t);
		memset(a,0,sizeof a);
		build(1,1,r);
		while (t--)
		{
			scanf("%lld",&q);
			if(!q)
			{
				scanf("%lld%lld%lld", &k,&l,&val);
				update(1,1,r,k,l,val);
			}
			else
			{
				scanf("%lld%lld", &k,&l);
				printf("%lld\n", query(1,1,r,k,l));
			}
		}
		
	}
	
}

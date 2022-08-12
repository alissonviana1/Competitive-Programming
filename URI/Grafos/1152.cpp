#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

ll pai[10001000];
ll peso[10001000];

ll find(ll x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(ll a, ll b){
    
    a = find(a);
    b = find(b);
    
    if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[a] = b;
        peso[b]++;
    }
}

ll uf(ll x, ll y)
{
	if(find(x) != find(y))
	{
		return true;
	}
	return false;
}


int main(){
    
	ll nv,na,u,v,w,total = 0;
	//freopen("in","r",stdin);
	while(scanf(" %lld%lld", &nv,&na) && nv!=0 && na!=0)
	{
		for (int i = 0; i <= nv; i++)
		{
			pai[i] = 0;
		}
		
		vector< pair<ll, ii> >G;
		for (int i = 0; i < na; i++)
		{
			scanf(" %lld%lld%lld", &u,&v,&w);
			total += w;
			G.push_back(make_pair(w, ii(u, v)));
		}
		
		for(int i = 0;i < nv;i++) pai[i] = i;
		
		sort(G.begin(), G.end());
		
		ll mst = 0;
		for(int i = 0;i < na;i++)
		{
			
			pair<ll, ii> front = G[i];
			if(uf(front.second.first, front.second.second))
			{
				mst += front.first;
				join(front.second.first, front.second.second);
			}
		}
		cout<<abs(mst-total)<<endl;
		total = 0;
	}
}

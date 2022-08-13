#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int pai[1000100];
int peso[1000100];

int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}


void join(int a, int b){
    
    a = find(a);
    b = find(b);
    
    if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[b] = a;
        peso[a]++;
    }
}




int main(){
    
    
    cin.tie(NULL);
	cout.sync_with_stdio(false);
	int nv,na,u,v,w;
	while(cin>>nv>>na && nv!=0 && na!=0)
	{
		
		vector< pair<int, ii> >G;
		
		for (int i = 1; i <= na; i++)
		{
			cin>>u>>v>>w;
			G.push_back(make_pair(w, ii(u, v)));
		}
		
		for(int i = 0;i < nv;i++) pai[i] = i;
		
		sort(G.begin(), G.end());
		
		int mini = 0;
		for(int i = 0;i < na;i++)
		{
			
			pair<int, ii> front = G[i];
			if(find(front.second.first) != find(front.second.second))
			{
				mini += front.first;
				join(front.second.first, front.second.second);
			}
		}
		cout<<mini<<"\n";
	}
}


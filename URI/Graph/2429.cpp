#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi num, low, S, visited;


vector<int> G[10000];
int numSCC, dfsNumberC;
int c = 0;


void tarjan(int u)
{    
    low[u] = num[u] = dfsNumberC++;
    S.push_back(u);
    visited[u] = 1;
    
    for(int j = 0; j < (int)G[u].size(); j++)
    {
        int v = G[u][j];
        if(num[v] == 0)
        {
            tarjan(v);
        }
        if(visited[v])
        {    
            low[u] = min(low[u], low[v]);
        }
        
    }
    if(low[u] == num[u])
    {
        ++numSCC;
        
        while(1)
        {
            int v = S.back();
        
            S.pop_back();
            visited[v] = 0;
            if(u == v)
            {    
                break;
            }
            
        }
        
        
    }
            
}
int main()
{
    int a,b,n;
    cin.tie(NULL);
    cout.sync_with_stdio(false);
    
    cin>>n;
    
    num.assign(n+3, 0);
    
    low.assign(n+3, 0); 
    
    visited.assign(n+3, 0);
    
    numSCC = 0;
    dfsNumberC = 0;
    for(int i = 0; i <= n; i++)
    {
        G[i].clear();
    }
    for(int i = 1; i <= n; i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
       
    
    }
    for(int k = 1; k <= n; k++)
    {
        if(num[k] == 0)
        {
            tarjan(k);
        }
                
    }
    if(numSCC != 1)
    {
        cout<<"N\n";
    }
    else
    {
        cout<<"S\n";
    }
            
}

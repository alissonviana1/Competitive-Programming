#include <bits/stdc++.h>

using namespace std;

vector<int>pai;
vector<int> r;

int findc(int x) {
	if(pai[x] == x)
		return x;
	return pai[x] = findc(pai[x]);
}

bool isSameSet(int i, int j){return findc(i) == findc(j);}

void junta(int i, int j)
{
	if(isSameSet(i,j)) return;
	int x = findc(i), y = findc(j);
	if(r[x] > r[y]) swap(x,y);
	pai[x] = y;
	if(r[x] == r[y]) ++r[y];
}

int main()
{
	int n,k,a,b;
	char c;
	
	cin>>n>>k;
	
	r.assign(n,0);
	pai.assign(n,0);
	for(int i = 0; i < n; i++) pai[i] = i;
	
	for (int i = 0; i < k; i++)
	{
		cin>>c>>a>>b;
		if(c == 'F')
		{
			junta(a-1,b-1);
		}
		else
		{
			 if(isSameSet(a-1,b-1)) cout<<"S\n";
			 else cout<<"N\n";
		}
	}
}

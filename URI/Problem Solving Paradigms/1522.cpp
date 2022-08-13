#include <bits/stdc++.h>
using namespace std;

int pd[111][111][111];
int M[111][3];
int n,p1[111],p2[111],p3[111];

bool f(int a,int b, int c)
{
	if(a > n || b > n || c > n) return false;
    if(a == n && b == n && c == n) return true;
    
    if (pd[a][b][c]!=-1) return pd[a][b][c];
    pd[a][b][c] = false;
	
	
	if(p1[a]%3==0) pd[a][b][c] |= f(a+1,b,c);
	if(p2[b]%3==0) pd[a][b][c] |= f(a,b+1,c);
	if(p3[c]%3==0) pd[a][b][c] |= f(a,b,c+1);
	if((p1[a]+p2[b])%3==0) pd[a][b][c] |= f(a+1,b+1,c);
	if((p1[a]+p3[c]) % 3 == 0) pd[a][b][c] |= f(a+1,b,c+1);
	if((p2[b]+p3[c])% 3==0) pd[a][b][c] |= f(a,b+1,c+1);
	if((p1[a]+p2[b]+p3[c]) % 3==0) pd[a][b][c] |= f(a+1,b+1,c+1);
	
    
    return pd[a][b][c];
}


int main()
{
    
    while(cin>>n && n!=0)
    {
		memset(pd,-1,sizeof pd);
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin>>M[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			p1[i] = M[i][0];
		}
		for (int i = 0; i < n; i++)
		{
			p2[i] = M[i][1];
		}
		for (int i = 0; i < n; i++)
		{
			p3[i] = M[i][2];
		}
		
		bool t = f(0,0,0);
		
		if(t == 1)
		{
			cout<<"1\n";
		}
		else
		{
			cout<<"0\n";
		}
	
	}
}

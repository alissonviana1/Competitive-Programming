#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
   
    scanf(" %d", &n);
    while(n--)
    {
	queue<int> fila;
	int soma = 0,a,b;
	scanf(" %d%d", &a,&b);
	int i;
	for (i = 0; i < a; i++)
	{
	    fila.push(i);
	    soma += i;
	}
	fila.push(soma);
	//~ fila.pop();
	if(a>b) printf("%d\n", b-1);
	else
	{
	   while(i<b-1)
	   {
	       //~ cout << soma << endl;
	       soma = (2*soma - fila.front()+1000007)%1000007;
	       fila.push(soma);
	       fila.pop();
	       i++;
	   }
	   printf("%d\n", soma);
	}
	
    }
    
}

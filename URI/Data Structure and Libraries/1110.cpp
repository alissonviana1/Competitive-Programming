#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	queue<int> fila;
	
	while(cin>>N && N!=0)
	{
		for (int i = 0; i < N; i++)
		{
			fila.push(i+1);
		}
		cout<<"Discarded cards: ";
		while(fila.size() > 1)
		{
			cout<<fila.front();
			if(fila.size() > 2)
			{
				cout<<", ";
			}
			
			fila.pop();
			fila.push(fila.front());
			fila.pop();
		}
		cout<<"\nRemaining card: "<<fila.front()<<endl;
		fila.pop();
	}
}
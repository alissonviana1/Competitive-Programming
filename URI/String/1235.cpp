#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	char texto[1000],textoprimeiro[1000],textosegundo[1000];
	cin>>n;
	cin.ignore();
	for(int i = 0; i < n; i++)
	{
		cin.getline(texto,101);
		//~ cerr << " >> " << texto << endl;
		//~ getchar();
		
		int t = strlen(texto);
		int c = (t/2);
		for (int k = 0,q = c-1; k < c; k++,q--)
		{
			textoprimeiro[k] = texto[q];
		}
		for (int k = c,q = t-1; k < t; k++,q--)
		{
			textosegundo[k] = texto[q];	
		}
		//~ cerr << " >> " << c << endl;
		for (int k = 0 ; k < c; k++)
		{
			cout<<textoprimeiro[k];
		}
		for (int k = c; k < t; k++)
		{
			cout<<textosegundo[k];
		}
		cout<<endl;
		
		
	}
		
}

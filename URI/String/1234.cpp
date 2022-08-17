#include <bits/stdc++.h>
using namespace std;

int main()
{
	char texto[52],textonovo[51];
	while(cin.getline(texto,51) && texto!="EOF")
	{
		int t = strlen(texto);
		int  u = 0;
		for(int i = 0; i < t; i++)
		{
			if(texto[i] != ' ')
			{	
				if(u%2==0)
				{
					textonovo[i] = toupper(texto[i]);
				}
				else
				{
					textonovo[i] = tolower(texto[i]);
					
				}
				u++;		
			}
			else
			{
				textonovo[i] = ' ';
			}
			
		}
		for(int i = 0; i < t; i++)
		{
			cout<<textonovo[i];
		}
		cout<<endl;
	}
}
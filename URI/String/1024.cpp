#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	char texto[100000],textoin[10000],textoinver[10000];
	
	cin>>n;
	for(int k = 0; k < n; k++)
	{
		scanf(" %[^\n]", texto);
		int t = strlen(texto);
		for(int i = 0; i < t; i++)
		{
			if(texto[i] == ' ')
			{
				textoin[i] = ' ';
			}
			else
			{
				if((texto[i]>='a'&& texto[i]<='z') || (texto[i]>='A' && texto[i]<='Z'))
				{
					textoin[i] = texto[i] + 3;
				}
				else
				{
					textoin[i] = texto[i];
				}
				
			}		
		}
		for(int i = 0, f = t-1; f >= 0; f--,i++)
		{	
			textoinver[i] = textoin[f];	
		}
		int c = (t/2);
		for(int i = 0; i < c; i++)
		{
			printf("%c", textoinver[i]);
		}
		for(int i = c; i < t; i++)
		{
			printf("%c",textoinver[i]-1);
		}
		cout<<endl;
		c = 0;
		
	}	
}
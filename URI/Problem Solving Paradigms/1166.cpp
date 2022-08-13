#include <bits/stdc++.h>
#define INF 1234567899

using namespace std;

int dp[110001], vet[110], n, h;
bool visited[100000];


int f (int val)
{   
    int &p = dp[val];
   
    if (p != -1) return p;
    p = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == 0)
        {
            vet[i] = val;
            p = max (p, 1 + f (val + 1));
            vet[i] = 0;
        }
        else if (visited[val + vet[i]])
        {
            int aux = vet[i];
            vet[i] = val;
            p = max (p, 1 + f (val + 1));
            vet[i] = aux;
        }
    }
   
    return p;
}

int main ()
{
    int t;
    for (int i = 2; i < 300; i++)
    {
        visited[i * i] = true;
    }
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d", &n);
       
        memset (dp, -1, sizeof dp);
        memset (vet, 0, sizeof vet);
        int res = f (1);
        cout << res << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int adj[n+1][n+1];
    int distance[n+1][n+1];
    for (int i = 0; i < m; i++)
    {
        int p, q, w;
        cin >> p >> q >> w;
        adj[p][q] = w;
        adj[q][p] = w;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                distance[i][j] = 0;
            else if (adj[i][j])
                distance[i][j] = adj[i][j];
            else
                distance[i][j] = 1000000;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                distance[i][j] = min(distance[i][j],
                                     distance[i][k] + distance[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<distance[i][j]<<" ";
        }
        cout<<"\n";
    }
}

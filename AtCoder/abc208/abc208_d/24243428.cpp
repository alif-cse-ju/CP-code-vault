#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int M=4e2+5;

ll dist[M][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0;
    int i,j,k,m,n,x,y,z;
    cin >> n >> m;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)dist[i][j]=(i == j ? 0 : 1e9+5);
    }
    while(m--)cin >> x >> y >> z,dist[x][y]=z;
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)ans+=(dist[i][j] < 1e9 ? dist[i][j] : 0);
        }
    }
    cout << ans;
    return 0;
}

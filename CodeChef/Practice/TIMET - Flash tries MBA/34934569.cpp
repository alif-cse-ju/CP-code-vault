#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    bool present;
    int i,j,k,n,t,dist[102][102];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)cin >> dist[i][j];
        }
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(dist[i][k]+dist[k][j] < dist[i][j])dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        present=false;
        for(i=1;i<=n  &&  !present;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(dist[i][j] < 0  &&  dist[j][i] < 0)
                {
                    present=true;
                    break;
                }
            }
        }
        if(present)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
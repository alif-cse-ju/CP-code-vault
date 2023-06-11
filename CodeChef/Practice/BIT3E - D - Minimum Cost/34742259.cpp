#include<bits/stdc++.h>
using namespace std;
int c[100002],p[100002];
long long dist[100002],inf=1e18;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    queue<int>q;
    int i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        for(i=1;i<=n;i++)cin >> p[i];
        for(i=1;i<=n;i++)cin >> c[i],dist[i]=inf;
        dist[1]=0;
        q.emplace(1);
        while(!q.empty())
        {
            y=q.front();
            q.pop();
            if(y < n  &&  dist[y+1] > dist[y]+x)
            {
                q.emplace(y+1);
                dist[y+1]=dist[y]+x;
            }
            if(dist[p[y]] > dist[y]+c[y])
            {
                q.emplace(p[y]);
                dist[p[y]]=dist[y]+c[y];
            }
            if(y > 1  &&  dist[y-1] > dist[y]+x)
            {
                q.emplace(y-1);
                dist[y-1]=dist[y]+x;
            }
        }
        cout << dist[n] << '\n';
    }
    return 0;
}
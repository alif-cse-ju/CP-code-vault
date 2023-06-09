#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
const int N=4e2+5;
const int mod=1e9+7;
int n,c[N][N],w[N][N];
long long dist[N][N];
pair<int,int>par[N][N];
priority_queue<pair<pair<long long,int>,pair<int,int>>>pq;
void Dijkstra(const int& mask)
    long long val;
    int x,dx,y,dy,curMask;
    while(!pq.empty())
    {
        val=-pq.top().first.first;
        curMask=pq.top().first.second;
        x=pq.top().second.first;
        y=pq.top().second.second;
        pq.pop();
        dx=x,dy=y+1;
        if(dx && dy && dx <= n && dy <= n)
        {
            if(val+w[dx][dy] < dist[dx][dy]  &&  (mask | (curMask | (1 << c[dx][dy]))) == mask)
            {
                par[dx][dy]={x,y};
                dist[dx][dy]=val+w[dx][dy];
                pq.push({{-val-w[dx][dy],(curMask | (1 << c[dx][dy]))},{dx,dy}});
            }
        }
        dx=x+1,dy=y;
        if(dx && dy && dx <= n && dy <= n)
        {
            if(val+w[dx][dy] < dist[dx][dy]  &&  (mask | (curMask | (1 << c[dx][dy]))) == mask)
            {
                par[dx][dy]={x,y};
                dist[dx][dy]=val+w[dx][dy];
                pq.push({{-val-w[dx][dy],(curMask | (1 << c[dx][dy]))},{dx,dy}});
            }
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long W;
    int i,j,k,x,y;
    pair<int,int>temp;
    cin >> n >> k >> W;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)cin >> w[i][j];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)cin >> c[i][j],--c[i][j];
    }
    priority_queue<pair<int,int>>dhon;
    for(i=1;i<(1 << k);i++)dhon.emplace(-__builtin_popcount(i),i);
    while(!dhon.empty())
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)dist[i][j]=LLONG_MAX;
        }
        pq.push({{0,0},{1,0}});
        Dijkstra(dhon.top().second);
        if(dist[n][n] <= W)
        {
            cout << -dhon.top().first << '\n';
            vector<pair<int,int>>ans;
            x=y=n;
            while(x  &&  y)
            {
                ans.emplace_back(x,y);
                temp=par[x][y];
                x=temp.first,y=temp.second;
            }
            reverse(ans.begin(),ans.end());
            for(auto it : ans)cout << it.first << ' ' << it.second << ' ';
            return 0;
        }
        dhon.pop();
    }
    cout << "-1";
    return 0;
}
//
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;

#define ll long long

int n;
bool visited[M];
long long dist[M];
vector<tuple<int,ll,ll>>adj[M];
priority_queue<pair<ll,int>>pq;

void Dijkstra()
{
    int x;
    long long cost,temp,rt;
    while(!pq.empty())
    {
        cost=-pq.top().first;
        x=pq.top().second;
        pq.pop();
        if(x == n)return;
        if(visited[x])continue;
        visited[x]=1;
        for(auto [y,c,d] : adj[x])
        {
            if(d == 0)temp=cost+c;
            else
            {
                rt=sqrt(d);
                if(rt*rt == d)--rt;
                if(cost >= rt)temp=cost+c+d/(cost+1);
                else temp=rt+c+d/(rt+1);
            }
            if(temp < dist[y])
            {
                dist[y]=temp;
                pq.emplace(-temp,y);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d,i,m;
    cin >> n >> m;
    for(i=2;i<=n;i++)dist[i]=LLONG_MAX;
    while(m--)
    {
        cin >> a >> b >> c >> d;
        adj[a].emplace_back(make_tuple(b,c,d));
        adj[b].emplace_back(make_tuple(a,c,d));
    }
    pq.emplace(0,1);
    Dijkstra();
    if(dist[n] == LLONG_MAX)cout << "-1";
    else cout << dist[n];
    return 0;
}

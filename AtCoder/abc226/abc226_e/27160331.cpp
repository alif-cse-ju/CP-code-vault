#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;

bool visited[M];
vector<int>adj[M], visitedList;

void DFS(int x)
{
    if(visited[x])return;
    visited[x]=1;
    visitedList.emplace_back(x);
    for(int y : adj[x])DFS(y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=1;
    int cnt,i,m,n,sz,x,y;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            visitedList.clear();
            DFS(i);
            cnt=0, sz=(int)visitedList.size();
            for(int it : visitedList)cnt += (int)adj[it].size();
            if((sz << 1) == cnt)ans=(ans*2)%mod;
            else ans=0;
        }
    }
    cout << ans;
    return 0;
}
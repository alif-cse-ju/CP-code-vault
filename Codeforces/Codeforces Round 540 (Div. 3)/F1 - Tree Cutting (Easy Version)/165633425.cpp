#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int dp[M][3];
vector<int>adj[M];

void DFS(int x,int p)
{
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            DFS(y,x);
            for(int i=1;i<3;i++)dp[x][i] += dp[y][i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin >> x;
        ++dp[i][x], cnt1 += (x == 1), cnt2 += (x == 2);
    }
    for(int i=1;i<n;i++)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS(1,0);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i][1] == cnt1  &&  !dp[i][2])++ans;
        else if(dp[i][2] == cnt2  &&  !dp[i][1])++ans;
    }
    cout << ans;
    return 0;
}
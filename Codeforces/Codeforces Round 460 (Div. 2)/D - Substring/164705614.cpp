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

char s[M];
vector<int>adj[M];
int dp[M][26],in[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m >> s+1;
    while(m--)
    {
        int x,y;cin >> x >> y;
        ++in[y], adj[x].emplace_back(y);
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(!in[i])++dp[i][s[i]-'a'], q.emplace(i);
    }
    if(q.empty())
    {
        cout << "-1";
        return 0;
    }
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        for(int y : adj[x])
        {
            if(!in[y])
            {
                cout << "-1";
                return 0;
            }
            for(int i=0;i<26;i++)dp[y][i]=max(dp[x][i], dp[y][i]);
            --in[y];
            if(!in[y])++dp[y][s[y]-'a'], q.emplace(y);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(in[i])
        {
            cout << "-1";
            return 0;
        }
        for(int j=0;j<26;j++)ans=max(ans, dp[i][j]);
    }
    cout << ans;
    return 0;
}
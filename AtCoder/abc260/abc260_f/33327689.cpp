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

const int sz = 3e3+5;

int dp[sz][sz];
vector<int>adj[M+sz];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,s,t;cin >> s >> t >> m;
    while(m--)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(int i=s+1;i<=s+t;i++)
    {
        for(int j : adj[i])
        {
            for(int k : adj[j])
            {
                if(i == k)continue;
                if(dp[i-s][k-s]  &&  dp[i-s][k-s] != j)
                {
                    cout << i << ' ' << j << ' ' << k << ' ' << dp[i-s][k-s];
                    return 0;
                }
                dp[i-s][k-s]=j;
            }
        }
    }
    cout << "-1";
    return 0;
}
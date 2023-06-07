#pragma GCC optimize("Ofast")

#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

ll s[M];
vector<int>adj[M];
vector<pair<ll,int>>posAns[M];

ll DFS(int x,int k)
{
    for(auto [dp,kk] : posAns[x])
    {
        if(kk == k)return dp;
    }
    ll dp=1ll*k*s[x];
    int sz=(int)adj[x].size();
    if(!sz)return dp;
    if(k%sz == 0)
    {
        for(int &y : adj[x])dp += DFS(y,k/sz);
    }
    else
    {
        vector<ll>diff(sz);
        for(int i=0;i<sz;i++)
        {
            ll dp1=DFS(adj[x][i], k/sz), dp2=DFS(adj[x][i], k/sz+1);
            dp += dp1, diff[i]=dp2-dp1;
        }
        sort(diff.begin(),diff.end());
        int rem=k%sz;
        while(rem--)dp+=diff.back(), diff.pop_back();
    }
    posAns[x].emplace_back(dp,k);
    return dp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int k,n;cin >> n >> k;
        for(int i=1;i<=n;i++)adj[i].clear(), posAns[i].clear();
        for(int i=2;i<=n;i++)
        {
            int p;cin >> p;
            adj[p].emplace_back(i);
        }
        for(int i=1;i<=n;i++)cin >> s[i];
        cout << DFS(1,k) << '\n';
    }
    return 0;
}

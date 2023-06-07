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
#include <climits>
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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

vector<pair<int,int>>adj[M];
int cnt,dp[M][2],in[M][2],out[M][2];

void DFS(int x,int p,int id)
{
    in[x][id]=++cnt;
    for(auto [y,z] : adj[x])
    {
        if(p ^ y)dp[y][id]=(dp[x][id] ^ z), DFS(y,x,id);
    }
    out[x][id]=cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int a,b,n;cin >> n >> a >> b;
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<n;i++)
        {
            int x,y,z;cin >> x >> y >> z;
            adj[x].emplace_back(y,z);
            adj[y].emplace_back(x,z);
        }
        cnt=dp[a][0]=0, DFS(a,0,0);
        cnt=dp[b][1]=0, DFS(b,0,1);
        if(!dp[b][0])cout << "YES\n";
        else
        {
            map<int,bool>mp;
            for(int i=1;i<=n;i++)
            {
                if(b == i)continue;
                mp[dp[i][1]]=1;
            }
            bool ok=0;
            for(int i=1;i<=n  &&  !ok;i++)
            {
                if(in[i][0] >= in[b][0]  &&  out[i][0] <= out[b][0])continue;
                if(mp.find(dp[i][0]) != mp.end())ok=1;
            }
            if(ok)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}

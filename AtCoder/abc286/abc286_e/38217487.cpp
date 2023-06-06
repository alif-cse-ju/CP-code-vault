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

const int mx = 302;

char s[mx][mx];
int a[mx],id,n;
pair<int,ll>dp[mx][mx];
priority_queue<tuple<int,ll,int>>pq;

void Dijkstra()
{
    while(!pq.empty())
    {
        auto [d,v,x]=pq.top(); pq.pop();
        if(dp[id][x] != make_pair(-d,v))continue;
        d=-d+1;
        for(int i=1;i<=n;i++)
        {
            if(s[x][i] == 'Y')
            {
                int y=i;
                if(dp[id][y].first > d)dp[id][y]={d,v+a[y]}, pq.emplace(make_tuple(-d,v+a[y],y));
                else if(dp[id][y].first == d  &&  dp[id][y].second < v+a[y])dp[id][y]={d,v+a[y]}, pq.emplace(make_tuple(-d,v+a[y],y));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++)cin >> s[i]+1;
    for(id=1;id<=n;id++)
    {
        for(int i=1;i<=n;i++)dp[id][i]={INT_MAX, LLONG_MIN};
        dp[id][id]={0,a[id]}, pq.emplace(make_tuple(0,a[id],id)), Dijkstra();
    }
    int q;cin >> q;
    while(q--)
    {
        int x,y;cin >> x >> y;
        if(dp[x][y].first == INT_MAX)cout << "Impossible\n";
        else cout << dp[x][y].first << ' ' << dp[x][y].second << '\n';
    }
    return 0;
}
